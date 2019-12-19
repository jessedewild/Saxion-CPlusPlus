#ifndef SAXION_CPLUSPLUS_VALUEBASE_H
#define SAXION_CPLUSPLUS_VALUEBASE_H

#include <string>

/**
 * ValueBase class.
 */
class ValueBase {
protected:

    std::string m_name; // Name

public:

    /**
     * Constructor for ValueBase.
     *
     * @param name string
     */
    ValueBase(const std::string &name);

    /**
     * Return the name of this value.
     *
     * @return string
     */
    std::string const &GetName() const;

    /**
     * Output the value to the output stream.
     *
     * @param out ostream
     */
    virtual void Get(std::ostream &out) const = 0;
};

#endif //SAXION_CPLUSPLUS_VALUEBASE_H
