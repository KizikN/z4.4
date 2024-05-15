#include"classmet.h"
#include<iostream>
#define _USE_MATH_DEFINES
#include<math.h>
using namespace std;

Im_number& Im_number::operator=(Im_number& L)
{
	ABS = L.Get_ABS();
	angle = L.Get_angle();
	return *this;
}

Im_number& Im_number::operator=(Im_number&& L)
{
	ABS = L.Get_ABS();
	return *this;
}

Im_number::Im_number(Im_number& L)
{
	ABS = L.Get_ABS();
	angle = L.Get_angle();
}

Im_number::Im_number(Im_number&& L)
{
	ABS = L.Get_ABS();
}

void Im_number::operator<<(Im_number L)
{
	cout << "ABS: " << Get_ABS();
	cout << "Angel: " << Get_angle();
}

void Im_number::operator<<(bool L)
{
	if(L)
		cout << "ABS: " << Get_ABS();
	else
		cout << "Angel: " << Get_angle();
}

void Im_number::operator>>(Im_number L)
{
	cout << "ABS = ";
	cin >> ABS;
	cout << "Angel = ";
	cin >> angle;
}

void Im_number::operator>>(bool L)
{
	if (L)
	{
		cout << "ABS = ";
		cin >> ABS;
	}
	else
	{
		cout << "Angel = ";
		cin >> angle;
	}
}

void Im_number::Plus(Im_number A, Im_number l1, Im_number l2)
{
	double x = l1.Get_ABS() * cos(l1.Get_angle()) + l2.Get_ABS() * cos(l2.Get_angle());
	double y = l1.Get_ABS() * sin(l1.Get_angle()) + l2.Get_ABS() * sin(l2.Get_angle());
	A.New_angle(atan(y / x));
	A.New_ABS(sqrt(y * y + x * x));
}

void Im_number::Plus(Im_number A, Im_number l)
{
	double x = l.Get_ABS() * cos(l.Get_angle()) + A.Get_ABS() * cos(A.Get_angle());
	double y = l.Get_ABS() * sin(l.Get_angle()) + A.Get_ABS() * sin(A.Get_angle());
	A.New_angle(atan(y / x));
	A.New_ABS(sqrt(y * y + x * x));
}

void Im_number::Minus(Im_number A, Im_number l1, Im_number l2)
{
	double x = l1.Get_ABS() * cos(l1.Get_angle()) - l2.Get_ABS() * cos(l2.Get_angle());
	double y = l1.Get_ABS() * sin(l1.Get_angle()) - l2.Get_ABS() * sin(l2.Get_angle());
	A.New_angle(atan(y / x));
	A.New_ABS(sqrt(y * y + x * x));
}

void Im_number::Minus(Im_number A, Im_number l)
{
	double x = A.Get_ABS() * cos(A.Get_angle()) - l.Get_ABS() * cos(l.Get_angle());
	double y = A.Get_ABS() * sin(A.Get_angle()) - l.Get_ABS() * sin(l.Get_angle());
	A.New_angle(atan(y / x));
	A.New_ABS(sqrt(y * y + x * x));
}

void Im_number::Product(Im_number A, Im_number l1, Im_number l2)
{
	double a = l1.Get_ABS() * cos(l1.Get_angle()), b = l1.Get_ABS() * sin(l1.Get_angle()), c = l2.Get_ABS() * cos(l2.Get_angle()), d = l2.Get_ABS() * sin(l2.Get_angle());
	double x = a * c - b * d;
	double y = a * d + b * c;
	A.New_angle(atan(y / x));
	A.New_ABS(sqrt(y * y + x * x));
}

void Im_number::Product(Im_number A, Im_number l)
{
	double a = A.Get_ABS() * cos(A.Get_angle()), b = A.Get_ABS() * sin(A.Get_angle()), c = l.Get_ABS() * cos(l.Get_angle()), d = l.Get_ABS() * sin(l.Get_angle());
	double x = a * c - b * d;
	double y = a * d + b * c;
	A.New_angle(atan(y / x));
	A.New_ABS(sqrt(y * y + x * x));
}

void Im_number::Division(Im_number A, Im_number l1, Im_number l2)
{
	double a = l1.Get_ABS() * cos(l1.Get_angle()), b = l1.Get_ABS() * sin(l1.Get_angle()), c = l2.Get_ABS() * cos(l2.Get_angle()), d = l2.Get_ABS() * sin(l2.Get_angle());
	double x = (a * c + b * d) / (c * c + d * d);
	double y = (-a * d + b * c) / (c * c + d * d);
	A.New_angle(atan(y / x));
	A.New_ABS(sqrt(y * y + x * x));
}

void Im_number::Division(Im_number A, Im_number l)
{
	double a = A.Get_ABS() * cos(A.Get_angle()), b = A.Get_ABS() * sin(A.Get_angle()), c = l.Get_ABS() * cos(l.Get_angle()), d = l.Get_ABS() * sin(l.Get_angle());
	double x = (a * c + b * d) / (c * c + d * d);
	double y = (-a * d + b * c) / (c * c + d * d);
	A.New_angle(atan(y / x));
	A.New_ABS(sqrt(y * y + x * x));
}

void Im_number::Pov(Im_number A, int n)
{
		if (n >= 0)
		{
			double r = A.Get_ABS(), a = 1;
			A.New_angle(A.Get_angle() * n);
			for (int i = 0; i < n; i++)
				a *= r;
			A.New_ABS(a);
		}
		else
		{
			A.New_angle(A.Get_angle() * n);
			double r = A.Get_ABS(), a = 1;
			for (int i = 0; i > n; i--)
				a /= r;
			A.New_ABS(a);
		}
}

void Im_number::Pov(Im_number A)
{
		double r = A.Get_ABS(), a = 1;
		A.New_angle(A.Get_angle() * 2);
		for (int i = 0; i < 2; i++)
			a *= r;
		A.New_ABS(a);
}

void Im_number::Radical(Im_number A)
{
	A.New_ABS(sqrt(A.Get_ABS()));
	double an = A.Get_angle() / 2;
	cout << "Choose an angle:\n 0 - " << an << "\n1 - " << an + M_PI;
	bool ch;
	cin >> ch;
	if (ch)
		A.New_angle(an);
	else
		A.New_angle(an + M_PI);
}

void Im_number::Radical(Im_number A, bool ch)
{
	A.New_ABS(sqrt(A.Get_ABS()));
	double an = A.Get_angle() / 2;
	cin >> ch;
	if (ch)
		A.New_angle(an);
	else
		A.New_angle(an + M_PI);
}