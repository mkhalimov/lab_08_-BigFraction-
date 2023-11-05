#include <iostream>
#include <algorithm>

#include "BigFraction.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    BigFraction a, b;
	
    cout << "ISTREAM EXAMPLE" << endl;
    std::cin >> a >> b;
    
	unsigned long coef = 3;
    
	cout << "OSTREAM EXAMPLE" << endl;
	cout << a << " " << b << endl;
    
	cout << "SUM EXAMPLE" << endl;
	cout << "a+b: " << a+b << endl;
    
	cout << "SUB EXAMPLE" << endl;
	cout << "a-b: " << a-b << endl;
    
	cout << "MUL EXAMPLE" << endl;
	cout << "a*b: " << a*b << endl;
    
	cout << "DIV EXAMPLE" << endl;
	cout << "a/b: " << a/b << endl;
    
	cout << "INT DIV EXAMPLE" << endl;
	cout << "1480/b: " << coef/b << endl;
    
	cout << "DIV WITH INT EXAMPLE" << endl;
	cout << "b/1480: " << b/coef << endl;
    
	cout << "INT MULLTIPLY EXAMPLE" << endl;
	cout << "1480*b: " << coef*b << endl;
    
	cout << "MULLTIPLY INT EXAMPLE" << endl;
	cout << "b*1480: " << b*coef<< endl;
    
	return 0;
}