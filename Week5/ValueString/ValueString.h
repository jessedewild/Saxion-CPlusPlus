#ifndef SAXION_CPLUSPLUS_VALUESTRING_H
#define SAXION_CPLUSPLUS_VALUESTRING_H

#include "../ValueBase/ValueBase.h"

/**
 * ValueString class.
 */
class ValueString : public ValueBase {
private:

    std::string m_value; // Value

public:

    /**
     * Constructor for ValueString.
     *
     * @param name const string
     * @param value const string
     */
    ValueString(const std::string &name, const std::string &value);

    /**
     * Update the value.
     *
     * @param value int
     */
    void Update(std::string value);

    /**
     * Output the value to the output stream.
     *
     * @param out ostream
     */
    void Get(std::ostream &out) const override;
};

#endif //SAXION_CPLUSPLUS_VALUESTRING_H
