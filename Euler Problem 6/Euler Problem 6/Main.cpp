/* Joesph Olliff 2/18/2014
Project Euler Problem 6 "Sum Square Difference"
Find the Difference between the sum of squares of the first one hundred natural numbers
and the square of the sum
*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int count = 0;
	long sumSquare = 0;
	long squareSum = 0;
	long difference = 0;

	for (count = 1; count <= 100; count++)
	{
		squareSum += pow(count, 2);
	}

	for (count = 1; count <= 100; count++)
	{
		sumSquare += count;
	}
	sumSquare *= sumSquare;

	difference = sumSquare - squareSum;
	
	cout << "The solution is: " << difference << endl << endl;

	system("pause");
	return 0;
}