/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_comp_2.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 19:37:53 by adbenoit          #+#    #+#             */
/*   Updated: 2021/10/16 20:19:10 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Dummy.hpp"

void    isConst(std::string& str) {
    std::cout << str;
}

int main(void)
{
    Dummy richard;
    isConst(richard.getType());
    
    return 0;
}
