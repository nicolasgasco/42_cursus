# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <string.h>

typedef struct s_tokens
{
    char **cmds;
    int std_out;
    int std_in;
    struct s_tokens *next;
}        t_tokens;

int ft_strlen(char *str)
{
    int i = 0;

    while (str[i])
        i++;
    return (i);
}

void    print_error(char *str, char *str1, int n)
{
    write(2, str, ft_strlen(str));
    if (str1)
        write(2, str1, ft_strlen(str1));
    write(2, "\n", 1);
    if (n)
        exit(1);
}

t_tokens    *init_tokens()
{
    t_tokens *tmp;
    if (!(tmp = malloc(sizeof(t_tokens))))
        print_error("error: fatal", NULL, 1);
    if (!(tmp->cmds = malloc(sizeof(char *) * 1024)))
        print_error("error: fatal", NULL, 1);
    tmp->std_in = 0;
    tmp->std_out = 1;
    return (tmp);
}

void    ft_pipe(t_tokens *tokens)
{
    int pip[2];

    pipe(pip);
    tokens->next = init_tokens();
    tokens->std_out = pip[1];
    tokens->next->std_in = pip[0];
}

int add_cmd(t_tokens *tokens, char **argv, int i)
{
    int j = 0;

    while (argv[i] && strcmp(argv[i], ";") && strcmp(argv[i], "|"))
    {
        tokens->cmds[j] = argv[i];
        i++;
        j++;
    }
    i++;
    tokens->cmds[j] = NULL;
    return (i);
}

void    exec_cmd(t_tokens *tokens, int *start, int i)
{
    int pid;
    if (!(strcmp(tokens->cmds[0], "cd")))
    {
        if (tokens->cmds[2] || !tokens->cmds[1])
            print_error("error: cd: bad arguments", NULL, 0);
        else if (chdir(tokens->cmds[1]))
            print_error("error: cd: cannot change ", tokens->cmds[1], 0);
        *start = i;
        return ;
    }
    pid = fork();
    if (pid < 0)
        print_error("error: fatal", NULL, 1);
    if (pid == 0)
    {
        if (tokens->std_out != 1)
        {
            close(tokens->next->std_in);
            if (dup2(tokens->std_out, 1) == -1)
                print_error("error: fatal", NULL, 1);
        }
        if (tokens->std_in != 0)
            if (dup2(tokens->std_in, 0) == -1)
                print_error("error: fatal", NULL, 1);
        execve(tokens->cmds[0], tokens->cmds, NULL);
        print_error("error: cannot execute ", tokens->cmds[0], 1);
    }
    if (tokens->std_out != 1)
        close(tokens->std_out);
    if (tokens->std_in != 0)
        close(tokens->std_in);
    if (tokens->std_out == 1)
    {
        while (*start < i)
        {
            waitpid(0, NULL, 0);
            (*start)++;
        }
    }
}   

void    ft_free(t_tokens *tokens)
{
    if (tokens)
    {
        if (tokens->cmds)
            free(tokens->cmds);
        free(tokens);
        tokens = NULL;
    }
}

int     main(int argc, char **argv)
{
    t_tokens *tokens;
    int i = 1;
    int start = i;
    t_tokens *before;
    while (i < argc)
    {
        if (tokens == NULL || start == i)
            tokens = init_tokens();
        if (!(strcmp(argv[i], ";")))
        {
            i++;
            continue;
        }
        i = add_cmd(tokens, argv, i);
        if (argv[i - 1] && !(strcmp(argv[i - 1], "|")))
            ft_pipe(tokens);
        exec_cmd(tokens, &start, i);
        before = tokens;
        if (tokens->std_out != 1)
            tokens = tokens->next;
        ft_free(before);
    }
    return (0);
}