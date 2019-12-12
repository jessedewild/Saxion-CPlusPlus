#include "KeyValue.h"

void KeyValue::Create(ValueInt *value) {
    m_values.emplace_back(*value);
}

ValueInt const &KeyValue::Get(std::string const &name) const {
    for (const auto &value : m_values) {
        if (value.GetName() == name) {
            return value;
        }
    }
}

ValueInt &KeyValue::Get(std::string const &name) {
    for (auto &value : m_values) {
        if (value.GetName() == name) {
            return value;
        }
    }
}

void KeyValue::Delete(std::string const &name) {
    for (int i = 0; i < m_values.size(); i++) {
        if (m_values[i].GetName() == name) {
            auto pos = m_values.begin() + i;
            m_values.erase(pos);
        }
    }
}
