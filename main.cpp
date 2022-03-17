// Name: Matthew Batres
// Group 3: Matthew Batres, Eduardo Ortiz, Victor Huerta, Alavi Isa
// Date: 03-16-2022
// Description: CMPR 131 Chapter 4 Assignment - Pointers and Dynamic Arrays

#include <iostream>
#include <string>
#include "optionOne.h"
#include "optionTwo.h"
#include "optionThree.h"
#include "input.h"
#include "menus.h"
#include "Polynomial.h"
#include "Complex.h"

void mainMenu(void);
void programOne(void);
void programOneSubProgramA(void);
void programOneSubProgramB(void);
void programThree(void);
void programThreeSubProgramA(void);

using namespace std;

int main(void)
{
    mainMenu();
    return 0;
}

//PreCondition: NA
//PostCondition: redirects user to different menus based on their choice
void mainMenu(void)
{
    do
    {
        clearScreen();

        displayMainMenu();

        int userInput = inputInteger("\t\tOption: ", 0, 3);
        switch (userInput)
        {
        case 0: clearScreen(); return;
        case 1: clearScreen(); programOne(); break;
        case 2: clearScreen(); rational_numbers(); break;
        case 3: clearScreen(); programThree(); break;
        default: cout << "\t\tERROR-3A: Invalid input. Must be from 0..3." << endl;
        }

    } while (true);
}

//PreCondition: NA
//PostCondition: redirects user to different options in program one
void programOne(void)
{
    do
    {
        clearScreen();
        displayOptionOneMenu();

        int option = inputChar("\t\tOption: ");

        switch (option)
        {
        case '0': return;
        case 'a': case 'A': programOneSubProgramA(); pause("\n\t\tPress enter to continue..."); break;
        case 'b': case 'B': programOneSubProgramB(); pause("\n\t\tPress enter to continue...");  break;
        default: cout << "\t\tERROR-1A: Invalid input. Must be '0','A', or 'B'" << endl;
            pause("\n\t\tPress enter to continue...");
        }

    } while (true);
}

//PreCondition: NA
//PostCondition: executes different programs in sub-program A
void programOneSubProgramA(void)
{
    Complex C1;

    do
    {
        clearScreen();
        displayOptionOneMenuA();

        int option = inputInteger("\t\tOption: ", 0, 8);

        switch (option)
        {
        case 0: return;
        case 1: newRealNumber(C1); pause("\n\t\tPress enter to continue..."); break;
        case 2: newImaginaryNumber(C1); pause("\n\t\tPress enter to continue..."); break;
        case 3: displayComplex(C1); pause("\n\t\tPress enter to continue..."); break;
        case 4: negateComplex(C1); pause("\n\t\tPress enter to continue..."); break;
        case 5: addConstant(C1); pause("\n\t\tPress enter to continue..."); break;
        case 6: subtractConstant(C1); pause("\n\t\tPress enter to continue..."); break;
        case 7: multiplyConstant(C1); pause("\n\t\tPress enter to continue..."); break;
        case 8: divideConstant(C1); pause("\n\t\tPress enter to continue..."); break;
        default: cout << "\t\tERROR-3A: Invalid input. Must be from 0..8." << endl;
        }

    } while (true);
}

//PreCondition: NA
//PostCondition: executes different programs in sub-program B
void programOneSubProgramB(void)
{
    Complex C1, C2;
    Complex C3(1.07109, 0.120832);
    do
    {
        clearScreen();
        displayOptionOneMenuB();
        int option = inputInteger("\t\tOption: ", 0, 5);
        switch (option)
        {
        case 0: return;
        case 1: newComplexNumber(C1, 1); pause("\n\t\tPress enter to continue..."); break;
        case 2: newComplexNumber(C2, 2); pause("\n\t\tPress enter to continue..."); break;
        case 3: verifyConditionOperators(C1, C2); pause("\n\t\tPress enter to continue..."); break;
        case 4: evaluateArithmaticOperators(C1, C2); pause("\n\t\tPress enter to continue..."); break;
        case 5: evaluateOperators(C1, C2, C3); pause("\n\t\tPress enter to continue..."); break;
        default: cout << "\t\tERROR-3A: Invalid input. Must be from 0..5." << endl;
        }

    } while (true);
}

//PreCondition: NA
//PostCondition: redirects user to different options in program three
void programThree(void)
{
    do
    {
        clearScreen();
        displayOptionThreeMenu();

        int option = inputChar("\t\tOption: ");

        switch (option)
        {
        case '0': return;
        case 'a': case 'A': programThreeSubProgramA(); pause("\n\t\tPress enter to continue..."); break;
        case 'b': case 'B': clearScreen(); twoPolynomials(); pause("\n\t\tPress enter to continue...");  break;
        default: cout << "\t\tERROR-1A: Invalid input. Must be '0','A', or 'B'" << endl;
            pause("\n\t\tPress enter to continue...");
        }

    } while (true);
}

//PreCondition: NA
//PostCondition: executes different programs in sub-program A
void programThreeSubProgramA(void)
{
    int numberOfTerms = 0;
    Polynomial poly = Polynomial();

    do
    {
        clearScreen();
        displayOptionThreeMenuA();

        int option = inputInteger("\t\tOption: ", 0, 5);

        switch (option)
        {
        case 0: return;
        case 1: numberOfTerms = inputInteger("\n\t\tEnter the number of terms(1..100) for the polynomial: ", 1, 100);
            pause("\n\t\tPress enter to continue..."); break;
        case 2: specCoefficients(numberOfTerms, poly); pause("\n\t\tPress enter to continue..."); break;
        case 3: evaluateExp(numberOfTerms, poly); pause("\n\t\tPress enter to continue..."); break;
        case 4: solveDerivative(numberOfTerms, poly); pause("\n\t\tPress enter to continue..."); break;
        case 5: solveIntegral(numberOfTerms, poly); pause("\n\t\tPress enter to continue..."); break;
        default: cout << "\t\tERROR-3A: Invalid input. Must be from 0..5." << endl;
        }

    } while (true);
}