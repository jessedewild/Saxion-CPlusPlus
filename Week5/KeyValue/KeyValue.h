#ifndef SAXION_CPLUSPLUS_KEYVALUE_H
#define SAXION_CPLUSPLUS_KEYVALUE_H

#include "string"
#include <vector>
#include "../ValueBase/ValueBase.h"

class KeyValue {
private:

    std::vector<ValueBase *> m_values;

public:

    /**
     * Store a new value entry in the database.
     * Generate an error when a duplicate entry
     * is being created!
     *
     * @param value ValueInt
     */
    void Create(ValueBase *value);

    /**
     * Obtain a KeyValue entry by name.
     * Returning a const reference.
     *
     * @param name string
     * @return ValueInt
     */
    ValueBase const &Get(std::string const &name) const;

    /**
     * Obtain a value entry by name.
     * Returning a reference.
     *
     * @param name string
     * @return ValueInt
     */
    ValueBase &Get(std::string const &name);

    /**
     * Delete the specified key from the database or
     * ignore if the key does not exist.
     *
     * @param name string
     */
    void Delete(std::string const &name);
};

#endif //SAXION_CPLUSPLUS_KEYVALUE_H
