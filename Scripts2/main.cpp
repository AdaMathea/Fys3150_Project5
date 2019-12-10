#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

#include <SIRS.h>

using namespace std;

int main()
{
    //cout << "A:" << endl;

    SIRS * A = new SIRS;

    A->N = 400;
    A->a = 4;
    A->b = 1;
    A->c = 0.5;

    A->rungekutta(0, 300, 100, 100, 0.1);
    
    //cout << "B:" << endl;

    SIRS * B = new SIRS;

    B->N = 400;
    B->a = 4;
    B->b = 2;
    B->c = 0.5;

    B->rungekutta(0, 300, 100, 100, 0.1);

    //cout << "C:" << endl;

    SIRS * C = new SIRS;

    C->N = 400;
    C->a = 4;
    C->b = 3;
    C->c = 0.5;

    C->rungekutta(0, 300, 100, 100, 0.1);

    //cout << "D:" << endl;

    SIRS * D = new SIRS;

    D->N = 400;
    D->a = 4;
    D->b = 4;
    D->c = 0.5;

    D->rungekutta(0, 300, 100, 100, 0.1);
    

    cout << A->S << " " << B->S << " " << C->S << " " << D->S << endl;
    cout << A->I << " " << B->I << " " << C->I << " " << D->I << endl;
    cout << A->R << " " << B->R << " " << C->R << " " << D->R << endl;

}