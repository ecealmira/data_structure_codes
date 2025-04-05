#include <iostream>
#include <cmath>
using namespace std;

// Complex Numbers z=x+yi

class ComplexNumber
{ 
    float x;
    float y;
  public:
    ComplexNumber(); 
    ComplexNumber(float a, float b);
    float real(void);
    float imag(void);
    float magnitude(void);
};

ComplexNumber::ComplexNumber(){};

ComplexNumber::ComplexNumber(float a, float b)
{
    x=a;
    y=b;
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

ComplexNumber operator+(ComplexNumber &cn1, ComplexNumber &cn2)
{
	float real_sum = cn1.real() + cn2.real();
	float img_sum = cn1.imag() + cn2.imag();
	return ComplexNumber(real_sum, img_sum);
};

ComplexNumber operator-(ComplexNumber &cn1, ComplexNumber &cn2)
{
	// gerçek ve sanal kýsýmlarý ayrý ayrý çýkartýlýr
	float real = cn1.real() - cn2.real();
	float imag = cn1.imag() - cn2.imag();
	return ComplexNumber(real, imag);
};

ComplexNumber operator*(ComplexNumber &cn1, ComplexNumber &cn2)
{
	// Find values of products
    float real_product = cn1.real() * cn2.real();
    float imag_product = cn1.imag() * cn2.imag();
    float prod = (cn1.real() + cn1.imag()) * (cn2.real() + cn2.imag());
 
    // Real Part
    float real = real_product - imag_product;
 
    // Imaginary Part
    float imag = prod - (real_product + imag_product);
 
    return ComplexNumber(real, imag);
};

ComplexNumber operator/(ComplexNumber &cn1, ComplexNumber &cn2)
{
	float x = cn1.real();
	float y = cn1.imag();
	float a = cn2.real();
	float b = cn2.imag();
	
	if(a==0 && b==0)
	{
		cout << "Error: Division by zero" << endl;
        return ComplexNumber(0, 0);
	}
	
	float denominator = a * a + b * b;
	float real_part = (a*x + b*y) / denominator;
	float imag_part = (a*y - b*x) / denominator;
 
    return ComplexNumber(real_part, imag_part);
};

ostream & operator<<(ostream &s, ComplexNumber &cn){
	s << cn.real();
	if(cn.imag() > 0)
	{
		s << "+";
	} 
	s << cn.imag();
	s << "i";
	return s;
};

int main()
{
	ComplexNumber z1=ComplexNumber(2,-16);
    ComplexNumber z2=ComplexNumber(3,4);
	ComplexNumber z3;
	
	// << için overload
	cout << "z2= "<< z2 << endl;
	cout <<"z2= "<<z2.real()<< "+" <<z2.imag() <<"i" <<endl; 
	
	// toplama overload
	z3 = z1 + z2;
	cout << " + overload result " << z3 << endl;
	
	// çýkarma için overload
	z3 = z1 - z2;
	cout << " - overload result = "<< z3 << endl;
	
	// çarpma için overload
	z3 = z1 * z2;
	cout << " * overload result = "<< z3 << endl;
    
    // bölme için overload
    z3 = z1 / z2;
    cout << " / overload result = "<< z3 << endl;
    
    cout <<endl; // enter
    return 0;
};
