#ifndef INPUT_HELPER_H
#define INPUT_HELPER_H

#include <iostream>
#include <functional>
#include <string>
#include <limits>

template <typename T>
T getInput(const std::string& prompt, const std::function<bool(T)>& validator = [](T) { return true; }, const std::string& errorMsg = "Invalid input. Please try again: ");

#include "../src/InputHelper.cpp" // Template implementation
#endif
