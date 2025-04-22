#include <iostream>
using namespace std;

class Mang
{
private:
    int data[100];
    int size;

public:
    Mang() { size = 0; }
    ~Mang() {}
    friend istream &operator>>(istream &in, Mang &m)
    {
        cout << "Nhap so phan tu: ";
        in >> m.size;
        cout << "Nhap cac phan tu: " << endl;
        for (int i = 0; i < m.size; i++)
        {
            in >> m.data[i];
        }
        return in;
    }
    friend ostream &operator<<(ostream &out, Mang &m)
    {
        out << "Mang: ";
        for (int i = 0; i < m.size; i++)
        {
            out << m.data[i] << " ";
        }
        return out;
    }
    int getSize()
    {
        return size;
    }
    int getData(int i)
    {
        if (i >= 0 && i < size)
            return data[i];
        else
            return -1;
    }
    void addData(int value)
    {
        data[size] = value;
        size++;
    }
    void removeData(int i)
    {
        if (i >= 0 && i < size)
        {
            for (int j = i; j < size - 1; j++)
            {
                data[j] = data[j + 1];
            }
            size--;
        }
    }
    void sortData()
    {
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (data[i] > data[j])
                {
                    int temp = data[i];
                    data[i] = data[j];
                    data[j] = temp;
                }
            }
        }
    }
    int findMin()
    {
        int min = data[0];
        for (int i = 1; i < size; i++)
        {
            if (data[i] < min)
                min = data[i];
        }
        return min;
    }
    int sumAll()
    {
        int sum = 0;
        for (int i = 0; i < size; i++)
        {
            sum += data[i];
        }
        return sum;
    }
};
int main()
{
    Mang m;
    cin >> m;
    cout << m << endl;
    cout << "So phan tu: " << m.getSize() << endl;
    cout << "Phan tu thu 2: " << m.getData(1) << endl;
    m.addData(10);
    m.addData(20);
    cout << "Mang sau khi them 2 phan tu: " << endl
         << m << endl;

    m.removeData(2);
    cout << "Mang sau khi xoa phan tu thu 3: " << endl
         << m << endl;
    m.sortData();
    cout << "Mang sau khi sap xep: " << endl
         << m << endl;
    cout << "Phan tu nho nhat: " << m.findMin() << endl;
    cout << "Tong cac phan tu: " << m.sumAll() << endl;
    return 0;
}