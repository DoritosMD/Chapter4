#pragma once
#ifndef OPTION_Three_LOCK
#define OPTION_Three_LOCK

#include "Polynomial.h"
#include "input.h"
#include <iostream>
#include <string>

using namespace std;

//PreCondition: input type int, input type Polynomial, input type string
//PostCondition: populate polynomial with coefficients
void specCoefficients(int numberOfTerms, Polynomial& poly, string outputMessage = "\n\t\tThe P(x) is entered:")
{
	if (numberOfTerms == 0)
	{
		cout << "\n\t\tERROR: 0 term. Please enter the number of terms.";
		return;
	}

	poly.clearCoeffi();
	cout << endl;
	for (int i = 1; i <= numberOfTerms; i++)
	{
		poly.insertCoeffi(inputDouble("\t\tEnter the coefficient for term #" + to_string(i) + ": "));
	}

	cout << outputMessage;
	cout << poly << endl;
}

//PreCondition: input type int, input type Polynomial
//PostCondition: outputs results of evaluated polynomial 
void evaluateExp(int numberOfTerms, Polynomial poly)
{
	if (numberOfTerms == 0)
	{
		cout << "\n\t\tERROR: 0 term. Please enter the number of terms.";
		return;
	}

	if (poly.getSize() == 0)
	{
		cout << "\n\t\tERROR: expression. Please specify the coefficients.";
		return;
	}

	cout << "\n\t\tThe P(x) is entered: ";
	cout << poly << endl;

	double xValue = inputDouble("\n\t\tEnter the value of x to evaluate the polynomial: ");

	poly.evaluate(xValue);

}

//PreCondition: input type int, input type Polynomial
//PostCondition: outputs results of derived polynomial
void solveDerivative(int numberOfTerms, Polynomial poly)
{
	if (numberOfTerms == 0)
	{
		cout << "\n\t\tERROR: 0 term. Please enter the number of terms.";
		return;
	}

	if (poly.getSize() == 0)
	{
		cout << "\n\t\tERROR: expression. Please specify the coefficients.";
		return;
	}

	cout << "\n\t\tPolynomial(x) = ";
	cout << poly << endl;

	Polynomial derivedPoly = poly.derive();
	cout << "\n\t\tDerivative    = ";
	cout << derivedPoly << endl;
}

//PreCondition: input type int, input type Polynomial
//PostCondition: outputs results of integrated polynomial
void solveIntegral(int numberOfTerms, Polynomial poly)
{
	if (numberOfTerms == 0)
	{
		cout << "\n\t\tERROR: 0 term. Please enter the number of terms.";
		return;
	}

	if (poly.getSize() == 0)
	{
		cout << "\n\t\tERROR: expression. Please specify the coefficients.";
		return;
	}

	cout << "\n\t\tPolynomial(x) = ";
	cout << poly << endl;

	Polynomial derivedPoly = poly.integrate();
	cout << "\n\t\tIntegral      = ";
	cout << derivedPoly << endl;
}

//PreCondition: NA
//PostCondition: outputs results from sub-program B
void twoPolynomials(void)
{
	Polynomial polyOne = Polynomial();
	Polynomial polyTwo = Polynomial();

	cout << "\tB> Two Polynomials" << endl;
	int polyOneTermNumb = inputInteger("\t\tEnter the number of terms(1..100) for the polynomial: ", 1, 100);
	specCoefficients(polyOneTermNumb, polyOne, "\n\tThe first polynomial (P1) is entered: ");

	int polyTwoTermNumb = inputInteger("\n\t\tEnter the number of terms(1..100) for the polynomial: ", 1, 100);
	specCoefficients(polyTwoTermNumb, polyTwo, "\n\tThe second polynomial (P2) is entered: ");

	cout << "\n\t\tAddition of polynomials       -> P1 + P2 = ";
	cout << polyOne + polyTwo;

	cout << "\n\t\tSubtraction of polynomials    -> P1 - P2 = ";
	cout << polyOne - polyTwo;

	cout << "\n\t\tMultiplication of polynomials -> P1 * P2 = ";
	cout << polyOne * polyTwo << endl;

	double constant = inputDouble("\n\t\tEnter a constant value: ");
	cout << "\n\t" << constant << " * Polynomial(P1) = " << constant * polyOne << endl;
	cout << "\n\t" << "Polynomial(P2) * " << constant << " = " << polyTwo * constant << endl;
}

#endif