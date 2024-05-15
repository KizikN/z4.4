#pragma once

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
	void operator << (Im_number);
	void operator << (bool);
	void operator >> (Im_number);
	void operator >> (bool);
	double Get_ABS() { return ABS; }
	double Get_angle() { return angle; }
	void Plus(Im_number, Im_number, Im_number);
	void Plus(Im_number, Im_number);
	void Minus(Im_number, Im_number, Im_number);
	void Minus(Im_number, Im_number);
	void Product(Im_number, Im_number, Im_number);
	void Product(Im_number, Im_number);
	void Division(Im_number, Im_number, Im_number);
	void Division(Im_number, Im_number);
	void Pov(Im_number, int);
	void Pov(Im_number);
	void Radical(Im_number);
	void Radical(Im_number, bool);
};