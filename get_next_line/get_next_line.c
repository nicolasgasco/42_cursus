/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 17:14:15 by ngasco            #+#    #+#             */
/*   Updated: 2021/08/18 18:13:13 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Read the file one piece at the time

// Store result in static variable



char *get_next_line(int fd)
{
    // Create a buffer which is as big as BUFFER_SIZE
    char    *buffer;
    // Create a variable for the line read
    char    *line;
    int     i;

    line = malloc(sizeof(char *));
    buffer = malloc(sizeof(char) * BUFFER_SIZE);
    i = 0;

    // printf("%d\n", fd);
    // Returns null if descriptor not valid or buffer not valid
    if (fd < 0 || BUFFER_SIZE <= 0)
    {
        free(buffer);
        free(line);
        return (NULL);
    }

    // Read bytes untill you reach a \n or the buffer is full
    // Read from specified fd with read
    read(fd, buffer, BUFFER_SIZE);
    
    // Look for \n inside of buffer
    printf("|%s|\n", buffer);
    while (buffer[i] != '\n' && buffer[i] != '\0')
    {
        // printf(".%c.\n", buffer[i]);
        line[i] = buffer[i];
        i++;
    }
    // If \n is found -> LINE FOUND
    if (buffer[i] == '\n')
    {
        // printf("Word found: %s\n", line);
        return (line);
    }

    // If \0 is found -> KEEP SEARCHING
    if (buffer[i] == '\0')
    {
        // printf("Keep searching...\n");
        return (NULL);
    }
    // Returns the line read
    return (NULL);
}
