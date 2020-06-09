#include <iostream>
using namespace std;
int main()
{
    unsigned int a = 5, b = 9; 
  
    cout << "a is: " << a << " b is: " << b << endl;

    int temp = a & b;
    cout << "a&b is: " << temp << endl;

    temp = a|b;
    cout << "a|b is: " << temp << endl;

    temp = ~a;
    cout << "~a is: " << temp << endl;

    temp = a^b;
    cout << "a^b is: " << temp << endl;

    temp = a >> 1;
    cout << "a>>1 is: " << temp << endl;

    temp = a << 1;
    cout << "a<<1 is: " << temp << endl;
    
    return 0; 
}