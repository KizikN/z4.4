#pragma once
#include<iostream>
using namespace std;

class Im_number
{
	double ABS = 0;
	double angle = 0;
public:
	Im_number() {}
	Im_number(double a, double b) { ABS = a; angle = b; }
	Im_number(Im_number&);
	Im_number(Im_number&&);
	~Im_number() { ABS = 0; angle = 0; }
	void New_ABS(double a) { ABS = a; }
	void New_angle(double a) { angle = a; }
	Im_number& operator = (Im_number&);
	Im_number& operator = (Im_number&&);
	double Get_ABS() { return ABS; }
	double Get_angle() { return angle; }

	friend ostream& operator <<(ostream& os, Im_number& L);
	friend istream& operator >>(istream& is, Im_number& L);
	
	void operator +=(Im_number);
	
	void operator -=(Im_number);
	
	void operator *=(Im_number);
	
	void operator /=(Im_number);

	Im_number* operator ^(int);
	
	Im_number* operator!();
};