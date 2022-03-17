#pragma once
#ifndef POLYNOMIAL_LOCK
#define POLYNOMIAL_LOCK

#include <vector>
#include <iostream>
#include <string>
#include <iomanip>

class Polynomial
{
private:
	std::vector<double> coefficients;
	int size;

public:
	Polynomial()
	{
		size = 0;
	}

	~Polynomial()
	{
		coefficients.clear();
	}

	//PreCondition: NA
	//PostCondition: returns size of coefficients vector 
	int getSize(void) const
	{
		return size;
	}

	//PreCondition: NA
	//PostCondition: returns coefficients vector 
	std::vector<double> getCoefficients(void)
	{
		return coefficients;
	}

	//PreCondition: input is type double
	//PostCondition: insert double in to coefficients vector 
	void insertCoeffi(double coeffi)
	{
		coefficients.push_back(coeffi);
		size++;
	}

	//PreCondition: NA
	//PostCondition: clear coefficients vector 
	void clearCoeffi(void)
	{
		coefficients.clear();
	}

	//PreCondition: input is type double
	//PostCondition: returns value of evaluated polynomial and prints steps.
	double evaluate(double xValue)
	{
		double total = 0;

		std::cout << std::endl;
		for (int i = 0; i < coefficients.size(); i++)
		{
			int exponent = coefficients.size() - (i + 1);

			double temp = coefficients[i] * pow(xValue, exponent);
			std::string tempString = std::to_string(temp);
			tempString.erase(tempString.find_last_not_of('0') + 1, std::string::npos);
			tempString.erase(tempString.find_last_not_of('.') + 1, std::string::npos);

			if (i == coefficients.size() - 1)
			{
				std::cout << "\t\t+\t" + tempString + "\t<-\t" << std::fixed << std::setprecision(2) << coefficients[i];
				std::cout << "x^" + std::to_string(exponent) << std::endl;
			}
			else
			{
				std::cout << "\t\t \t" + tempString + "\t<-\t" << std::fixed << std::setprecision(2) << coefficients[i];
				std::cout << "x^" + std::to_string(exponent) << std::endl;
			}
			total += temp;
		}
		std::string totalString = std::to_string(total);
		totalString.erase(totalString.find_last_not_of('0') + 1, std::string::npos);
		totalString.erase(totalString.find_last_not_of('.') + 1, std::string::npos);

		std::cout << "\t\t" + std::string(45, char(196)) << std::endl;
		std::cout << "\t\t\t" + totalString << std::endl;
		return total;
	}

	//PreCondition: NA
	//PostCondition: returns derivative of polynomial
	Polynomial derive(void)
	{
		Polynomial temp = Polynomial();
		if (coefficients.size() == 1) return temp;

		for (int i = 0; i < coefficients.size() - 1; i++)
		{
			double coeffi = ((double)coefficients.size() - ((double)i + 1)) * coefficients[i];
			temp.insertCoeffi(coeffi);
		}

		return temp;
	}

	//PreCondition: NA
	//PostCondition: returns integral of polynomial
	Polynomial integrate(void)
	{
		Polynomial temp = Polynomial();
		if (coefficients.size() == 1)
		{
			temp.insertCoeffi(coefficients[0]);
			temp.insertCoeffi(0);
			return temp;
		}

		for (int i = 0; i < coefficients.size(); i++)
		{
			double coeffi = coefficients[i] / ((double)coefficients.size() - i);
			temp.insertCoeffi(coeffi);
		}
		temp.insertCoeffi(0);

		return temp;
	}

	//PreCondition: input ostream, input type Polynomial
	//PostCondition: overloaded << operator outputs polynomial 
	friend std::ostream& operator<<(std::ostream& out, const Polynomial& poly)
	{
		std::string output = "";
		for (int i = 0; i < poly.coefficients.size(); i++)
		{
			if (poly.coefficients[i] == 0) continue;
			int exponent = poly.coefficients.size() - (i + 1);

			std::string coeffi = std::to_string(poly.coefficients[i]);
			coeffi.erase(coeffi.find_last_not_of('0') + 1, std::string::npos);
			coeffi.erase(coeffi.find_last_not_of('.') + 1, std::string::npos);

			if (exponent == 1)
			{
				if (poly.coefficients.size() == 2 || poly.coefficients[i] < 0)
					output += " " + coeffi + "x";
				else
					output += " +" + coeffi + "x";
			}
			else if (exponent == 0)
			{
				if (poly.coefficients.size() == 1 || poly.coefficients[i] < 0)
					output += " " + coeffi;
				else
					output += " +" + coeffi;
			}
			else
			{
				if (i == 0 || poly.coefficients[i] < 0)
					output += " " + coeffi + "x^" + std::to_string(exponent);
				else
					output += " +" + coeffi + "x^" + std::to_string(exponent);
			}

		}
		out << output;
		return out;
	}

	//PreCondition: input type Polynomial, input type Polynomial
	//PostCondition: overloaded + operator returns sum of two polynomials
	friend Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs)
	{
		Polynomial temp = Polynomial();
		if (lhs.getSize() == 0)
		{
			temp = rhs;
			return temp;
		}
		else if (rhs.getSize() == 0)
		{
			temp = lhs;
			return temp;
		}

		int sizeDifference = lhs.getSize() - rhs.getSize();
		if (sizeDifference < 0) sizeDifference *= -1;


		if (lhs.getSize() > rhs.getSize())
		{

			for (int i = 0; i < lhs.getSize(); i++)
			{
				if (i + 1 <= sizeDifference)
					temp.insertCoeffi(lhs.coefficients[i]);
				else
				{
					double insert = lhs.coefficients[i] + rhs.coefficients[i - sizeDifference];
					temp.insertCoeffi(insert);
				}
			}
		}
		else
		{
			for (int i = 0; i < rhs.getSize(); i++)
			{
				if (i + 1 <= sizeDifference)
					temp.insertCoeffi(rhs.coefficients[i]);
				else
				{
					double insert = lhs.coefficients[i - sizeDifference] + rhs.coefficients[i];
					temp.insertCoeffi(insert);
				}
			}
		}
		return temp;
	}

	//PreCondition: input type Polynomial, input type Polynomial
	//PostCondition: overloaded - operator returns difference of two polynomials
	friend Polynomial operator-(const Polynomial& lhs, const Polynomial& rhs)
	{
		Polynomial temp = Polynomial();
		if (lhs.getSize() == 0)
		{
			temp = rhs;
			return temp;
		}
		else if (rhs.getSize() == 0)
		{
			temp = lhs;
			return temp;
		}

		for (int i = 0; i < rhs.getSize(); i++)
		{
			double multiple = -1 * rhs.coefficients[i];
			temp.insertCoeffi(multiple);
		}

		return lhs + temp;
	}

	//PreCondition: input type Polynomial, input type Polynomial
	//PostCondition: overloaded * operator returns multiple of two polynomials
	friend Polynomial operator*(const Polynomial& lhs, const Polynomial& rhs)
	{

		int sizeDifference = lhs.getSize() - rhs.getSize();
		if (sizeDifference < 0) sizeDifference *= -1;

		std::vector<Polynomial> collection;
		if (lhs.getSize() < rhs.getSize())
		{

			for (int y = 0; y < lhs.getSize(); y++)
			{
				Polynomial temp = Polynomial();
				for (int i = 0; i < rhs.getSize(); i++)
				{
					double multiple = lhs.coefficients[y] * rhs.coefficients[i];
					temp.insertCoeffi(multiple);
				}
				for (int x = 0; x < (lhs.getSize() - 1) - y; x++) temp.insertCoeffi(0);
				collection.push_back(temp);
			}
		}
		else
		{
			for (int y = 0; y < rhs.getSize(); y++)
			{
				Polynomial temp = Polynomial();
				for (int i = 0; i < lhs.getSize(); i++)
				{
					double multiple = rhs.coefficients[y] * lhs.coefficients[i];
					temp.insertCoeffi(multiple);
				}
				for (int x = 0; x < (rhs.getSize() - 1) - y; x++) temp.insertCoeffi(0);
				collection.push_back(temp);

			}
		}
		Polynomial total = Polynomial();
		for (int i = 0; i < collection.size(); i++)
		{
			total = total + collection[i];
		}

		return total;
	}

	//PreCondition: input type Polynomial, input type int
	//PostCondition: overloaded * operator returns multiple of polynomial and integer
	friend Polynomial operator*(const Polynomial& lhs, const int constant)
	{
		Polynomial temp = Polynomial();
		for (int i = 0; i < lhs.getSize(); i++)
		{
			double multiple = lhs.coefficients[i] * constant;
			temp.insertCoeffi(multiple);
		}
		return temp;
	}

	//PreCondition: input type int, input type Polynomial
	//PostCondition: overloaded * operator returns multiple of integer and polynomial
	friend Polynomial operator*(const int constant, const Polynomial& rhs)
	{
		Polynomial temp = Polynomial();
		for (int i = 0; i < rhs.getSize(); i++)
		{
			double multiple = constant * rhs.coefficients[i];
			temp.insertCoeffi(multiple);
		}
		return temp;
	}
};

#endif