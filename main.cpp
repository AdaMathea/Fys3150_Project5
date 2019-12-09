#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

#include <SIRS.h>

using namespace std;

int main()
{
    SIRS * sirs = new SIRS;

    sirs->N = 400;
    //sirs->S = 400;
    //sirs->I = 100;
    //sirs->R = 0
    sirs->a = 4;
    sirs->b = 1;
    sirs->c = 0.5;

    sirs->rungekutta(0, 300, 100, 100, 1);

    cout << sirs->S << endl;

}
