#pragma once
#include<iostream>
#include<fstream>
using namespace std;
class Vector_file
{
	double* p;
	int n;
public:
	void print();
	Vector_file(double* V, int N);
	Vector_file();
	Vector_file(const Vector_file& Vec);
	Vector_file(Vector_file&& Vec);
	~Vector_file();
	double& operator[](int i);
	Vector_file& operator=(Vector_file& v);
	friend Vector_file& operator+(double* M, Vector_file& v1);
	friend istream& operator>>(istream& ON, Vector_file& v1);
	friend ostream& operator<<(ostream& OFF, Vector_file& v1);
	friend ifstream& operator>>(ifstream& ON, Vector_file& v1);
	friend ofstream& operator<<(ofstream& OFF, Vector_file& v1);
};

