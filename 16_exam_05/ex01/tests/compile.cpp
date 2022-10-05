/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_main.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 18:13:58 by adbenoit          #+#    #+#             */
/*   Updated: 2021/10/16 20:04:04 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Warlock.hpp"
#include "../Fwoosh.hpp"
#include "../Dummy.hpp"

class test1 : public ASpell
{
    public:
        test1() : ASpell("ASpell attributs", " is protected") {}
        void printAttributs() const {
            std::cout << ASpell::name + ASpell::effects << std::endl;
        }
        virtual test1    *clone() const { return new test1(); }
};

class test2 : public ATarget
{
    public:
        test2() : ATarget("ATarget attributs is protected") {}
        void printAttributs() const {
            std::cout << ATarget::type << std::endl;
        }
        virtual test2    *clone() const { return new test2(); }
};

int main()
{
    Warlock richard("Richard", "foo");
    
    // test const
    const Fwoosh *fwoosh = new Fwoosh();
    const Dummy bob;
    fwoosh->launch(bob);
    
    // test class attributs
    test1 aspell;
    test2 atarget;
    aspell.printAttributs();
    atarget.printAttributs();
}
