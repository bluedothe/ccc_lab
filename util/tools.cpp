#include<iostream>
//using namespace std;

template<class T>

int arrayLength(T& arr)
{
    //std::cout << sizeof(arr[0]) << std::endl;
    //std::cout << sizeof(arr) << std::endl;
    return sizeof(arr) / sizeof(arr[0]);
}

//对于字符串数组，可以用 strlen() 函数来获取字符串数组的长度。
int main_()
{
    int arr[] = { 1,5,9,10,9,2 };
    // 方法一
    std::cout << "array length:" << arrayLength(arr) << std::endl;
    // 方法二
    //std::cout << end(arr) << std::endl;
    //std::cout << begin(arr) << std::endl;
    std::cout << "array length:" << std::end(arr)-std::begin(arr) << std::endl;
    //system("pause");
    return 0;
}