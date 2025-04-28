#include <iostream>
#include <cmath>
using namespace std;

class Point2D {
private:
    int x, y;
public:
    Point2D(int x = 0, int y = 0) {
        this->x = x;
        this->y = y;
    }
    void set(int x, int y) {
        this->x = x;
        this->y = y;
    }
    int getX() { return x; }
    int getY() { return y; }
    void print() {
        cout << "(" << x << ", " << y << ")";
    }
};

class TamGiac {
private:
    Point2D A, B, C;
public:
    TamGiac(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0, int x3 = 0, int y3 = 0) {
        A.set(x1, y1);
        B.set(x2, y2);
        C.set(x3, y3);
    }

    ~TamGiac() {}

    void set(int x1, int y1, int x2, int y2, int x3, int y3) {
        A.set(x1, y1);
        B.set(x2, y2);
        C.set(x3, y3);
    }

    float doDai(Point2D p1, Point2D p2) {
        int dx = p1.getX() - p2.getX();
        int dy = p1.getY() - p2.getY();
        return sqrt(dx * dx + dy * dy);
    }

    float tinhChuVi() {
        float ab = doDai(A, B);
        float bc = doDai(B, C);
        float ca = doDai(C, A);
        return ab + bc + ca;
    }

    float tinhDienTich() {
        float ab = doDai(A, B);
        float bc = doDai(B, C);
        float ca = doDai(C, A);
        float p = (ab + bc + ca) / 2;
        return sqrt(p * (p - ab) * (p - bc) * (p - ca));
    }

    void print() {
        cout << "Dinh A: ";
        A.print();
        cout << ", Dinh B: ";
        B.print();
        cout << ", Dinh C: ";
        C.print();
        cout << endl;
    }

    int phanLoai() {
        float ab = doDai(A, B);
        float bc = doDai(B, C);
        float ca = doDai(C, A);

        float ab2 = ab * ab;
        float bc2 = bc * bc;
        float ca2 = ca * ca;

        bool vuong = (fabs(ab2 + bc2 - ca2) < 1e-6) ||
                     (fabs(ab2 + ca2 - bc2) < 1e-6) ||
                     (fabs(bc2 + ca2 - ab2) < 1e-6);
        bool can = (fabs(ab - bc) < 1e-6) ||
                   (fabs(ab - ca) < 1e-6) ||
                   (fabs(bc - ca) < 1e-6);
        bool deu = (fabs(ab - bc) < 1e-6) && (fabs(bc - ca) < 1e-6);

        if (deu) return 4;
        else if (vuong && can) return 3;
        else if (vuong) return 1;
        else if (can) return 2;
        else return 0;
    }
};

int main() {
    TamGiac tg;
    tg.set(0, 0, 3, 0, 0, 4);

    tg.print();
    cout << "Chu vi tam giac: " << tg.tinhChuVi() << endl;
    cout << "Dien tich tam giac: " << tg.tinhDienTich() << endl;

    int loai = tg.phanLoai();
    cout << "Loai tam giac: ";
    switch (loai) {
        case 0: cout << "Tam giac thuong"; break;
        case 1: cout << "Tam giac vuong"; break;
        case 2: cout << "Tam giac can"; break;
        case 3: cout << "Tam giac vuong can"; break;
        case 4: cout << "Tam giac deu"; break;
    }
    cout << endl;

    return 0;
}