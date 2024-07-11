#include "CustomAssert.h"

void CustomAssert::run(int x, int y) 
{
    if (x != y) 
    {
        std::cout << "Expected: " << x << ", Actual: " << y << std::endl;
        assert(x == y);
    }
}

void CustomAssert::run(int x, int y, std::string message) 
{
    if (x != y) 
    {
        std::cout << message << " Expected: " << x << ", Actual: " << y << std::endl;
        assert(x == y);
    }
}
