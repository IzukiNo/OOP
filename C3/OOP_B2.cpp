#include<iostream>
using namespace std;

class Animal {
protected:
	int age;
	float weight;
	int sex;     // 0: male, 1: female
public:
	Animal(){}

	Animal(int a, float w, int s) {
		age = a;
		weight = w;
		sex = s;
	}

	void setAge(int k) {
		age = k;
	}

	int getAge() {
		return age;
	}

	void setWeight(float k) {
		weight = k;
	}

	int getWeight() {
		return weight;
	}

	void setSex(int k) {
		sex = k;
	}

	int getSex() {
		return sex;
	}

	void an() {
		cout << "Con vat dang an"<<endl;
	}

	void Print() {
		if (sex == 0) {
			cout << "Toi la Animal" << endl;
			cout << "Tuoi: " << age << endl;
			cout << "Can nang: " << weight << endl;
			cout << "Gioi tinh: Nam" << endl;
		}
		else {
			cout << "Toi la Animal" << endl;
			cout << "Tuoi: " << age << endl;
			cout << "Can nang: " << weight << endl;
			cout << "Gioi tinh: Nu" << endl;
		}
		
	}


	~Animal(){}

};


class Elephant :public Animal {
private:
	int root;  // 0: Asia, 1: Africa
public:
	Elephant(){}

	Elephant(int a,float b,int c,int d) : Animal(a,b,c){
		root = d;
	
	}

	void an() {
		cout << "Voi dang an co"<<endl;
	}

	void Print() {
		if (root == 0) {
			cout << "Voi Chau A"<<endl;
			cout << "Tuoi: " << age << endl;
			cout << "Can nang: " << weight << endl;
			if (sex == 0) {
				cout << "Gioi tinh: Nam" << endl;
			}
			else {
				cout << "Gioi tinh: Nu" << endl;
			}
			
		}
		else {
			cout << "Voi Chau Phi" << endl;
			cout << "Tuoi: " << age << endl;
			cout << "Can nang: " << weight << endl;
			if (sex == 0) {
				cout << "Gioi tinh: Nam" << endl;
			}
			else {
				cout << "Gioi tinh: Nu" << endl;
			}
		}
	}
};





int main() {
	Elephant voi(19, 90.23, 1, 0);
	Animal a;
	a.an();

	voi.Print();
	voi.an();


	return 0;
}