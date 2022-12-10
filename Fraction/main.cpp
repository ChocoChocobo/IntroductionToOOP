#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define WIDTH	27
#define delimiter "\n____________________________________\n"

class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(const Fraction& left, const Fraction& right);
Fraction operator+(Fraction left, Fraction right);
Fraction operator-(Fraction left, Fraction right);

class Fraction
{
	int integer;
	int numerator;
	int denominator;
public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}

	//				Constructors:
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout.width(WIDTH);
		cout << std::left << "DefaultConstructor:" << this << endl;
	}
	explicit Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout.width(WIDTH);
		cout << std::left << "SingleArgumentConstructor:" << this << endl;
	}
	Fraction(double decimal)
	{
		int fake_integer;
		fake_integer = decimal;
		decimal -= fake_integer;
		this->integer = fake_integer;
		this->numerator = decimal * 100;
		this->denominator = 100;
		Reduce();

	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);
		cout.width(WIDTH);
		cout << std::left << "Constructor:" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		set_denominator(denominator);
		cout.width(WIDTH);
		cout << std::left << "Constructor:" << this << endl;
	}
	~Fraction()
	{
		cout.width(WIDTH);
		cout << std::left << "Destructor:" << this << endl;
	}

	//				Operators:
	Fraction& operator()(int integer, int numerator, int denominator)
	{
		set_integer(integer);
		set_numerator(numerator);
		set_denominator(denominator);
		return *this;
	}
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout.width(WIDTH);
		cout << std::left << "CopyAssignment:" << this << endl;
		return *this;
	}
	//				+=, -=, *=, /=
	Fraction& operator+=(const Fraction& other)
	{
		// a = a + b;		a += b;
		return *this = *this + other;
	}
	Fraction& operator-=(const Fraction& other)
	{
		// a = a - b;		a -= b;
		return *this = *this - other;
	}
	Fraction& operator*=(const Fraction& other)
	{
		// a = a - b;		a -= b;
		return *this = *this * other;
	}
	Fraction& operator/=(const Fraction& other)
	{
		// a = a - b;		a -= b;
		return *this = *this / other;
	}

	//					Increment/Deecrement
	Fraction& operator++()	//Preifx increment
	{
		integer++;
		return *this;
	}
	Fraction operator++(int)//Postfix increment
	{
		Fraction old = *this;
		integer++;
		return old;
	}
	Fraction& operator--()	//Prefix decrement
	{
		integer--;
		return *this;
	}
	Fraction operator--(int)//Postfix decrement
	{
		Fraction old = *this;
		integer--;
		return old;
	}
	//				Type-cast operators:
	explicit operator int()const
	{
		return integer;
	}
	explicit operator double()const
	{
		return integer + (double)numerator / denominator;
	}

	//				Methods:
	Fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction& to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction inverted()const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		swap(inverted.numerator, inverted.denominator);
		return inverted;
	}
	Fraction& Reduce() //Euclidian algorithm
	{
		if (numerator == 0)
			return *this;
		int big_one; //Biggest number of numerator/denominator
		int small_one; //Smallest number of numerator/denominator
		int rest; //%
		if (numerator > denominator)
			big_one = numerator, small_one = denominator;
		else big_one = denominator, small_one = numerator;
		do
		{
			rest = big_one % small_one;
			big_one = small_one;
			small_one = rest;
		} while (rest);
		int GCD = big_one;	//Greatest common divisor
		numerator /= GCD;
		denominator /= GCD;
		return *this;
	}

	void print()const
	{
		/*
				1/2
				5
				5 0/2
		*/
		if (integer)cout << integer << " ";
		if (numerator)
		{
			cout << numerator << "/" << denominator;
		}
		else if (integer == 0)cout << 0;
		cout << endl;
	}
};

Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*Fraction res;
	res.set_numerator(left.get_numerator()*right.get_numerator());
	res.set_denominator(left.get_denominator()*right.get_denominator());*/
	/*Fraction res
	(
		left.get_numerator()*right.get_numerator(),
		left.get_denominator()*right.get_denominator()
	);
	res.to_proper();
	return res;*/
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().Reduce();
}
Fraction operator/(const Fraction& left, const Fraction& right)
{
	/*left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator()*right.get_denominator(),
		right.get_numerator()*left.get_denominator()
	).to_proper();*/
	return left * right.inverted();
}
Fraction operator+(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator() * right.get_denominator() + right.get_numerator() * left.get_denominator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().Reduce();
}
Fraction operator-(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator() * right.get_denominator() - right.get_numerator() * left.get_denominator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().Reduce();
}
//				==, !=, >, <, >=, <=
bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator() == right.get_numerator() * left.get_denominator();
}
bool operator!=(Fraction left, Fraction right)
{
	return !(left == right);
}
bool operator > (Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator() > right.get_numerator() * left.get_denominator();
}
bool operator < (Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator() < right.get_numerator() * left.get_denominator();
}
bool operator >=(Fraction left, Fraction right)
{
	return left > right || left == right;
}
bool operator <= (Fraction left, Fraction right)
{
	return !(left > right);
}

std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
	if (obj.get_integer())os << obj.get_integer() << " ";
	if (obj.get_numerator())
	{
		os << obj.get_numerator() << "/" << obj.get_denominator();
	}
	else if(obj.get_integer() == 0) os << 0;
	return os;
}
istream& operator>>(istream& is, Fraction& obj)
{
	
	//int integer, numerator, denominator;
	//is >> integer >> numerator >> denominator;
	/*obj.set_integer(integer);
	obj.set_numerator(numerator);
	obj.set_denominator(denominator);*/
	//obj(integer, numerator, denominator);

	int number[3] = {}; //This array keeps numbers from the string

	const int SIZE = 256;
	char buffer[SIZE] = {};
	char delimiters[] = " /()";
	//is >> buffer;		//cin keeps data until it hits 'space'
						//In order to keep the line with 'space' we use cin.getline() 
	is.getline(buffer, SIZE);
	int n = 0;
	//Функция strtok() делит строку на подстроки, используя разделители, где каждый разделитель заменяется нулём
	for (char* pch = strtok(buffer, delimiters); pch; pch = strtok(NULL, delimiters))
	{
		number[n++] = atoi(pch); //Функция atoi() конвертирует тип string в int. Принимает строку, если строка 
								//является числом, то возвращает int-овый эквивалент этого числа
	}
	/*for (int i = 0; i < n; i++)
	{
		cout << number[i] << "\t";
	}
	cout << endl;*/

	obj = Fraction();
	switch (n)
	{
	case 1: 
		obj.set_integer(number[0]); break;
	case 2: 
		obj.set_numerator(number[0]); 
		obj.set_denominator(number[1]); break;
	case 3:
		obj.set_integer(number[0]);
		obj.set_numerator(number[1]);
		obj.set_denominator(number[2]); break;
	}
	return is;
}

//#define CONSTRUCTORS_CHECK
//#define ARITHMETICAL_OPERATORS_CHECK
//#define INCREMENT_CHECK
//#define ISTREAM_OPERATOR_CHECK
//#define TYPE_CONVERSION_BASICS
//#define CONVERSION_FROM_OTHER_TO_CLASS
//#define CONVERSION_FROM_CLASS_TO_OTHER

void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	Fraction A;		//Default constructor
	A.print();

	Fraction B = 5;	//Single-argument constructor
	B.print();

	Fraction C(1, 2);
	C.print();

	Fraction D(2, 3, 4);
	D.print();

	D.to_improper();
	D.print();

	D.to_proper();
	D.print();
#endif // CONSTRUCTORS_CHECK

#ifdef ARITHMETICAL_OPERATORS_CHECK

	Fraction A(2, 3, 4);
	Fraction B(3, 4, 5);
	Fraction C = A / B;
	C.print();

	A *= B;
	A.print();
	A /= B;
	A.print();
#endif // ARITHMETICAL_OPERATORS_CHECK

#ifdef INCREMENT_CHECK
	for (double i = .0325; i < 10; i++)cout << i << "\t"; cout << endl;
	for (Fraction i(1, 2); i.get_integer() < 10; i++)
	{
		i.print();
	}
#endif // INCREMENT_CHECK

#ifdef ISTREAM_OPERATOR_CHECK
	/*Fraction A(2, 3, 5);
Fraction B(3, 4, 5);
cout << A << endl;*/
	Fraction A(50, 75, 80);
	cout << "Enter a simple fraction: ";
	cin >> A;
	cout << delimiter << endl;
	cout << A;
	cout << delimiter << endl;
#endif // ISTREAM_OPERATOR_CHECK

#ifdef TYPE_CONVERSION_BASICS
	cout << (double)7 / 2 << endl;

	int a = 2;		//No conversions
	double b = 3;	//Conversion from less to more
	int c = b;		//From more to less without data loss
	int d = 4.6;	//From more to less with data loss
	cout << d << endl;
#endif // TYPE_CONVERSION_BASICS

#ifdef CONVERSION_FROM_OTHER_TO_CLASS
	int a = 2;		//No conversions
	Fraction A = 5;	//Conversion from 'int' to 'Fraction'
					//Single-Argument Constructor
	cout << A << endl;
	cout << delimiter << endl;

	Fraction B;
	B = 8;			//Conversion from 'int' to 'Fraction'
					//Assignment operator
	cout << B << endl;
#endif // CONVERSION_FROM_OTHER_TO_CLASS

#ifdef CONVERSION_FROM_CLASS_TO_OTHER
	Fraction A(2, 3, 4);
	cout << A << endl;

	int a = (int)A;			//explicit
	cout << a << endl;

	double b = (double)A;	//explicit
	cout << b << endl;
#endif // CONVERSION_FROM_CLASS_TO_OTHER

	Fraction A = 2.75;
	cout << A << endl;

}