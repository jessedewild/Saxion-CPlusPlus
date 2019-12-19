#ifndef SAXION_CPLUSPLUS_VALUEINT_H
#define SAXION_CPLUSPLUS_VALUEINT_H

#include "../ValueBase/ValueBase.h"

/**
 * ValueInt class.
 */
class ValueInt : public ValueBase {
protected:

    int m_value; // Value

public:

    /**
     * Constructor for ValueInt.
     *
     * @param name const string
     * @param value const int
     */
    ValueInt(const std::string &name, int value);

    /**
     * Update the value.
     *
     * @param value int
     */
    void Update(int value);

    /**
    * Output the value to the output stream.
    *
    * @param out ostream
    */
    void Get(std::ostream &out) const override;
};

#endif //SAXION_CPLUSPLUS_VALUEINT_H
