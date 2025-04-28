#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class DaThuc {
private:
    int bac;    
    vector<double> heSo; 
public:
    DaThuc() {
        bac = 0;
        heSo.push_back(0);
    }

    ~DaThuc() {}

    void input() {
        cout << "Nhap bac cao nhat cua da thuc: ";
        cin >> bac;
        heSo.resize(bac + 1);
        cout << "Nhap cac he so:\n";
        for (int i = 0; i <= bac; ++i) {
            cout << "He so bac " << i << ": ";
            cin >> heSo[i];
        }
    }

    void print() const {
        for (int i = bac; i >= 0; --i) {
            if (heSo[i] != 0) {
                if (i != bac && heSo[i] > 0) cout << "+ ";
                cout << heSo[i];
                if (i > 0) cout << "x^" << i;
                cout << " ";
            }
        }
        cout << endl;
    }

    double tinhGiaTri(double x) const {
        double tong = 0;
        for (int i = 0; i <= bac; ++i) {
            tong += heSo[i] * pow(x, i);
        }
        return tong;
    }

    DaThuc daoHam() const {
        DaThuc kq;
        if (bac == 0) {
            kq.bac = 0;
            kq.heSo.push_back(0);
        } else {
            kq.bac = bac - 1;
            kq.heSo.resize(kq.bac + 1);
            for (int i = 1; i <= bac; ++i) {
                kq.heSo[i-1] = heSo[i] * i;
            }
        }
        return kq;
    }

    DaThuc tichPhan() const {
        DaThuc kq;
        kq.bac = bac + 1;
        kq.heSo.resize(kq.bac + 1);
        kq.heSo[0] = 0; 
        for (int i = 0; i <= bac; ++i) {
            kq.heSo[i+1] = heSo[i] / (i+1);
        }
        return kq;
    }

    DaThuc operator+(const DaThuc& other) const {
        DaThuc kq;
        kq.bac = max(bac, other.bac);
        kq.heSo.resize(kq.bac + 1, 0);
        for (int i = 0; i <= bac; ++i) kq.heSo[i] += heSo[i];
        for (int i = 0; i <= other.bac; ++i) kq.heSo[i] += other.heSo[i];
        return kq;
    }

    DaThuc operator-(const DaThuc& other) const {
        DaThuc kq;
        kq.bac = max(bac, other.bac);
        kq.heSo.resize(kq.bac + 1, 0);
        for (int i = 0; i <= bac; ++i) kq.heSo[i] += heSo[i];
        for (int i = 0; i <= other.bac; ++i) kq.heSo[i] -= other.heSo[i];
        return kq;
    }

    DaThuc operator*(const DaThuc& other) const {
        DaThuc kq;
        kq.bac = bac + other.bac;
        kq.heSo.resize(kq.bac + 1, 0);
        for (int i = 0; i <= bac; ++i) {
            for (int j = 0; j <= other.bac; ++j) {
                kq.heSo[i+j] += heSo[i] * other.heSo[j];
            }
        }
        return kq;
    }

    double& operator[](int k) {
        return heSo[k];
    }

    DaThuc& operator++() {
        for (int i = 0; i <= bac; ++i) {
            heSo[i]++;
        }
        return *this;
    }
    DaThuc& operator--() {
        for (int i = 0; i <= bac; ++i) {
            heSo[i]--;
        }
        return *this;
    }
};

int main() {
    DaThuc A, B;
    cout << "Nhap da thuc A:\n";
    A.input();
    cout << "Nhap da thuc B:\n";
    B.input();

    cout << "\nDa thuc A: "; A.print();
    cout << "Da thuc B: "; B.print();

    DaThuc Tong = A + B;
    DaThuc Hieu = A - B;
    DaThuc Tich = A * B;

    cout << "\nTong A + B: "; Tong.print();
    cout << "Hieu A - B: "; Hieu.print();
    cout << "Tich A * B: "; Tich.print();

    cout << "\nDao ham cua A: "; A.daoHam().print();
    cout << "Tich phan cua A: "; A.tichPhan().print();

    double x;
    cout << "\nNhap x de tinh gia tri A(x): ";
    cin >> x;
    cout << "Gia tri A(" << x << ") = " << A.tinhGiaTri(x) << endl;

    cout << "\nTang tat ca he so cua A len 1: ";
    ++A;
    A.print();

    cout << "\nGiam tat ca he so cua B xuong 1: ";
    --B;
    B.print();

    return 0;
}