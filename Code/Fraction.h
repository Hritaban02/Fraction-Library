#ifndef __FRACTION_H__
#define __FRACTION_H__

#include <cmath>
#include <iostream>

class Fraction
{
private:
	//The data members have been made private for information hiding.
	//The user feels like he is actually dealing with a Fraction data type and not with two integers.
	
	int p;	//Numerator
	unsigned int q;	//Denominator
	
public:
	//The static constants declared here are made public in order to be used by the user whenever he needs them.
	
	static Fraction sc_fUnity;	//Fraction Unity 1/1
	static Fraction sc_fZero;	//Fraction Zero 0/1
	
private:
	//Utility Functions
	//Utitlity Functions are functions that are to be accessed by the class alone for its internal computations.
	//These are not be seen by the user and thus are made private.
	//Some of them are made static because they are part of the class and not part of the behaviour of an instance of the class.
	
	//precision() function returns an integer value which can be changed based on the accuracy needed in the application.
	//This determines the number of decimal places upto which a floating point value should be rounded off.
	//This function has been made inline considering the fact that it is the same as declaring a MACRO manifest constant but much more safer and type-safe.
	inline static int precision() {return static_cast<int>(pow(10,5));}
	
	//gcd(int,int) function returns a Greatest Common Divisor of two positive integers passed to it as arguments.
	//Built-in types are passed by value.(To avoid overheads caused by referencing to built-in types)
	//The function returns the GCD of the two integers by value.(It is fatal to return a temporary local variable to a function by reference)
	//It is made static as it is only a part of the class and there is no meaning for an instance of the Fraction class i.e. a Fraction object to have gcd() as a non-static member function.
	//It uses a recursive algorithm to compute the GCD.
	static int gcd(int,int);
	
	//lcm(int,int) function returns a Least Commmon Multiple of two positive integers passed to it as arguments.
	//Built-in types are passed by value.(To avoid overheads caused by referencing to built-in types)
	//The function returns the LCM of the two integers by value.(It is fatal to return a temporary local variable to a function by reference)
	//It is made static as it is only a part of the class and there is no meaning for an instance of the Fraction class i.e. a Fraction object to have lcm() as a non-static member function.
	//It uses a recursive algorithm to compute the LCM.
	static int lcm(int,int);
	
	//normalize() function acts on a Fraction Object to normalize it's data members p and q.
	//It is a utility function to be only used by the class internally and is not exposed to the user.
	//It normalizes the Fraction p/q as per the norms mentioned in the assignment.
	//It does not take any explicit arguments but the Fraction *const this is implcitly passes when the function is called upon by an instance of the class.
	//It's return type is void as it only makes changes to the data members of the object and does bot explicitly return anything.
	void normalize();
	
public:

	//Constructors
	
	//This is a Constructor of the Fraction class and has three ways of being called.
	//1)As a default no args Constructor Fraction().
	//2)As a one arg Constructor Fraction(int).
	//3)As a two args Constructor Fraction(int,int).
	//These three ways are possible because the parameters are defaulted.
	//Built-in type parameters passed to the constructor are by value.(To avoid overheads caused by referencing to built-in types)
	//This Constructor takes two integer arguments as parameters and constructs a normalized Fraction based on them.
	//The constructor exits the program if n=0. It does not throw an exception.
	Fraction(int m=1,int n=1);
	
	//This is another Constructor of the Fraction class which takes a double precision floating point value as an argument.
	//Built-in type parameters passed to the constructor are by value.(To avoid overheads caused by referencing to built-in types)
	//This Constructor takes a double value as parameter and constructs a normalized Fraction based on the precision value returned by the precision() function.
	Fraction(double);
	
	
	//Copy Constructor
	
	//This is the copy constructor of the Fraction Class.
	//It takes a Fraction object as const so that the constructor is forbidden from arbitarily altering the data members of the passed object and has only read-only access to them. 
	//It takes a Fraction object by reference.(If it was taken by value the program falls into an infinite loop of copying as Call by value uses the Copy Constructor to construct the formal parameter object based on the actual parameter object) 
	//The Copy Constructor simply constructs a new object of class Fraction based on the data members of the Parameter Object.
	Fraction(const Fraction&);
	
	
	//Destructor
	
	//This is the destructor of the Fraction Class and has the default semantics as there are no pointers or allocated memory that's needs to be explicitly destroyed.
	~Fraction();
	
	
	//Copy Assignment Operator
	
	//This is the copy assignment operator.
	//The left operand is implicitly passed as Fraction *const this.
	//The right operand has to be explicitly passed. It is passed by reference to avoid the overhead of copying. It is passed as const so that no changes can be made to the actual source object.
	//It returns Fraction object by reference to support chaining of assignments. Thus (F1=F2) returns a reference to F1 and then this can be done (F3=F1=F2).
	//It takes care of self-copy and only performs copying when the two operands are different objects.
	//F1=F2 <------> F1.operator=(F2)
	Fraction& operator=(const Fraction&);
	
	
	//Unary Arithmetic Operators
	
	//The overloaded unary minus operator is a public member function and is const qualified.
	//It is made const so that it does not alter the operand.
	//Implicitly const Fraction *const this is passed to the function.
	//It returns by value because it creates a new object based on the semantics of the operator and the operand.
	//-F1 <-------> F1.operator-()
	Fraction operator-() const;
	
	//The overloaded unary plus operator is a public member function and is const qualified.
	//It is made const so that it does not alter the operand.
	//Implicitly const Fraction *const this is passed to the function.
	//It returns by value because it creates a new object based on the semantics of the operator and the operand.
	//+F1 <-------> F1.operator+()
	Fraction operator+() const;
	
	//The overloaded unary pre-drecrement operator is a public member function.
	//It is not const because it needs to make changes to the operand.
	//Implicitly Fraction *const this is passed to the function.
	//It returns by value because it creates a new object based on the semantics of the operator and the operand.
	//This function first alters the operand and then returns a copy of it.
	//--F1 <-------> F1.operator--()
	Fraction operator--();
	
	//The overloaded unary post-drecrement operator is a public member function.
	//It is not const because it needs to make changes to the operand.
	//Implicitly Fraction *const this is passed to the function.
	//It returns by value because it creates a new object based on the semantics of the operator and the operand.
	//This function creates a copy of the operand and then alters the original,finally it returns the copy.
	//F1-- <-------> F1.operator--(int)
	Fraction operator--(int);
	
	//The overloaded unary pre-increment operator is a public member function.
	//It is not const because it needs to make changes to the operand.
	//Implicitly Fraction *const this is passed to the function.
	//It returns by value because it creates a new object based on the semantics of the operator and the operand.
	//This function first alters the operand and then returns a copy of it.
	//++F1 <-------> F1.operator++()
	Fraction operator++();
	
	//The overloaded unary post-increment operator is a public member function.
	//It is not const because it needs to make changes to the operand.
	//Implicitly Fraction *const this is passed to the function.
	//It returns by value because it creates a new object based on the semantics of the operator and the operand.
	//This function creates a copy of the operand and then alters the original,finally it returns the copy.
	//F1++ <-------> F1.operator++(int)
	Fraction operator++(int);
	
	
	//Binary Arithmetic Operators
	
	//The overloaded binary plus operator is a friend to the Fraction class.
	//It takes two arguments of type Fraction as const reference to avoid the overhead of copying and to forbid any changes to the operands.
	//It returns by value the sum of the two Fractions because it creates a new Fraction object with the sum of the two Fractions passed to it.
	//F1+F2 <------> operator+(F1,F2)
	friend Fraction operator+(const Fraction&,const Fraction&);
	
	//The overloaded binary minus operator is a friend to the Fraction class.
	//It takes two arguments of type Fraction as const reference to avoid the overhead of copying and to forbid any changes to the operands.
	//It returns by value the difference of the two Fractions because it creates a new Fraction object with the diferrence of the two Fractions passed to it.
	//F1-F2 <------> operator-(F1,F2)
	friend Fraction operator-(const Fraction&,const Fraction&);
	
	//The overloaded binary multiply operator is a friend to the Fraction class.
	//It takes two arguments of type Fraction as const reference to avoid the overhead of copying and to forbid any changes to the operands.
	//It returns by value the product of the two Fractions because it creates a new Fraction object with the product of the two Fractions passed to it.
	//F1*F2 <------> operator*(F1,F2)
	friend Fraction operator*(const Fraction&,const Fraction&);	
	
	//The overloaded binary divide operator is a friend to the Fraction class.
	//It takes two arguments of type Fraction as const reference to avoid the overhead of copying and to forbid any changes to the operands.
	//It returns by value the quotient of the two Fractions because it creates a new Fraction object with the quotient of the two Fractions passed to it.
	//F1/F2 <------> operator/(F1,F2)
	//If F2=0 then, it throws an exception because the value F1/F2 becomes undefined and cannot be further used in the program.
	friend Fraction operator/(const Fraction&,const Fraction&);
	
	//The overloaded binary modulo operator is a friend to the Fraction class.
	//It takes two arguments of type Fraction as const reference to avoid the overhead of copying and to forbid any changes to the operands.
	//It returns by value the remainder of the two Fractions upon division because it creates a new Fraction object with the remainder of the two Fractions passed to it.
	//F1%F2 <------> operator%(F1,F2)
	//If F2=0 then, it throws an exception because the value F1/F2 becomes undefined and cannot be further used in the program.
	friend Fraction operator%(const Fraction&,const Fraction&);
	
	
	//Binary Relational Operators
	
	//The overloaded equality operator is a public member function.
	//It is made const so that it does not alter the operands.
	//Implicitly the left hand operand is passed as const Fraction *const this to the function.
	//EXplicitly the right hand operand is passed to the function as const reference.
	//It takes the argument of type Fraction as const reference to avoid the overhead of copying and to forbid any changes to the operand.
	//It returns by boolean value true if the two Fractions are equal else false.
	//F1==F2 <-------> F1.operator==(F2)
	bool operator==(const Fraction&) const;
	
	//The overloaded inequality operator is a public member function.
	//It is made const so that it does not alter the operands.
	//Implicitly the left hand operand is passed as const Fraction *const this to the function.
	//EXplicitly the right hand operand is passed to the function as const reference.
	//It takes the argument of type Fraction as const reference to avoid the overhead of copying and to forbid any changes to the operand.
	//It returns by boolean value true if the two Fractions are not equal else false.
	//F1!=F2 <-------> F1.operator!=(F2)
	bool operator!=(const Fraction&) const;
	
	//The overloaded less than operator is a public member function.
	//It is made const so that it does not alter the operands.
	//Implicitly the left hand operand is passed as const Fraction *const this to the function.
	//EXplicitly the right hand operand is passed to the function as const reference.
	//It takes the argument of type Fraction as const reference to avoid the overhead of copying and to forbid any changes to the operand.
	//It returns by boolean value true if the left operand is less than the right operand else false.
	//F1<F2 <-------> F1.operator<(F2)
	bool operator<(const Fraction&) const;
	
	//The overloaded less than or equal to operator is a public member function.
	//It is made const so that it does not alter the operands.
	//Implicitly the left hand operand is passed as const Fraction *const this to the function.
	//EXplicitly the right hand operand is passed to the function as const reference.
	//It takes the argument of type Fraction as const reference to avoid the overhead of copying and to forbid any changes to the operand.
	//It returns by boolean value true if the left operand is less than or equal to the right operand else false.
	//F1<=F2 <-------> F1.operator<=(F2)
	bool operator<=(const Fraction&) const;
	
	//The overloaded greater than operator is a public member function.
	//It is made const so that it does not alter the operands.
	//Implicitly the left hand operand is passed as const Fraction *const this to the function.
	//EXplicitly the right hand operand is passed to the function as const reference.
	//It takes the argument of type Fraction as const reference to avoid the overhead of copying and to forbid any changes to the operand.
	//It returns by boolean value true if the left operand is greater than the right operand else false.
	//F1>F2 <-------> F1.operator>(F2)
	bool operator>(const Fraction&) const;
	
	//The overloaded greater than or equal to operator is a public member function.
	//It is made const so that it does not alter the operands.
	//Implicitly the left hand operand is passed as const Fraction *const this to the function.
	//EXplicitly the right hand operand is passed to the function as const reference.
	//It takes the argument of type Fraction as const reference to avoid the overhead of copying and to forbid any changes to the operand.
	//It returns by boolean value true if the left operand is greater than or equal to the right operand else false.
	//F1>=F2 <-------> F1.operator>=(F2)
	bool operator>=(const Fraction&) const;
	
	//Special Operators
	
	//The overloaded not operator is a public member function.
	//It is made const so that it does not alter the operands.
	//Implicitly the left hand operand is passed as const Fraction *const this to the function.
	//It returns by value the reciprocal of the Fraction because it creates a new Fraction object and stores the reciprocal in it.
	//!F1 <-------> F1.operator!()
	Fraction operator!() const;
	
	//Input/Output Operators
	
	//The overloaded insertion operator is a friend to the Fraction class.
	//It takes two arguments.
	//First is a reference to the output stream to print the Fraction to the same stream and not to a copy of it.
	//Second type is Fraction as const reference to avoid the overhead of copying and to forbid any changes to the operand.
	//It returns by reference the same output stream to facilitate chaining.
	//std::cout << F1 <------> operator<<(cout,F1)
	friend std::ostream& operator<<(std::ostream&,const Fraction &);
	
	//The overloaded extraction operator is a friend to the Fraction class.
	//It takes two arguments.
	//First is a reference to the input stream to obtain the parameters for the construction of the Fraction object.
	//Second type is Fraction as reference because changes are to be made to the actual parameter.
	//It returns by reference the same input stream to facilitate chaining.
	//std::cin >> F1 <------> operator>>(cin,F1)
	friend std::istream& operator>>(std::istream&,Fraction &);
};

#endif // __FRACTION_H__

