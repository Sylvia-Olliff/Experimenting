#include <iostream>
using namespace std;

int main()
{
	//Declare Variables
	long long count = 0;
	long long count2 = 0;
	long long num1 = 0;
	long long temp = 0; 
	long long factor = 600851475143;
	bool notPrime = false;
	
	//Find the largest Prime
	for (count = 2; count < factor; count++)
	{
		if (factor % count == 0)
		{
			temp = count;
			cout << "Found a factor: " << factor/temp << endl;
			for (count2 = 2; count2 < factor/temp; count2++)
			{
				if (factor/temp % count2 == 0)
				{
					cout << "It's not a prime..." << endl;
					notPrime = true;
					break;
				}
			}
			if (!notPrime)
			{
				cout << "Found it!" << endl;
				system("pause");
				num1 = factor/temp;
				break;
			}
			else
			{
				notPrime = false;
			}
		}
	}
	system("cls");

	//Display the results
	cout << "The largest Prime Factor of: " << factor << " is: " << num1 << endl << endl;
	system("pause");

	return 0;
}