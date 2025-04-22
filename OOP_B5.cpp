#include <iostream>
#include <cmath>
using namespace std;

class Point
{
public:
    int x, y;
    Point(int x1, int y1) : x(x1), y(y1) {}
};

double doDai(const Point &p1, const Point &p2)
{
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
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
        cout << "A: (" << A.x << ", " << A.y << ")" << endl;
        cout << "B: (" << B.x << ", " << B.y << ")" << endl;
        cout << "C: (" << C.x << ", " << C.y << ")" << endl;
    }

    void set(int x1, int y1, int x2, int y2, int x3, int y3)
    {
        A.x = x1;
        A.y = y1;
        B.x = x2;
        B.y = y2;
        C.x = x3;
        C.y = y3;
    }

    float chuVi()
    {
        return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y)) + sqrt((A.x - C.x) * (A.x - C.x) + (A.y - C.y) * (A.y - C.y)) + sqrt((B.x - C.x) * (B.x - C.x) + (B.y - C.y) * (B.y - C.y));
    }

    float dienTich()
    {
        return 0.5 * abs((A.x - C.x) * (B.y - C.y) - (B.x - C.x) * (A.y - C.y));
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