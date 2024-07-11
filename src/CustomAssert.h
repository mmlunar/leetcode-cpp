#ifndef CUSTOMASSERT_H
#define CUSTOMASSERT_H

#include <iostream>
#include <string>
#include <cassert>

class CustomAssert 
{
    public:
        static void run(int x, int y);
        static void run(int x, int y, std::string message);
};

#endif // CUSTOMASSERT_H
