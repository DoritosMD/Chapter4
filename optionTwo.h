#pragma once
#ifndef OPTION_TWO_LOCK
#define OPTION_TWO_LOCK
#include <iostream>
#include <string>
#include "input.h"
#include "Rational.h"

using namespace std;

void rational_numbers();
char displayMenuOptions(char& option);
void option_A();
int option_A_menuOptions(int& option);
void enterNumberator(Rational& R1);
void enterDenominator(Rational& R1);
void displayRationalNumber(Rational R1);
void normalizeRationalNumber(Rational R1);
void negateRationalNumber(Rational R1);
void calculateRationalNumberWithConstant(Rational R1, int option);
void option_B();
int option_B_menuOptions(int& option);
void enterRationalNumber(Rational& number, int option);
void verifyConditionOperators(Rational R1, Rational R2);
void evaluateArithmaticOperators(Rational R1, Rational R2);
void evaluateExpression(Rational R1, Rational R2);

// Precondition: NA
// Postcondition: display menu and instruction for rational number
void rational_numbers()
{
	do
	{
		cout << "\tA rational number is a number that can be written as a fraction, a/b, where a is numerator and\n";
		cout << "\tb is denominator. Rational numbers are all real numbers, and can be positive or negative. A\n";
		cout << "\tnumber that is not rational is called irrational. Most of the numbers that people use in everyday\n";
		cout << "\tlife are rational.These include fractions, integers and numbers with finite decimal digits.\n";
		cout << "\tIn general, a number that can be written as a fraction while it is in its own form is rational.\n";

		char option = ' ';
		switch (displayMenuOptions(option))
		{
		case '0': return; break;
		case 'A': option_A(); break;
		case 'B': option_B(); break;
		default: cout << "\n\tERROR-1A: Invalid input. Must be 'A','B', or '0'\n";
			pause("\n\tPress enter to continue...");
			clearScreen();
			break;

		}
	} while (true);
}

// Precondition: NA
// Postcondition: ask the user to choose the option
char displayMenuOptions(char& option)
{
	cout << "\n\t2> Rational Numbers";
	cout << "\n\t" + string(60, char(205));
	cout << "\n\t\tA> A Rational Number";
	cout << "\n\t\tB> Multiple Rational Numbers";
	cout << "\n\t" + string(60, char(196));
	cout << "\n\t\t0> return";
	cout << "\n\t" + string(60, char(205));
	option = inputChar("\n\t\tOption: ");

	return toupper(option);
}

// Rational Number -> option A: A Rational Number -> functions to implement
// Precondition: NA
// Postcondition: display option A menu and tasks
void option_A()
{
	Rational R1;
	clearScreen();
	do
	{
		int option;
		switch (option_A_menuOptions(option))
		{
		case 0: clearScreen(); return; break;
		case 1:
			enterNumberator(R1);
			pause("\n\n\tPress enter to continue...");
			clearScreen();
			break;
		case 2:
			enterDenominator(R1);
			pause("\n\n\tPress enter to continue...");
			clearScreen();
			break;
		case 3:
			displayRationalNumber(R1);
			pause("\n\n\tPress enter to continue...");
			clearScreen();
			break;
		case 4:
			normalizeRationalNumber(R1);
			pause("\n\n\tPress enter to continue...");
			clearScreen();
			break;
		case 5:
			negateRationalNumber(R1);
			pause("\n\n\tPress enter to continue...");
			clearScreen();
			break;
		case 6:
			calculateRationalNumberWithConstant(R1, 1);
			pause("\n\n\tPress enter to continue...");
			clearScreen();
			break;
		case 7:
			calculateRationalNumberWithConstant(R1, 2);
			pause("\n\n\tPress enter to continue...");
			clearScreen();
			break;
		case 8:
			calculateRationalNumberWithConstant(R1, 3);
			pause("\n\n\tPress enter to continue...");
			clearScreen();
			break;
		case 9:
			calculateRationalNumberWithConstant(R1, 4);
			pause("\n\n\tPress enter to continue...");
			clearScreen();
			break;
		default: cout << "\n\tERROR-1A: Invalid input. Must be 1, 2, 3, 4, 5, 6, 7, 8, 9, or 0\n"; break;
			pause("\n\tPress enter to continue...");
			clearScreen();
		}
	} while (true);
}

// Precondition: Rational reference object
// Postcondition: enter numerator for rational number
void enterNumberator(Rational& R1)
{
	int n = inputInteger("\n\tEnter an integer for the numerator: ");
	R1.setNumerator(n);

}

// Precondition: Rational reference object
// Postcondition: enter denominator for rational number
void enterDenominator(Rational& R1)
{
	int d = inputInteger("\n\tEnter an integer for the denominator: ");
	R1.setDenominator(d);
}

// Precondition: Rational object
// Postcondition: display rational number
void displayRationalNumber(Rational R1)
{
	if (!R1.isDenominatorValid(R1))
		cout << "\n\tRational number R1 = " << R1 << " = undefined.\n";
	else
		cout << "\n\tRational number R1 = " << R1;
}

// Precondition: Rational object
// Postcondition: normalize rational number
void normalizeRationalNumber(Rational R1)
{
	Rational R2(R1);
	int n = R2.getNumerator();
	int d = R2.getDenominator();
	if (!R2.isDenominatorValid(R2))
	{
		cout << "\tR2 = " << R2 << " = undefine.";
		cout << "\n\n\tThe rational number has zero denominator.\n";
	}
	else
	{
		cout << "\n\tNormalized rational number R2 (a copy of R1)\n\n";
		R2.simplify(n, d);
		cout << "\tR2 = " << R2;
	}

}

// Precondition: Rational object
// Postcondition: negate rational number
void negateRationalNumber(Rational R1)
{
	Rational R2(R1);
	cout << "\n\tNegated rational number R2 (a copy of R1)\n\n";
	int n = R2.getNumerator();
	int d = R2.getDenominator();
	if (!R2.isDenominatorValid(R2))
	{
		cout << "\tR2 = " << R2 << " = undefine.";
		cout << "\n\tThe rational number has zero denominator.\n";
	}
	else
	{
		R2.simplify(n, d);
		cout << "\tR2 = -(" << R2 << ") = ";
		if (n < 0 && d < 0)
		{
			cout << "-" << abs(n) << "/" << abs(d);
		}
		else if (n < 0 || d < 0)
		{
			cout << abs(n) << "/" << abs(d);
		}
		else if (n > 0)
		{
			cout << "-" << R2;
		}
	}

}

// Precondition: Rational object and valid option to proceed the calculation
// Postcondition: Calculate rational number with constant depending on the assigned option
void calculateRationalNumberWithConstant(Rational R1, int option)
{
	if (option == 1)
	{
		Rational R2, R3;
		int number = inputInteger("\n\tEnter an integer value: ");
		R2.setNumerator(number);
		R2.setDenominator(1);
		if (!R1.isDenominatorValid(R1))
		{
			cout << "\n\tR2 + value ";
			cout << "\n\n\t(" << R1 << ")" << " + " << number << " = undefined";
			cout << "\n\n\tvalue + R2";
			cout << "\n\n\t" << number << " + (" << R1 << ")" << " = undefined";

		}
		else
		{
			R3 = R2 + R1;

			cout << "\n\tR2 + value ";
			cout << "\n\n\t(" << R1 << ")" << " + " << number << " = " << R3;
			cout << "\n\n\tvalue + R2";
			cout << "\n\n\t" << number << " + (" << R1 << ")" << " = " << R3;
		}

	}
	else if (option == 2)
	{
		Rational R2, R3, R4;
		int number = inputInteger("\n\tEnter an integer value: ");
		R2.setNumerator(number);
		R2.setDenominator(1);

		if (!R1.isDenominatorValid(R1))
		{
			cout << "\n\tR2 + value ";
			cout << "\n\n\t(" << R1 << ")" << " - " << number << " = undefined";
			cout << "\n\n\tvalue + R2";
			cout << "\n\n\t" << number << " - (" << R1 << ")" << " = undefined";

		}
		else
		{
			R3 = R1 - R2;
			R4 = R2 - R1;

			cout << "\n\tR2 - value ";
			cout << "\n\n\t(" << R1 << ")" << " - " << number << " = " << R3;
			cout << "\n\n\tvalue - R2";
			cout << "\n\n\t" << number << " - (" << R1 << ")" << " = " << R4;
		}

	}
	else if (option == 3)
	{
		Rational R2, R3;
		int number = inputInteger("\n\tEnter an integer value: ");
		R2.setNumerator(number);
		R2.setDenominator(1);
		if (!R1.isDenominatorValid(R1))
		{
			cout << "\n\tR2 * value ";
			cout << "\n\n\t(" << R1 << ")" << " * " << number << " = undefined";
			cout << "\n\n\tvalue * R2";
			cout << "\n\n\t" << number << " * (" << R1 << ")" << " = undefined";
		}
		else
		{
			R3 = R2 * R1;

			cout << "\n\tR2 * value ";
			cout << "\n\n\t(" << R1 << ")" << " * " << number << " = " << R3;
			cout << "\n\n\tvalue * R2";
			cout << "\n\n\t" << number << " * (" << R1 << ")" << " = " << R3;
		}

	}
	else if (option == 4)
	{
		Rational R2, R3, R4;
		int number = inputInteger("\n\tEnter an integer value: ");
		R2.setNumerator(number);
		R2.setDenominator(1);

		if (!R1.isDenominatorValid(R1))
		{
			cout << "\n\tR2 / value ";
			cout << "\n\n\t(" << R1 << ")" << " / " << number << " = undefined";
			cout << "\n\n\tvalue / R2";
			cout << "\n\n\t" << number << " / (" << R1 << ")" << " = undefined";

		}
		else if ((!R1.isDenominatorValid(R1)) && number == 0)
		{
			cout << "\n\tR2 / value ";
			cout << "\n\n\t(" << R1 << ")" << " / " << number << " = undefined";
			cout << "\n\n\tvalue / R2";
			cout << "\n\n\t" << number << " / (" << R1 << ")" << " = undefined";
		}
		else if (number == 0)
		{
			R4 = R2 / R1;
			cout << "\n\tR2 / value ";
			cout << "\n\n\t(" << R1 << ")" << " / " << number << " = undefined";
			cout << "\n\n\tvalue / R2";
			if (R1.getNumerator() == 0)
				cout << "\n\n\t" << number << " / (" << R1 << ")" << " = undefined";
			else
				cout << "\n\n\t" << number << " / (" << R1 << ")" << " = 0";
		}
		else
		{
			R3 = R1 / R2;
			R4 = R2 / R1;

			cout << "\n\tR2 / value ";
			cout << "\n\n\t(" << R1 << ")" << " / " << number << " = " << R3;
			cout << "\n\n\tvalue / R2";
			cout << "\n\n\t" << number << " / (" << R1 << ")" << " = " << R4;
		}
	}
}

// Precondition: valid integer reference option
// Postcondition: ask user to choose one option
int option_A_menuOptions(int& option)
{
	cout << "\n\tB> A Rational Number";
	cout << "\n\t" + string(60, char(205));
	cout << "\n\t\t1. Enter the numerator";
	cout << "\n\t\t2. Enter the denominator";
	cout << "\n\t\t3. Display the rational number";
	cout << "\n\t\t4. Normalize the rational number";
	cout << "\n\t\t5. Negate the rational number";
	cout << "\n\t\t6. Add (+) the rational number with a constant";
	cout << "\n\t\t7. Subtract (-) the rational number with a constant";
	cout << "\n\t\t8. Multiply (*) the rational number with a constant";
	cout << "\n\t\t9. Divide (/) the rational number with a constant";
	cout << "\n\t" + string(60, char(196));
	cout << "\n\t\t0. return";
	cout << "\n\t" + string(60, char(205));
	option = inputInteger("\n\t\tOption: ", 0, 9);

	return toupper(option);
}

// Rational Number -> option B: Multiple Rational Numbers -> functions to implement
// Precondition: NA
// Postcondition: display option B's menu and tasks
void option_B()
{
	Rational R1, R2;
	clearScreen();
	do
	{
		int option;
		switch (option_B_menuOptions(option))
		{
		case 0: clearScreen(); return;  break;
		case 1:
			enterRationalNumber(R1, 1);
			pause("\n\n\tPress enter to continue...");
			clearScreen();
			break;
		case 2:
			enterRationalNumber(R2, 2);
			pause("\n\n\tPress enter to continue...");
			clearScreen();
			break;
		case 3:
			verifyConditionOperators(R1, R2);
			pause("\n\n\tPress enter to continue...");
			clearScreen();
			break;
		case 4:
			evaluateArithmaticOperators(R1, R2);
			pause("\n\n\tPress enter to continue...");
			clearScreen();
			break;
		case 5:
			evaluateExpression(R1, R2);
			pause("\n\n\tPress enter to continue...");
			clearScreen();
			break;
		default: cout << "\n\tERROR-1A: Invalid input. Must be 1, 2, 3, 4, 5 or 0\n"; break;
			pause("\n\tPress enter to continue...");
		}
	} while (true);
}

// Precondition: Rational reference object and integer valid option
// Postcondition: ask the user to input numerator and denominator for two different rational numbers
void enterRationalNumber(Rational& number, int option)
{
	if (option == 1)
	{

		int n1 = inputInteger("\n\tEnter the numerator for R1: ");
		number.setNumerator(n1);
		int d1 = inputInteger("\n\tEnter the denominator for R1: ");
		number.setDenominator(d1);
		if (!number.isDenominatorValid(number))
		{
			cout << "\n\tR1 = " << number << " = undefined\n\n";
		}
		else
		{
			number.simplify(n1, d1);
			cout << "\n\tR1 = " << number;
		}


	}
	else if (option == 2)
	{
		int n2 = inputInteger("\n\tEnter the numerator for R2: ");
		number.setNumerator(n2);
		int d2 = inputInteger("\n\tEnter the denominator for R2: ");
		number.setDenominator(d2);
		if (!number.isDenominatorValid(number))
		{
			cout << "\n\tR2 = " << number << " = undefined";
		}
		else
		{

			number.simplify(n2, d2);
			cout << "\n\tR2 = " << number;
		}
	}
}

// Precondition: two Rational objects
// Postcondition: verify condition operators between two rational numbers
void verifyConditionOperators(Rational R1, Rational R2)
{
	bool status1 = R1 == R2;
	bool status2 = R1 != R2;
	bool status3 = R1 >= R2;
	bool status4 = R1 > R2;
	bool status5 = R1 <= R2;
	bool status6 = R1 < R2;

	cout << "\n\t\tR1 = " << R1 << " ; R2 = " << R2;

	if (!R1.isDenominatorValid(R1) && !R2.isDenominatorValid(R2))
	{
		cout << "\n\n\t\tR1 == R2 -> (undefined) == (undefined) ? " << std::boolalpha << status1;
		cout << "\n\t\tR1 != R2 -> (undefined) != (undefined) ? " << std::boolalpha << status2;
		cout << "\n\t\tR1 >= R2 -> (undefined) >= (undefined) ? " << std::boolalpha << status3;
		cout << "\n\t\tR1 > R2 -> (undefined) > (undefined) ? " << std::boolalpha << status4;
		cout << "\n\t\tR1 <= R2 -> (undefined) <= (undefined) ? " << std::boolalpha << status5;
		cout << "\n\t\tR1 < R2 -> (undefined) < (undefined) ? " << std::boolalpha << status6;
	}
	else if (!R1.isDenominatorValid(R1) && R2.isDenominatorValid(R2))
	{
		cout << "\n\n\t\tR1 == R2 -> (undefined) == (" << R2 << ") ? " << std::boolalpha << status1;
		cout << "\n\t\tR1 != R2 -> (undefined) != (" << R2 << ") ? " << std::boolalpha << status2;
		cout << "\n\t\tR1 >= R2 -> (undefined) >= (" << R2 << ") ? " << std::boolalpha << status3;
		cout << "\n\t\tR1 > R2 -> (undefined) > (" << R2 << ") ? " << std::boolalpha << status4;
		cout << "\n\t\tR1 <= R2 -> (undefined) <= (" << R2 << ") ? " << std::boolalpha << status5;
		cout << "\n\t\tR1 < R2 -> (undefined) < (" << R2 << ") ? " << std::boolalpha << status6;
	}
	else if (R1.isDenominatorValid(R1) && !R2.isDenominatorValid(R2))
	{
		cout << "\n\n\t\tR1 == R2 -> (" << R1 << ") == (undefined) ? " << std::boolalpha << status1;
		cout << "\n\t\tR1 != R2 -> (" << R1 << ") != (undefined) ? " << std::boolalpha << status2;
		cout << "\n\t\tR1 >= R2 -> (" << R1 << ") >= (undefined) ? " << std::boolalpha << status3;
		cout << "\n\t\tR1 > R2 -> (" << R1 << ") > (undefined) ? " << std::boolalpha << status4;
		cout << "\n\t\tR1 <= R2 -> (" << R1 << ") <= (undefined) ? " << std::boolalpha << status5;
		cout << "\n\t\tR1 < R2 -> (" << R1 << ") < (undefined) ? " << std::boolalpha << status6;
	}
	else
	{
		cout << "\n\n\t\tR1 == R2 -> (" << R1 << ") == (" << R2 << ") ? " << std::boolalpha << status1;
		cout << "\n\t\tR1 != R2 -> (" << R1 << ") != (" << R2 << ") ? " << std::boolalpha << status2;
		cout << "\n\t\tR1 >= R2 -> (" << R1 << ") >= (" << R2 << ") ? " << std::boolalpha << status3;
		cout << "\n\t\tR1 > R2 -> (" << R1 << ") > (" << R2 << ") ? " << std::boolalpha << status4;
		cout << "\n\t\tR1 <= R2 -> (" << R1 << ") <= (" << R2 << ") ? " << std::boolalpha << status5;
		cout << "\n\t\tR1 < R2 -> (" << R1 << ") < (" << R2 << ") ? " << std::boolalpha << status6;
	}
}

// Precondition: two Rational objects
// Postcondition:  evaluate arithmatic operators between two rational numbers
void evaluateArithmaticOperators(Rational R1, Rational R2)
{
	Rational R3 = R1 + R2;
	Rational R4 = R2 - R1;
	Rational R5 = R1 * R2;
	Rational R6 = R2 / R1;

	cout << "\n\t\tR1 = " << R1 << " ; R2 = " << R2;

	if (!R1.isDenominatorValid(R1) && !R2.isDenominatorValid(R2))
	{
		cout << "\n\n\t\tAddition\t: R1 + R2 -> (undefined) + (undefined) = undefined";
		cout << "\n\t\tSubtraction\t: R2 - R1 -> (undefined) - (undefined) = undefined";
		cout << "\n\t\tMultiplication\t: R1 * R2 -> (undefined) * (undefined) = undefined";
		cout << "\n\t\tDivision\t: R2 / R1 -> (undefined) / (undefined) = undefined";
	}
	else if (!R1.isDenominatorValid(R1) && R2.isDenominatorValid(R2))
	{
		cout << "\n\n\t\tAddition\t: R1 + R2 -> (undefined) + (" << R2 << ") = undefined";
		cout << "\n\t\tSubtraction\t: R2 - R1 -> (" << R2 << ") - (undefined) = undefined";
		cout << "\n\t\tMultiplication\t: R1 * R2 -> (undefined) * (" << R2 << ") = undefined";
		cout << "\n\t\tDivision\t: R2 / R1 -> (" << R2 << ") / (undefined) = undefined";
	}
	else if (R1.isDenominatorValid(R1) && !R2.isDenominatorValid(R2))
	{
		cout << "\n\n\t\tAddition\t: R1 + R2 -> (" << R1 << ") + (undefined) = undefined";
		cout << "\n\t\tSubtraction\t: R2 - R1 -> (undefined) - (" << R1 << ") = undefined";
		cout << "\n\t\tMultiplication\t: R1 * R2 -> (" << R1 << ") * (undefined) = undefined";
		cout << "\n\t\tDivision\t: R2 / R1 -> (undefined) / (" << R1 << ") = undefined";
	}
	else
	{
		R3.simplify(R3.getNumerator(), R3.getDenominator());
		R4.simplify(R4.getNumerator(), R4.getDenominator());
		R5.simplify(R5.getNumerator(), R5.getDenominator());
		R6.simplify(R6.getNumerator(), R6.getDenominator());

		cout << "\n\n\t\tAddition\t: R1 + R2 -> (" << R1 << ") + (" << R2 << ") = " << R3;
		cout << "\n\t\tSubtraction\t: R2 - R1 -> (" << R2 << ") - (" << R1 << ") = " << R4;
		cout << "\n\t\tMultiplication\t: R1 * R2 -> (" << R1 << ") * (" << R2 << ") = " << R5;
		if (R1.getNumerator() == 0)
			cout << "\n\t\tDivision\t: R2 / R1 -> (" << R2 << ") / (" << R1 << ") = undefined";
		else
			cout << "\n\t\tDivision\t: R2 / R1 -> (" << R2 << ") / (" << R1 << ") = " << R6;
	}
}

// Precondition: two Rational objects
// Postcondition: evaluate the indicated expression and show the steps
void evaluateExpression(Rational R1, Rational R2)
{
	Rational R3;
	R3.setNumerator(621);
	R3.setDenominator(889);
	Rational R4 = R1 + R2;
	Rational temp1;
	temp1.setNumerator(3);
	temp1.setDenominator(1);
	Rational R5 = R4 * temp1;
	Rational temp2;
	temp2.setNumerator(7);
	temp2.setDenominator(1);
	Rational numerator = R5 / temp2;
	Rational temp3;
	temp3.setNumerator(9);
	temp3.setDenominator(1);
	Rational R6 = R1 / temp3;
	Rational denominator = R2 - R6;
	Rational R7 = numerator / denominator;
	bool status = R7 >= R3;

	R4.simplify(R4.getNumerator(), R4.getDenominator());
	R5.simplify(R5.getNumerator(), R5.getDenominator());
	R6.simplify(R6.getNumerator(), R6.getDenominator());
	R7.simplify(R7.getNumerator(), R7.getDenominator());
	numerator.simplify(numerator.getNumerator(), numerator.getDenominator());
	denominator.simplify(denominator.getNumerator(), denominator.getDenominator());

	cout << "\n\t\t R1 = " << R1 << endl;
	cout << "\t\t R2 = " << R2 << endl;
	cout << "\t\t R3 = " << R3 << endl;

	cout << "\n\t\tEvaluating expression..." << endl;
	cout << "\t\t\t(3 * (R1 + R2) / 7) / (R2 - R1 / 9) >= (" << R3 << ") ? " << endl;
	cout << "\n\t\tStep #1: (3 * (" << R4 << ") / 7) / ((" << R2 << ") - (" << R6 << ")) >= (" << R3 << ") ? " << endl;
	cout << "\t\tStep #2: ((" << R5 << ") / 7) / (" << denominator << ") >= (" << R3 << ") ? " << endl;
	cout << "\t\tStep #3: (" << numerator << ") / (" << denominator << ") >= (" << R3 << ") ? " << endl;
	cout << "\t\tStep #4: (" << R7 << ") >= (" << R3 << ") ? " << endl;
	cout << "\t\tStep #5: " << std::boolalpha << status << endl;
}

// Precondition: valid integer reference option
// Postcondition: ask user to choose one option
int option_B_menuOptions(int& option)
{
	cout << "\n\tB> Multiple Rational Numbers";
	cout << "\n\t" + string(60, char(205));
	cout << "\n\t\t1. Enter rational number R1";
	cout << "\n\t\t2. Enter rational number R2";
	cout << "\n\t\t3. Verify condition operators (==, !=, >=, >, <= and <) of R1 and R2";
	cout << "\n\t\t4. Evaluate arithmatic operators (+, - , * and /) of R1 and R2";
	cout << "\n\t\t5. Evaluate (3 * (R1 + R2) / 7) / (R2 - R1 / 9) >= 621/889";
	cout << "\n\t" + string(60, char(196));
	cout << "\n\t\t0. return";
	cout << "\n\t" + string(60, char(205));
	option = inputInteger("\n\t\tOption: ", 0, 5);

	return toupper(option);
}

#endif