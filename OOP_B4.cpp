#include <iostream>
#include <cmath>
using namespace std;

class Point
{
public:
    int x, y;
    Point(int x1, int y1) : x(x1), y(y1) {}
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
        A.x = x1;
        A.y = y1;
        B.x = x2;
        B.y = y2;
    }

    float tinhDoDai()
    {
        return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
    }

    void print()
    {
        cout << "Line:" << endl;
        cout << "A: (" << A.x << ", " << A.y << ")" << endl;
        cout << "B: (" << B.x << ", " << B.y << ")" << endl;
    }

    void xuatPhuongTrinh()
    {
        cout << "Phuong trinh cua duong thang la: ";
        cout << "y = " << (B.y - A.y) / (B.x - A.x) << "x + " << A.y - (B.y - A.y) / (B.x - A.x) * A.x << endl;
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