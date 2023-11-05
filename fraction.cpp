#include "fraction.h"

#include <iostream>
#include <algorithm>

fraction::fraction()
	: numenator(0), denominator(1) {}

fraction::fraction(const fraction& number)
	: numenator(number.numenator), denominator(number.denominator) {}

fraction::fraction(unsigned long a, unsigned long b)
	: numenator(a), denominator(b)
{
    if(denominator == 0)
    {
        std::cerr << "ERROR" << std::endl;
        denominator = 1;
    }
}

fraction::~fraction()
{
    numenator = 0;
    denominator = 1;
} 

fraction fraction::operator=(const fraction& number)
{
    if (this == &number)
	{
        return *this;
    }
	
    this->numenator = number.numenator;
    this->denominator = number.denominator;
    
	return *this;
}

const fraction operator+(const fraction& left, const fraction& right)
{
    fraction left_clone = left, right_clone = right;
	
    unsigned long lcm = (left.denominator*right.denominator)/std::__gcd(left.denominator, right.denominator);
    unsigned long left_coefficient = lcm/left.denominator, right_coefficient = lcm/right.denominator;
    
	left_clone = fraction(left_clone.numenator*left_coefficient, left_clone.denominator*left_coefficient);
    right_clone = fraction(right_clone.numenator*right_coefficient, right_clone.denominator*right_coefficient);
    
	fraction task(left_clone.numenator + right_clone.numenator,  left_clone.denominator);
    
	task.simplify();
	
    return task;
}

const fraction operator-(const fraction& left, const fraction& right)
{

    fraction left_clone = left, right_clone = right;
    
	unsigned long lcm = (left.denominator*right.denominator)/std::__gcd(left.denominator, right.denominator);
    unsigned long left_coefficient = lcm/left.denominator, right_coefficient = lcm/right.denominator;
    
	left_clone = fraction(left_clone.numenator*left_coefficient, left_clone.denominator*left_coefficient);
    right_clone = fraction(right_clone.numenator*right_coefficient, right_clone.denominator*right_coefficient);
    
	fraction task;
    
	if(left_clone.numenator >= right_clone.numenator)
	{
        task = fraction(left_clone.numenator - right_clone.numenator,  left_clone.denominator);
    }
	else
	{
        task = fraction(right_clone.numenator - left_clone.numenator,  left_clone.denominator);
    }
	
	task.simplify();
    
	return task;
}

const fraction operator*(const fraction& left, const fraction& right)
{
    fraction task(left.numenator*right.numenator, left.denominator*right.denominator);
    
	task.simplify();
    
	return task;
}

const fraction operator*(int coefficient, const fraction& number)
{
    fraction task = number;
    
	task.numenator *= coefficient;
    task.simplify();
    
	return task;
}

const fraction operator*(const fraction& number, int coefficient)
{
    fraction task = number;
    
	task.numenator *= coefficient;
    task.simplify();
    
	return task;
}

const fraction operator/(const fraction& left, const fraction& right)
{
    fraction task(left.numenator*right.denominator, left.denominator*right.numenator);
    
	task.simplify();
    
	return task;
}

const fraction operator/(int coefficient, const fraction& number)
{
    fraction task(coefficient*number.denominator, number.numenator);
    
	task.simplify();
    
	return task;
}

const fraction operator/(const fraction& number, int coefficient)
{
    if(coefficient != 0)
    {
        fraction task(number.numenator, number.denominator*coefficient);
        
		task.simplify();
        
		return task;
    }
    
	std::cerr << "ERROR" << std::endl;
    
	return fraction(0, 1);
}

std::ostream& operator<<(std::ostream &outstream, const fraction& number)
{
    outstream << number.numenator << '/' << number.denominator;
    
	return outstream;
}

std::istream& operator>>(std::istream &inputstream, fraction& number) 
{
    inputstream >> number.numenator;
    
	inputstream.ignore(1,'/');
    
	inputstream >> number.denominator;
    
	number.simplify();
    
	return inputstream;
}

void fraction::simplify()
{
    unsigned long simplified = std::__gcd(numenator, denominator);
    
	numenator /= simplified;
    denominator /= simplified;
}

fraction::operator double() const
{
    return double(numenator)/double(denominator);
}