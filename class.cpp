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

ostream& operator <<(std::ostream& os, Im_number& L)
{
	cout << "ABS: " << L.Get_ABS();
	cout << "\nAngel: " << L.Get_angle() << "\n";
	return os;
}

istream& operator >>(std::istream& os, Im_number& L)
{
	double a, b;
	cout << "ABS = ";
	cin >> a;
	cout << "Angel = ";
	cin >> b;
	L.New_ABS(a);
	L.New_angle(b);
	return os;
}


void Im_number::operator+=(Im_number A)
{
	double x = this->Get_ABS() * cos(this->Get_angle()) + A.Get_ABS() * cos(A.Get_angle());
	double y = this->Get_ABS() * sin(this->Get_angle()) + A.Get_ABS() * sin(A.Get_angle());
	A.New_angle(atan(y / x));
	A.New_ABS(sqrt(y * y + x * x));
}

void Im_number::operator-=(Im_number A)
{
	double x = A.Get_ABS() * cos(A.Get_angle()) - this->Get_ABS() * cos(this->Get_angle());
	double y = A.Get_ABS() * sin(A.Get_angle()) - this->Get_ABS() * sin(this->Get_angle());
	A.New_angle(atan(y / x));
	A.New_ABS(sqrt(y * y + x * x));
}

void Im_number::operator *=(Im_number A)
{
	double a = A.Get_ABS() * cos(A.Get_angle()), b = A.Get_ABS() * sin(A.Get_angle()), c = this->Get_ABS() * cos(this->Get_angle()), d = this->Get_ABS() * sin(this->Get_angle());
	double x = a * c - b * d;
	double y = a * d + b * c;
	A.New_angle(atan(y / x));
	A.New_ABS(sqrt(y * y + x * x));
}

void Im_number::operator /=(Im_number A)
{
	double a = A.Get_ABS() * cos(A.Get_angle()), b = A.Get_ABS() * sin(A.Get_angle()), c = this->Get_ABS() * cos(this->Get_angle()), d = this->Get_ABS() * sin(this->Get_angle());
	double x = (a * c + b * d) / (c * c + d * d);
	double y = (-a * d + b * c) / (c * c + d * d);
	A.New_angle(atan(y / x));
	A.New_ABS(sqrt(y * y + x * x));
}

Im_number* Im_number::operator ^(int n)
{
		if (n >= 0)
		{
			double r = this->Get_ABS(), a = 1;
			this->New_angle(this->Get_angle() * n);
			for (int i = 0; i < n; i++)
				a *= r;
			this->New_ABS(a);
		}
		else
		{
			this->New_angle(this->Get_angle() * n);
			double r = this->Get_ABS(), a = 1;
			for (int i = 0; i > n; i--)
				a /= r;
			this->New_ABS(a);
		}
		return this;
}

Im_number* Im_number::operator !()
{
	this->New_ABS(sqrt(this->Get_ABS()));
	double an = this->Get_angle() / 2;
	cout << "Choose an angle:\n 0 - " << an << "\n1 - " << an + M_PI << endl;
	bool ch;
	cin >> ch;
	if (!ch)
		this->New_angle(an);
	else
		this->New_angle(an + M_PI);
	return this;
}