/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 13:14:49 by ngasco            #+#    #+#             */
/*   Updated: 2022/04/22 13:14:58 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstring>
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    for (int i = 1; i < argc; ++i) {
        for (int x = 0; x < (int)strlen(argv[i]); ++x) {
            std::cout << (char)toupper(argv[i][x]);
        }
    }
    std::cout << std::endl;
    return 0;
}
