#include <iostream>
using namespace std;

#define WIDTH	27

class String;
String operator+(const String& left, const String& right);

class String
{
	size_t size;
	char* str;
public:
	int get_size()const
	{
		return size;
	}
	char* get_str()const
	{
		return str;
	}
	void set_size(int size)
	{
		this->size = size;
	}
	void set_str(char* str)
	{
		this->str = str;
	}

	//			Constructors
	explicit String(size_t size = 50) //50 characters default string
	{
		this->size = size;
		this->str = new char[size] {};
		cout.width(WIDTH);
		cout << left << "Default Constructor:" << this << endl;
	}
	String(const char* str)
	{
		this->size = strlen(str) + 1; //strlen() возвращает размер строки в символах
									  //+1 резервирует место для NULL терминатора
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
		{
			this->str[i] = str[i];
		}
		cout.width(WIDTH);
		cout << left << "Constructor:" << this << endl;
	}
	String(const String& other)
	{
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
		{
			this->str[i] = other.str[i];
		}
		cout.width(WIDTH);
		cout << left << "Copy Constructor:" << this << endl;
	}
	~String()
	{
		delete[] this->str;
		cout.width(WIDTH);
		cout << std::left << "Destructor:" << this << endl;
	}

	//			Operators
	String& operator=(const String& other)
	{
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
		{
			this->str[i] = other.str[i];
		}
		return *this;
	}

	//			[]
	char operator[](int i)const //For left right
	{
		return str[i];
	}
	char& operator[](int i)		//For the buffer
	{
		return str[i];
	}
	//			Methods
	void Print()const
	{
		cout << "Size: " << size << endl;
		cout << "Str: " << str << endl;
	}

};

String operator+(const String& left, const String& right)
{
	String str_sum(left.get_size() + right.get_size());
	for (int i = 0; i < left.get_size(); i++)
	{
		str_sum[i] = left[i];
	}
	for (int i = 0; i < right.get_size(); i++)
	{
		str_sum[i + left.get_size() - 1] = right[i];
	}
	return str_sum;
}

ostream& operator << (ostream& os, const String& obj)
{
	return os << obj.get_str();
}

void main()
{
	//String str1 = 12;  //explicit constructor нельзя вызвать так
	String def_str(12);  //explicit constructor можно вызвать только так
	def_str.Print();

	String str1 = "Hello";
	str1.Print();
	String str2 = "World";
	str2.Print();

	//cout << str1 << str2 << endl;
	String str3;
	str3 = str1 + str2;
	cout << str3 << endl;

}