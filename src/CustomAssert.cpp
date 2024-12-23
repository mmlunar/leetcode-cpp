#include "CustomAssert.h"

// Explicit instantiation of template functions
template void CustomAssert::run<int>(int, int);
template void CustomAssert::run<bool>(bool, bool);
template void CustomAssert::run<double>(double, double);
template void CustomAssert::run<std::string>(std::string, std::string);

template void CustomAssert::run<int>(int, int, const std::string&);
template void CustomAssert::run<bool>(bool, bool, const std::string&);
template void CustomAssert::run<double>(double, double, const std::string&);
template void CustomAssert::run<std::string>(std::string, std::string, const std::string&);
