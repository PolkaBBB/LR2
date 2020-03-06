#include "Vector_file.h"
#include<stdio.h>
	void Vector_file::print()
	{
		for (int i = 0; i < n; i++)
			cout << p[i] << " ";
		cout << endl;
	}
	Vector_file::Vector_file (double* V, int N)
	{
		n = N;
		p = new double[N];
		for (int i = 0; i < N; i++)
			p[i] = V[i];
	}
	Vector_file::Vector_file()
	{
		p = nullptr;
		n = 0;
	}
	Vector_file::Vector_file(const Vector_file& Vec)
	{
		n = Vec.n;
		p = new double[n];
		for (int i = 0; i < n; i++)
			p[i] = Vec.p[i];
	}
	Vector_file::Vector_file(Vector_file&& Vec)
		:p(Vec.p), n(Vec.n)
	{
		Vec.p = nullptr;
		Vec.n = 0;
	}
	Vector_file::~Vector_file()
	{
		if (p != nullptr)
			delete[]p;
	}
	double& Vector_file::operator[](int i)
	{
		return p[i];
	}
	Vector_file& Vector_file::operator=(Vector_file& v)
	{
		n = v.n;
		if (p != nullptr)delete[]p;
		p = new double[n];
		for (int i = 0; i < n; i++)
			return*this;
	}
Vector_file&operator+(double* M, Vector_file& v1)
{
	double* p = new double[v1.n];
	for (int i = 0; i < v1.n; i++)
		p[i] = M[i] + v1.p[i];
	Vector_file* pv1 = new Vector_file(p, v1.n);
	delete[]p;
	return *pv1;

}
std::istream&operator>>(istream& ON, Vector_file& v1)
{
	int n;
	ON >> n;
	v1.n = n;
	v1.p = new double[n];
	for (int i = 0; i < n; i++)
		ON >> v1.p[i];
	return ON;
}
std::ostream& operator<<(ostream& OFF, Vector_file& v1)
{
	for (int i = 0; i < v1.n; i++)
		OFF << v1.p[i] << " ";
	return OFF;
}
std::ifstream& operator>>(ifstream& ON, Vector_file& v1)
{
	ON >> v1.n;
	v1.p = new double[v1.n];
	for (int i = 0; i < v1.n; i++)
		ON >> v1.p[i];
	return ON;
}
std::ofstream& operator<<(ofstream& OFF, Vector_file& v1)
{
	for (int i = 0; i < v1.n; i++)
		OFF << v1.p[i] << " ";
	return OFF;
}