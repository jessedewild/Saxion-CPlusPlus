#include <iostream>
#include "ValueInt.h"

ValueInt::ValueInt(const std::string &name, const int value) {
    m_name = name;
    m_value = value;
}

void ValueInt::Update(int value) {
    m_value = value;
}

void ValueInt::Get(std::ostream &out) const {
    out << m_name << "=" << m_value << " (int)" << std::endl;
}

std::string const &ValueInt::GetName() const {
    return m_name;
}
