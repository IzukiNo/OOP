#include <iostream>
#include <string>
using namespace std;

class MANG1C {
    private:
    int sopt;
    int data[100];
    public:
    MANG1C() {sopt = -1;}
    ~MANG1C() {}
    int& getSopt() {return sopt;}
    int& getData(int i) {return data[i];}
    void input(){
        cout << "Nhap so phan tu: ";
        cin >> sopt;
        for (int i = 0; i < sopt; i++) {
            cin >> data[i];
        }
    }
    void print(){
        for (int i = 0; i < sopt; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

class STACK : public MANG1C {
    public:
    STACK() {cout<<"Khoi tao STACK"<<endl;}
    ~STACK() {cout<<"Huy STACK"<<endl;}

    int isEmpty() {
        if (getSopt() == -1) return 1;
        else return 0;
    }

    void push(int n){
        if (isEmpty()) {
            getData(0) = n;
            getSopt()= 1;
        } else if (getSopt() < 100) {
            getData(getSopt()) = n;
            getSopt()++;
        } else {
            cout << "Stack day!" << endl;
        }
    }

    int pop(){
        if (isEmpty()) {
            cout << "Stack rong!" << endl;
            return -1;
        } else {
            getSopt()--;
            if (getSopt() == -1) {return getData(0);} else return getData(getSopt());
        }
    }
};

class BINARY : public STACK {
    public:
    BINARY() {cout<<"Khoi tao BINARY"<<endl;}
    ~BINARY() {cout<<"Huy BINARY"<<endl;}

    string doiNhiPhan(int n) {
        string result = "";
        if (n == 0) return "0";
        while (n > 0) {
            result = to_string(n % 2) + result;
            n /= 2;
        }
        return result;
    }
};

int main(){
    BINARY b;
    int n;
    b.input();
    b.print();

    b.push(5);
    b.print();
    
    cout << "So nhi phan: " << b.doiNhiPhan(b.pop()) << endl;
    return 0;
}