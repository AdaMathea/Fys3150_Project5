#include <iostream>
#include <random>
#include <utility>
#include <string>
#include <fstream>
#include <sstream>

#include <SIRS.h>
using namespace std;

double SIRS::dSdt(double t, double y) {
    double l = this->c*(this->N - this->S - this->I);
    double r = (this->a*this->S*this->I)/this->N;
    if(abs(l - r) < 1e-12) {
        //cout << "ops" << endl;
        return 0;
    }
    else {
        return l-r;
    }
}

double SIRS::dIdt(double t, double y) {
    double l = (this->a*this->S*this->I/this->N);
    double r = this->b*this->I;
    if(abs(l - r) < 1e-12) {
        //cout << "ops" << endl;
        return 0;
    }
    else {
        return l-r;
    }
}

double SIRS::dRdt(double t, double y) {
    double l = 1;
    double r = 2;
    if(abs(l - r) < 1e-12) {
        //cout << "ops" << endl;
        return 0;
    }
    else {
        return l-r;
    }
}

double SIRS::a_t(double omega, double a_0, double A, double t_n) {
    A*cos(omega*t_n) + a_0;
}

void SIRS::montecarlo(double t_0, double t, double S_0, double I_0, double h, bool season) {
    this->S = S_0;
    this->I = I_0;
    this->R = this->N - this->S - this->I;

    int n = (int)((t - t_0) / h); 
    
    random_device rd;  //Will be used to obtain a seed for the random number engine
    mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    uniform_real_distribution<double> dis(0, 1);

    double t_n = t_0;

    for(int i=1; i <= n; i++) {

        if(season = true) {
            this->a = a_t(2*M_PI/100, 4, 1, t_n);
        }
        else {
            this->a = this->a;
        }

        double delta_t = min(min(4/(this->a*this->N), 1/(this->b*this->N)), 1/(this->c*this->N));

        double p_si = this->a*this->S*this->I*delta_t/this->N;
        double p_ir = this->b*this->I*delta_t;
        double p_rs = this->c*this->R*delta_t;

        if(dis(gen) < p_si) {
            this->S -= 1;
            this->I += 1;
        }
        if(dis(gen) < p_ir) {
            this->I -= 1;
            this->R += 1;
        }
        if(dis(gen) < p_rs) {
            this->R -= 1;
            this->S += 1;
        }
        t_n += delta_t;
    }
}

void SIRS::rungekutta(double t_0, double S_0, double I_0, double t, double h) 
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
        double k1_R = h*this->dRdt(t_0, R); 

        double k2_S = h*this->dSdt(t_0 + 0.5*h, S + 0.5*k1_S); 
        double k2_I = h*this->dIdt(t_0 + 0.5*h, I + 0.5*k1_I); 
        double k2_R = h*this->dRdt(t_0 + 0.5*h, R + 0.5*k1_R); 

        double k3_S = h*this->dSdt(t_0 + 0.5*h, S + 0.5*k2_S); 
        double k3_I = h*this->dIdt(t_0 + 0.5*h, I + 0.5*k2_I); 
        double k3_R = h*this->dRdt(t_0 + 0.5*h, R + 0.5*k2_R); 

        double k4_S = h*this->dSdt(t_0 + h, S + k3_S); 
        double k4_I = h*this->dIdt(t_0 + h, I + k3_I); 
        double k4_R = h*this->dRdt(t_0 + h, R + k3_R); 

        // Update next value of y 
        S += (1.0/6.0)*(k1_S + 2*k2_S + 2*k3_S + k4_S);
        I += (1.0/6.0)*(k1_I + 2*k2_I + 2*k3_I + k4_I);
        R += (1.0/6.0)*(k1_R + 2*k2_R + 2*k3_R + k4_R);

        //cout << S << endl;

        // Update next value of t
        t_0 = t_0 + h; 

        this->S = S;
        this->I = I;
        this->R = this->N - this->S - this->I;
    } 

    
}