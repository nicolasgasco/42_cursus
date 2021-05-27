/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_memccpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 11:56:21 by ngasco            #+#    #+#             */
/*   Updated: 2021/05/26 11:21:01 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include <string.h>
void *ft_memccpy(void *restrict dest, const void *restrict src, int c, size_t n);
int main(void)
{
    const char src[] = "Stars: Altair, Sun, Vega.";
    const char terminal[] = {':', ' ', ',', '.', '!'};
    char dest[sizeof src];
    const char alt = '@';
 
    for (size_t i = 0; i != sizeof terminal; ++i) {
 
        void *to = ft_memccpy(dest, src, terminal[i], sizeof dest);
 
        printf("Terminal '%c' (%s):\t\"", terminal[i], to ? "found" : "absent");
 
        // if `terminal` character was not found - print the whole `dest`
        to = to ? to : dest + sizeof dest;
 
        for (char *from = dest; from != to; ++from)
            putchar(isprint(*from) ? *from : alt);
 
        puts("\"");
    }
 
 
    puts("\n" "Separate star names from distances (ly):");
    const char *star_distance[] = {
        "Arcturus : 37", "Vega : 25", "Capella : 43", "Rigel : 860", "Procyon : 11"
    };
    char names_only[64];
    char *first = names_only;
    char *last = names_only + sizeof names_only;
 
    for (size_t t = 0; t != (sizeof star_distance)/(sizeof star_distance[0]); ++t) {
        if (first) {
            first = ft_memccpy(first, star_distance[t], ' ', last - first);
        } else break;
    }
    if (first) {
        *first = '\0';
        puts(names_only);
    } else {
        puts("Buffer is too small.");
    }
}