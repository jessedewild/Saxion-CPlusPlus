#ifndef SAXION_CPLUSPLUS_VALUEINT_H
#define SAXION_CPLUSPLUS_VALUEINT_H

/**
 * ValueInt class.
 */
class ValueInt {
private:

    std::string m_name; // Name
    int m_value; // Value

public:

    /**
     * Constructor for ValueInt.
     *
     * @param name const string
     * @param value const int
     */
    ValueInt(const std::string &name, const int value);

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
    void Get(std::ostream &out) const;

    /**
     * Return the name of this value.
     *
     * @return string
     */
    std::string const &GetName() const;
};

#endif //SAXION_CPLUSPLUS_VALUEINT_H
