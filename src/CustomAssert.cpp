#include "CustomAssert.h"

template <typename T>
void CustomAssert::run(T x, T y) 
{
    if (x != y) 
    {
        std::cout << "Expected: " << x << ", Actual: " << y << std::endl;
    }
    assert(x == y);
}

template <typename T>
void CustomAssert::run(T x, T y, const std::string message)
{
    if (x != y) 
    {
        std::cout << message << " Expected: " << x << ", Actual: " << y << std::endl;
    }
    assert(x == y);
}


