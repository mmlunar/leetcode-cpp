#ifndef CUSTOMASSERT_H
#define CUSTOMASSERT_H

#include <iostream>
#include <string>
#include <cassert>

class CustomAssert 
{
public:
    // Template function to compare two values
    template <typename T>
    static void run(T x, T y) 
    {
        if (x != y) 
        {
            std::cout << "Expected: " << x << ", Actual: " << y << std::endl;
        }
        assert(x == y);
    }

    // Template function with a custom message
    template <typename T>
    static void run(T x, T y, const std::string& message) 
    {
        if (x != y) 
        {
            std::cout << message << " Expected: " << x << ", Actual: " << y << std::endl;
        }
        assert(x == y);
    }
};

#endif // CUSTOMASSERT_H

