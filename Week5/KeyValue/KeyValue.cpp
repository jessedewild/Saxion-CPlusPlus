#include <iostream>
#include "KeyValue.h"

[[noreturn]] void Error(std::string const &message) {
    std::cerr << message << std::endl;
    exit(-1);
}

void KeyValue::Create(ValueBase *value) {
    m_values.push_back(value);
}

ValueBase const &KeyValue::Get(std::string const &name) const {
    try {
        for (const auto &value : m_values) {
            if (value->GetName() == name) {
                return *value;
            }
        }
    } catch (...) {
        Error("Key not found!");
    }
}

ValueBase &KeyValue::Get(std::string const &name) {
    try {
        for (auto &value : m_values) {
            if (value->GetName() == name) {
                return *value;
            }
        }
    } catch (...) {
        Error("Key not found!");
    }
}

void KeyValue::Delete(std::string const &name) {
    for (unsigned int i = 0; i < m_values.size(); i++) {
        if (m_values[i]->GetName() == name) {
            auto pos = m_values.begin() + i;
            m_values.erase(pos);
        }
    }
}
