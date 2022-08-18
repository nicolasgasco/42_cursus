#pragma once
#ifndef __KAREN_H__
#define __KAREN_H__

#include <iostream>

class Karen
{

public:
    Karen(void);
    ~Karen(void);

    void complain(std::string level);

private:
    void debug(void) const;
    void info(void) const;
    void warning(void) const;
    void error(void) const;
};

#endif
