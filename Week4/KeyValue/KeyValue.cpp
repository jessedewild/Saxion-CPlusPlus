#include <iostream>
#include "KeyValue.h"

[[noreturn]] void Error(std::string const &message) {
    std::cerr << message << std::endl;
    exit(-1);
}

void KeyValue::Create(ValueInt *value) {
    m_values.emplace_back(*value);
}

ValueInt const &KeyValue::Get(std::string const &name) const {
    for (const auto &value : m_values) {
        if (value.GetName() == name) {
            return value;
        }
    }
    Error("Key not found!");
}

ValueInt &KeyValue::Get(std::string const &name) {
    for (auto &value : m_values) {
        if (value.GetName() == name) {
            return value;
        }
    }
    Error("Key not found!");
}

void KeyValue::Delete(std::string const &name) {
    for (int i = 0; i < m_values.size(); i++) {
        if (m_values[i].GetName() == name) {
            auto pos = m_values.begin() + i;
            m_values.erase(pos);
        }
    }
}
