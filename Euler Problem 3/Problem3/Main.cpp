#include <iostream>
using namespace std;

int main()
{
	//Declare Variables
	long array1[100000];
	long array2[100000];
	long long count = 0;
	long long count2 = 0;
	long long count3 = 0;
	long long num1 = 0;
	long long temp = 0;
	long long temp2 = 0;
	long long temp3 = 0;
	long long factor = 600851475143;

	//Initialize arrays
	for (count = 0; count < 100000; count++)
	{
		array1[count] = 0;
	}
	
	for (count = 0; count < 100000; count++)
	{
		array2[count] = 0;
	}

	cout << "Made it past Initializeing " << endl;

	//Generate all of the factors
	for (count = 0; count < factor; count++)
	{
		for (count2 = 0; count2 < factor; count2++)
		{
			cout << "progress 1: " << count << " progress 2: " << count2 << endl;
			if (count * count2 == factor)
			{
				array1[temp] = count;
				temp++;
				array1[temp] = count2;
				temp++;
			}
		}
	}

	cout << "Made it past Generating all of the factors " << endl;

	//Determine which factors are Prime
	for (count = 0; count < temp; count++)
	{
		if (array1[count] == 1)
		{
			array2[temp2] = array1[count];
			temp2++;
		}
		else
		{
			for (count2 = 0; count2 < array1[count]; count2++)
			{
				for (count3 = 0; count3 < array1[count]; count3++)
				{
					if (count2 * count3 == array1[count])
					{
						temp3++;
					}
				}
			}
			if (temp3 == 1)
			{
				array2[temp2] = array1[count];
				temp2++;
				temp3 = 0;
			}
			else
			{
				temp3 = 0;
			}
		}
	}

	cout << "Made it past Determining which factors are Prime " << endl;

	//Determine which of the Primes is the largest
	for (count = 0; count < temp2; count++)
	{
		if (num1 < array2[count])
		{
			num1 = array2[count];
		}
	}

	//Display the results
	cout << "The largest Prime Factor of: " << factor << " is: " << num1 << endl << endl;
	system("pause");

	return 0;
}