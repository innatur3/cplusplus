// ввести прізвища та ініціали студентів групи і відсортувати їх в алфавітному пордку

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    string str[5];
    cout << "Enter name: "<< '\n';
    for  (int i = 0; i<5;i++){
        getline(cin, str[i], '\n');}

    bool swapped = true;
    string tmp;
    int j = 0;
    int n = 5;

    while (swapped)
    {
        swapped = false;
        ++j;
        for (int i = 0; i < n - j; i++)
        {
            if (str[i].compare(str[i + 1]) > 0)
            {
                tmp = str[i];
                str[i] = str[i + 1];
                str[i + 1] = tmp;
                swapped = true;
            }
        }
    }
//=======================================================================================
    ofstream out("new1.txt");
    for (int j = 0; j < n; j++)
    {
        out << str[j] << " ";
        out << "\n";
    }
    out.close();
//=======================================================================================
    for (int i = 0; i < n; i++)
    {
        cout << "Output sorted names: " << str[i] << endl;
    }
//=======================================================================================

return 0;
}
