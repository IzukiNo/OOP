#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Mang {
private:
    vector<int> data;
public:
    friend istream& operator>>(istream& is, Mang& m) {
        int n, x;
        cout << "Nhap so luong phan tu: ";
        is >> n;
        m.data.clear();
        cout << "Nhap cac phan tu: ";
        for (int i = 0; i < n; ++i) {
            is >> x;
            m.data.push_back(x);
        }
        return is;
    }

    friend ostream& operator<<(ostream& os, const Mang& m) {
        for (int x : m.data) {
            os << x << " ";
        }
        return os;
    }

    int soPhanTu() const {
        return data.size();
    }

    int layGiaTri(int i) const {
        if (i >= 0 && i < data.size()) {
            return data[i];
        }
        else {
            cout << "Chi so khong hop le.\n";
            return -1;
        }
    }

    void themPhanTu(int x) {
        data.push_back(x);
    }

    void xoaPhanTu(int i) {
        if (i >= 0 && i < data.size()) {
            data.erase(data.begin() + i);
        }
        else {
            cout << "Chi so khong hop le.\n";
        }
    }

    void huyMang() {
        data.clear();
    }

    void sapXep() {
        sort(data.begin(), data.end());
    }

    int phanTuNhoNhat() const {
        if (!data.empty()) {
            return *min_element(data.begin(), data.end());
        }
        else {
            cout << "Mang rong.\n";
            return -1;
        }
    }

    int tongPhanTu() const {
        int sum = 0;
        for (int x : data) {
            sum += x;
        }
        return sum;
    }
};

int main() {
    Mang m;
    cin >> m;
    cout << "Mang vua nhap: " << m << endl;

    cout << "So phan tu: " << m.soPhanTu() << endl;
    cout << "Gia tri phan tu thu 2: " << m.layGiaTri(1) << endl;

    m.themPhanTu(100);
    cout << "Mang sau khi them 100: " << m << endl;

    m.xoaPhanTu(0);
    cout << "Mang sau khi xoa phan tu dau tien: " << m << endl;

    m.sapXep();
    cout << "Mang sau khi sap xep: " << m << endl;

    cout << "Phan tu nho nhat: " << m.phanTuNhoNhat() << endl;
    cout << "Tong cac phan tu: " << m.tongPhanTu() << endl;

    m.huyMang();
    cout << "Mang sau khi huy: " << m << endl;

    return 0;
}
