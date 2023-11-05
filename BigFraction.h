#include <cstddef>
#include <iostream>

#include "bigint.h"
#include "fraction.h"

class BigFraction: fraction {
    bigint numenator, denominator;
	
    friend class bigint;
    
	public:
        BigFraction();
        BigFraction(const BigFraction&);
        BigFraction(const bigint&, const bigint&);
        ~BigFraction();
        
        BigFraction operator=(const BigFraction&);

        friend const BigFraction operator+(const BigFraction&, const BigFraction&);
        friend const BigFraction operator-(const BigFraction&, const BigFraction&);
        friend const BigFraction operator*(const BigFraction&, const BigFraction&);
        friend const BigFraction operator/(const BigFraction&, const BigFraction&);
        friend const BigFraction operator*(const BigFraction&, unsigned long);
        friend const BigFraction operator/(const BigFraction&, unsigned long);
        friend const BigFraction operator*(unsigned long, const BigFraction&);
        friend const BigFraction operator/(unsigned long, const BigFraction&);
		//operator double() const;
		
        friend std::ostream& operator<<(std::ostream &, const BigFraction&);
        friend std::istream& operator>>(std::istream &, BigFraction&);

		
		void simplify();
};