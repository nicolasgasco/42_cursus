/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <ngasco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 11:56:21 by ngasco            #+#    #+#             */
/*   Updated: 2021/05/26 09:35:29 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>


void	ft_bzero(void *s, size_t nbyte);
int main () {
   char str[34];

   strcpy(str,"This is string.h library function");

   ft_bzero(str, 5);
   int i = 0;
   while (i < 34)
   {
      printf("%c", str[i]);
      i++;
   }
   
   return(0);
}
