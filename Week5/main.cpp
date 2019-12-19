#include <iostream>
#include <chrono>
#include <sstream>
#include "ValueInt/ValueInt.h"
#include "KeyValue/KeyValue.h"
#include "ValueString/ValueString.h"

enum KeyVariable {
    V_INT, V_STRING
};
KeyVariable const g_variable = V_STRING;
std::string g_variable_str;

std::string IntToString(int value) {
    std::ostringstream output;
    output << value;
    return output.str();
}

int main(int argc, char *argv[]) {
    KeyValue key_value;

    std::chrono::time_point<std::chrono::system_clock> p1;
    p1 = std::chrono::system_clock::now();

    constexpr size_t number_of_keys = 10000;

    // Create elements with names int_1..number_of_keys
    // and values 1..number_of_keys
    for (size_t i = 1; i < number_of_keys; ++i) {
        switch (g_variable) {
            case V_INT:
                g_variable_str = "int";
                key_value.Create(new ValueInt("int_" + IntToString(i), i));
                break;
            case V_STRING:
                g_variable_str = "string";
                key_value.Create(new ValueString("string_" + IntToString(i), IntToString(i)));
                break;
        }
    }

    for (size_t i = 1; i < number_of_keys; ++i) {
        std::string key = g_variable_str + "_" + IntToString(i);
        ValueBase const &value = key_value.Get(key);

        std::ostringstream value_check;
        value.Get(value_check);

        std::string expected_get = (key + "=" + IntToString(i));
        expected_get.append(+" (" + g_variable_str + ")");

        if (value_check.str() != expected_get) {
            std::cout << "Wrong value returned for key: " << key
                      << ", value was: " << value_check.str()
                      << ", expected: " << expected_get << std::endl;
        }
    }

    for (size_t i = 1; i < number_of_keys; ++i) {
        std::string key = g_variable_str + "_" + IntToString(i);
        key_value.Delete(key);
    }

    std::chrono::time_point<std::chrono::system_clock> p2;
    p2 = std::chrono::system_clock::now();

    std::cout << "Duration: " <<
              std::chrono::duration_cast<std::chrono::milliseconds>(p2 - p1).count()
              << " milliseconds " << std::endl;
    std::cout << g_variable_str << std::endl;
    return 0;
}
