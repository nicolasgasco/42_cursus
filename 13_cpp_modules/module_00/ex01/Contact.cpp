#include <iostream>

class Contact {
   public:
    Contact(void) {
        std::cout << "Contact constructor" << std::endl;
    };
    ~Contact(void) {
        std::cout << "Contact destructor" << std::endl;
    };

    // First
    // Last
    // Nick
    // Phone number
    // Darkest secret
};
