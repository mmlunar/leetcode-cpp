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

// Explicit instantiation
template void CustomAssert::run<int>(int, int);
template void CustomAssert::run<bool>(bool, bool);
template void CustomAssert::run<double>(double, double);
template void CustomAssert::run<std::string>(std::string, std::string);

template void CustomAssert::run<int>(int, int, const std::string);
template void CustomAssert::run<bool>(bool, bool, const std::string);
template void CustomAssert::run<double>(double, double, const std::string);
template void CustomAssert::run<std::string>(std::string, std::string, const std::string);
