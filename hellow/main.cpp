#include <iostream>
//#include <stdio.h>
//using namespace std;
#include "Hellow.cpp"
#include "../basiclab/arrayFoo.cpp"

int main()
{
    std::cout << "=======begin execute main function========" << std::endl;
    printf("my name is %s\n","Tony");
    //Hellow hellow;
    //hellow.printInfo();
    arrayTest1();
    int arr[] = {1,2,3}; 
    printf("main first:%d\n",arr[0]);
    return 0;
} 