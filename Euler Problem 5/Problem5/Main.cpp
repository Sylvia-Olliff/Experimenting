/* Joesph Olliff 2/1/2014
Project Euler Problem 5 "Smallest Multiple"
Create a program that determins what the smallest positive number that is evenly divisable by all of the numbers from 1 to 20
*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	//declare variables used
	int primes[50];
	int highestExp[50];
	int exponents[50];
	long long solution = 1;
	int seriesBeg = 0;
	int seriesEnd = 0;
	int factoring = 0;
	int count = 0;
	int count2 = 0;
	int primeInc = 4;
	bool exit = false;

	//initialize arrays
	for (count = 0; count < 50; count++)
	{
		primes[count] = 0;
	}

	for (count = 0; count < 50; count++)
	{
		highestExp[count] = 0;
	}

	for (count = 0; count < 50; count++)
	{
		exponents[count] = 0;
	}
	primes[0] = 2;
	primes[1] = 3;
	primes[2] = 5;
	primes[3] = 7;

	//Welcome message
	cout << "This program will calculate the LCM of a given series of numbers." << endl << "Do not start your series lower than 1 " << endl << endl;
	system("pause");
	system("cls");

	//Get the starting point of the series
	cout << "Please enter the beginning of your series: ";
	cin >> seriesBeg;
	system("cls");

	//Get the end of the series
	cout << "Please enter the end of the series: ";
	cin >> seriesEnd;
	system("cls");

	//Break down each number in the series using Prime Factorization
	for (count = seriesBeg; count <= seriesEnd; count++)
	{
		exit = false;
		factoring = count;
		do
		{
			if (factoring % 2 == 0)
			{
				factoring /= 2;
				exponents[0]++;
			}
			else if (factoring % 3 == 0)
			{
				factoring /= 3;
				exponents[1]++;
			}
			else if (factoring % 5 == 0)
			{
				factoring /= 5;
				exponents[2]++;
			}
			else if (factoring % 7 == 0)
			{
				factoring /= 7;
				exponents[3]++;
			}
			else if (factoring == 1)
			{
				exit = true;
			}
			else
			{
				primes[primeInc] = factoring;
				exponents[primeInc]++;
				primeInc++;
				exit = true;
			}
		} while (!exit);

		//check if the exponent values just used are the highest yet
		for (count2 = 0; count2 < 50; count2++)
		{
			if (exponents[count2] > highestExp[count2])
			{
				highestExp[count2] = exponents[count2];
			}
		}

		//reset current exponent tracker
		for (count2 = 0; count2 < 50; count2++)
		{
			exponents[count2] = 0;
		}
	}

	//Determine number of primes used
	count2 = 0;
	for (count = 0; count < 50; count++)
	{
		if (primes[count] != 0)
		{
			count2++;
		}
		else
		{
			break;
		}
	}

	//Calculate the results
	for (count = 0; count <= count2; count++)
	{
		solution *= pow(primes[count], highestExp[count]);
	}

	
	//display the results
	cout << "The smallest number that is divisible by every whole number between" << seriesBeg << " and " << seriesEnd << " is: " << solution << endl;
	system("pause");

}