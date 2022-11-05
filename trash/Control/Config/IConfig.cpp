#include "IConfig.h"

void IConfig::is_ok() {
    std::vector<char> used_chars;
    for (auto elem : control) {
        if (elem.first == '\0') {
            control = control_default;
            return;
        }
        used_chars.push_back(elem.first);
    }

    if (check_repeats(used_chars))
        control = control_default;
}

bool IConfig::check_repeats(const std::vector<char>& used_chars) {
    for (size_t i = 0; i != used_chars.size(); ++i) {
        for (size_t j = i + 1; j != used_chars.size() - 1; ++j) {
            if (used_chars[i] == used_chars[j])
                return true;
        }
    }
    return false;
}
