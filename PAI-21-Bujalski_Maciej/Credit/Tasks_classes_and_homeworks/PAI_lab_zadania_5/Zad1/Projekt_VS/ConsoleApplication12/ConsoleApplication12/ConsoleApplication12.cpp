// ConsoleApplication12.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#include <iostream>

using namespace std;

const short WIELKOSC_TAB = 7;
const short WIELKOSC_TAB2 = 2;
const int x0 = 1;

int y_(int sum);

int suma(int xi, int xi2, int w1, int w2, int x0, int Theta);

int main()
{
	int x1[WIELKOSC_TAB] = { 2, 2, 0, -2, -2, 0, 4 };
	int x2[WIELKOSC_TAB] = { 1, 2, 6, 10, 0, 0, -20 };
	int d[WIELKOSC_TAB] = { 1, 1, 1, -1, -1, -1, -1 };
	int w[WIELKOSC_TAB2] = { 0, 0 };
	int Theta = 0, iterator = 0, y , z ;

	do
	{
		z = 0;

		for (int i = 0; i < 7; i++)
		{
		
			y = y_(suma(x1[i], x2[i], w[0], w[1], x0, Theta));
			
			if (y != d[i])
			{
				w[0] = w[0] + d[i] * x1[i];
				w[1] = w[1] + d[i] * x2[i];
				Theta = Theta + d[i] * x0;
				z++;
			}

			cout << y << " " << d[i] << endl;
			

		}

		iterator++;
		cout << endl;
		cout << iterator << endl;
		cout << endl;
	} 
	while (z > 0);

	cout << "w 0 =" << Theta << " " << "w 1 =" << w[0] << " " << "w 2 =" << w[1] << endl;

}

int y_(int sum)
{
	if (sum > 0)
	{
		return 1;
	}

	else
	{
		return -1;
	}
}

int suma(int xi,int xi2, int w1, int w2, int x0, int Theta)
{
	int sum;
	
		sum = xi * w1 + xi2 * w2 + Theta * x0;

	return sum;
}
