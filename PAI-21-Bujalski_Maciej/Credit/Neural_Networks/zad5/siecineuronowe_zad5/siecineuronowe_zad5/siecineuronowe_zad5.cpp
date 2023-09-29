// siecineuronowe_zad5.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

// zadania7_zadS.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
// zadania6_zadX.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>

using namespace std;

const short WIELKOSC_TAB = 2;
const short WIELKOSC_tabX = 36;

double f(double suma);
double fprim(double x);
double beta = 1;
double ni = 1;
int main()
{


	double w[3][36] = { {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} };
	double tabE[36] = { 1, 1,1,1,1,-1, 1,-1,-1,-1,-1,  1,-1,-1,-1,-1, 1,1,1,-1,-1,  1,-1,-1,-1,-1,  1,-1,-1,-1,-1, 1,1,1,1,-1 };
	double tabF[36] = { 1,  1,1,1,1,-1, 1,-1,-1,-1,-1,  1,-1,-1,-1,-1, 1,1,1,-1,-1,  1,-1,-1,-1,-1,  1,-1,-1,-1,-1, 1,-1,-1,-1,-1 };
	double tabG[36] = { 1, -1,1,1,1,-1, 1,-1,-1,-1,1,  1,-1,-1,-1,-1, 1,-1,1,1,-1,  1,-1,-1,-1,1,  1,-1,-1,-1,1, -1,1,1,1,-1 };
	double tabH[36] = { 1, 1,-1,-1,-1,1, 1,-1,-1,-1,1,  1,-1,-1,-1,1, 1,1,1,1,1,  1,-1,-1,-1,1,  1,-1,-1,-1,1, 1,-1,-1,-1,1 };
	double tabS[36] = { 1, -1,1,1,1,-1, 1,-1,-1,-1,1,  1,-1,-1,-1,-1, -1,1,1,1,-1,  -1,-1,-1,-1,1,  1,-1,-1,-1,1, -1,1,1,1,-1 };
	double tabT[36] = { 1,  1,1,1,1,1,  -1,-1,1,-1,-1,   -1,-1,1,-1,-1,    -1,-1,1,-1,-1, -1,-1,1,-1,-1,   -1,-1,1,-1,-1, -1,-1,1,-1,-1 };
	double tabY[36] = { 1,  1,-1,-1,-1,1,  1,-1,-1,-1,1,  -1,1,-1,1,-1,  -1,1,-1,1,-1,   -1,-1,1,-1,-1, -1,-1,1,-1,-1, -1,-1,1,-1,-1 };
	double tabX[36] = { 1, 1,-1,-1,-1,1, 1,-1,-1,-1,1, -1,1,-1,1,-1, -1,-1,1,-1,-1,  -1,1,-1,1,-1,  1,-1,-1,-1,1, 1,-1,-1,-1,1 };
	double dS[3] = { 0,0,0 }, dT[3] = { 0,0,1 }, dY[3] = { 0,1,0 }, dX[3] = { 0,1,1 }, dE[3] = { 1,0,0 }, dF[3] = { 1,0,1 },dG[3] = { 1,1,0 },dH[3] = { 1,1,1 };
	
	/*	double w[36] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
		double jeden[36] = { 1,-1,-1,1,-1,-1,1,-1,-1,1,-1,-1,1 };
		double cztery[36] = { 1,1,-1,1,1,1,1,-1,-1,1,-1,-1,1 };

		int d[WIELKOSC_TAB] = { -1,1 };*/

	double ni = 2.0;

	//double w2[WIELKOSC_tabX] = { 0, 0, 0, 0, 0,  0, 0, 0 ,0 ,0, 0, 0, 0 };

	int  iterator = 0;
	double E, s1 = 0, s2 = 0, s3 = 0, y1, y2, y3;

	//double dS = 1, dT = 0;


	do
	{

		s1 = 0;
		s2 = 0;
		s3 = 0;
		E = 0;
		//Podajemy S
		for (int i = 0; i < 36; i++)
		{

			s1 = s1 + tabS[i] * w[0][i];
			s2 = s2 + tabS[i] * w[1][i];
			s3 = s3 + tabS[i] * w[2][i];

		}
		y1 = f(s1);
		y2 = f(s2);
		y3 = f(s3);

		for (int i = 0; i < 36; i++)
		{

			w[0][i] = w[0][i] + ni * beta*(dS[0] - y1)*y1*(1 - y1)*tabS[i];
			w[1][i] = w[1][i] + ni * beta*(dS[1] - y2)*y2*(1 - y2)*tabS[i];
			w[2][i] = w[2][i] + ni * beta*(dS[2] - y3)*y3*(1 - y3)*tabS[i];



		}

		E = 0.5*(dS[0] - y1)*(dS[0] - y1) + 0.5*(dS[1] - y2)*(dS[1] - y2) + 0.5*(dS[2] - y3)*(dS[2] - y3);

		s1 = 0;
		s2 = 0;
		s3 = 0;
		//Podajemy T
		for (int i = 0; i < 36; i++)
		{

			s1 = s1 + tabT[i] * w[0][i];
			s2 = s2 + tabT[i] * w[1][i];
			s3 = s3 + tabT[i] * w[2][i];

		}
		y1 = f(s1);
		y2 = f(s2);
		y3 = f(s3);

		for (int i = 0; i < 36; i++)
		{

			w[0][i] = w[0][i] + ni * beta*(dT[0] - y1)*y1*(1 - y1)*tabT[i];
			w[1][i] = w[1][i] + ni * beta*(dT[1] - y2)*y2*(1 - y2)*tabT[i];
			w[2][i] = w[2][i] + ni * beta*(dT[2] - y3)*y3*(1 - y3)*tabT[i];



		}

		E = E + 0.5*(dT[0] - y1)*(dT[0] - y1) + 0.5*(dT[1] - y2)*(dT[1] - y2) + 0.5*(dT[2] - y3)*(dT[2] - y3);

		s1 = 0;
		s2 = 0;
		s3 = 0;
		//Podajemy Y
		for (int i = 0; i < 36; i++)
		{

			s1 = s1 + tabY[i] * w[0][i];
			s2 = s2 + tabY[i] * w[1][i];
			s3 = s3 + tabY[i] * w[2][i];

		}
		y1 = f(s1);
		y2 = f(s2);
		y3 = f(s3);

		for (int i = 0; i < 36; i++)
		{

			w[0][i] = w[0][i] + ni * beta*(dY[0] - y1)*y1*(1 - y1)*tabY[i];
			w[1][i] = w[1][i] + ni * beta*(dY[1] - y2)*y2*(1 - y2)*tabY[i];
			w[2][i] = w[2][i] + ni * beta*(dY[2] - y3)*y3*(1 - y3)*tabY[i];



		}

		E = E + 0.5*(dY[0] - y1)*(dY[0] - y1) + 0.5*(dY[1] - y2)*(dY[1] - y2) + 0.5*(dY[2] - y3)*(dY[2] - y3);

		s1 = 0;
		s2 = 0;
		s3 = 0;

		//Podajemy X
		for (int i = 0; i < 36; i++)
		{

			s1 = s1 + tabX[i] * w[0][i];
			s2 = s2 + tabX[i] * w[1][i];
			s3 = s3 + tabX[i] * w[2][i];

		}
		y1 = f(s1);
		y2 = f(s2);
		y3 = f(s3);

		for (int i = 0; i < 36; i++)
		{

			w[0][i] = w[0][i] + ni * beta*(dX[0] - y1)*y1*(1 - y1)*tabX[i];
			w[1][i] = w[1][i] + ni * beta*(dX[1] - y2)*y2*(1 - y2)*tabX[i];
			w[2][i] = w[2][i] + ni * beta*(dX[2] - y3)*y3*(1 - y3)*tabX[i];



		}

		E = E + 0.5*(dX[0] - y1)*(dX[0] - y1) + 0.5*(dX[1] - y2)*(dX[1] - y2) + 0.5*(dX[2] - y3)*(dX[2] - y3);

		s1 = 0;
		s2 = 0;
		s3 = 0;


		for (int i = 0; i < 36; i++)
		{

			s1 = s1 + tabE[i] * w[0][i];
			s2 = s2 + tabE[i] * w[1][i];
			s3 = s3 + tabE[i] * w[2][i];

		}
		y1 = f(s1);
		y2 = f(s2);
		y3 = f(s3);

		for (int i = 0; i < 36; i++)
		{

			w[0][i] = w[0][i] + ni * beta*(dE[0] - y1)*y1*(1 - y1)*tabE[i];
			w[1][i] = w[1][i] + ni * beta*(dE[1] - y2)*y2*(1 - y2)*tabE[i];
			w[2][i] = w[2][i] + ni * beta*(dE[2] - y3)*y3*(1 - y3)*tabE[i];



		}

		E = E + 0.5*(dE[0] - y1)*(dE[0] - y1) + 0.5*(dE[1] - y2)*(dE[1] - y2) + 0.5*(dE[2] - y3)*(dE[2] - y3);

		s1 = 0;
		s2 = 0;
		s3 = 0;


		for (int i = 0; i < 36; i++)
		{

			s1 = s1 + tabF[i] * w[0][i];
			s2 = s2 + tabF[i] * w[1][i];
			s3 = s3 + tabF[i] * w[2][i];

		}
		y1 = f(s1);
		y2 = f(s2);
		y3 = f(s3);

		for (int i = 0; i < 36; i++)
		{

			w[0][i] = w[0][i] + ni * beta*(dF[0] - y1)*y1*(1 - y1)*tabF[i];
			w[1][i] = w[1][i] + ni * beta*(dF[1] - y2)*y2*(1 - y2)*tabF[i];
			w[2][i] = w[2][i] + ni * beta*(dF[2] - y3)*y3*(1 - y3)*tabF[i];



		}

		E = E + 0.5*(dF[0] - y1)*(dF[0] - y1) + 0.5*(dF[1] - y2)*(dF[1] - y2) + 0.5*(dF[2] - y3)*(dF[2] - y3);

		s1 = 0;
		s2 = 0;
		s3 = 0;



		for (int i = 0; i < 36; i++)
		{

			s1 = s1 + tabG[i] * w[0][i];
			s2 = s2 + tabG[i] * w[1][i];
			s3 = s3 + tabG[i] * w[2][i];

		}
		y1 = f(s1);
		y2 = f(s2);
		y3 = f(s3);

		for (int i = 0; i < 36; i++)
		{

			w[0][i] = w[0][i] + ni * beta*(dG[0] - y1)*y1*(1 - y1)*tabG[i];
			w[1][i] = w[1][i] + ni * beta*(dG[1] - y2)*y2*(1 - y2)*tabG[i];
			w[2][i] = w[2][i] + ni * beta*(dG[2] - y3)*y3*(1 - y3)*tabG[i];



		}

		E = E + 0.5*(dG[0] - y1)*(dG[0] - y1) + 0.5*(dG[1] - y2)*(dG[1] - y2) + 0.5*(dG[2] - y3)*(dG[2] - y3);

		s1 = 0;
		s2 = 0;
		s3 = 0;


		for (int i = 0; i < 36; i++)
		{

			s1 = s1 + tabH[i] * w[0][i];
			s2 = s2 + tabH[i] * w[1][i];
			s3 = s3 + tabH[i] * w[2][i];

		}
		y1 = f(s1);
		y2 = f(s2);
		y3 = f(s3);

		for (int i = 0; i < 36; i++)
		{

			w[0][i] = w[0][i] + ni * beta*(dH[0] - y1)*y1*(1 - y1)*tabH[i];
			w[1][i] = w[1][i] + ni * beta*(dH[1] - y2)*y2*(1 - y2)*tabH[i];
			w[2][i] = w[2][i] + ni * beta*(dH[2] - y3)*y3*(1 - y3)*tabH[i];



		}

		E = E + 0.5*(dH[0] - y1)*(dH[0] - y1) + 0.5*(dH[1] - y2)*(dH[1] - y2) + 0.5*(dH[2] - y3)*(dH[2] - y3);

		s1 = 0;
		s2 = 0;
		s3 = 0;
		iterator++;
		//cout << endl;
		//cout << iterator << " <-- przebieg funkcji" << endl;
		//cout << endl;

		//blad sumaryczny
	//	E = E + 0.5*(dT - y2)*(dT - y2);

		cout << E << " blad sumaryczny" << endl;


	} while (E > 0.00005);
	cout << E << " blad sumaryczny koncowy" << endl;
	s1 = 0;
	s2 = 0;
	s3 = 0;
	//Podajemy S
	for (int i = 0; i < 36; i++)
	{

		s1 = s1 + tabS[i] * w[0][i];
		s2 = s2 + tabS[i] * w[1][i];
		s3 = s3 + tabS[i] * w[2][i];

	}
	cout << "wyjscie dla S " << f(s1) << " " << f(s2) << " " << f(s3) << endl;
	s1 = 0;
	s2 = 0;
	s3 = 0;
	//Podajemy T
	for (int i = 0; i < 36; i++)
	{

		s1 = s1 + tabT[i] * w[0][i];
		s2 = s2 + tabT[i] * w[1][i];
		s3 = s3 + tabT[i] * w[2][i];

	}
	cout << "wyjscie dla T " << f(s1) << " " << f(s2) << " " << f(s3) << endl;

	s1 = 0;
	s2 = 0;
	s3 = 0;
	//Podajemy Y
	for (int i = 0; i < 36; i++)
	{

		s1 = s1 + tabY[i] * w[0][i];
		s2 = s2 + tabY[i] * w[1][i];
		s3 = s3 + tabY[i] * w[2][i];

	}
	cout << "wyjscie dla Y " << f(s1) << " " << f(s2) << " " << f(s3) << endl;

	s1 = 0;
	s2 = 0;
	s3 = 0;
	//Podajemy X
	for (int i = 0; i < 36; i++)
	{

		s1 = s1 + tabX[i] * w[0][i];
		s2 = s2 + tabX[i] * w[1][i];
		s3 = s3 + tabX[i] * w[2][i];

	}
	cout << "wyjscie dla X " << f(s1) << " " << f(s2) << " " << f(s3) << endl;

	for (int i = 0; i < 36; i++)
	{

		s1 = s1 + tabE[i] * w[0][i];
		s2 = s2 + tabE[i] * w[1][i];
		s3 = s3 + tabE[i] * w[2][i];

	}
	cout << "wyjscie dla E " << f(s1) << " " << f(s2) << " " << f(s3) << endl;

	for (int i = 0; i < 36; i++)
	{

		s1 = s1 + tabF[i] * w[0][i];
		s2 = s2 + tabF[i] * w[1][i];
		s3 = s3 + tabF[i] * w[2][i];

	}
	cout << "wyjscie dla F " << f(s1) << " " << f(s2) << " " << f(s3) << endl;

	for (int i = 0; i < 36; i++)
	{

		s1 = s1 + tabG[i] * w[0][i];
		s2 = s2 + tabG[i] * w[1][i];
		s3 = s3 + tabG[i] * w[2][i];

	}
	cout << "wyjscie dla G " << f(s1) << " " << f(s2) << " " << f(s3) << endl;

	for (int i = 0; i < 36; i++)
	{

		s1 = s1 + tabH[i] * w[0][i];
		s2 = s2 + tabH[i] * w[1][i];
		s3 = s3 + tabH[i] * w[2][i];

	}
	cout << "wyjscie dla H " << f(s1) << " " << f(s2) << " " << f(s3) << endl;

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



// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
