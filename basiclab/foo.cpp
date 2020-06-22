#include <string>
#include <iostream>
#include <cmath>

int main()
{   int a = 7;
    int b = 8;
    double c = round(a/b * 100) / 100.0;
    double d = float(a/b*100+0.5)/100;
    std::cout << "main a/b: " << a/b << std::endl;
    std::cout << "main d: " << d << std::endl;
}