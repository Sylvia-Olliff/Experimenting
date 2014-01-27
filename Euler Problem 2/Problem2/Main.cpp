#include <iostream>
using namespace std;

int main()
{
	//declare variables
	const int num1 = 1;
	const int num2 = 2;
	int tempNum1 = 0;
	int tempNum2 = 0;
	int limit = 0;
	int count = 0;
	int count2 = 0;
	int solution = 0;

	int temp[1500];

	bool exit = false;

	//initialize the array
	for (count = 0; count < 1500; count++)
	{
		temp[count] = 0;
	}
	count = 0;

	//Generate all of the Fibonacci numbers less than 4 mil
	do
	{
		if (count == 0)
		{
			temp[count] = num1;
			count++;
		}
		else if (count == 1)
		{
			temp[count] = num2;
			count++;
		}
		else
		{
			tempNum1 = count - 2;
			tempNum2 = count - 1;
			temp[count] = temp[tempNum1] + temp[tempNum2];
		}

		if (temp[count] >= 4000000)
		{
			temp[count] = 0;
			exit = true;
		}
		count++;
	} while (!exit);

	//Add all of the even ones
	for (count2 = 0; count2 < count; count2++)
	{
		if (temp[count2] % 2 == 0)
		{
			solution = solution + temp[count2];
		}
	}

	//Display the results
	cout << "The sum of all of the even Fibonacci Numbers less than 4 million is: " << solution << endl << endl;
	system("pause");

	return 0;
}