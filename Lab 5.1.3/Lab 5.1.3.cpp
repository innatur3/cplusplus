#include <iostream>

using namespace std;

class AdHocSquare {
private:
	double side;
public:
	AdHocSquare(double s);
	void setSide(double s) {
		side = s;
	}
	double getArea() {
		return side;
	}
};

int main() {
	AdHocSquare adHocSquare(100);
	adHocSquare.setSide(100);
	adHocSquare.getArea();
	return 0;
}