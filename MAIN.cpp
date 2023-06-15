#include <iostream>
#include <fstream>
#include <Windows.h>
#include <math.h>
#include <conio.h>
using namespace std;
void main()
{
	int a,b,c, A,B,C, x,y, n,*nx,*ny, i;
	//float x,y;
	float accuracy = 1, MaxAccuracy = 0;
	bool check;
	while(1)
	{
		system("cls");
		//--------Input--------
		cout << "Number of points: ";
		cin >> n;
		nx = new int[n];
		ny = new int[n];
		for(i = 0; i < n; i++){
			cout << "X,Y: ";
			cin >> nx[i];
			cin >> ny[i];
		}
		cout << "-------------------" << endl;
		//--------Train--------
		for(a = -10; a < 20; a++){
			for(b = 0; b < 20; b++){
				for(c = 0; c < 50; c++){
					accuracy = 1;
					float error = (float)1/n;
					//cout << accuracy << " " << error << " " << accuracy-error << endl;
					//_getch();
					for(i = 0; i < n; i++){
						if(ny[i] != (a*nx[i]*nx[i])+b*nx[i]+c)
							accuracy -= error;
					}
					if(accuracy > MaxAccuracy)
						A = a, B = b, C = c, MaxAccuracy = accuracy;
					if(accuracy == 1)
						break;
				}
				if(accuracy == 1)
					break;
			}
			if(accuracy == 1)
				break;
		}
		//Visualisation
		cout << "y = ";
		if(A != 0){
			if(A == -1)
				cout << "-";
			else if(abs(A) != 1)
				cout << A;
			cout << "x^2";
		}
		if(A != 0 && B != 0)
			cout << " + ";
		if(B != 0){
			if(B == -1)
				cout << "-";
			else if(abs(B) != 1)
				cout << B;
			cout << "x";
		}
		if((A != 0 || B != 0) && C != 0)
			cout << " + ";
		if(C != 0)
			cout << C;
		cout << " [Accuracy: " << MaxAccuracy*100 << "%]";
		cout << endl << "-------------------" << endl;
		char screen[12][16] = {
		"       |       ",
		"       |       ",
		"       |       ",
		"       |       ",
		"---------------",
		"       |       ",
		"       |       ",
		"       |       ",
		"       |       ",};
		for(x = -4; x < 5; x++){
			y = A*x*x+B*x+C;
			if((y-4)*-1 >= 0 && x+7 >= 0)
				screen[(y-4)*-1][(x+7)] = '.';
		}
		for(int j = 0; j < 12; j++){
			for(i = 0; i < 16; i++)
				cout << screen[j][i];
			cout << endl;
		}
		system("pause");
	}
}