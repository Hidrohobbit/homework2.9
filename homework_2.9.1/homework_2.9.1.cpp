#include <iostream>

class Fraction
{
private:
	double numerator_;
	double denominator_;
	double division_;
public:
	bool operator == (Fraction& other)
	{
		return this->division_ == other.division_;
	}
	bool operator != (Fraction& other)
	{
		return !(*this == other);
	}
	bool operator > (Fraction& other)
	{
		return this->division_ > other.division_;
	}
	bool operator < (Fraction& other)
	{
		return other > *this;
	}
	bool operator >= (Fraction& other)
	{
		return !(*this < other);
	}
	bool operator <= (Fraction& other)
	{
		return !(*this > other);
	}
	Fraction(double numerator, double denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
		division_= (this->numerator_ / this->denominator_);
	}
};

int main()
{
	Fraction f1(4, 3);
	Fraction f2(6,11);

	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';

	return 0;
}