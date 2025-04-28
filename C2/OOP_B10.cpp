#include <iostream>
#include <cmath>
using namespace std;

const float can7 = sqrt(7);


class BieuThuc {    // a + b*can7
private:
	int a;
	int b;
public:
	BieuThuc() {
		a = 0;
		b = 0;
	}

	BieuThuc(int x, int y) {
		a = x;
		b = y;
	}

	void setA(int k) {
		a = k;
	}

	int getA() {
		return a;
	}

	void setB(int k) {
		b = k;
	}

	int getB() {
		return b;
	}

	friend istream& operator>>(istream& in, BieuThuc& f) {
		in >> f.a >> f.b;
		return in;
	}

	friend ostream& operator<<(ostream& out, BieuThuc f) {
		if (f.b < 0) {
			f.b = -f.b;
			out << f.a <<" - "<< f.b << "*can7";
		}
		else {
			out << f.a << " + " << f.b << "*can7";
		}
		
		return out;
	}

	friend BieuThuc operator+(BieuThuc& f, BieuThuc& g) {
		int a_moi = f.a + g.a;
		int b_moi = f.b + g.b;
		BieuThuc kq(a_moi, b_moi);
		return kq;
	}

	friend BieuThuc operator-(BieuThuc& f, BieuThuc& g) {
		int a_moi = f.a - g.a;
		int b_moi = f.b - g.b;
		BieuThuc kq(a_moi, b_moi);
		return kq;
	}

	friend BieuThuc operator*(BieuThuc& f, BieuThuc& g) {
		int a_moi = f.a * g.a + 7*f.b*g.b;
		int b_moi = f.a * g.b + f.b*g.a;
		BieuThuc kq(a_moi, b_moi);
		return kq;
	}

	void doi() {
		a = -a;
		b = -b;
	}

	~BieuThuc(){}


};






int main() {
	BieuThuc a,b;
	cin >> a>>b;
	
	BieuThuc tong = a - b;
	cout << tong;
	


	return 0;
}