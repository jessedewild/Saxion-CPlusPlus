#include <iostream>
#include "ValueInt.h"

ValueInt::ValueInt(const std::string &name, const int value)
        : ValueBase(name) {
    m_value = value;
}

void ValueInt::Update(int value) {
    m_value = value;
}

void ValueInt::Get(std::ostream &out) const {
    out << m_name << "=" << m_value << " (int)";
}
