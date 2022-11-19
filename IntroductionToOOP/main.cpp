#include <iostream>
using namespace std;


class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}

	//			Constructors:
	/*Point()
	{
		x = y = double();//Default double value
		cout << "Constructor:\t" << this << endl;
	}*/
	/*Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "1argConstructor: " << this << endl;
	}*/

	//			Methods:

	Point(double x = 0,double y = 0)
	{
		this->x = x;
		this->y = y;
		//cout << "2argConstructor: " << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		//cout << "CopyConstructor: " << this << endl;
	}
	~Point()
	{
		//cout << "Destructor:\t" << this << endl;
	}

	void Print()
	{
		cout << "X = " << x << ", Y = " << y << std::endl;
	}
	double distance(Point other)
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance); //Vector length
		return distance;
	}
};

double distance(Point A, Point B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;
}

//#define STRUCT_POINT
#define DISTANCE_CHECK
//#define CONSTRUCTORS_CHECK

void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef STRUCT_POINT
	cout << "Hello OOP" << endl;

	int a;   //Объявление переменной типа int
	Point A; //Объявление переменной типа Point

	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
#endif // STRUCT_POINT

#ifdef DISTANCE_CHECK
	Point A;
	A.set_x(12);
	A.set_y(5);
	cout << "Point A: "; A.Print();

	Point B;
	B.set_x(4);
	B.set_y(7);
	cout << "Point B: "; B.Print();
	cout << "Distance: " << A.distance(B) << " | " << B.distance(A) << endl; //Method
	cout << "Distance A to B: " << distance(A, B) << endl;		//Function
	cout << "Distance B to A: " << distance(B, A) << endl;	//Function
#endif // DISTANCE_CHECK

#ifdef CONSTRUCTORS_CHECK
	Point A;		//Default Constructor
	A.Print();

	Point B = 5;	//Single argument constructor
	B.Print();

	Point C(8);		//Single argument constructor
	C.Print();

	Point D(5, 8);	//Parametrised constructor
	D.Print();

	Point E = D;
	E.Print();		//CopeConstructor  
#endif // CONSTRUCTORS_CHECK

}