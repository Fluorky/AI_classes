// zadania7_zad2.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

// siecineuronowe_zad5.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

// zadania7_zadS.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
// zadania6_zadX.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>

using namespace std;



double f(double suma);
double fprim(double x);
double beta = 0.8;

int main()
{


	double w[3][3] = { {0,0,0},{0,0,0},{0,0,0} };

	//double tab1[4][3] = { {-1,0,0},{-1,1,1},{-1,0,1},{-1,1,0} };
	double tab1[4][3] = { {-1,0,0},{-1,1,1},{-1,0,1},{-1,1,0} };

	double tabZ[4] = { 0,0,0,0 };

	double d1 = 0, d2 = 0, d3 = 1, d4 = 1;

	/*	double w[36] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
		double jeden[36] = { 1,-1,-1,1,-1,-1,1,-1,-1,1,-1,-1,1 };
		double cztery[36] = { 1,1,-1,1,1,1,1,-1,-1,1,-1,-1,1 };

		int d[WIELKOSC_TAB] = { -1,1 };*/

	double ni = 3.0;

	//double w2[WIELKOSC_tabX] = { 0, 0, 0, 0, 0,  0, 0, 0 ,0 ,0, 0, 0, 0 };

	int  iterator = 0;
	double E, s1 = 0, s2 = 0, s3 = 0, Z = 0, y1, y2, y3 = -1;

	//double dS = 1, dT = 0;
	double Dz1 = 0;
	double Dy1 = 0;
	double Dy2 = 0;
	
	do
	{
		s1 = 0;
		s2 = 0;
		s3 = 0;
		y1 = 0;
		y2 = 0;
		E = 0;
	//1
	
				for (int i = 0; i < 3; i++)
				{
					s1 = s1 + tab1[0][i] * w[0][i];
					s2 = s2 + tab1[0][i] * w[1][i];
				}

				y1 = f(s1);
				y2 = f(s2);

					


				s3 = s3 + y1 * w[2][0];
				s3 = s3 + y2 * w[2][1];
				s3 = s3 + y3 * w[2][2];

				tabZ[0] = f(s3);

				w[0][0] = w[0][0] + ni * y1*(1 - y1)*((d1 - tabZ[0])*tabZ[0] * (1 - tabZ[0]))*w[2][0] * tab1[0][1];
				w[0][1] = w[0][1] + ni * y1*(1 - y1)*((d1 - tabZ[0])*tabZ[0] * (1 - tabZ[0]))*w[2][0] * tab1[0][2];
				w[0][2] = w[0][2] - ni * (y1*(1 - y1)*((d1 - tabZ[0])*tabZ[0] * (1 - tabZ[0]))*w[2][0]);

				w[1][0] = w[1][0] + ni * y2*(1 - y2)*((d1 - tabZ[0])*tabZ[0] * (1 - tabZ[0]))*w[2][1] * tab1[0][1];
				w[1][1] = w[1][1] + ni * y2*(1 - y2)*((d1 - tabZ[0])*tabZ[0] * (1 - tabZ[0]))*w[2][1] * tab1[0][2];
				w[1][2] = w[1][2] - ni * (y2*(1 - y2)*((d1 - tabZ[0])*tabZ[0] * (1 - tabZ[0]))*w[2][1]);


				w[2][0] = w[2][0] + ni * ((d1 - tabZ[0])*tabZ[0]*(1 - tabZ[0]))*y1;
				w[2][1] = w[2][1] + ni * ((d1 - tabZ[0])*tabZ[0]*(1 - tabZ[0]))*y2;
				w[2][2] = w[2][2] - ni * ((d1 - tabZ[0])*tabZ[0]*(1 - tabZ[0]));


				E = E + 0.5*(d1 - tabZ[0])*(d1 - tabZ[0]);

				s1 = 0;
				s2 = 0;
				s3 = 0;

			

				s1 = 0;
				s2 = 0;
				s3 = 0;
				y1 = 0;
				y2 = 0;


		
			//2
		
				for (int i = 0; i < 3; i++)
				{
					s1 = s1 + tab1[1][i] * w[0][i];
					s2 = s2 + tab1[1][i] * w[1][i];
				}

				y1 = f(s1);
				y2 = f(s2);

				


				s3 = s3 + y1 * w[2][0];
				s3 = s3 + y2 * w[2][1];
				s3 = s3 + y3 * w[2][2];

				tabZ[1] = f(s3);

				w[0][0] = w[0][0] + ni * y1*(1 - y1)*((d2 - tabZ[1])*tabZ[1] * (1 - tabZ[1]))*w[2][0] * tab1[1][1];
				w[0][1] = w[0][1] + ni * y1*(1 - y1)*((d2 - tabZ[1])*tabZ[1] * (1 - tabZ[1]))*w[2][0] * tab1[1][2];
				w[0][2] = w[0][2] - ni * (y1*(1 - y1)*((d2 - tabZ[1])*tabZ[1] * (1 - tabZ[1]))*w[2][0]);

				w[1][0] = w[1][0] + ni * y2*(1 - y2)*((d2 - tabZ[1])*tabZ[1] * (1 - tabZ[1]))*w[2][1] * tab1[1][1];
				w[1][1] = w[1][1] + ni * y2*(1 - y2)*((d2 - tabZ[1])*tabZ[1] * (1 - tabZ[1]))*w[2][1] * tab1[1][2];
				w[1][2] = w[1][2] - ni * (y2*(1 - y2)*((d2 - tabZ[1])*tabZ[1] * (1 - tabZ[1]))*w[2][1]);

				w[2][0] = w[2][0] + ni * ((d2 - tabZ[1])*tabZ[1]*(1 - tabZ[1]))*y1;
				w[2][1] = w[2][1] + ni * ((d2 - tabZ[1])*tabZ[1]*(1 - tabZ[1]))*y2;
				w[2][2] = w[2][2] - ni * ((d2 - tabZ[1])*tabZ[1]*(1 - tabZ[1]));


				E = E + 0.5*(d2 - tabZ[1])*(d2 - tabZ[1]);
				/*
			
//3
		for (int i = 0; i < 3; i++)
		{
			s1 = s1 + tab1[2][i] * w[0][i];
			s2 = s2 + tab1[2][i] * w[1][i];
		}

		y1 = f(s1);
		y2 = f(s2);

	

		s3 = s3 + y1 * w[2][0];
		s3 = s3 + y2 * w[2][1];
		s3 = s3 + y3 * w[2][2];

		tabZ[2] = f(s3);

		w[0][0] = w[0][0] + ni * y1*(1 - y1)*((d3 - tabZ[2])*tabZ[2] * (1 - tabZ[2]))*w[2][0] * tab1[2][1];
		w[0][1] = w[0][1] + ni * y1*(1 - y1)*((d3 - tabZ[2])*tabZ[2] * (1 - tabZ[2]))*w[2][0] * tab1[2][2];
		w[0][2] = w[0][2] - ni * y1*(1 - y1)*((d3 - tabZ[2])*tabZ[2] * (1 - tabZ[2]))*w[2][0];

		w[1][0] = w[1][0] + ni * y2*(1 - y2)*((d3 - tabZ[2])*tabZ[2] * (1 - tabZ[2]))*w[2][1] * tab1[2][1];
		w[1][1] = w[1][1] + ni * y2*(1 - y2)*((d3 - tabZ[2])*tabZ[2] * (1 - tabZ[2]))*w[2][1] * tab1[2][2];
		w[1][2] = w[1][2] - ni * (y2*(1 - y2)*((d3 - tabZ[2])*tabZ[2] * (1 - tabZ[2]))*w[2][1]);


		w[2][0] = w[2][0] + ni * ((d3 - tabZ[2])*tabZ[2] * (1 - tabZ[2]))*y1;
		w[2][1] = w[2][1] + ni * ((d3 - tabZ[2])*tabZ[2] * (1 - tabZ[2]))*y2;
		w[2][2] = w[2][2] - ni * ((d3 - tabZ[2])*tabZ[2] * (1 - tabZ[2]));


		E = E + 0.5*(d3 - tabZ[2])*(d3 - tabZ[2]);

		s1 = 0;
		s2 = 0;
		s3 = 0;
		y1 = 0;
		y2 = 0;
		//	
		
		//4
		for (int i = 0; i < 3; i++)
		{
			s1 = s1 + tab1[3][i] * w[0][i];
			s2 = s2 + tab1[3][i] * w[1][i];
		}

		y1 = f(s1);
		y2 = f(s2);


		s3 = s3 + y1 * w[2][0];
		s3 = s3 + y2 * w[2][1];
		s3 = s3 + y3 * w[2][2];

		tabZ[3] = f(s3);



		w[0][0] = w[0][0] + ni * y1*(1 - y1)*((d4 - tabZ[3])*tabZ[3] * (1 - tabZ[3]))*w[2][0] * tab1[3][1];
		w[0][1] = w[0][1] + ni * y1*(1 - y1)*((d4 - tabZ[3])*tabZ[3] * (1 - tabZ[3]))*w[2][0] * tab1[3][2];
		w[0][2] = w[0][2] - ni * y1*(1 - y1)*((d4 - tabZ[3])*tabZ[3] * (1 - tabZ[3]))*w[2][0];

		w[1][0] = w[1][0] + ni * y2*(1 - y2)*((d4 - tabZ[3])*tabZ[3] * (1 - tabZ[3]))*w[2][1] * tab1[3][1];
		w[1][1] = w[1][1] + ni * y2*(1 - y2)*((d4 - tabZ[3])*tabZ[3] * (1 - tabZ[3]))*w[2][1] * tab1[3][2];
		w[1][2] = w[1][2] - ni * y2*(1 - y2)*((d4 - tabZ[3])*tabZ[3] * (1 - tabZ[3]))*w[2][1];

		w[2][0] = w[2][0] + ni * ((d4 - tabZ[3])*tabZ[3] * (1 - tabZ[3]))*y1;
		w[2][1] = w[2][1] + ni * ((d4 - tabZ[3])*tabZ[3] * (1 - tabZ[3]))*y2;
		w[2][2] = w[2][2] - ni * ((d4 - tabZ[3])*tabZ[3] * (1 - tabZ[3]));


		E = E + 0.5*(d4 - tabZ[3])*(d4 - tabZ[3]);
		s1 = 0;
		s2 = 0;
		s3 = 0;
		y1 = 0;
		y2 = 0;
		iterator++;
		//cout << endl;
		//cout << iterator << " <-- przebieg funkcji" << endl;
		//cout << endl;
		
		//blad sumaryczny
	//	E = E + 0.5*(dT - y2)*(dT - y2);
	
		cout << E << " blad sumaryczny" << endl;
		*/


	} while (E > 0.0005);
	
	


cout << E << " blad sumaryczny koncowy" << endl;
s1 = 0;
s2 = 0;
Z = 0;
//Podajemy S
for (int i = 0; i < 3; i++)
{

	s1 = s1 + tab1[0][i] * w[0][i];
	s2 = s2 + tab1[0][i] * w[1][i];

}

y1 = f(s1);
y2 = f(s2);
Z = Z + y1 * w[2][0];
Z = Z + y2 * w[2][1];
Z = Z + y3 * w[2][2];

cout << "wyjscie dla [0,0] " << f(Z) << " " << f(tabZ[0]) << endl;
s1 = 0;
s2 = 0;
Z = 0;

for (int i = 0; i < 3; i++)
{

	s1 = s1 + tab1[1][i] * w[0][i];
	s2 = s2 + tab1[1][i] * w[1][i];

}
y1 = f(s1);
y2 = f(s2);

Z = Z + y1 * w[2][0];
Z = Z + y2 * w[2][1];
Z = Z + y3 * w[2][2];

cout << "wyjscie dla [1,1] " << f(Z) << " " << f(tabZ[1]) << endl;
	do
	{
		s1 = 0;

		s2 = 0;
		s3 = 0;
		y1 = 0;
		y2 = 0;
		E = 0;
	
				
//3
		for (int i = 0; i < 3; i++)
		{
			s1 = s1 + tab1[2][i] * w[0][i];
			s2 = s2 + tab1[2][i] * w[1][i];
		}

		y1 = f(s1);
		y2 = f(s2);



		s3 = s3 + y1 * w[2][0];
		s3 = s3 + y2 * w[2][1];
		s3 = s3 + y3 * w[2][2];

		tabZ[2] = f(s3);

		w[0][0] = w[0][0] + ni * y1*(1 - y1)*((d3 - tabZ[2])*tabZ[2] * (1 - tabZ[2]))*w[2][0] * tab1[2][1];
		w[0][1] = w[0][1] + ni * y1*(1 - y1)*((d3 - tabZ[2])*tabZ[2] * (1 - tabZ[2]))*w[2][0] * tab1[2][2];
		w[0][2] = w[0][2] - ni * y1*(1 - y1)*((d3 - tabZ[2])*tabZ[2] * (1 - tabZ[2]))*w[2][0];

		w[1][0] = w[1][0] + ni * y2*(1 - y2)*((d3 - tabZ[2])*tabZ[2] * (1 - tabZ[2]))*w[2][1] * tab1[2][1];
		w[1][1] = w[1][1] + ni * y2*(1 - y2)*((d3 - tabZ[2])*tabZ[2] * (1 - tabZ[2]))*w[2][1] * tab1[2][2];
		w[1][2] = w[1][2] - ni * (y2*(1 - y2)*((d3 - tabZ[2])*tabZ[2] * (1 - tabZ[2]))*w[2][1]);


		w[2][0] = w[2][0] + ni * ((d3 - tabZ[2])*tabZ[2] * (1 - tabZ[2]))*y1;
		w[2][1] = w[2][1] + ni * ((d3 - tabZ[2])*tabZ[2] * (1 - tabZ[2]))*y2;
		w[2][2] = w[2][2] - ni * ((d3 - tabZ[2])*tabZ[2] * (1 - tabZ[2]));


		E = E + 0.5*(d3 - tabZ[2])*(d3 - tabZ[2]);

		s1 = 0;
		s2 = 0;
		s3 = 0;
		y1 = 0;
		y2 = 0;
		//


	//4
	for (int i = 0; i < 3; i++)
	{
		s1 = s1 + tab1[3][i] * w[0][i];
		s2 = s2 + tab1[3][i] * w[1][i];
	}

	y1 = f(s1);
	y2 = f(s2);


	s3 = s3 + y1 * w[2][0];
	s3 = s3 + y2 * w[2][1];
	s3 = s3 + y3 * w[2][2];

	tabZ[3] = f(s3);



	w[0][0] = w[0][0] + ni * y1*(1 - y1)*((d4 - tabZ[3])*tabZ[3] * (1 - tabZ[3]))*w[2][0] * tab1[3][1];
	w[0][1] = w[0][1] + ni * y1*(1 - y1)*((d4 - tabZ[3])*tabZ[3] * (1 - tabZ[3]))*w[2][0] * tab1[3][2];
	w[0][2] = w[0][2] - ni * y1*(1 - y1)*((d4 - tabZ[3])*tabZ[3] * (1 - tabZ[3]))*w[2][0];

	w[1][0] = w[1][0] + ni * y2*(1 - y2)*((d4 - tabZ[3])*tabZ[3] * (1 - tabZ[3]))*w[2][1] * tab1[3][1];
	w[1][1] = w[1][1] + ni * y2*(1 - y2)*((d4 - tabZ[3])*tabZ[3] * (1 - tabZ[3]))*w[2][1] * tab1[3][2];
	w[1][2] = w[1][2] - ni * y2*(1 - y2)*((d4 - tabZ[3])*tabZ[3] * (1 - tabZ[3]))*w[2][1];

	w[2][0] = w[2][0] + ni * ((d4 - tabZ[3])*tabZ[3] * (1 - tabZ[3]))*y1;
	w[2][1] = w[2][1] + ni * ((d4 - tabZ[3])*tabZ[3] * (1 - tabZ[3]))*y2;
	w[2][2] = w[2][2] - ni * ((d4 - tabZ[3])*tabZ[3] * (1 - tabZ[3]));


	E = E + 0.5*(d4 - tabZ[3])*(d4 - tabZ[3]);
	s1 = 0;
	s2 = 0;
	s3 = 0;
	y1 = 0;
	y2 = 0;
	iterator++;
	//cout << endl;
	//cout << iterator << " <-- przebieg funkcji" << endl;
	//cout << endl;

	
	cout << E << " blad sumaryczny 2" << endl;



	} while (E > 0.0005);
	

	s1 = 0;
	s2 = 0;
	Z = 0;

	for (int i = 0; i < 3; i++)
	{

		s1 = s1 + tab1[2][i] * w[0][i];
		s2 = s2 + tab1[2][i] * w[1][i];

	}
	y1 = f(s1);
	y2 = f(s2);

	Z = Z + y1 * w[2][0];
	Z = Z + y2 * w[2][1];
	Z = Z + y3 * w[2][2];

	cout << "wyjscie dla [0,1] " << f(Z) << " " << f(tabZ[2]) << endl;


	s1 = 0;
	s2 = 0;
	Z = 0;

	for (int i = 0; i < 3; i++)
	{

		s1 = s1 + tab1[3][i] * w[0][i];
		s2 = s2 + tab1[3][i] * w[1][i];

	}
	y1 = f(s1);
	y2 = f(s2);

	Z = Z + y1 * w[2][0];
	Z = Z + y2 * w[2][1];
	Z = Z + y3 * w[2][2];

	cout << "wyjscie dla [1,0] " << f(Z) << " " << f(tabZ[3]) << endl;

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



