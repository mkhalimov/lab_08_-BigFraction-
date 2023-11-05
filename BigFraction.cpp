#include "BigFraction.h"
#include "bigint.h"

#include <iostream>
#include <algorithm>

BigFraction::BigFraction()
	: numenator(bigint("0")), denominator(bigint("1")) {}

BigFraction::BigFraction(const BigFraction& number)
	: numenator(number.numenator), denominator(number.denominator) {}

BigFraction::BigFraction(const bigint& numen, const bigint& denomin)
	: numenator(numen), denominator(denomin)
{
    if(denominator == bigint("0"))
    {
        std::cerr << "ERROR" << std::endl;
        exit(1);
    }
}

BigFraction::~BigFraction()
{
    numenator = bigint("0");
    denominator = bigint("1");
} 

BigFraction BigFraction::operator=(const BigFraction& number)
{
    if (this == &number) 
	{
        return *this;
    }
	
    this->numenator = number.numenator;
    this->denominator = number.denominator;
    
	return *this;
}

const BigFraction operator+(const BigFraction& left, const BigFraction& right)
{
    BigFraction left_clone = left, right_clone = right;
    
	bigint lcm = bigint::div(bigint::mul(left.denominator,right.denominator),bigint::gcd(left.denominator, right.denominator));
    bigint left_coefficient = bigint::div(lcm,left.denominator), right_coefficient = bigint::div(lcm,right.denominator);
    
	left_clone = BigFraction(bigint::mul(left_clone.numenator,left_coefficient), bigint::mul(left_clone.denominator,left_coefficient));
    right_clone = BigFraction(bigint::mul(right_clone.numenator,right_coefficient), bigint::mul(right_clone.denominator,right_coefficient));
    
	BigFraction task(bigint::add(left_clone.numenator, right_clone.numenator),  left_clone.denominator);
    
	task.simplify();
    
	return task;
}

const BigFraction operator-(const BigFraction& left, const BigFraction& right)
{
    BigFraction left_clone = left, right_clone = right;
    
	bigint lcm = bigint::div(bigint::mul(left.denominator,right.denominator),bigint::gcd(left.denominator, right.denominator));
    bigint left_coefficient = bigint::div(lcm,left.denominator), right_coefficient = bigint::div(lcm,right.denominator);
    
	left_clone = BigFraction(bigint::mul(left_clone.numenator,left_coefficient), bigint::mul(left_clone.denominator,left_coefficient));
    right_clone = BigFraction(bigint::mul(right_clone.numenator,right_coefficient), bigint::mul(right_clone.denominator,right_coefficient));
    
	BigFraction task;
    
	if(left_clone.numenator >= right_clone.numenator)
	{
        task = BigFraction(bigint::sub(left_clone.numenator, right_clone.numenator),  left_clone.denominator);
    }
	else
	{
        task = BigFraction(bigint::sub(right_clone.numenator, left_clone.numenator),  left_clone.denominator);
    }
	
	task.simplify();
    
	return task;
}

const BigFraction operator*(const BigFraction& left, const BigFraction& right)
{
    BigFraction task(bigint::mul(left.numenator,right.numenator), bigint::mul(left.denominator,right.denominator));
    
	task.simplify();
    
	return task;
}

const BigFraction operator*(unsigned long coefficient, const BigFraction& number)
{
    BigFraction task = number;
    
	task.numenator = bigint::mul(task.numenator, bigint(coefficient));
    
	task.simplify();
    
	return task;
}

const BigFraction operator*(const BigFraction& number, unsigned long coefficient)
{
    BigFraction task = number;
    
	task.numenator = bigint::mul(task.numenator, bigint(coefficient));
    
	task.simplify();
    
	return task;
}

const BigFraction operator/(const BigFraction& left, const BigFraction& right)
{
    BigFraction task(bigint::mul(left.numenator,right.denominator), bigint::mul(left.denominator,right.numenator));
    
	task.simplify();
    
	return task;
}

const BigFraction operator/(unsigned long coefficient, const BigFraction& number)
{
    BigFraction task(bigint::mul(bigint(coefficient),number.denominator), number.numenator);
    
	task.simplify();
    
	return task;
}

const BigFraction operator/(const BigFraction& number, unsigned long coefficient)
{
    if (coefficient != 0)
    {
        bigint d = number.denominator;
        
		BigFraction task(number.numenator, bigint::mul(d, bigint(coefficient)));
        
		task.simplify();
        
		return task;
    }
	
    std::cerr << "ERROR" << std::endl;
    
	return BigFraction(bigint("0"), bigint("1"));
}

std::ostream& operator<<(std::ostream &outstream, const BigFraction& number)
{
    outstream << number.numenator << '/' << number.denominator;
	
    return outstream;
}

std::istream& operator>>(std::istream &inputstream, BigFraction& number) 
{
    inputstream >> number.numenator >> number.denominator;
    
	number.simplify();
    
	return inputstream;
}

void BigFraction::simplify()
{
    bigint g = bigint::gcd(numenator, denominator);
    
	numenator = bigint::div(numenator, g);
    
	denominator = bigint::div(denominator, g);
}

/*BigFraction::operator double() const
{
	bigint reminder(numenator);
	
	double task;
	
	for(size_t index = 0; index <= 5; ++index)
	{
		task += static_cast<int>(div(reminder,denominator)) / pow(10.f, index);
		
		reminder = (reminder % denominator) * bigint(10);
	}
	
	return task;
}*/

//штука выше не работает, не придмула в итоге как заставить работать

//Я в итоге не понял как нужно написать double();