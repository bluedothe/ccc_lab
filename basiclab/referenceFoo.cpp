#include <iostream>

void swap(int& x, int& y)
{
   int temp;
   temp = x; 
   x = y;
   y = temp; 
  
   return;
}

int main ()
{
   int a = 100;
   int b = 200;
 
   printf("before swap, aa: %d\n", a);
   printf("before swap, bb: %d\n", b);
 
   swap(a, b);
 
   printf("after swap, aa: %d\n", a);
   printf("after swap, bb: %d\n", b);
 
   return 0;
}

