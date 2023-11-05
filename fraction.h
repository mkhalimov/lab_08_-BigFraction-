#include <cstddef>
#include <iostream>

class fraction {
    unsigned long int numenator, denominator;
    
	public:
        fraction();
        fraction(const fraction&);
        fraction(unsigned long, unsigned long);
        ~fraction();
        
        fraction operator=(const fraction&);

        friend const fraction operator+(const fraction&, const fraction&);
        friend const fraction operator-(const fraction&, const fraction&);
        friend const fraction operator*(const fraction&, const fraction&);
        friend const fraction operator/(const fraction&, const fraction&);
        friend const fraction operator*(const fraction&, int);
        friend const fraction operator/(const fraction&, int);
        friend const fraction operator*(int, const fraction&);
        friend const fraction operator/(int, const fraction&);
        operator double() const;

        friend std::ostream& operator<<(std::ostream &, const fraction&);
        friend std::istream& operator>>(std::istream &, fraction&);

        void simplify();
};