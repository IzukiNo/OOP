#include <iostream>
#include <cmath>
using namespace std;

class Point {
private:
    int x, y;
public:
    Point(int x = 0, int y = 0) {
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

class Line {
private:
    Point A, B;
public:
    Line(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0) {
        A.set(x1, y1);
        B.set(x2, y2);
    }

    ~Line() {}

    void set(int x1, int y1, int x2, int y2) {
        A.set(x1, y1);
        B.set(x2, y2);
    }

    float tinhDoDai() {
        int dx = B.getX() - A.getX();
        int dy = B.getY() - A.getY();
        return sqrt(dx * dx + dy * dy);
    }

    void print() {
        cout << "Diem A: ";
        A.print();
        cout << ", Diem B: ";
        B.print();
        cout << endl;
    }

    void xuatPhuongTrinh() {
        int x1 = A.getX(), y1 = A.getY();
        int x2 = B.getX(), y2 = B.getY();
        int a = y2 - y1;
        int b = x1 - x2;
        int c = x2 * y1 - x1 * y2;

        cout << "Phuong trinh duong thang: ";
        cout << a << "x ";
        if (b >= 0) cout << "+ " << b << "y ";
        else cout << "- " << -b << "y ";

        if (c >= 0) cout << "+ " << c << " = 0" << endl;
        else cout << "- " << -c << " = 0" << endl;
    }
};

int main() {
    Line l;
    l.set(1, 2, 3, 4);
    l.print();
    cout << "Do dai doan thang: " << l.tinhDoDai() << endl;
    l.xuatPhuongTrinh();

    return 0;
}