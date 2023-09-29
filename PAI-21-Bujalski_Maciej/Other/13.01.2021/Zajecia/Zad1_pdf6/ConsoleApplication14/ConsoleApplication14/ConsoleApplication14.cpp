// ConsoleApplication14.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

// ConsoleApplication13.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>

using namespace std;

const short WIELKOSC_TAB = 2;
const short WIELKOSC_TAB2 = 13;

double f(double suma);
double fprim(double x);
double beta = 1;
double ni = 1;
int main()
{


	//int jeden[WIELKOSC_TAB2] = { -1, -1, 1, -1, -1, 1, -1, -1, 1, -1, -1, 1, 1 };

	//int cztery[WIELKOSC_TAB2] = { 1, -1, 1, 1, 1, 1, -1, -1, 1, -1, -1, 1, 1 };

	double w[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
	double jeden[13] = { 1,-1,-1,1,-1,-1,1,-1,-1,1,-1,-1,1 };
	double cztery[13] = { 1,1,-1,1,1,1,1,-1,-1,1,-1,-1,1 };

	int d[WIELKOSC_TAB] = { -1,1 };


	//double w[WIELKOSC_TAB2] = { 0, 0, 0, 0, 0,  0, 0, 0 ,0 ,0, 0, 0, 0 };

	double w2[WIELKOSC_TAB2] = { 0, 0, 0, 0, 0,  0, 0, 0 ,0 ,0, 0, 0, 0 };

	int  iterator = 0;
	double E, s = 0 , s2=0 , y, y2;
	//double d1 = -1, d4 = 1, ni = 0.35;
	double d1 = 1, d4 = 0;


	do
	{

		s = 0;
		E = 0;
		//Podajemy 1
		for (int i = 0; i < 13; i++)
		{

			s = s + jeden[i] * w[i];

		}
			y = f(s);

		for (int i = 0; i < 13; i++)
		{

		/*	s = s+ jeden[i] * w[i]; //+ w[12] * jeden[12];
			//s = jeden[i] * w[i] + w[12] * jeden[12];
			y = f(s);*/

			//modyfikacja wag
		//	w[i] = w[i] + d[0] * jeden[i] * ni;
			
		//	w[i] = w[i] + ni * (d[0] - f(s))*fprim(s)*jeden[i];
			w[i] = w[i] + ni *beta*(1-y)*y*(d1 - y)*jeden[i];
			//w[12] = w[12] + d[0] * jeden[12] * ni;
		//	w[12] = w[12] + ni * (d[0] - f(s))*fprim(s)*jeden[12];
			//w[12] = w[12] + d[0] * jeden[12] * ni;

			//cout << y << " " << d1 << endl;


		}
	//	cout << y << " <-- y koncowy dla 1 " << d1 << " <--d oczekiwana " << endl;
		//blad dla 1
		E = 0.5*(d1 - y)*(d1 - y);

		s = 0;
		//Podajemy 4
		for (int i = 0; i < 13; i++)
		{
			s = s + cztery[i] * w[i];// +w2[12] * cztery[12];
		}
		//s2 = s2 + cztery[i] * w2[i];// +w2[12] * cztery[12];
		y2 = f(s);
		
		for (int i = 0; i < 13; i++)
		{
			//s2 = cztery[i] * w2[i] + w2[12] * cztery[12];
		//	s2 = s2 + cztery[i] * w2[i];// +w2[12] * cztery[12];
			//y2 = f(s2);
			//modyfikacja wag
			w[i] = w[i] + ni * beta*(1 - y2)*y2*(d4 - y2)*cztery[i];
			//w2[i] = w2[i] + ni * (d[1] - f(s2))*fprim(s2)*cztery[i];

			//w[12] = w[12] + d[0] * jeden[12] * ni;
			//w2[12] = w2[12] + ni * (d[1] - f(s2))*fprim(s2)*cztery[12];
			//w2[i] = w2[i] + d[1] * cztery[i] * ni;
			//w2[12] = w2[12] + d[1] * cztery[12] * ni;
		//	cout << y2 << " " << d4 << endl;


		}
	//	cout << y2 << " <-- y koncowy dla 4 " << d4 << " <--d oczekiwana " << endl;
		iterator++;
		//cout << endl;
		//cout << iterator << " <-- przebieg funkcji" << endl;
		//cout << endl;

		//blad sumaryczny
		E = E + 0.5*(d4 - y2)*(d4 - y2);


		cout << E << " blad sumaryczny" << endl;

	//	cout << "wyjscie" << y << " " << y2 << endl;
	} while (E > 0.0005);
	s = 0;
	//Podajemy 4
	for (int i = 0; i < 13; i++)
	{
		s = s + jeden[i] * w[i];// +w2[12] * cztery[12];
	}
	cout << "wyjscie dla 1 " << f(s) << endl;
	s = 0;
	
	//Podajemy 4
	for (int i = 0; i < 13; i++)
	{
		s = s + cztery[i] * w[i];// +w2[12] * cztery[12];
	}
	cout << "wyjscie dla 4  " << f(s) << endl;

}



double f(double suma)
{
//	double beta = 0.5;// beta z przedzialu (0,1]

	return 1 / (1 + exp(-beta * suma));
}

double fprim(double x)
{
	double y = beta * f(x)* (1-f(x));

	return y;
}





// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
