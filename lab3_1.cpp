#include <iostream>
#include <cmath>
using namespace std;

// Complex Numbers z=x+yi

class ComplexNumber
{ // Class members:
  // private by default; "encapsulation"
  // Attributes:
    float x;
    float y;
  public:
  // Methods:
    ComplexNumber();  // default constructor
    ComplexNumber(float a, float b);  // another constructor
    float real(void);
    float imag(void);
    float magnitude(void);
};

ComplexNumber::ComplexNumber()
{
    x=0;
    y=0;
    //cout <<"Default constructor" <<endl;
};

ComplexNumber::ComplexNumber(float a, float b)
{
    x=a;
    y=b;
    //cout <<"The other constructor" <<endl;
};

float ComplexNumber::real(void)
{
    return x;
};

float ComplexNumber::imag(void)
{
    return y;
};

float ComplexNumber::magnitude(void)
{
    return sqrt(x*x+y*y);
};

// + iþleminin nasýl çalýþtýðýný tanýmlýyor
// ayrý özellik ekliyoruz
// z1 ve z2 compleks göndermesi zor diye adresi verilir
ComplexNumber operator+(ComplexNumber &cn1, ComplexNumber &cn2)
{
	float real_sum = cn1.real() + cn2.real();
	float img_sum = cn1.imag() + cn2.imag();
	return ComplexNumber(real_sum, img_sum);
};

// return tipi ostream --> output stream
// ostream &s --> ekrana gönderir
ostream & operator<<(ostream &s, ComplexNumber &cn){
	// cout yerine s yazarak s'ye yollarýz
	s << cn.real();
	if(cn.imag() > 0)
	{
		// pozitif ise + koy
		s << "+";
	} 
	// deðilse kendisi - koyar
	s << cn.imag();
	s << "i";
	return s;
};

int main()
{
	ComplexNumber z1=ComplexNumber(2,-16);
    ComplexNumber z2=ComplexNumber(3,4);
	 
	ComplexNumber z3;
	// overload edilerek z toplama özelliði eklendi
	z3 = z1 + z2;
	
	// overload edilerek z yazdýrma özelliði eklendi
	cout << "z2= "<< z2 << endl;
	
	cout <<"z3= "<<z3.real()<<z3.imag() <<"i" <<endl;
	cout << "z3= "<< z3 << endl; 
    
    cout <<endl; // enter
    return 0;
};
