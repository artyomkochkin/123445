#define _CRT_SECURE_NO_WARNINGS

#include "Marsh.h"
#include <cstring>

Marsh::Marsh()
{
    name1[0] = '\0';
    name2[0] = '\0';

    number = 0;
}

Marsh::Marsh(
    const char* name1,
    const char* name2,
    int number
)
{
    strcpy(this->name1, name1);
    strcpy(this->name2, name2);

    this->number = number;
}

Marsh::~Marsh()
{
}

bool Marsh::operator >(const Marsh& b)
{
    return number > b.number;
}

Marsh& Marsh::operator=(const Marsh& b)
{
    if (this != &b)
    {
        strcpy(name1, b.name1);
        strcpy(name2, b.name2);

        number = b.number;
    }

    return *this;
}

bool Marsh::compareNumber(
    const Marsh& a,
    const Marsh& b
)
{
    return a.number < b.number;
}
