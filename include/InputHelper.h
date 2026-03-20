#ifndef INPUT_HELPER_H
#define INPUT_HELPER_H

#include <string>

std::string promptRequiredText(
    const std::string& prompt,
    const std::string& errorMsg
);

int promptIntInRange(
    const std::string& prompt,
    int minValue,
    int maxValue,
    const std::string& errorMsg
);

float promptFloatInRange(
    const std::string& prompt,
    float minValue,
    float maxValue,
    const std::string& errorMsg
);

char promptGender(
    const std::string& prompt,
    const std::string& errorMsg
);

#endif
