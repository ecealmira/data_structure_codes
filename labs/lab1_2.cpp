#include <iostream>
using namespace std;

int main()
{
    float a[10]={10, 20, 30, 40, 50};
    
    cout <<"Size of int in this compiler: " <<sizeof(int) <<endl;
    cout <<"Size of float in this compiler: " <<sizeof(float) <<endl;
    cout <<"Size of double in this compiler: " <<sizeof(double) <<endl;
    
    for(int i=0; i<=9; i++)
        cout <<"a[" <<i <<"]=" <<a[i] <<" and address of a[" << i << "]: " << &a[i] <<endl;
    cout <<"Array start is located at " <<&a <<"." <<endl;
    
/*
    Hexadecimal (Base-16) digits: 
    0 1 2 3 ... 9 10 11 12 13 14 15
    0 1 2 3 ... 9 A  B  C  D  E  F
*/
	
    cout <<a[1] <<endl;
    a[1]/=100;
    cout <<a[1] <<endl;
    
    return 0;
};



