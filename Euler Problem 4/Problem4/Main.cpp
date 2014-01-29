#include <iostream>
#include <iomanip>
#include <locale>
#include <sstream>
using namespace std;

int main()
{
	int count = 0;
	int count2 = 0;
	int temp = 0;
	int solution = 0;
	int num1 = 0;
	int num2 = 0;
	bool exit = false;
	string string1;
	string string2;
	ostringstream convert;

	for (count = 999; count > 100; count--)
	{
		for (count2 = 999; count2 > 100; count2--)
		{
			string1.clear();
			string2.clear();
			convert.str("");
			temp = count * count2;
			convert << temp;
			string1 = convert.str();
			string2 = string1;
			reverse(string2.begin(), string2.end());
			cout << "Checking " << count << " * " << count2 << " = " << temp << endl;
			if (string1.compare(string2) == 0)
			{
				system("cls");
				cout << "Found it!" << endl;
				system("pause");
				solution = temp;
				num1 = count;
				num2 = count2;
				exit = true;
				break;
			}

		}
		if (exit)
		{
			break;
		}
	}

	system("cls");
	cout << "The largest palindrome made from the product of two 3-digit numbers is: " << endl << num1 << " * " << num2 << " = " << solution << endl << endl;
	system("pause");

	return 0;
}