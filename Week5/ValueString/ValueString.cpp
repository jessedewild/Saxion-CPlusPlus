#include "ValueString.h"
#include <iostream>
#include <utility>

ValueString::ValueString(const std::string &name, const std::string &value)
        : ValueBase(name) {
    m_value = value;
}

void ValueString::Update(std::string value) {
    m_value = std::move(value);
}

void ValueString::Get(std::ostream &out) const {
    out << m_name << "=" << m_value << " (string)";
}
