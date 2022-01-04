#include <iostream>
#include <algorithm>
#include <string>

// Cambiamos el texto a texto grande o uppercase :)
std::string ConvertirTextoUpper(std::string t)
{
    std::for_each(t.begin(), t.end(), [](char & c) {
        c = ::toupper(c);
    });

    return t;
}

// Cambiamos el texto a texto pequeño o lowercase
std::string ConvertirTextoLower(std::string t)
{
    std::for_each(t.begin(), t.end(), [](char & c) {
        c = ::tolower(c);
    });
}

bool PalabraEsIgual(std::string t, std::string t2)
{
    std::for_each(t.begin(), t.end(), [](char & c) {
        c = ::tolower(c);
    });

    if (t == t2) return true;

    return false;
}