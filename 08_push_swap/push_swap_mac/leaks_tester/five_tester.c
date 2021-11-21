#include "tester.h"

int main()
{
    int     fd;
    char    *line;
    int     i;
    char    *cmd;

    // Open file containing one set of numbers for each line
    // Random sets generator: https://www.random.org/integer-sets/
    fd = open("numbers", O_RDONLY);
    i = 0;
    system("echo '' > output");
    while (1)
    {
        // Bash command initialized
        cmd = malloc(1);
        cmd[0] = '\0';

        // Reading one line at a time
        line = get_next_line(fd);
        if (!line)
        {
            system("cat output | grep 'ERROR' > results");
            system("rm -rf output");
            system("cat results");
            return (0);
        }
        else
        {
            printf("Test %d\n\n", i + 1);

            
            // Removing newline after set of numbers
            line[ft_strlen(line) - 1] = '\0';
            
            // Putting Bash command together
            cmd = ft_strjoin(cmd, "ARG='");
            cmd = ft_strjoin(cmd, line); // set of numbers
            cmd = ft_strjoin(cmd, "'; ./push_swap $ARG  | valgrind --undef-value-errors=no --leak-check=full --log-file='log' ./checker $ARG");
            // valgrind --undef-value-errors=no --leak-check=full
            
            
            // Copy over binaries and checker
            system("cp ../push_swap ./");
            system("cp ../checker ./");
            
            // Execute Bash command
            system(cmd);
            system("cat log >> output");
            printf("_____________________________________________________________\n\n");
        }
        free(cmd);
        i++;
    }
}