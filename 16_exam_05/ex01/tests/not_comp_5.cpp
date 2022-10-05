/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_comp_5.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 19:37:53 by adbenoit          #+#    #+#             */
/*   Updated: 2021/10/16 20:19:04 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Fwoosh.hpp"

void    isConst(std::string& str) {
    std::cout << str;
}

int main(void)
{
    Fwoosh richard;
    isConst(richard.getName());
    
    return 0;
}
