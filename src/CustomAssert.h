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

// Explicit instantiation
template void CustomAssert::run<int>(int, int);
template void CustomAssert::run<bool>(bool, bool);
template void CustomAssert::run<double>(double, double);
template void CustomAssert::run<std::string>(std::string, std::string);

template void CustomAssert::run<int>(int, int, const std::string);
template void CustomAssert::run<bool>(bool, bool, const std::string);
template void CustomAssert::run<double>(double, double, const std::string);
template void CustomAssert::run<std::string>(std::string, std::string, const std::string);

#endif // CUSTOMASSERT_H
