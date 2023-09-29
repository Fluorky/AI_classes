// zadania6_zad2.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
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


	double w[2][13] = { {0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0} };
	double tab1[13] = { 1,-1,-1,1,-1,-1,1,-1,-1,1,-1,-1,1 };
	double tab4[13] = { 1,1,-1,1,1,1,1,-1,-1,1,-1,-1,1 };
	double tab7[13] = { 1,1,1,1,-1,-1,1,-1,-1,1,-1,-1,1 };
	double d1[2] = { 1,1 }, d4[2] = { 1,0 }, d7[2] = { 0,0 };

/*	double w[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
	double jeden[13] = { 1,-1,-1,1,-1,-1,1,-1,-1,1,-1,-1,1 };
	double cztery[13] = { 1,1,-1,1,1,1,1,-1,-1,1,-1,-1,1 };

	int d[WIELKOSC_TAB] = { -1,1 };*/

	double ni = 2.0;

	//double w2[WIELKOSC_TAB2] = { 0, 0, 0, 0, 0,  0, 0, 0 ,0 ,0, 0, 0, 0 };

	int  iterator = 0;
	double E, s1 = 0, s2 = 0, y1, y2;

	//double d1 = 1, d4 = 0;


	do
	{

		s1 = 0;
		s2 = 0;
		E = 0;
		//Podajemy 1
		for (int i = 0; i < 13; i++)
		{

			s1 = s1 + tab1[i] * w[0][i];
			s2 = s2 + tab1[i] * w[1][i];

		}
		y1 = f(s1);
		y2 = f(s2);

		for (int i = 0; i < 13; i++)
		{

			w[0][i] = w[0][i] + ni * beta*(d1[0] - y1)*y1*(1 - y1)*tab1[i];
			w[1][i] = w[1][i] + ni * beta*(d1[1] - y2)*y2*(1 - y2)*tab1[i];



		}

		E = 0.5*(d1[0] - y1)*(d1[0] - y1)+ 0.5*(d1[1] - y2)*(d1[1] - y2);

		s1 = 0;
		s2 = 0;
		//Podajemy 4
		for (int i = 0; i < 13; i++)
		{

			s1 = s1 + tab4[i] * w[0][i];
			s2 = s2 + tab4[i] * w[1][i];

		}
		y1 = f(s1);
		y2 = f(s2);

		for (int i = 0; i < 13; i++)
		{

			w[0][i] = w[0][i] + ni * beta*(d4[0] - y1)*y1*(1 - y1)*tab4[i];
			w[1][i] = w[1][i] + ni * beta*(d4[1] - y2)*y2*(1 - y2)*tab4[i];



		}

		E = E+ 0.5*(d4[0] - y1)*(d4[0] - y1) + 0.5*(d4[1] - y2)*(d4[1] - y2);

		s1 = 0;
		s2 = 0;

		for (int i = 0; i < 13; i++)
		{

			s1 = s1 + tab7[i] * w[0][i];
			s2 = s2 + tab7[i] * w[1][i];

		}
		y1 = f(s1);
		y2 = f(s2);

		for (int i = 0; i < 13; i++)
		{

			w[0][i] = w[0][i] + ni * beta*(d7[0] - y1)*y1*(1 - y1)*tab7[i];
			w[1][i] = w[1][i] + ni * beta*(d7[1] - y2)*y2*(1 - y2)*tab7[i];



		}

		E = E + 0.5*(d7[0] - y1)*(d7[0] - y1) + 0.5*(d7[1] - y2)*(d7[1] - y2);

		s1 = 0;
		s2 = 0;
		iterator++;
		//cout << endl;
		//cout << iterator << " <-- przebieg funkcji" << endl;
		//cout << endl;

		//blad sumaryczny
	//	E = E + 0.5*(d4 - y2)*(d4 - y2);

		cout << E << " blad sumaryczny" << endl;


	} while (E > 0.00005);
	cout << E << " blad sumaryczny koncowy" << endl;
	s1 = 0;
	s2 = 0;
	//Podajemy 1
	for (int i = 0; i < 13; i++)
	{

		s1 = s1 + tab1[i] * w[0][i];
		s2 = s2 + tab1[i] * w[1][i];

	}
	cout << "wyjscie dla 1 " << f(s1) << f(s2) << endl;
	s1 = 0;
	s2 = 0;
	//Podajemy 4
	for (int i = 0; i < 13; i++)
	{

		s1 = s1 + tab4[i] * w[0][i];
		s2 = s2 + tab4[i] * w[1][i];

	}
	cout << "wyjscie dla 4 " << f(s1) << f(s2) << endl;

	s1 = 0;
	s2 = 0;
	//Podajemy 8
	for (int i = 0; i < 13; i++)
	{

		s1 = s1 + tab7[i] * w[0][i];
		s2 = s2 + tab7[i] * w[1][i];

	}
	cout << "wyjscie dla 7 " << f(s1) << f(s2) << endl;


}



double f(double suma)
{
	//	double beta = 0.5;// beta z przedzialu (0,1]

	return 1 / (1 + exp(-beta * suma));
}

double fprim(double x)
{
	double y = beta * f(x)* (1 - f(x));

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

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
