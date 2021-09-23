#include "so_long.h"

int ft_map_line_length(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0' && str[i] != '\n')
        i++;
    return (i);
}

void    ft_check_middle_line(char *line)
{
    if (line[0] != '1' || line[ft_map_line_length(line) - 1] != '1')
    {
        perror("Map error (breach in the side walls)");
        exit(0);
    }

}
void    ft_check_horizontal_border(char *line)
{
    int i;
    
    i = 0;
    while (line[i] != '\0' && line[i] != '\n')
    {
        if (line[i] != '1')
        {
            perror("Map error (breach in the top walls)");
            exit(0);
        }
        i++;
    }
}

void    ft_check_foreign_chars(char *line)
{
    int i;

    i = 0;
    while(line[i] != '\0')
    {
        if (line[i] != '1' && line[i] != '0' && line[i] != 'E'
        && line[i] != 'C' && line[i] != 'P' && line[i] != '\n')
        {
            perror("Map error (foreign character)");
            exit(0);
        }
        i++;
    }
}

void    ft_check_min_chars(char *line)
{
    static int exit_count;
    static int collect_count;
    static int pos_count;
    int        i;

    if (!exit_count)
        exit_count = 0;
    if (!collect_count)
        collect_count = 0;
    if (!pos_count)
        pos_count = 0;
    if (line[0] == '\0' && (exit_count == 0 || collect_count == 0 || pos_count == 0))
    {
        printf("%d (exit), %d (pos), %d (col)\n", exit_count, pos_count, collect_count);
        perror("Map error (chars missing)");
        exit(0);
    }
    i = 0;
    while (line[i] != '\0')
    {
        if (line[i] == 'E')
            exit_count++;
        else if (line[i] == 'C')
            collect_count++;
        else if (line[i] == 'P')
            pos_count++;
        i++;
    }    
}

void    ft_check_map_length(char *line)
{
    static int     line_lenght;

    if (!line_lenght)
        line_lenght = ft_map_line_length(line);
    else
        if (ft_map_line_length(line) != line_lenght)
        {
            perror("Map error (not rectangular)");
            exit(0);
        }
}

void    ft_validate_map(int file)
{
	char	*line;
    char    *previous_line;

    previous_line = NULL;
	while (1)
	{
		line = ft_get_next_line(file, 1);
		if (line == NULL)
        {
            ft_check_min_chars("");
			break;
        }
        if (!previous_line)
        {
            ft_check_horizontal_border(line);
        }
        else
            ft_check_middle_line(line);
        ft_check_map_length(line);
        ft_check_min_chars(line);
        ft_check_foreign_chars(line);
        previous_line = line;
		// printf("Line is: '%s'\n", line);
	}
    ft_check_horizontal_border(previous_line);
    printf("Map is legit.\n");
}