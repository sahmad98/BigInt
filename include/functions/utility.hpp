/*
    ===========================================================================
    Utility functions
    ===========================================================================
*/

#ifndef BIG_INT_UTILITY_FUNCTIONS_HPP
#define BIG_INT_UTILITY_FUNCTIONS_HPP

#include <tuple>
#include <vector>


/*
    is_valid_number
    ---------------
    Checks whether the given string is a valid integer.
*/

bool is_valid_number(const std::string& num) {
    for (char digit : num)
        if (digit < '0' or digit > '9')
            return false;

    return true;
}


/*
    strip_leading_zeroes
    --------------------
    Strip the leading zeroes from a number represented as a string.
*/

void strip_leading_zeroes(std::string& num) {
    size_t i;
    for (i = 0; i < num.size(); i++)
        if (num[i] != '0')
            break;

    if (i == num.size())
        num = "0";
    else
        num = num.substr(i);
}


/*
    add_leading_zeroes
    ------------------
    Adds a given number of leading zeroes to a string-represented integer `num`.
*/

void add_leading_zeroes(std::string& num, size_t num_zeroes) {
    num = std::string(num_zeroes, '0') + num;
}


/*
    add_trailing_zeroes
    -------------------
    Adds a given number of trailing zeroes to a string-represented integer `num`.
*/

void add_trailing_zeroes(std::string& num, size_t num_zeroes) {
    num += std::string(num_zeroes, '0');
}


/*
    get_larger_and_smaller
    ----------------------
    Identifies the given string-represented integers as `larger` and `smaller`,
    padding the smaller number with leading zeroes to make it equal in length to
    the larger number.
*/

std::tuple<std::string, std::string> get_larger_and_smaller(const std::string& num1,
        const std::string& num2) {
    std::string larger, smaller;
    if (num1.size() > num2.size() or
        (num1.size() == num2.size() and num1 > num2)) {
        larger = num1;
        smaller = num2;
    }
    else {
        larger = num2;
        smaller = num1;
    }

    // pad the smaller number with zeroes
    add_leading_zeroes(smaller, larger.size() - smaller.size());

    return std::make_tuple(larger, smaller);
}


/*
    is_power_of_10
    ----------------------
    Checks whether a string-represented integer is a power of 10.
*/

bool is_power_of_10(const std::string& num){
    if (num[0] != '1')
        return false;
    for (size_t i = 1; i < num.size(); i++)
        if (num[i] != '0')
            return false;

    return true;    // first digit is 1 and the following digits are all 0
}

/*
    convert_to_base_64
    ----------------------
    Converts a unsigned string-represented integer into a base 64 vector of
    magnitude
*/

std::vector<unsigned long long> convert_to_base_64(std::string& num) {
    std::vector<unsigned long long> magnitude;
    auto start_index = num.size() - 1;  // From backward direction
    auto stop_index = num.size();
    uint64_t component = 0;
    while(start_index != -1) {
        try {
            std::string num_slice = num.substr(start_index, stop_index);
            component = std::stoull(num_slice);
        } catch (std::out_of_range& e) {
            magnitude.push_back(component);
            stop_index = start_index + 1;
        }
        --start_index;
    }
    magnitude.push_back(component);
    return magnitude;
}

#endif  // BIG_INT_UTILITY_FUNCTIONS_HPP
