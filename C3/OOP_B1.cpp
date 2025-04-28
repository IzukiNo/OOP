#include<iostream>
#include<cmath>
using namespace std;

class TamGiac {
protected:
	float canh1, canh2, canh3;
public:
	TamGiac() {
		canh1 = 0;
		canh2 = 0;
		canh3 = 0;
	}

	TamGiac(float a, float b, float c) {
		canh1 = a;
		canh2 = b;
		canh3 = c;
	}

	void setCanh1(float k) {
		canh1 = k;
	}

	float getCanh1() {
		return canh1;
	}

	void setCanh2(float k) {
		canh2 = k;
	}

	float getCanh2() {
		return canh2;
	}

	void setCanh3(float k) {
		canh3 = k;
	}

	float getCanh3() {
		return canh3;
	}

	float ChuVi() {
		return canh1 + canh2 + canh3;
	}

	float DienTich() {
		float p = ChuVi() / 2;
		float s = sqrt(p * (p - canh1) * (p - canh2) * (p - canh3));
		return s;
	}

	~TamGiac(){}
};


class TamGiacDeu :public TamGiac {
public:
	TamGiacDeu(float a) : TamGiac(a, a, a){}

	
};


int main() {
	TamGiac tg(3, 3, 3);
	cout << "Chu vi tam giac thuong: " << tg.ChuVi() << endl;
	cout << "Dien tich tam giac thuong: " << tg.DienTich() << endl;
	
	TamGiacDeu tgd(3);
	cout << "Chu vi tam giac deu: " << tgd.ChuVi() << endl;
	cout << "Dien tich tam giac deu: " << tgd.DienTich() << endl;


	return 0;
}