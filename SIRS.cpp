#include <iostream>
#include <random>
#include <utility>
#include <string>
#include <fstream>
#include <sstream>

#include <SIRS.h>
using namespace std;

double SIRS::dSdt(double t, double y) {
    return this->c*(this->N - this->S - this->I) - (this->a*this->S*this->I)/this->N;
}

double SIRS::dIdt(double t, double y) {
    return this->a*this->S*this->I/this->N - this->b*this->I;
}

double SIRS::rungekutta(double t_0, double S_0, double I_0, double t, double h = 0) 
{ 
    // Count number of iterations using step size or 
    // step height h 
    int n = (int)((t - t_0) / h); 

    double k1_S, k2_S, k3_S, k4_S;
    double k1_I, k2_I, k3_I, k4_I;

    S = S_0;
    I = I_0;

    // Iterate for number of iterations 
    for (int i=1; i<=n; i++) 
    { 
        // Apply Runge Kutta Formulas to find 
        // next value of y 
        double k1_S = h*this->dSdt(t_0, S); 
        double k1_I = h*this->dIdt(t_0, I); 

        double k2_S = h*this->dSdt(t_0 + 0.5*h, S + 0.5*k1_S); 
        double k2_I = h*this->dIdt(t_0 + 0.5*h, I + 0.5*k1_I); 

        double k3_S = h*this->dSdt(t_0 + 0.5*h, S + 0.5*k2_S); 
        double k3_I = h*this->dIdt(t_0 + 0.5*h, I + 0.5*k2_I); 

        double k4_S = h*this->dSdt(t_0 + h, S + k3_S); 
        double k4_I = h*this->dIdt(t_0 + h, I + k3_I); 

        // Update next value of y 
        S = S + (1.0/6.0)*(k1_S + 2*k2_S + 2*k3_S + k4_S);
        I = I + (1.0/6.0)*(k1_I + 2*k2_I + 2*k3_I + k4_I);

        // Update next value of x 
        t_0 = t_0 + h; 

        this->S = S;
        this->I = I;
        this->R = this->N - this->S - this->I;
    } 

    
}
