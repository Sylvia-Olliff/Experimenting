#include <iostream>
using namespace std;

int main()
{
	//Declare variables
	int count = 0;
	int count2 = 0;
	int temp[500];
	int solution = 0;

	//initialize the array used to store the multiples
	for (count = 0; count<500; count++)
	{
		temp[count] = 0;
	}
	
	//Find all of the multiples
	for (count = 0; count < 1000; count++)
	{
		if (count % 3 == 0 || count % 5 == 0)
		{
			temp[count2] = count;
			count2++;
		}
	}

	//Add them all up
	for (count = 0; count < 500; count++)
	{
		solution = solution + temp[count];
	}
	
	//Display the result
	cout << "The sum of all of the multiples of 3 and 5 that are less than 1000 is: " << solution << endl << endl;
	system("pause");
	return 0;
}