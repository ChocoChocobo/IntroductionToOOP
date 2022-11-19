#include "stdafx.h"


class Fraction
{
	int numerator;
	int denominator;
public:
	const int get_numerator()const
	{
		return numerator;
	}
	const int get_denominator()const
	{
		return denominator;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)
			denominator = 1;
		this->denominator = denominator;
	}

	Fraction()
	{
		this->numerator = 0;
		this->denominator = 1;
	}
	Fraction(const Fraction& other)
	{
		this->numerator = other.numerator;
		this->denominator = other.denominator;
	}
	Fraction(int numerator, int denominator)
	{
		this->numerator = numerator;
		set_denominator(denominator);
	}
	Fraction& compare(const Fraction& other)
	{
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		return *this;
	}
	~Fraction()
	{

	}

	int Sum(Fraction other)
	{
		int sum_numerator = this->numerator * other.denominator + other.numerator * this->denominator;
		int sum_denominator = this->denominator * other.denominator;
		cout << "Your sum of two fractions is: " << sum_numerator << "/" << sum_denominator << endl;
		return 0;
	}
	int Sub(Fraction other)
	{
		int sub_numerator = this->numerator * other.denominator - other.numerator * this->denominator;
		int sub_denominator = this->denominator * other.denominator;
		cout << "Your substraction of two fractions is: " << sub_numerator << "/" << sub_denominator << endl;
		return 0;
	}
	int Div(Fraction other)
	{
		int div_numerator = this->numerator * other.denominator;
		int div_denominator = this->denominator * other.numerator;
		cout << "Your division of two fractions is: " << div_numerator << "/" << div_denominator << endl;
		return 0;
	}
	int Multi(Fraction other)
	{
		int multi_numerator = this->numerator * other.numerator;
		int multi_denominator = this->denominator * other.denominator;
		cout << "Your multiplication of two fractions is: " << multi_numerator << "/" << multi_denominator << endl;
		return 0;
	}
	void Print()
	{
		cout << numerator << "/" << denominator << endl;	
	}
};

void main()
{
	Fraction One(8,3);
	cout << "Fraction one: ";
	One.Print();

	Fraction Two(9,7);
	cout << "Fraction two: ";
	Two.Print();

	One.Sum(Two);
	One.Sub(Two);
	One.Div(Two);
	One.Multi(Two);

}