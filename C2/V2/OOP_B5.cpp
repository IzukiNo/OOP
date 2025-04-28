#include <iostream>
#include <cmath>
using namespace std;

class Point
{
private:
    int x, y;

public:
    Point(int x1, int y1) : x(x1), y(y1) {}
    ~Point() {}
    int getX() { return x; }
    int getY() { return y; }
    void set(int x1, int y1)
    {
        x = x1;
        y = y1;
    }
    void print()
    {
        cout << "Point: (" << x << ", " << y << ")" << endl;
    }
};

double doDai(Point &p1, Point &p2)
{
    return sqrt(pow(p1.getX() - p2.getX(), 2) + pow(p1.getY() - p2.getY(), 2));
}

class TamGiac
{
private:
    Point A, B, C;

public:
    TamGiac(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0, int x3 = 0, int y3 = 0) : A(x1, y1), B(x2, y2), C(x3, y3) {}
    ~TamGiac() {}
    void print()
    {
        cout << "Tam giac:" << endl;
        cout << "A: (" << A.getX() << ", " << A.getY() << ")" << endl;
        cout << "B: (" << B.getX() << ", " << B.getY() << ")" << endl;
        cout << "C: (" << C.getX() << ", " << C.getY() << ")" << endl;
    }

    void set(int x1, int y1, int x2, int y2, int x3, int y3)
    {
        A.set(x1, y1);
        B.set(x2, y2);
        C.set(x3, y3);
    }

    float chuVi()
    {
        return sqrt(pow(A.getX() - B.getX(), 2) + pow(A.getY() - B.getY(), 2)) + sqrt(pow(A.getX() - C.getX(), 2) + pow(A.getY() - C.getY(), 2)) + sqrt(pow(B.getX() - C.getX(), 2) + pow(B.getY() - C.getY(), 2));
    }

    float dienTich()
    {
        return 0.5 * abs((A.getX() - C.getX()) * (B.getY() - C.getY()) - (B.getX() - C.getX()) * (A.getY() - C.getY()));
    }

    int phanLoai()
    {
        double a = doDai(B, C);
        double b = doDai(A, C);
        double c = doDai(A, B);

        if (a > c)
            swap(a, c);
        if (b > c)
            swap(b, c);

        if (a + b <= c)
        {
            cout << "Khong phai tam giac! ";
            return -1;
        }

        bool laVuong = (abs(a * a + b * b - c * c) < 1e-9);

        if (a == b && b == c)
        {
            return 4;
        }
        else if (laVuong && a == b)
        {
            return 3;
        }
        else if (laVuong)
        {
            return 1;
        }
        else if (a == b || b == c)
        {
            return 2;
        }
        else
        {
            return 0;
        }
    }
};

int main()
{
    TamGiac A;
    A.set(0, 0, 1, 1, -1, 1);
    A.print();
    cout << "Chu vi: " << A.chuVi() << endl;
    cout << "Dien tich: " << A.dienTich() << endl;
    cout << "Phan loai: " << A.phanLoai() << endl;
    return 0;
}