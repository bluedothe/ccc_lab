#include <iostream>
using namespace std;
//https://www.jianshu.com/p/fe3559eee136
class Demo{
public:
    /*
     Demo(){
        cout << "A Demo..." << endl; 
    } */
    Demo(char* str)
    {
        name = str;
        cout << this->name << " come out"  << endl; 
    }
private:
    string name;
};

int main(){
    //Demo objs[10]; // error;
    /*
    Demo *objs = new Demo[10];  // error;
    */
    Demo **objs = new Demo *[10];
    for (int i = 0; i < 10; i++)
    {
        objs[i] = new Demo("object");
    }
    
   delete [] objs;
   
    int lenth = 3;
    int **a = new int* [lenth];
    for(int i = 0; i < lenth; ++i)
    a[i] = new int [lenth];

    for(int i = 0; i < lenth; ++i)
    delete []a[i];
    delete []a;
}