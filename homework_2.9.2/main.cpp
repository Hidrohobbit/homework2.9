#include <iostream>

class Fraction
{
private:
	int numerator_;
	int denominator_;
public:
	Fraction operator + (Fraction& other)
	{
		Fraction temp;

		if(this->denominator_ == other.denominator_) //Проверка на схожесть знаменателей двух дробей необходима для корректной работы оператора " + " и " - ".
		{
			temp.numerator_ = this->numerator_ + other.numerator_;
			temp.denominator_ = this->denominator_; //При равенстве знаменателей нам необходимо лишь суммировать или вычесть числитель 
			return temp;
		}
		else //В случае неравенства знаменателей нам необходимо привести дроби к общему знаментаелю посредством перемножения первой дроби на знаменатель второй дроби и умножения второй дроби на знаменатель певрой дроби
		{
			temp.numerator_ = (this->numerator_ * other.denominator_) + (this->denominator_ * other.numerator_); 
			temp.denominator_ = this->denominator_ * other.denominator_;
			return temp;
		}
	}
	Fraction operator - (Fraction& other)
	{
		Fraction temp;

		if (this->denominator_ == other.denominator_)
		{
			temp.numerator_ = this->numerator_ - other.numerator_;
			temp.denominator_ = this->denominator_;
			return temp;
		}
		else
		{
			temp.numerator_ = (this->numerator_ * other.denominator_) - (this->denominator_ * other.numerator_);
			temp.denominator_ = this->denominator_ * other.denominator_;
			return temp;
		}
	}
	Fraction operator * (Fraction& other)
	{
		Fraction temp;

		temp.numerator_ = this->numerator_ * other.numerator_;
		temp.denominator_ = this->denominator_ * other.denominator_;
		return temp;
	}
	Fraction operator / (Fraction& other)
	{
		Fraction temp;

		temp.numerator_ = this->numerator_ * other.denominator_;
		temp.denominator_ = this->denominator_ * other.numerator_;
		return temp;
	}
	Fraction operator ++ ()
	{
		this->numerator_ += this->denominator_;
		return *this;
	}
	Fraction operator ++ (int value)
	{
		Fraction temp(*this);
		this->numerator_ += this->denominator_;
		return temp;
	}
	Fraction operator -- ()
	{
		this->numerator_ -= this->denominator_;
		return *this;
	}
	Fraction operator -- (int value)
	{
		Fraction temp(*this);
		this->numerator_ -= this->denominator_;
		return temp;
	}

	friend std::ostream& operator << (std::ostream& out, const Fraction& fraction);

	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}
	Fraction()
	{
		numerator_ = 0;
		denominator_ = 0;
	}
};
std::ostream& operator << (std::ostream& out, const Fraction& fraction)
{
	out << fraction.numerator_ << "/" << fraction.denominator_;
	return out;
}

int main()
{
	Fraction f1(3, 4);
	Fraction f2(4, 4);
	Fraction f3(7, 4);
	Fraction f_result;
	
	f_result = f1 + f2;
	std::cout << f1 << " + " << f2 << " = " << f_result << std::endl;
	f_result = f1 - f2;
	std::cout << f1 << " - " << f2 << " = " << f_result << std::endl;
	f_result = f1 * f2;
	std::cout << f1 << " * " << f2 << " = " << f_result << std::endl;
	f_result = f1 / f2;
	std::cout << f1 << " / " << f2 << " = " << f_result << std::endl;


	f_result = ++f1 * f2;
	std::cout << f1 << " * " << f2 << " = " << f_result << std::endl;
	f_result = f3-- * f2;
	std::cout << f3 << " * " << f2 << " = " << f_result << std::endl;
	

	return 0;
}