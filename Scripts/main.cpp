#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

#include <SIRS.h>
#include <tests.h>

using namespace std;

int main()
{
    // Checks if we want to test the functions in the SIRS class
    string temp = "temp";
    while(temp != "J" and temp != "N")
    {
        cout << "Test functions of the SIRS class? [J/N]" << endl;
        cin >> temp;
    }

    if(temp == "J") // Runs tests if this is wanted
    {
        bool resultat;
        tests * Tests = new tests;
        resultat = Tests->Run_Tests();
        if(resultat == false)
        {
            return 0;   // Ends run if tests are not passed
        }
    }

    // Sets up class A, B, C and D and runs them
    int lim = 10;

    SIRS * A = new SIRS;

    A->N = 400;     // Total population
    A->a = 4;       // rate of infection
    A->b = 1;       // rate of recovery
    A->c = 0.5;     // rate of immunity loss
    A->d = 0.006;   // death rate
    A->dI = 0.002;  // death rate due to illness
    A->e = 0.012;   // birth rate

    //A->rungekutta(0, 100, 300, 100, 0.1, 'A', false, false);    // Run of class A, solved by Runge Kutta 4 without vitality or seasons
    //A->rungekutta(0, 100, 300, 100, 0.1, 'A', true, false);   // Run of class A, solved by Runge Kutta 4 without seasons
    //A->rungekutta(0, 100, 300, 100, 0.1, 'A', false, true);   // Run of class A, solved by Runge Kutta 4 without vitality
    A->rungekutta(0, 100, 300, 100, 0.1, 'A', true, true);    // Run of class A, solved by Runge Kutta 4 with vitality and seasons
    for(int i = 0; i < lim; i++) {
        cout << "a" << endl;
        //A->montecarlo(0, 100, 300, 100, 0.1, 'A', i, false, false);    // Run of class A, solved by Monte Carlo without vitality or seasons
        //A->montecarlo(0, 100, 300, 100, 0.1, 'A', i, true, false);   // Run of class A, solved by Monte Carlo without seasons
        //A->montecarlo(0, 100, 300, 100, 0.1, 'A', i, false, true);   // Run of class A, solved by Monte Carlo without vitality
        A->montecarlo(0, 100, 300, 100, 0.1, 'A', i, true, true);    // Run of class A, solved by Monte Carlo with vitality and seasons
    }

    SIRS * B = new SIRS;

    B->N = 400;
    B->a = 4;
    B->b = 2;
    B->c = 0.5;
    B->d = 0.006;
    B->dI = 0.002;
    B->e = 0.012;

    //B->rungekutta(0, 100, 300, 100, 0.1, 'B', false, false);    // Run of class B, solved by Runge Kutta 4 without vitality or seasons
    //B->rungekutta(0, 100, 300, 100, 0.1, 'B', true, false);   // Run of class B, solved by Runge Kutta 4 without seasons
    //B->rungekutta(0, 100, 300, 100, 0.1, 'B', false, true);   // Run of class B, solved by Runge Kutta 4 without vitality
    B->rungekutta(0, 100, 300, 100, 0.1, 'B', true, true);    // Run of class B, solved by Runge Kutta 4 with vitality and seasons
    for(int i = 0; i < lim; i++) {
        cout << "b" << endl;
        //B->montecarlo(0, 100, 300, 100, 0.1, 'B', i, false, false);    // Run of class B, solved by Monte Carlo without vitality or seasons
        //B->montecarlo(0, 100, 300, 100, 0.1, 'B', i, true, false);   // Run of class B, solved by Monte Carlo without seasons
        //B->montecarlo(0, 100, 300, 100, 0.1, 'B', i, false, true);   // Run of class B, solved by Monte Carlo without vitality
        B->montecarlo(0, 100, 300, 100, 0.1, 'B', i, true, true);    // Run of class B, solved by Monte Carlo with vitality and seasons
    }

    SIRS * C = new SIRS;

    C->N = 400;
    C->a = 4;
    C->b = 3;
    C->c = 0.5;
    C->d = 0.006;
    C->dI = 0.002;
    C->e = 0.012;

    //C->rungekutta(0, 100, 300, 100, 0.1, 'C', false, false);    // Run of class C, solved by Runge Kutta 4 without vitality or seasons
    //C->rungekutta(0, 100, 300, 100, 0.1, 'C', true, false);   // Run of class C, solved by Runge Kutta 4 without seasons
    //C->rungekutta(0, 100, 300, 100, 0.1, 'C', false, true);   // Run of class C, solved by Runge Kutta 4 without vitality
    C->rungekutta(0, 100, 300, 100, 0.1, 'C', true, true);    // Run of class C, solved by Runge Kutta 4 with vitality and seasons
    for(int i = 0; i < lim; i++) {
        cout << "c" << endl;
        //C->montecarlo(0, 100, 300, 100, 0.1, 'C', i, false, false);    // Run of class C, solved by Monte Carlo without vitality or seasons
        //C->montecarlo(0, 100, 300, 100, 0.1, 'C', i, true, false);   // Run of class C, solved by Monte Carlo without seasons
        //C->montecarlo(0, 100, 300, 100, 0.1, 'C', i, false, true);   // Run of class C, solved by Monte Carlo without vitality
        C->montecarlo(0, 100, 300, 100, 0.1, 'C', i, true, true);    // Run of class C, solved by Monte Carlo with vitality and seasons
    }

    SIRS * D = new SIRS;

    D->N = 400;
    D->a = 4;
    D->b = 4;
    D->c = 0.5;
    D->d = 0.006;
    D->dI = 0.002;
    D->e = 0.012;

    //D->rungekutta(0, 100, 300, 100, 0.1, 'D', false, false);    // Run of class D, solved by Runge Kutta 4 without vitality or seasons
    //D->rungekutta(0, 100, 300, 100, 0.1, 'D', true, false);   // Run of class D, solved by Runge Kutta 4 without seasons
    //D->rungekutta(0, 100, 300, 100, 0.1, 'D', false, true);   // Run of class D, solved by Runge Kutta 4 without vitality
    D->rungekutta(0, 100, 300, 100, 0.1, 'D', true, true);    // Run of class D, solved by Runge Kutta 4 with vitality and seasons
    for(int i = 0; i < lim; i++) {
        cout << "d" << endl;
        //D->montecarlo(0, 100, 300, 100, 0.1, 'D', i, false, false);    // Run of class D, solved by Monte Carlo without vitality or seasons
        //D->montecarlo(0, 100, 300, 100, 0.1, 'D', i, true, false);   // Run of class D, solved by Monte Carlo without seasons
        //D->montecarlo(0, 100, 300, 100, 0.1, 'D', i, false, true);   // Run of class D, solved by Monte Carlo without vitality
        D->montecarlo(0, 100, 300, 100, 0.1, 'D', i, true, true);    // Run of class D, solved by Monte Carlo with vitality and seasons
    }
    return 0;
}
