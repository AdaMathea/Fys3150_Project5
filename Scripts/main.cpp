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
    int time = 730;

    SIRS * A = new SIRS;

    A->N = 400;     // Total population
    A->a = 4;       // rate of infection
    A->b = 1;       // rate of recovery
    A->c = 0.5;     // rate of immunity loss
    A->d = 0.006;   // death rate
    A->dI = 0.002;  // death rate due to illness
    A->e = 0.012;   // birth rate
    A->f = 0.1;     // initial value for the vaccination rate

    //A->rungekutta(0, 100, 300, 100, 0.1, 'A', false, false, false);    // Run of class A, solved by Runge Kutta 4
    //A->rungekutta(0, 100, 300, 100, 0.1, 'A', true, false, false);   // Run of class A, solved by Runge Kutta 4 with vitality
    //A->rungekutta(0, 100, 300, 100, 0.1, 'A', false, true, false);   // Run of class A, solved by Runge Kutta 4 with seasons
    A->rungekutta(0, 100, 300, 100, 0.1, 'A', false, false, true);    // Run of class A, solved by Runge Kutta 4 with vaccination
    //A->rungekutta(0, 100, 300, 100, 0.1, 'A', true, true, false);    // Run of class A, solved by Runge Kutta 4 with vitality and seasons
    //A->rungekutta(0, 100, 300, 100, 0.1, 'A', true, false, true);    // Run of class A, solved by Runge Kutta 4 with vitality and vaccination
    //A->rungekutta(0, 100, 300, 100, 0.1, 'A', false, true, true);    // Run of class A, solved by Runge Kutta 4 with seasons and vaccination
    //A->rungekutta(0, 100, 300, 100, 0.1, 'A', true, true, true);    // Run of class A, solved by Runge Kutta 4 with vitality, seasons and vaccination
    for(int i = 0; i < lim; i++) {
        cout << "a" << endl;
        //A->montecarlo(0, 100, 300, 100, 0.1, 'A', i, false, false, false, lim > 0);    // Run of class A, solved by Monte Carlo
        //A->montecarlo(0, 100, 300, 100, 0.1, 'A', i, true, false, false, lim > 0);   // Run of class A, solved by Monte Carlo with vitality
        //A->montecarlo(0, 100, 300, 100, 0.1, 'A', i, false, true, false, lim > 0);   // Run of class A, solved by Monte Carlo with seasons
        A->montecarlo(0, 100, 300, 100, 0.1, 'A', i, false, false, true, lim > 0);    // Run of class A, solved by Monte Carlo with vaccination
        //A->montecarlo(0, 100, 300, 100, 0.1, 'A', i, true, true, false, lim > 0);    // Run of class A, solved by Monte Carlo with vitality and seasons
        //A->montecarlo(0, 100, 300, 100, 0.1, 'A', i, true, false, true, lim > 0);    // Run of class A, solved by Monte Carlo with vitality and vaccination
        //A->montecarlo(0, 100, 300, 100, 0.1, 'A', i, false, true, true, lim > 0);    // Run of class A, solved by Monte Carlo with seasons and vaccination
        //A->montecarlo(0, 100, 300, 100, 0.1, 'A', i, true, true, true, lim > 0);    // Run of class A, solved by Monte Carlo with vitality, seasons and vaccination
    }

    SIRS * B = new SIRS;

    B->N = 400;
    B->a = 4;
    B->b = 2;
    B->c = 0.5;
    B->d = 0.006;
    B->dI = 0.002;
    B->e = 0.012;
    B->f = 0.1;

    //B->rungekutta(0, 100, 300, 100, 0.1, 'B', false, false, false);    // Run of class B, solved by Runge Kutta 4
    //B->rungekutta(0, 100, 300, 100, 0.1, 'B', true, false, false);   // Run of class B, solved by Runge Kutta 4 with vitality
    //B->rungekutta(0, 100, 300, 100, 0.1, 'B', false, true, false);   // Run of class B, solved by Runge Kutta 4 with seasons
    B->rungekutta(0, 100, 300, 100, 0.1, 'B', false, false, true);    // Run of class B, solved by Runge Kutta 4 with vaccination
    //B->rungekutta(0, 100, 300, 100, 0.1, 'B', true, true, false);    // Run of class B, solved by Runge Kutta 4 with vitality and seasons
    //B->rungekutta(0, 100, 300, 100, 0.1, 'B', true, false, true);    // Run of class B, solved by Runge Kutta 4 with vitality and vaccination
    //B->rungekutta(0, 100, 300, 100, 0.1, 'B', false, true, true);    // Run of class B, solved by Runge Kutta 4 with seasons and vaccination
    //B->rungekutta(0, 100, 300, 100, 0.1, 'B', true, true, true);    // Run of class B, solved by Runge Kutta 4 with vitality, seasons and vaccination
    for(int i = 0; i < lim; i++) {
        cout << "a" << endl;
        //B->montecarlo(0, 100, 300, 100, 0.1, 'B', i, false, false, false, lim > 0);    // Run of class B, solved by Monte Carlo
        //B->montecarlo(0, 100, 300, 100, 0.1, 'B', i, true, false, false, lim > 0);   // Run of class B, solved by Monte Carlo with vitality
        //B->montecarlo(0, 100, 300, 100, 0.1, 'B', i, false, true, false, lim > 0);   // Run of class B, solved by Monte Carlo with seasons
        B->montecarlo(0, 100, 300, 100, 0.1, 'B', i, false, false, true, lim > 0);    // Run of class B, solved by Monte Carlo with vaccination
        //B->montecarlo(0, 100, 300, 100, 0.1, 'B', i, true, true, false, lim > 0);    // Run of class B, solved by Monte Carlo with vitality and seasons
        //B->montecarlo(0, 100, 300, 100, 0.1, 'B', i, true, false, true, lim > 0);    // Run of class B, solved by Monte Carlo with vitality and vaccination
        //B->montecarlo(0, 100, 300, 100, 0.1, 'B', i, false, true, true, lim > 0);    // Run of class B, solved by Monte Carlo with seasons and vaccination
        //B->montecarlo(0, 100, 300, 100, 0.1, 'B', i, true, true, true, lim > 0);    // Run of class B, solved by Monte Carlo with vitality, seasons and vaccination
    }
/*
    SIRS * C = new SIRS;

    C->N = 400;
    C->a = 4;
    C->b = 3;
    C->c = 0.5;
    C->d = 0.006;
    C->dI = 0.002;
    C->e = 0.012;
    C->f = 0.1;

    //C->rungekutta(0, 100, 300, 100, 0.1, 'C', false, false, false);    // Run of class B, solved by Runge Kutta 4
    //C->rungekutta(0, 100, 300, 100, 0.1, 'C', true, false, false);   // Run of class B, solved by Runge Kutta 4 with vitality
    //C->rungekutta(0, 100, 300, 100, 0.1, 'C', false, true, false);   // Run of class B, solved by Runge Kutta 4 with seasons
    C->rungekutta(0, 100, 300, 100, 0.1, 'C', false, false, true);    // Run of class B, solved by Runge Kutta 4 with vaccination
    //C->rungekutta(0, 100, 300, 100, 0.1, 'C', true, true, false);    // Run of class B, solved by Runge Kutta 4 with vitality and seasons
    //C->rungekutta(0, 100, 300, 100, 0.1, 'C', true, false, true);    // Run of class B, solved by Runge Kutta 4 with vitality and vaccination
    //C->rungekutta(0, 100, 300, 100, 0.1, 'C', false, true, true);    // Run of class B, solved by Runge Kutta 4 with seasons and vaccination
    //C->rungekutta(0, 100, 300, 100, 0.1, 'C', true, true, true);    // Run of class B, solved by Runge Kutta 4 with vitality, seasons and vaccination
    for(int i = 0; i < lim; i++) {
        cout << "a" << endl;
        //C->montecarlo(0, 100, 300, 100, 0.1, 'C', i, false, false, false, lim > 0);    // Run of class C, solved by Monte Carlo
        //C->montecarlo(0, 100, 300, 100, 0.1, 'C', i, true, false, false, lim > 0);   // Run of class C, solved by Monte Carlo with vitality
        //C->montecarlo(0, 100, 300, 100, 0.1, 'C', i, false, true, false, lim > 0);   // Run of class C, solved by Monte Carlo with seasons
        C->montecarlo(0, 100, 300, 100, 0.1, 'C', i, false, false, true, lim > 0);    // Run of class C, solved by Monte Carlo with vaccination
        //C->montecarlo(0, 100, 300, 100, 0.1, 'C', i, true, true, false, lim > 0);    // Run of class C, solved by Monte Carlo with vitality and seasons
        //C->montecarlo(0, 100, 300, 100, 0.1, 'C', i, true, false, true, lim > 0);    // Run of class C, solved by Monte Carlo with vitality and vaccination
        //C->montecarlo(0, 100, 300, 100, 0.1, 'C', i, false, true, true, lim > 0);    // Run of class C, solved by Monte Carlo with seasons and vaccination
        //C->montecarlo(0, 100, 300, 100, 0.1, 'C', i, true, true, true, lim > 0);    // Run of class C, solved by Monte Carlo with vitality, seasons and vaccination
    }

    SIRS * D = new SIRS;

    D->N = 400;
    D->a = 4;
    D->b = 4;
    D->c = 0.5;
    D->d = 0.006;
    D->dI = 0.002;
    D->e = 0.012;
    D->f = 0.1;

    //D->rungekutta(0, 100, 300, 100, 0.1, 'D', false, false, false);    // Run of class D, solved by Runge Kutta 4
    //D->rungekutta(0, 100, 300, 100, 0.1, 'D', true, false, false);   // Run of class D, solved by Runge Kutta 4 with vitality
    //D->rungekutta(0, 100, 300, 100, 0.1, 'D', false, true, false);   // Run of class D, solved by Runge Kutta 4 with seasons
    D->rungekutta(0, 100, 300, 100, 0.1, 'D', false, false, true);    // Run of class D, solved by Runge Kutta 4 with vaccination
    //D->rungekutta(0, 100, 300, 100, 0.1, 'D', true, true, false);    // Run of class D, solved by Runge Kutta 4 with vitality and seasons
    //D->rungekutta(0, 100, 300, 100, 0.1, 'D', true, false, true);    // Run of class D, solved by Runge Kutta 4 with vitality and vaccination
    //D->rungekutta(0, 100, 300, 100, 0.1, 'D', false, true, true);    // Run of class D, solved by Runge Kutta 4 with seasons and vaccination
    //D->rungekutta(0, 100, 300, 100, 0.1, 'D', true, true, true);    // Run of class D, solved by Runge Kutta 4 with vitality, seasons and vaccination
    for(int i = 0; i < lim; i++) {
        cout << "a" << endl;
        //D->montecarlo(0, 100, 300, 100, 0.1, 'D', i, false, false, false, lim > 0);    // Run of class D, solved by Monte Carlo
        //D->montecarlo(0, 100, 300, 100, 0.1, 'D', i, true, false, false, lim > 0);   // Run of class D, solved by Monte Carlo with vitality
        //D->montecarlo(0, 100, 300, 100, 0.1, 'D', i, false, true, false, lim > 0);   // Run of class D, solved by Monte Carlo with seasons
        D->montecarlo(0, 100, 300, 100, 0.1, 'D', i, false, false, true, lim > 0);    // Run of class D, solved by Monte Carlo with vaccination
        //D->montecarlo(0, 100, 300, 100, 0.1, 'D', i, true, true, false, lim > 0);    // Run of class D, solved by Monte Carlo with vitality and seasons
        //D->montecarlo(0, 100, 300, 100, 0.1, 'D', i, true, false, true, lim > 0);    // Run of class D, solved by Monte Carlo with vitality and vaccination
        //D->montecarlo(0, 100, 300, 100, 0.1, 'D', i, false, true, true, lim > 0);    // Run of class D, solved by Monte Carlo with seasons and vaccination
        //D->montecarlo(0, 100, 300, 100, 0.1, 'D', i, true, true, true, lim > 0);    // Run of class D, solved by Monte Carlo with vitality, seasons and vaccination
    }
*/
    return 0;
}
