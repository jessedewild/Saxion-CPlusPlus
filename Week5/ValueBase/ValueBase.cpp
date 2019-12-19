#include "ValueBase.h"

ValueBase::ValueBase(const std::string &name) {
    m_name = name;
}

std::string const &ValueBase::GetName() const {
    return m_name;
}
