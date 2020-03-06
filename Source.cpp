#include<iostream>
#include<fstream>
#include"Vector_file.h"
using namespace std;
int main()
{
	ifstream on;
	on.open("input.txt");
	int n;
	on >> n;
	double* V1 = new double[n];
	for (int i = 0; i < n; i++)
		on >> V1[i];
	cout << "V1:";
	for (int i = 0; i < n; i++)
		cout << V1[i] << " ";
	Vector_file V2;
	on >> V2;
	on.close();
	cout << "V2:";
	V2.print();
	Vector_file V3 = V1 + V2;
	ofstream off;
	off.open("output.txt", fstream::out);
	off << V3;
	off.close();
	cout << "V3:";
	V3.print();
	system("pause");
	return 0;
}
