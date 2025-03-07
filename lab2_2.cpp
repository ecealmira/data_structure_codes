#include <iostream>
#include <cmath>
using namespace std;

// complex number --> z = a+bi

// kompleks say�lar� temsil eden bir s�n�f
class comp{
	// Encapsulation: 
	// Koruma seviyeleri:
	// default olarak class i�inde t�m de�i�kenler private olur
	private: // bu s�n�f�n d���ndakiler art�k bu de�i�kenlere eri�emez
		// Class members(Attribute)
		// bu s�n�fa ait olan de�i�kenleri yaz�yoruz
		float a;
		float b;
	
	// Methods (Functions):
	// yapmak istedi�imiz i�lemler
	
	public: // s�n�f d���ndan eri�im sa�lanabilir.
		// Constructor:
		// bu s�n�ftan bir nesne yarat�lmak istendi�inde ilk olarak bu method �a�r�l�r
		// class ismi ile ayn� isimde olmal�
		// constructor private olanlara eri�ebilir
		comp(); // default constructur --> zorunlu
		comp(float x, float y); // comp i�ine de�er verilirse bu �al���r
		
		// bir �ey almas�na gerek olmad��� i�in void yazd�k
		float real(void); // ger�ek k�sm�n� d�nd�r�r
		float img(void); // imajiner k�sm�n� d�nd�r�r
		float mag(void){ // prototip yerine fonksiyonun tamam� da yaz�labilir
			// returns the magnitude
			return sqrt(a*a + b*b);
		} 
		
	// protected
};

// e�er comp:: yazmazsak expected unqualified id diyor
// ��nk� comp nereden geliyor bilemiyor
// constructor i�inde return de�eri girilemiyor
comp::comp(){
	a = 0;
	b = 0;
	cout << "default constructor worked" << endl;
}

// ayn� isimli birden fazla fonksiyon olmas� overload
comp::comp(float x, float y){
	a = x;
	b = y;
	cout << "another constructor worked" << endl;
}

float comp::real(){
	return a;
}

float comp::img(){
	return b;
}

int main(){
	comp z1;
	comp z2 = comp(3,4);
	// toplama i�lemine yeni �zellik ekleme gibi �zellik artt�rmaya overload deniyor
	// comp z3 = z1 + z2; toplama i�lemi tan�ml� olmad��� i�in hata verir
	
	// a ve b private olduklar�ndan onlara ula�mak i�in real ve img fonksiyonlar� kullan�l�r
	// Dot operator: class i�inde member'lara ula�may� sa�l�yor
	cout << "z1=" << z1.real() << "+" << z1.img() << "i" << endl;
	cout << "z2=" << z2.real() << "+" << z2.img() << "i" << endl;
	
	return 0;
}
