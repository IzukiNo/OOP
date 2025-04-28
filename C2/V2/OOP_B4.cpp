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

class Line
{
private:
    Point A, B;

public:
    Line(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0) : A(x1, y1), B(x2, y2) {}
    ~Line() {}
    void set(int x1, int y1, int x2, int y2)
    {
        A.set(x1, y1);
        B.set(x2, y2);
    }

    float tinhDoDai()
    {
        return sqrt((A.getX() - B.getX()) * (A.getX() - B.getX()) + (A.getY() - B.getY()) * (A.getY() - B.getY()));
    }

    void print()
    {
        cout << "Line:" << endl;
        cout << "A: (" << A.getX() << ", " << A.getY() << ")" << endl;
        cout << "B: (" << B.getX() << ", " << B.getY() << ")" << endl;
    }

    void xuatPhuongTrinh()
    {
        cout << "Phuong trinh cua duong thang la: ";
        cout << "y = " << (B.getY() - A.getY()) / (B.getX() - A.getX()) << "x + " << A.getY() - (B.getY() - A.getY()) / (B.getX() - A.getX()) * A.getX() << endl;
    }
};

int main()
{
    Line A;
    A.set(1, 2, 3, 4);
    A.print();
    cout << "Do dai: " << A.tinhDoDai() << endl;
    A.xuatPhuongTrinh();
    return 0;
}