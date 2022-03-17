#pragma once
#include <iostream>
#include <string>

using namespace std;

//PreCondition: NA
//PostCondition: displays main menu options
void displayMainMenu(void)
{
    cout << "\n\tCMPR131 Chapter 4: Complex Numbers, Rational Numbers, Polynomials by Matthew Batres, Eduardo Ortiz";
    cout << "\n\t Victor Huerta, and Alavi Isa" << endl;
    cout << "\t" + string(90, char(205)) << endl;
    cout << "\t\t1> Complex Numbers" << endl;
    cout << "\t\t2> Rational Numbers" << endl;
    cout << "\t\t3> Polynomials" << endl;
    cout << "\t" + string(90, char(196)) << endl;
    cout << "\t\t0> exit" << endl;
    cout << "\t" + string(90, char(205)) << endl;
}

//PreCondition: NA
//PostCondition: displays option one menu options
void displayOptionOneMenu(void)
{
    cout << "\n\tA complex number is a number that can be expressed in the form a + b i, where a and b are real";
    cout << "\n\tnumbers, and i represents the \"imaginary uni\", satisfying the equation i^2 = -1. Because no";
    cout << "\n\treal number satisfies this equation, i is called an imaginary number. For the complex number";
    cout << "\n\ta + b i, a is called the real part and b is called the imaginary part." << endl;
    cout << "\n\t1> Complex Numbers" << endl;
    cout << "\t" + string(90, char(205)) << endl;
    cout << "\t\tA> A Complex Number" << endl;
    cout << "\t\tB> Multiple Complex Numbers" << endl;
    cout << "\t" + string(90, char(196)) << endl;
    cout << "\t\t0> return" << endl;
    cout << "\t" + string(90, char(205)) << endl;
}

//PreCondition: NA
//PostCondition: displays option one sub menu options
void displayOptionOneMenuA(void)
{
    cout << "\n\tA> A Complex Number" << endl;
    cout << "\t" + string(90, char(205)) << endl;
    cout << "\t\t1. Enter the real number" << endl;
    cout << "\t\t2. Enter the imaginary number" << endl;
    cout << "\t\t3. Display the complex number" << endl;
    cout << "\t\t4. Negate the complex number" << endl;
    cout << "\t\t5. Add (+) the complex number with a constant" << endl;
    cout << "\t\t6. Subtract (-) the complex number with a constant" << endl;
    cout << "\t\t7. Multiply (*) the complex number with a constant" << endl;
    cout << "\t\t8. Divide (/) the complex number with a constant" << endl;
    cout << "\t" + string(90, char(196)) << endl;
    cout << "\t\t0. return" << endl;
    cout << "\t" + string(90, char(205)) << endl;
}

//PreCondition: NA
//PostCondition: displays option one sub menu options
void displayOptionOneMenuB(void)
{
    cout << "\n\tB> Multiple Complex Numbers" << endl;
    cout << "\t" + string(90, char(205)) << endl;
    cout << "\t\t1. Enter complex number C1" << endl;
    cout << "\t\t2. Enter complex number C2" << endl;
    cout << "\t\t3. Verify condition operators (== and !=) of C1 and C2" << endl;
    cout << "\t\t4. Evaluate arithmatic operators (+, - , * and /) of C1 and C2" << endl;
    cout << "\t\t5. Evaluate steps in (3 * (C1 + C2) / 7) / (C2 - C1 / 9) != (1.07109 + 0.120832i) ?" << endl;
    cout << "\t" + string(90, char(196)) << endl;
    cout << "\t\t0. return" << endl;
    cout << "\t" + string(90, char(205)) << endl;
}

//PreCondition: NA
//PostCondition: displays option two menu options
void displayOptionTwoMenu(void)
{
    cout << "\n\tA rational number is a number that can be written as a fraction, a/b, where a is numerator and";
    cout << "\n\tb is denominator. Rational numbers are all real numbers, and can be positive or negative. A";
    cout << "\n\tnumber that is not rational is called irrational. Most of the numbers that people use in everyday";
    cout << "\n\tlife are rational.These include fractions, integers and numbers with finite decimal digits.";
    cout << "\n\tIn general, a number that can be written as a fraction while it is in its own form is rational." << endl;
    cout << "\n\t2> Rational Numbers" << endl;
    cout << "\t" + string(90, char(205)) << endl;
    cout << "\t\tA> A Rational Number" << endl;
    cout << "\t\tB> Multiple Rational Numbers" << endl;
    cout << "\t" + string(90, char(196)) << endl;
    cout << "\t\t0> return" << endl;
    cout << "\t" + string(90, char(205)) << endl;
}

//PreCondition: NA
//PostCondition: displays option two menu options
void displayOptionTwoMenuA(void)
{
    cout << "\n\tA> A Rational Number" << endl;
    cout << "\t" + string(90, char(205)) << endl;
    cout << "\t\t1. Enter the numerator" << endl;
    cout << "\t\t2. Enter the deminator" << endl;
    cout << "\t\t3. Display the rational number" << endl;
    cout << "\t\t4. Normalize the rational number" << endl;
    cout << "\t\t5. Negate the rational number" << endl;
    cout << "\t\t6. Add (+) the rational number with a constant" << endl;
    cout << "\t\t7. Subtract (-) the rational number with a constant" << endl;
    cout << "\t\t8. Multiply (*) the rational number with a constant" << endl;
    cout << "\t\t9. Divide (/) the rational number with a constant" << endl;
    cout << "\t" + string(90, char(196)) << endl;
    cout << "\t\t0. return" << endl;
    cout << "\t" + string(90, char(205)) << endl;
}

//PreCondition: NA
//PostCondition: displays option two sub menu options
void displayOptionTwoMenuB(void)
{
    cout << "\n\tB> Multiple Rational Numbers" << endl;
    cout << "\t" + string(90, char(205)) << endl;
    cout << "\t\t1. Enter rational number R1" << endl;
    cout << "\t\t2. Enter rational number R2" << endl;
    cout << "\t\t3. Verify condition operators (==, !=, >=, >, <= and <) of R1 and R2" << endl;
    cout << "\t\t4. Evaluate arithmatic operators (+, - , * and /) of R1 and R2" << endl;
    cout << "\t\t5. Evaluate (3 * (R1 + R2) / 7) / (R2 - R1 / 9) >= 621/889" << endl;
    cout << "\t" + string(90, char(196)) << endl;
    cout << "\t\t0. return" << endl;
    cout << "\t" + string(90, char(205)) << endl;
}

//PreCondition: NA
//PostCondition: displays option three menu options
void displayOptionThreeMenu(void)
{
    cout << "\n\tA polynomial is an expression consisting of variables(also called indeterminates) and";
    cout << "\n\tcoefficients, that involves only the operations of addition, subtraction, multiplication,";
    cout << "\n\tand non-negative integer exponentiation of variables." << endl;
    cout << "\n\t3> Polynomials" << endl;
    cout << "\t" + string(90, char(205)) << endl;
    cout << "\t\tA> A Polynomial" << endl;
    cout << "\t\tB> Multiple Polynomials" << endl;
    cout << "\t" + string(90, char(196)) << endl;
    cout << "\t\t0> return" << endl;
    cout << "\t" + string(90, char(205)) << endl;
}

//PreCondition: NA
//PostCondition: displays option three sub menu options
void displayOptionThreeMenuA(void)
{
    cout << "\n\tA> Single Polynomial" << endl;
    cout << "\t" + string(90, char(205)) << endl;
    cout << "\t\t1. Enter the number of terms" << endl;
    cout << "\t\t2. Specify the coefficients" << endl;
    cout << "\t\t3. Evaluate epxression" << endl;
    cout << "\t\t4. Solve for the derivative" << endl;
    cout << "\t\t5. Solve for the integral" << endl;
    cout << "\t" + string(90, char(196)) << endl;
    cout << "\t\t0. return" << endl;
    cout << "\t" + string(90, char(205)) << endl;
}