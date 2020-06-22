#include <iostream>
#include "arrayFoo.hpp"
#include "../util/tools.cpp"

int arraySum(int arr[])
{
    int len = arrayLength(arr);
    //int len = sizeof(arr) / sizeof(arr[0]);
    printf("arr len: %d\n",len);
    int sums = 0;
    for (int i=0; i < len; i++)
    {
        sums += arr[i];
    }
    return sums;
}

void arrayTest1()
{
    
    int arr[5];
    arr[0] = 21;
    arr[1] = 22;
    arr[2] = 23;
    arr[3] = 24;
    arr[4] = 25; 
    /**/
    int arr2[] = {1,2,3};
    printf("first arr:%d\n",arr[2]);
    int* p = arr2;
    printf("second arr:%d\n",p[2]); //get third element
    printf("p addr:%d\n", p);
    printf("p addr:%d\n", p + 1);
    printf("p* element:%d\n", *p);//get first element
    printf("arr addr:%d\n", arr2);
    printf("arr addr:%d\n", arr2 + 1);
    printf("arr length:%d\n", arrayLength(arr));
    printf("in arraytest1!\n");
    printf("arr sum:%d\n", arraySum(arr));
}

void arrayTest2()
{
    int *parr = new int[10];  //for debug parr array data,can add watch expression: *(int(*)[10])(parr)
    for (int i = 0; i < 10; i++)
    {
        parr[i] = i * 10;
    }

    printf("parr value: %d\n", parr[2]);
    printf("parr value: %d\n", *(parr+3));
}

int main()
{
    arrayTest2();
}