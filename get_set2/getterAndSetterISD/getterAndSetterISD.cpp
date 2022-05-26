#include <iostream>
#include <string>

using namespace std;

class Square {
private:
	double side;
	double area;
public:
	void setSide(double side) {
		this->side = side;
		this->area = side * side;
	}

	int getSalary() {
		return side;
	}

	void print() {
		cout << "Square: side = " << this->side << ", area = " << this->area << endl;
	}
};




int main() {
	Square s;
	s.setSide(4);
	s.print();
	s.setSide(10);
	s.print();
}