#include <iostream>
#include<vector>

using namespace std;

class Storage {
public:
	void addItem(int items) {
		for (int i = 0; i < items; i++) {
			string itemName;
			int itemPrice;
			cout << "Enter the name of item:" << endl;
			cout << "> ";
			cin >> itemName;
			cout << "Enter the price of item:" << endl;
			cout << "> ";
			cin >> itemPrice;
			itemNames.push_back(itemName);
			itemPrices.push_back(itemPrice);
			itemLeft.push_back(0);
		}
	}

	void showItems() {
		for (int i = 0; i < itemNames.size(); i++) {
			cout << "Item #" << i + 1 << " {\n" << itemNames[i] << ": " << itemPrices[i] << " (Left: " << itemLeft[i] << ")" << "\n}\n" << endl;
		}
	}

	int getItemNamesSize() {
		return itemNames.size();
	}

	int getItemPrice(int itemNum) {
		return itemPrices[itemNum - 1];
	}

	void setItemLeft (int numInList, int left) {
		itemLeft[numInList - 1] = left;
	}

	void sellItemLeft(int numInList) {
		itemLeft[numInList - 1] -= 1;
	}

	int getItemLeft(int ni) {
		return itemLeft[ni - 1];
	}

private:
	vector<string> itemNames;
	vector<int> itemPrices;
	vector<int> itemLeft;
};

class Cashier {
private:
	int money = 0;
public:
	Storage stg;
	int sellItem(int i) {
		return money += stg.getItemPrice(i);
	}

	int getMoney() {
		return money;
	}
};

class Shop {
private:
	Cashier csh;
public:
	void shop() {
		bool working = true;
		int answ;
		cout << "Welcome to shop!" << endl;
		while (working) {
			cout << "Money: " << csh.getMoney() << "$" << endl;
			cout << "1 - Add items\n2 - Show list\n3 - Add item left\n4 - Sell item\n0 - End proccess\n> ";
			cin >> answ;
			if (answ == 1) {
				cout << "How many items to add?" << endl;
				int hm;
				cout << "> ";
				cin >> hm;
				csh.stg.addItem(hm);
			}
			else if (answ == 2) {
				if (csh.stg.getItemNamesSize() > 0) {
					csh.stg.showItems();
				}
				else {
					cout << "Nothing!" << endl;
				}
			}
			else if (answ == 3) {
				if (csh.stg.getItemNamesSize() > 0) {
					cout << "What is the number of item?" << endl;
					int ni;
					cout << "> ";
					cin >> ni;
					cout << "How many to add?" << endl;
					int hm;
					cout << "> ";
					cin >> hm;
					csh.stg.setItemLeft(ni, hm);
				}
				else {
					cout << "Nothing to add to!" << endl;
				}
			}
			else if (answ == 4) {
				if (csh.stg.getItemNamesSize() > 0) {
					cout << "What item wanna sell (type number of item)" << endl;
					int ni;
					cout << "> ";
					cin >> ni;
					if (csh.stg.getItemLeft(ni) > 0) {
						csh.stg.sellItemLeft(ni);
						csh.sellItem(ni);
					}
					else {
						cout << "Out of stock!" << endl;
					}
				}
				else {
					cout << "Nothing to sell!" << endl;
				}
			}
			else {
				working = false;
			}
		}
	}
};

int main() {
	Shop sh;
	sh.shop();
}
