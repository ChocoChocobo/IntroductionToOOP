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
	void Print()
	{
		cout << "(" << x << ", " << y << ")" << std::endl;
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

void main()
{
	Point A;
	A.set_x(12);
	A.set_y(5);
	cout << "Point A: "; A.Print();

	Point B;
	B.set_x(4);
	B.set_y(7);
	cout << "Point B: "; B.Print();
	cout << "Distance: " << A.distance(B) << " | " << B.distance(A) << endl;
	cout << "Distance A to B: " << distance(A, B) << endl;
	cout << "Distance B to A: " << distance(B, A) << endl;

}