// BISECTION METHOD.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include<math.h>
using namespace std;

#define EP 0.0000001

void Bisection_Method()
{
	int n = 0;
	int* arr;
	cout << "\n\t\t************************************************************\n";
	cout << "\t\t**********************BISECTION METHOD**********************\n";
	cout << "\t\t************************************************************\n\n\n";
	cout << "Enter the maximum power of the coffeicent you want to enter: "; cin >> n;
	cout << "\n\n";

	//ALLOCATING THE DYNAMIC ARRAY
	arr = new int[n + 1];
	//INITIALIZING THE ARRAY WITH ZERO
	for (int i = 0; i < n; i++)
	{
		arr[i] = 0;
	}

	//TAKING THE USER INPUT
	cout << "Enter the following:\n\n";
	for (int i = 0, x = n; i < n + 1; i++, x--)
	{
		if (i == n)
		{
			cout << "c = ";
		}
		else
		{
			cout << "x ^ " << x << ": ";
		}
		cin >> arr[i];
	}

	cout << "\n\nEQUATION:\n\n";
	cout << "f(x) = ";
	//DISPLAYING THE EQUTION USER ENTERED
	for (int i = 0; i < n+1; i++)
	{
		if (arr[i] != 0)
		{
			cout << "(" << arr[i] << "x ^ " << i << ")  +  ";
		}
	}
	cout << "0\n\n";

	//CHECKING THE INTERVAL
	float x1 = 0, x2 = 0;
	float	sum1 = 0, sum2 = 0, i = 0;
	bool find = false;
	int power = n;
	while (find == false)
	{
		for (int h = 0, k = power; h < power; h++, --k)
		{
			sum1 = sum1 + (pow(i, k) * arr[h]);
		}

		x1 = i;
		i += 1;
		x2 = i;
		for (int h = 0, k = power; h < power; h++, --k)
		{
			sum2 = sum2 + (pow(i, k) * arr[h]);
		}
		sum1 = sum1 + arr[power];
		sum2 = sum2 + arr[power];
		if (sum1 < 0 && sum2>0)
		{
			break;
		}
		else if (sum1 > 0 && sum2 < 0)
		{
			break;
		}
		else
			find = false;
		sum1 = sum2 = 0;
	}
	cout << "\nINTERVAL IS: (" << x1 << " , " << x2 << ")\n\n";
	
	
	float a = x1, b = x2;
	float xN = (a+b)/2, prev_fxN = 0;
	bool checkFinal = false;
	int iterations = 1;
	cout << "\nITERATIONS:\n\n";
	cout << "		a		b		x(n)		f(x(n))		\n";
	sum1 = 0, sum2 = 0;
	while ((b - a) >= EP)
	{
		//bisecting
		xN = ((a + b) / 2);
		for (int h = 0, k = power; h <= power; h++, --k)
		{
			sum1 = sum1 + (pow(xN, k) * arr[h]);
		}
		for (int h = 0, k = power; h <= power; h++, --k)
		{
			sum2 = sum2 + (pow(a, k) * arr[h]);
		}
		if (sum1 == 0.0)
		{
			break;
		}
		else if ((sum1*sum2) < 0)
		{
			b = xN;
		}
		else 
		{
			a = xN;
		}
		cout << "		" << a << "		" << b << "		" << xN << "		" << sum1 << "		\n";
		if (prev_fxN == sum1)
		{
			checkFinal = true;
			break;
		}
		prev_fxN = sum1;
		sum1 = 0;
		iterations++;
	}
	cout << "\n\nFinal result was at this --> Iteration # " << iterations << " and this the interval at which the answer was repeating [" << a << " , " << b << "]"<<"\n\n";
}

int main()
{
	Bisection_Method();

	system("pause");
	return 0;
}
