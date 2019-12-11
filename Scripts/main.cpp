#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

#include <SIRS.h>

using namespace std;

int main()
{
    SIRS * A = new SIRS;

    A->N = 400;
    A->a = 4;
    A->b = 1;
    A->c = 0.5;
    A->d = 0.008;
    A->dI = 0.002;
    A->e = 0.012;

    A->rungekutta(0, 300, 100, 100, 0.1, 'A', false, false);
    //A->rungekutta(0, 300, 100, 100, 0.1, 'A', true, false);
    //A->rungekutta(0, 300, 100, 100, 0.1, 'A', false, true);
    //A->rungekutta(0, 300, 100, 100, 0.1, 'A', true, true);
    A->montecarlo(0, 100, 300, 100, 0.1, 'A', false, false);
    //A->montecarlo(0, 100, 300, 100, 0.1, 'A', true, false);
    //A->montecarlo(0, 100, 300, 100, 0.1, 'A', false, true);
    //A->montecarlo(0, 100, 300, 100, 0.1, 'A', true, true);

    SIRS * B = new SIRS;

    B->N = 400;
    B->a = 4;
    B->b = 2;
    B->c = 0.5;
    A->d = 0.008;
    A->dI = 0.002;
    A->e = 0.012;

    B->rungekutta(0, 300, 100, 100, 0.1, 'B', false, false);
    //B->rungekutta(0, 300, 100, 100, 0.1, 'B', true, false);
    //B->rungekutta(0, 300, 100, 100, 0.1, 'B', false, true);
    //B->rungekutta(0, 300, 100, 100, 0.1, 'B', true, true);
    B->montecarlo(0, 100, 300, 100, 0.1, 'B', false, false);
    //B->montecarlo(0, 100, 300, 100, 0.1, 'B', true, false);
    //B->montecarlo(0, 100, 300, 100, 0.1, 'B', false, true);
    //B->montecarlo(0, 100, 300, 100, 0.1, 'B', true, true);

    SIRS * C = new SIRS;

    C->N = 400;
    C->a = 4;
    C->b = 3;
    C->c = 0.5;
    A->d = 0.008;
    A->dI = 0.002;
    A->e = 0.012;

    C->rungekutta(0, 300, 100, 100, 0.1, 'C', false, false);
    //C->rungekutta(0, 300, 100, 100, 0.1, 'C', true, false);
    //C->rungekutta(0, 300, 100, 100, 0.1, 'C', false, true);
    //C->rungekutta(0, 300, 100, 100, 0.1, 'C', true, true);
    C->montecarlo(0, 100, 300, 100, 0.1, 'C', false, false);
    //C->montecarlo(0, 100, 300, 100, 0.1, 'C', true, false);
    //C->montecarlo(0, 100, 300, 100, 0.1, 'C', false, true);
    //C->montecarlo(0, 100, 300, 100, 0.1, 'C', true, true);

    SIRS * D = new SIRS;

    D->N = 400;
    D->a = 4;
    D->b = 4;
    D->c = 0.5;
    A->d = 0.008;
    A->dI = 0.002;
    A->e = 0.012;

    D->rungekutta(0, 300, 100, 100, 0.1, 'D', false, false);
    //D->rungekutta(0, 300, 100, 100, 0.1, 'D', true, false);
    //D->rungekutta(0, 300, 100, 100, 0.1, 'D', false, true);
    //D->rungekutta(0, 300, 100, 100, 0.1, 'D', true, true);
    D->montecarlo(0, 100, 300, 100, 0.1, 'D', false, false);
    //D->montecarlo(0, 100, 300, 100, 0.1, 'D', true, false);
    //D->montecarlo(0, 100, 300, 100, 0.1, 'D', false, true);
    //D->montecarlo(0, 100, 300, 100, 0.1, 'D', true, true);
    

    cout << A->S << " " << B->S << " " << C->S << " " << D->S << endl;
    cout << A->I << " " << B->I << " " << C->I << " " << D->I << endl;
    cout << A->R << " " << B->R << " " << C->R << " " << D->R << endl;

}
