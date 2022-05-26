#include <iostream>
#include <string>

using namespace std;

class Weapon {
public:
	string type;
	string name;
	string caliber;

	void print() {
		cout << "Type: " << type << "\n" << "Name: " << name << "\n" << "Caliber: " << caliber << "\n" << endl;
	}
};


int main() {
	Weapon glock;
	Weapon ak;
	Weapon ar;
	Weapon colt;

	glock.type = "Pistol";
	glock.name = "Glock";
	glock.caliber = "9mm";
	glock.print();

	ak.type = "Rifle";
	ak.name = "AK-47";
	ak.caliber = "7.62";
	ak.print();

	return 0;
}