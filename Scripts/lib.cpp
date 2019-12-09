#include <cmath>
#include <iostream>
#include <fstream>

#include "lib.h"


using namespace std;

void lib::Set_up_lists(int Pop, int Pop_S, int Pop_I, int Pop_R, int N)
{
    cout << "Setting up lists" << endl;

    // Set up class constants
    this->Pop   = Pop;
    this->Pop_S = Pop_S;
    this->Pop_I = Pop_I;
    this->Pop_R = Pop_R;
    this->N     = N;


    // Set up pointers for susceptable, infected and recovered

    // S = susceptable
    double * S_A = new double [N];
    S_A[0] = 1;
    S_A[1] = 2;
    double * S_B = new double [N];
    double * S_C = new double [N];
    double * S_D = new double [N];

    S_A[0] = S_B[0] = S_C[0] = S_D[0] = Pop_S;

    // I = infected
    double * I_A = new double [N];
    double * I_B = new double [N];
    double * I_C = new double [N];
    double * I_D = new double [N];

    I_A[0] = I_B[0] = I_C[0] = I_D[0] = Pop_I;

    // R = recovered
    double * R_A = new double [N];
    double * R_B = new double [N];
    double * R_C = new double [N];
    double * R_D = new double [N];

    R_A[0] = R_B[0] = R_C[0] = R_D[0] = Pop_R;
    cout << "her" << endl;
    this->S[0] = &S_A; this->S[1] = &S_B; this->S[2] = &S_C; this->S[3] = &S_D;
    cout << "her" << endl;
    for(int i = 0; i < 100; i++)
        cout << this->S[0][i][0] << endl;

    this->I[0] = &I_A; this->I[1] = &I_B; this->I[2] = &I_C; this->I[3] = &I_D;
    this->R[0] = &R_A; this->R[1] = &R_B; this->R[2] = &R_C; this->R[3] = &R_D;
    cout << "her" << endl;
    // Set up rates
    this->a[0] = 4.0; this->a[1] = 4.0; this->a[3] = 4.0; this->a[3] = 4.0;
    this->b[0] = 1.0; this->b[1] = 2.0; this->b[3] = 3.0; this->b[3] = 4.0;
    this->c[0] = 0.5; this->c[1] = 0.5; this->c[2] = 0.5; this->c[3] = 0.5;
}

double lib::S_f(double S, double I, double a, double b, double c)
{
    return c * (Pop - S - I) - (a * S * I) / (this->Pop);
}

double lib::I_f(double S, double I, double a, double b, double c)
{
    return (a * S * I) / Pop - b * I;
}

void lib::RK4(double t, double h, int i, int j)
{
    cout << this->S[j][i][0] << endl;
    double k_1_S = h * this->S_f(this->S[j][i][0], this->I[j][i][0], this->a[j], this->b[j], this->c[j]);
    double k_1_I = h * this->I_f(this->S[j][i][0], this->I[j][i][0], this->a[j], this->b[j], this->c[j]);

    double k_2_S = h * this->S_f(this->S[j][i][0] + k_1_S / 2, this->I[j][i][0] + k_1_I / 2, this->a[j], this->b[j], this->c[j]);
    double k_2_I = h * this->S_f(this->S[j][i][0] + k_1_S / 2, this->I[j][i][0] + k_1_I / 2, this->a[j], this->b[j], this->c[j]);

    double k_3_S = h * this->S_f(this->S[j][i][0] + k_2_S / 2, this->I[j][i][0] + k_2_I / 2, this->a[j], this->b[j], this->c[j]);
    double k_3_I = h * this->I_f(this->S[j][i][0] + k_2_S / 2, this->I[j][i][0] + k_2_I / 2, this->a[j], this->b[j], this->c[j]);

    double k_4_S = h * this->S_f(this->S[j][i][0] + k_3_S / 2, this->I[j][i][0] + k_3_I / 2, this->a[j], this->b[j], this->c[j]);
    double k_4_I = h * this->I_f(this->S[j][i][0] + k_3_S, this->I[j][i][0] + k_3_I, this->a[j], this->b[j], this->c[j]);

    S[j][i + 1][0] = S[j][i][0] + 1 / 6 * (k_1_S + 2 * k_2_S + 2 * k_3_S + k_4_S);
    I[j][i + 1][0] = I[j][i][0] + 1 / 6 * (k_1_I + 2 * k_2_I + 2 * k_3_I + k_4_I);
    R[j][i + 1][0] = this->Pop - S[j][i + 1][0] - I[j][i + 1][0];
}
