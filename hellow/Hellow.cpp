#include <iostream>
#include <string>
#include "Hellow.hpp"

Hellow::Hellow():age{20}
{
    printf("in constuct,init: %d\n",age);
}

void Hellow::printInfo()
{
    printf("in printInfo, %d\n", 5);
}