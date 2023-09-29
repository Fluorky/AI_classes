// ConsoleApplication13.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>

using namespace std;

const short WIELKOSC_TAB = 2;
const short WIELKOSC_TAB2 = 13;

double f(double suma);

int main()
{


	int jeden[WIELKOSC_TAB2] = { -1, -1, 1, -1, -1, 1, -1, -1, 1, -1, -1, 1, 1 };
	
	int cztery[WIELKOSC_TAB2] = { 1, -1, 1, 1, 1, 1, -1, -1, 1, -1, -1, 1, 1 };

	int d[WIELKOSC_TAB] = { -1,1 };


	double w[WIELKOSC_TAB2] = { 0, 0, 0, 0, 0,  0, 0, 0 ,0 ,0, 0, 0, 0};

	double w2[WIELKOSC_TAB2] = { 0, 0, 0, 0, 0,  0, 0, 0 ,0 ,0, 0, 0, 0};

	int  iterator = 0;
	double E, s,s2,y,y2;
	double d1=-1, d4=1, ni=0.35;


	do
	{
	

		E = 0;
		//Podajemy 1
	

		for (int i = 0; i < 12; i++)
		{
		
		     	s = jeden[i] * w[i]  + w[12] * jeden[12];
				y = f(s);

				//modyfikacja wag
				w[i] = w[i] + d[0] * jeden[i] * ni;
			
				w[12] = w[12] + d[0] * jeden[12] * ni;
		

			cout << y << " " << d[0] << endl;


		}
		cout << y << " <-- y koncowy dla 1 " << d[0] <<" <--d oczekiwana " <<endl;
			//blad dla 1
			E = 0.5*(d1 - y)*(d1 - y);

		//Podajemy 4


		for (int i = 0; i < 12; i++)
		{
			s2 = cztery[i] * w2[i]  + w2[12] * cztery[12];
			y2 = f(s2);
			//modyfikacja wag
			w2[i] = w2[i] + d[1] * cztery[i] * ni;
			w2[12] = w2[12] + d[1] * cztery[12] * ni;
			cout << y2 << " " << d[1] << endl;


		}
		cout << y << " <-- y koncowy dla 4" << d[1] << " <--d oczekiwana " << endl;
		iterator++;
		cout << endl;
		cout << iterator<<" <-- przebieg funkcji" << endl;
		cout << endl;

			//blad sumaryczny
			E = E + 0.5*(d4 - y2)*(d4 - y2);

			cout << E << " blad sumaryczny" << endl;
	} 
	while (E > 0.0000000005);


}



double f(double suma)
{
	double beta = 0.5;// beta z przedzialu (0,1]

	double y = (1 - exp(-1*suma*beta))/(1+exp(-1*suma*beta));

	return y;
}



