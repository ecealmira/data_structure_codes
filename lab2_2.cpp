#include <iostream>
#include <cmath>
using namespace std;

// complex number --> z = a+bi

// kompleks sayýlarý temsil eden bir sýnýf
class comp{
	// Encapsulation: 
	// Koruma seviyeleri:
	// default olarak class içinde tüm deðiþkenler private olur
	private: // bu sýnýfýn dýþýndakiler artýk bu deðiþkenlere eriþemez
		// Class members(Attribute)
		// bu sýnýfa ait olan deðiþkenleri yazýyoruz
		float a;
		float b;
	
	// Methods (Functions):
	// yapmak istediðimiz iþlemler
	
	public: // sýnýf dýþýndan eriþim saðlanabilir.
		// Constructor:
		// bu sýnýftan bir nesne yaratýlmak istendiðinde ilk olarak bu method çaðrýlýr
		// class ismi ile ayný isimde olmalý
		// constructor private olanlara eriþebilir
		comp(); // default constructur --> zorunlu
		comp(float x, float y); // comp içine deðer verilirse bu çalýþýr
		
		// bir þey almasýna gerek olmadýðý için void yazdýk
		float real(void); // gerçek kýsmýný döndürür
		float img(void); // imajiner kýsmýný döndürür
		float mag(void){ // prototip yerine fonksiyonun tamamý da yazýlabilir
			// returns the magnitude
			return sqrt(a*a + b*b);
		} 
		
	// protected
};

// eðer comp:: yazmazsak expected unqualified id diyor
// çünkü comp nereden geliyor bilemiyor
// constructor içinde return deðeri girilemiyor
comp::comp(){
	a = 0;
	b = 0;
	cout << "default constructor worked" << endl;
}

// ayný isimli birden fazla fonksiyon olmasý overload
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
	// toplama iþlemine yeni özellik ekleme gibi özellik arttýrmaya overload deniyor
	// comp z3 = z1 + z2; toplama iþlemi tanýmlý olmadýðý için hata verir
	
	// a ve b private olduklarýndan onlara ulaþmak için real ve img fonksiyonlarý kullanýlýr
	// Dot operator: class içinde member'lara ulaþmayý saðlýyor
	cout << "z1=" << z1.real() << "+" << z1.img() << "i" << endl;
	cout << "z2=" << z2.real() << "+" << z2.img() << "i" << endl;
	
	return 0;
}
