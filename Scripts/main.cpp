#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

#include <lib.h>

using namespace std;

int main()
{
    cout << "Setting up parameters" << endl;

    lib * Lib = new lib;

    int N       = 10;
    int t_0     = 0;
    int t_1     = 10;

    double t = t_0;
    double h = t_1 - t_0 / (double) N;

    Lib->Set_up_lists(400, 300, 100, 400 - 300 - 100, N);

    cout << "Starting Simulation" << endl;

    for(int i = 0; i < N; i += h)
    {
        t += h;

        for(int j = 0; j < 4; j++)
        {
            Lib->RK4(t, h, i, j);
        }
        cout << Lib->S[i][0] << "     " << Lib->S[i][3] << endl;
    }

    return 0;
}
