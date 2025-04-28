#include <iostream>
using namespace std;

class Ngay {
private:
    int d,m, y;
public:
    bool isNhuan () {return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);}

    int ngayTrongThang() {
        if (m==2) return isNhuan() ? 29 : 28;
        if (m == 4 || m == 6 || m == 9 || m == 11) return 30;
        return 31;
    }

    int getDay() {return d;}
    int getMonth() {return m;}
    int getYear() {return y;}

    bool isValid() {
        if (y < 0 || m < 1 || m > 12 || d < 1 || d > ngayTrongThang()) return false;
        return true;
    }

    Ngay(int day=1, int month=1, int year=2000) : d(day), m(month), y(year) {}
    ~Ngay() {}

    friend istream& operator>>(istream& in, Ngay& a) {
        do {
            in >> a.d >> a.m >> a.y;
            if (!a.isValid()) {
            cout << "Ngay khong hop le. Vui long nhap lai." << endl;
            }
        } while (!a.isValid());

        return in;
    }

    friend ostream& operator<<(ostream& out, Ngay a) {
        out << a.d << "/" << a.m << "/" << a.y;
        return out;
    }

    Ngay operator+(int n) {
        Ngay kq = *this;
        kq.d += n;
        while (kq.d > kq.ngayTrongThang()) {
            kq.d -= kq.ngayTrongThang();
            kq.m++;
            if (kq.m > 12) {
                kq.m = 1;
                kq.y++;
            }
        }
        return kq;
    }

    Ngay operator-(int n) {
        Ngay kq = *this;
        kq.d -= n;
        while (kq.d < 1) {
            kq.m--;
            if (kq.m < 1) {
                kq.m = 12;
                kq.y--;
            }
            kq.d += kq.ngayTrongThang();
        }
        return kq;
    }

    Ngay operator++() {
        d++;
        if (d > ngayTrongThang()) {
            d = 1;
            m++;
            if (m > 12) {
                m = 1;
                y++;
            }
        }
        return *this;
    }

    Ngay operator--() {
        d--;
        if (d < 1) {
            m--;
            if (m < 1) {
                m = 12;
                y--;
            }
            d += ngayTrongThang();
        }
        return *this;
    }

    bool operator<(Ngay& b) {
        if (y < b.y) return true;
        if (y == b.y && m < b.m) return true;
        if (y == b.y && m == b.m && d < b.d) return true;
        return false;
    }
    bool operator>(Ngay& b) {
        return b < *this;
    }

    int khoangCach(Ngay& b) {
        Ngay a = *this;
        Ngay c = b;
        int d = 0;
    
        if (a > c) {
            while (a > c) {
            c = c+1;
            d++;
            }
        } else if (a < c) {
            while (c > a) {
            a = a+1;
            d++;
            }
        }
    
        return d;
    }
};

int main() {
    Ngay a, b;
    cout << "Nhap ngay a: ";
    cin >> a;
    cout << "Nhap ngay b: ";
    cin >> b;

    cout << "Ngay a: " << a << endl;
    cout << "Ngay b: " << b << endl;

    if (a < b) {
        cout << "a < b" << endl;
    } else if (a > b) {
        cout << "a > b" << endl;
    } else {
        cout << "a = b" << endl;
    }

    cout << "a + 5 = " << a+5 << endl;

    cout << "b - 10 = " << b-10 << endl;

    cout << "Khoang cach giua " << a << " va " << b << " la: " << a.khoangCach(b) << endl;

    return 0;
}