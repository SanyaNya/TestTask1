#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <cassert>
#include <unordered_map>

inline std::string convert_str(std::string s)
{
    //To lower s chars
    std::transform(
        s.begin(), s.end(), s.begin(), 
        [](unsigned char c){ return std::tolower(c); });

    //Count chars
    std::unordered_map<char, unsigned> counts;
    for(char c : s) counts[c]++;

    //Replace chars
    for(char& c : s)
    {
        if(counts[c] == 1) c = '(';
        else c = ')';
    }

    return s;
}

int main()
{
    assert(convert_str("din")     == "(((");
    assert(convert_str("recede")  == "()()()");
    assert(convert_str("Success") == ")())())");
    assert(convert_str("(( @")    == "))((");

    assert(convert_str("") == "");
    assert(convert_str("aAAA") == "))))");
    assert(convert_str("X") == "(");
    assert(convert_str(" \t\n") == "(((");
    assert(
        convert_str("qQwWeErRtTyYuUiIoOpPaAsSdDfFgGhHjJkKlLzZxXcCvVbBnNmM[{]};:'\",<.>/?\\|`~1!2@3#4$5%6^7&8*9(0)-_=+") ==
        "))))))))))))))))))))))))))))))))))))))))))))))))))))((((((((((((((((((((((((((((((((((((((((((");

    std::cout << "All tests passed\n";
}
