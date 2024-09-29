#ifndef CUSTOMASSERT_H
#define CUSTOMASSERT_H

#include <iostream>
#include <string>
#include <cassert>

class CustomAssert 
{
    public:
        template <typename T>
        static void run(T x, T y);

        template <typename T>
        static void run(T x, T y, const std::string message);
};

#endif // CUSTOMASSERT_H
