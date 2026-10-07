#pragma once

#include <iostream>

class Marsh
{
public:
    char name1[20];
    char name2[20];
    int number;

    Marsh();

    Marsh(
        const char* name1,
        const char* name2,
        int number
    );

    ~Marsh();

    bool operator >(const Marsh& b);

    Marsh& operator=(const Marsh& b);

    friend std::ostream& operator<<(
        std::ostream& os,
        const Marsh& m
    )
    {
        os << m.name1 << " "
           << m.name2 << " "
           << m.number;

        return os;
    }

    friend std::istream& operator>>(
        std::istream& is,
        Marsh& m
    )
    {
        return is >> m.name1
                  >> m.name2
                  >> m.number;
    }

    static bool compareNumber(
        const Marsh& a,
        const Marsh& b
    );
};
