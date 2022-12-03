#include <iostream>
using namespace std;

#define WIDTH 25

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
		if (denominator == 0)
			denominator = 1;
		this->denominator = denominator;
	}

	//				Constructos:
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout.width(WIDTH);
		cout << std::left <<"Default Constructor:" << this << endl;
	}
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout.width(WIDTH);
		cout << std::left << "Single arg Constructor:" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);
		cout.width(WIDTH);
		cout << std::left << "Construcror:" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		set_denominator(denominator);
		cout.width(WIDTH);
		cout << std::left << "Constructor:" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout.width(WIDTH);
		cout << std::left << "CopyConstructor:" << this << endl;
	}
	~Fraction()
	{
		cout.width(WIDTH);
		cout << std::left << "Destructor:" << this << endl;
	}
	//				Operators:
	Fraction& operator++()
	{
		integer++;
		return *this;
	}
	Fraction& operator--()
	{
		integer--;
		return *this;
	}
	//				+, -, *, /
	Fraction operator+(Fraction other)
	{
		this->to_improper();
		other.to_improper();
		numerator = this->numerator * other.denominator + other.numerator * this->denominator;
		denominator = this->denominator * other.denominator;
		to_proper();
		return *this;
	}
	Fraction operator-(Fraction other)
	{
		this->to_improper();
		other.to_improper();
		numerator = this->numerator * other.denominator - other.numerator * this->denominator;
		denominator = this->denominator * other.denominator;
		to_proper();
		return *this;
	}
	Fraction operator*(Fraction other)
	{
		this->to_improper();
		other.to_improper();
		numerator = this->numerator * other.numerator;
		denominator = this->denominator * other.denominator;
		to_proper();
		return *this;
	}
	Fraction operator/(Fraction other)
	{
		this->to_improper();
		other.to_improper();
		numerator = this->numerator * other.denominator;
		denominator = this->denominator * other.numerator;
		to_proper();
		return *this;
	}
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
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
	//				==, !=, >, <, >=, <=
	bool operator==(Fraction& other)
	{
		this->to_improper();
		other.to_improper();
		return this->numerator * other.denominator == other.numerator * this->denominator;
	}
	bool operator!=(Fraction& other)
	{
		return !(this->operator==(other));
	}
	bool operator > (Fraction& other)
	{
		this->to_improper();
		other.to_improper();
		return this->numerator * other.denominator > other.numerator * this->denominator;
	}
	bool operator < (Fraction& other)
	{
		this->to_improper();
		other.to_improper();
		return this->numerator * other.denominator < other.numerator * this->denominator;
	}
	bool operator >=(Fraction& other)
	{
		return this->operator>(other) || this->operator==(other);
	}
	bool operator <= (Fraction& other)
	{
		return this->operator<(other) || this->operator==(other);
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

	void Print()const
	{
		/*
				1/2
				5
				5 1/2
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

ostream& operator<<(ostream& os, const Fraction& obj)
{
	if (obj.get_integer())os << obj.get_integer() << " ";
	if (obj.get_numerator())
	{
		os << obj.get_numerator() << "/" << obj.get_denominator();
	}
	else os << 0;
	return os;
}

//#define CONSTRUCTOS_CHECK

void main()
{
#ifdef CONSTRUCTORS_CHECK
	Fraction One;	//Default Constructor
	One.Print();

	Fraction Two = 5;//Single arg Constructor
	Two.Print();

	Fraction Three(1, 2);
	Three.Print();

	Fraction Four(2, 3, 4);
	Four.Print();

	Four.to_improper();
	Four.Print();

	Four.to_proper();
	Four.Print();
#endif // CONSTRUCTORS_CHECK
	//						Fraction reduction
	/*Fraction C(840, 3600);
	cout << "Original fraction: "; C.Print();
	cout << "Reduced fraction: "; C.Reduce(); C.Print();*/
	//						Increment/Decrement (++/--)
	/*C.operator++();
	C.Print();
	C.operator--();
	C.Print();*/

	//						+, -, *, /
	/*Fraction A(1, 7, 3);
	Fraction B(2, 4, 5);
	A.operator+(B);
	A.Print();

	Fraction D(7, 3);
	Fraction E(4, 5);
	D.operator-(E);
	D.Print();

	Fraction F(7, 3);
	Fraction G(4, 5);
	F.operator*(G);
	F.Print();

	Fraction H(7, 3);
	Fraction I(4, 5);
	H.operator/(I);
	H.Print();*/
	//						=
	/*Fraction J(7, 3);
	Fraction K(4, 5);
	J.operator=(K);
	J.Print();*/
	//						+=, -=, *=, /=
	/*Fraction L(7, 3);
	Fraction M(4, 5);
	L.operator+=(M);
	L.Print();

	Fraction N(7, 3);
	Fraction O(4, 5);
	N.operator-=(O);
	N.Print();

	Fraction P(7, 3);
	Fraction Q(4, 5);
	P.operator*=(Q);
	P.Print();

	Fraction R(7, 3);
	Fraction S(4, 5);
	R.operator/=(S);
	R.Print();*/
	//						==, !=, >, <, >=, <=
	/*Fraction T(7, 3);
	Fraction U(4, 5);
	if (T.operator==(U)) cout << "Correct!" << endl;
	else cout << "Incorrect!" << endl;

	if (T.operator!=(U)) cout << "Correct!" << endl;
	else cout << "Incorrect!" << endl;

	if (T.operator>(U)) cout << "Correct!" << endl;
	else cout << "Incorrect!" << endl;

	if (T.operator<(U)) cout << "Correct!" << endl;
	else cout << "Incorrect!" << endl;

	if (T.operator>=(U)) cout << "Correct!" << endl;
	else cout << "Incorrect!" << endl;

	if (T.operator<=(U)) cout << "Correct!" << endl;
	else cout << "Incorrect!" << endl;*/

	Fraction A(2, 3, 4);
	cout << A << endl;
}