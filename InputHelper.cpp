template <typename T>
T getInput(const std::string& prompt, const std::function<bool(T)>& validator, const std::string& errorMsg) {
    T value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value && validator(value)) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
        else {
            std::cout << errorMsg;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}
