#pragma once
#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include "input.h"
using namespace std;


class Rational
{
private:
	int numerator; // To hold the numerator
	int denominator; // To hold the denominator
public:

	//Argument constructor
	Rational(int newNumerator = 0, int newDenominator = 1)
	{
		numerator = newDenominator;
		denominator = newDenominator;
	}

	// Copy constructor
	Rational(const Rational& obj)
	{
		numerator = obj.numerator;
		denominator = obj.denominator;
	}

	// Precondition: valid integer n
	// Postcondition: numerator is assigned to n
	void setNumerator(int n)
	{
		numerator = n;
	}

	// Precondition: NA
	// Postcondition: return numerator
	int getNumerator() const
	{
		return numerator;
	}

	// Precondition: valid integer d
	// Postcondition: denominator is assigned to d
	void setDenominator(int d)
	{
		denominator = d;
	}

	// Precondition: NA
	// Postcondition: return denominator
	int getDenominator() const
	{
		return denominator;
	}

	// Precondition: valid reference integer of numerator and denominator
	// Postcondition: simplify rational number
	void simplify(int numerator, int denominator)
	{
		if (numerator == 0)
		{
			setNumerator(numerator);
			setDenominator(denominator);
		}
		else
		{
			int n = numerator;
			if (numerator < 0)
				n = -numerator;
			else
				n = numerator;
			int d = denominator;
			int largest = 1;
			if (n > d)
				largest = n;
			else
				largest = d;

			int gcd = 0;

			for (int i = largest; i >= 2; i--)
			{
				if (numerator % i == 0 && denominator % i == 0)
				{
					gcd = i;
					break;
				}
			}

			if (gcd != 0)
			{
				numerator /= gcd;
				denominator /= gcd;
			}

			if (numerator < 0 && denominator < 0)
			{
				numerator = abs(numerator);
				denominator = abs(denominator);
			}

			if (denominator < 0)
			{
				numerator = -numerator;
				denominator = abs(denominator);
			}

			setNumerator(numerator);
			setDenominator(denominator);
		}

	}

	// Precondition: pass in Rational object
	// Postcondition: return false if the object has zero denominator and true if it is not
	bool isDenominatorValid(Rational& obj)
	{
		if (obj.getDenominator() == 0)
			return false;
		else
			return true;
	}

	// Overloaded operator functions
	// Overload operator + function to add two rational numbers
	Rational operator + (const Rational& right)
	{
		Rational temp;
		int a = numerator;
		int b = denominator;
		int c = right.numerator;
		int d = right.denominator;
		temp.numerator = (a * d) + (b * c);
		temp.denominator = b * d;
		return temp;
	}

	// Overload operator - function to subtract two rational numbers
	Rational operator - (const Rational& right)
	{
		Rational temp;
		int a = numerator;
		int b = denominator;
		int c = right.numerator;
		int d = right.denominator;
		temp.numerator = (a * d) - (b * c);
		temp.denominator = b * d;
		return temp;
	}

	// Overload operator * function to multiply two rational numbers
	Rational operator * (const Rational& right)
	{
		Rational temp;
		int a = numerator;
		int b = denominator;
		int c = right.numerator;
		int d = right.denominator;
		temp.numerator = a * c;
		temp.denominator = b * d;
		return temp;
	}

	// Overload operator / function to divide two rational numbers
	Rational operator / (const Rational& right)
	{
		Rational temp;
		int a = numerator;
		int b = denominator;
		int c = right.numerator;
		int d = right.denominator;
		temp.numerator = a * d;
		temp.denominator = b * c;
		return temp;
	}

	// Overloaded == operator. Returns true if the current object 
	// is set to a value equal to that of right.  
	bool operator == (const Rational& right)
	{
		bool status;

		if (numerator == right.numerator && denominator == right.denominator)
			status = true;
		else
			status = false;

		return status;
	}

	// Overloaded != operator. Returns false if the current object 
	// is set to a value equal to that of right.   
	bool operator != (const Rational& right)
	{
		bool status;
		if (numerator == right.numerator && denominator == right.denominator)
			status = false;
		else
			status = true;

		return status;
	}

	// Overloaded < operator. Returns true if the current object 
	// is set to a value less than to that of right.  
	bool operator <(const Rational& right)
	{
		bool status;
		int lside = getNumerator() * right.getDenominator();
		int rside = getDenominator() * right.getNumerator();

		if (lside < rside)
			status = true;
		else
			status = false;
		return status;
	}

	// Overloaded > operator. Returns true if the current object 
	// is set to a value greater than to that of right.  
	bool operator > (const Rational& right)
	{
		bool status;
		int lside = getNumerator() * right.getDenominator();
		int rside = getDenominator() * right.getNumerator();

		if (lside > rside)
			status = true;
		else
			status = false;
		return status;
	}

	// Overloaded <= operator. Returns true if the current object 
	// is set to a value less than or equal to that of right. 
	bool operator <= (const Rational& right)
	{
		bool status;
		int lside = getNumerator() * right.getDenominator();
		int rside = getDenominator() * right.getNumerator();

		if (lside < rside || numerator == right.numerator && denominator == right.denominator)
			status = true;
		else
			status = false;

		return status;
	}

	// Overloaded > operator. Returns true if the current object 
	// is set to a value greater than or equal to that of right.  
	bool operator >= (const Rational& right)
	{
		bool status;
		int lside = getNumerator() * right.getDenominator();
		int rside = getDenominator() * right.getNumerator();

		if (lside > rside || numerator == right.numerator && denominator == right.denominator)
			status = true;
		else
			status = false;
		return status;
	}

	// Overloaded << operator. Gives cout the ability to     
	// directly display Rational objects. 
	friend ostream& operator<< (ostream& strm, const Rational& obj)
	{
		strm << obj.numerator << "/" << obj.denominator;
		return strm;
	}
};

#endif