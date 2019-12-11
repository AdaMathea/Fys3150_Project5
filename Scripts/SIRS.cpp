#include <iostream>
#include <random>
#include <utility>
#include <string>
#include <fstream>
#include <sstream>

#include <SIRS.h>
using namespace std;

double SIRS::dSdt(double t, double y, bool vital = false)
{
    if (vital == true)
    {
        double value = c * R - (a * S * I) / N - d * S + e * N;
        if(abs(value) < 1e-12)
        {
            return 0;
        }
        else
        {
            return value;
        }
    }
    else
    {
        double value = c * (N - S - I) - (a * S * I) / N;
        if(abs(value) < 1e-12)
        {
            return 0;
        }
        else
        {
            return value;
        }
    }
}

double SIRS::dIdt(double t, double y, bool vital = false)
{
    if (vital == true)
    {
        double value = (a * S * I / N) - b * I - d * I - dI * I;
        if(abs(value) < 1e-12)
        {
            return 0;
        }
        else
        {
            return value;
        }
    }
    else
    {
        double value = (a * S * I / N) - b * I;
        if(abs(value) < 1e-12)
        {
            return 0;
        }
        else
        {
            return value;
        }
    }
}

double SIRS::dRdt(double t, double y, bool vital = false)
{
    if (vital == true)
    {
        double value = b * I - c * R - d * R;
        if(abs(value) < 1e-12)
        {
            return 0;
        }
        else
        {
            return value;
        }
    }
    else
    {
        return 1;
    }
}

double SIRS::a_t(double omega, double a_0, double A, double t_n)
{
    return A * cos(omega * t_n) + a_0;
}

void SIRS::montecarlo(double t_0, double t, double S_0, double I_0, double h, char letter, bool vital = false, bool season = false) {
    S = S_0;
    I = I_0;
    R = N - S - I;

    int n = (int)((t - t_0) / h); 
    
    random_device rd;  //Will be used to obtain a seed for the random number engine
    mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    uniform_real_distribution<double> dis(0, 1);

    t_ = t_0;

    // Open file to save values
    ofstream myfile;
    if (letter == 'A')
    {
        myfile.open("5b.txt");
    }
    else
    {
        myfile.open("5b.txt", ios::app);
    }
    myfile << letter << endl << "t S I R" << endl;
    myfile << t_ << " " << S << " " << I << " " << R << endl;

    for(int i=1; i <= n; i++)
    {
        double p_si;
        double p_ir;
        double p_rs;
        double delta_t;

        if(season == true)
        {
            a = a_t(2 * M_PI / 100, 4, 1, t_);
        }

        if (vital == true)
        {
            delta_t = min(min(4 / (a * N), 1 / (b * N)), 1 / (c * N));

            p_si = delta_t * (a * S * I / N - d * S);
            p_ir = delta_t * (b * I - d * I - dI * I);
            p_rs = delta_t * (c * R - d * R);
        }

        else
        {
            delta_t = min(min(4 / (a * N), 1 / (b * N)), 1 / (c * N));

            p_si = a * S * I * delta_t / N;
            p_ir = b * I * delta_t;
            p_rs = c * R * delta_t;
        }

        if(dis(gen) < p_si)
        {
            S -= 1;
            I += 1;
        }
        if(dis(gen) < p_ir)
        {
            I -= 1;
            R += 1;
        }
        if(dis(gen) < p_rs)
        {
            R -= 1;
            S += 1;
        }

        t_ += delta_t;

        // Write to file
        myfile << t_ << " " << S << " " << I << " " << R << endl;
    }
    myfile << "------------------------------" << endl;
    myfile.close();
}

void SIRS::rungekutta(double t_0, double S_0, double I_0, double t, double h, char letter, char Model, bool vital = false, bool season = false)
{ 
    // Count number of iterations using step size or 
    // step height h 
    int n = (int)((t - t_0) / h); 

    t_ = t_0;

    S = S_0;
    I = I_0;

    // Open file to save values
    ofstream myfile;
    if (letter == 'A')
    {
        myfile.open("5a.txt");
    }
    else
    {
        myfile.open("5a.txt", ios::app);
    }
    
    myfile << letter << endl << "t S I R" << endl;
    myfile << t_ << " " << S << " " << I << " " << R << endl;

    // Iterate for number of iterations 
    for (int i=1; i<=n; i++) 
    { 
        if(season == true)
        {
            a = a_t(2 * M_PI / 100, 4, 1, t_);
        }
        // Apply Runge Kutta Formulas to find
        // next value of y
        double k1_S = h * this->dSdt(t_0, S);
        double k1_I = h * this->dIdt(t_0, I);
        double k1_R = h * this->dRdt(t_0, R);

        double k2_S = h * this->dSdt(t_0 + 0.5*h, S + 0.5*k1_S);
        double k2_I = h * this->dIdt(t_0 + 0.5*h, I + 0.5*k1_I);
        double k2_R = h * this->dRdt(t_0 + 0.5*h, R + 0.5*k1_R);

        double k3_S = h * this->dSdt(t_0 + 0.5*h, S + 0.5*k2_S);
        double k3_I = h * this->dIdt(t_0 + 0.5*h, I + 0.5*k2_I);
        double k3_R = h * this->dRdt(t_0 + 0.5*h, R + 0.5*k2_R);

        double k4_S = h * this->dSdt(t_0 + h, S + k3_S);
        double k4_I = h * this->dIdt(t_0 + h, I + k3_I);
        double k4_R = h * this->dRdt(t_0 + h, R + k3_R);

        // Update next value of y 
        S += (1.0/6.0) * (k1_S + 2 * k2_S + 2 * k3_S + k4_S);
        I += (1.0/6.0) * (k1_I + 2 * k2_I + 2 * k3_I + k4_I);
        R += (1.0/6.0) * (k1_R + 2 * k2_R + 2 * k3_R + k4_R);

        //cout << S << endl;
        // Update next value of t
        t_ = t_ + h;

        R = N - S - I;

        // Write to file
        myfile << t_ << " " << S << " " << I << " " << R << endl;
    }
    myfile << "-----------------------------------------" << endl;
    myfile.close();
}
