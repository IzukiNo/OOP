#include <iostream>
#include <stack>
using namespace std;

class Stack {
private:
	stack<int> st;
public:
	Stack() {}
	
	Stack(int value) {
		st.top() = value;
	}

	friend istream& operator>>(istream& in, Stack& a) {
		
		int x; 
		while (in >> x) {
			if (x == -1) {
				break;
			}
			a.st.push(x);
			
		}
		return in;


	}

	friend ostream& operator<<(ostream& out, Stack a) {
		stack<int> temp;
		temp = a.st;
		cout << "Ngan xep dang co: ";
		while (!temp.empty()) {
			out << temp.top() << " ";
			temp.pop();
		}
		return out;
	}

	int Size() {
		int dem = 0;
		stack<int> temp = st;
		while (!temp.empty()) {
			temp.pop();
			dem++;
		}
		 return dem;
	}

	void add() {
		cout << "Ban muon them gia tri nao: ";
		int x; cin >> x;
		st.push(x);
		stack<int> temp = st;
		cout << "Ngan xep dang co: ";
		while (!temp.empty())
		{
			cout << temp.top()<< " ";
			temp.pop();
		}
	}

	void take() {
		cout << "Ban co muon lay phan tu top ?" << endl;
		char ch; cin >> ch;
		
		if (ch == 'y') {
			
			st.pop();
			stack<int> temp = st;
			cout << "Ngan xep dang co: ";
			while (!temp.empty())
			{
				cout << temp.top() << " ";
				temp.pop();
			}
		}
		else {

			stack<int> temp = st;
			cout << "Ngan xep dang co: ";
			while (!temp.empty())
			{
				cout << temp.top() << " ";
				temp.pop();
			}
		}
		
	
	}
		

	void xoa() {
		cout << "Ban co muon xoa ngan xep khong ?" << endl;
		char ch;
		cin >> ch;
		stack<int> temp = st;
		if (ch == 'y') {
			while (!temp.empty()) {
				temp.pop();
			}

			cout << "Ngan xep rong" << endl;
		}
		else if (ch == 'n') {
			return;
		}
	}
};





int main() {
	Stack s;
	cout << "Nhap ngan xep (nhap -1 de ket thuc)" << endl;
	cin >> s;
	cout << s;
	cout << endl;
	cout << "Ngan xep co: ";
	cout << s.Size()<<" phan tu";

	cout << endl;
	s.take();
	cout << endl;
	s.add();
	cout << endl;
	s.xoa();

	return 0;
}