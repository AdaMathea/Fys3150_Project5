#include <iostream>
#include <random>
#include <utility>
#include <string>
#include <fstream>
#include <sstream>

#include <SIRS.h>
using namespace std;

double SIRS::dSdt(double t, double y, bool vital = false, bool vacc = false)
{
    // A function calculating the growth of S

    double value = c * R - (a * S * I) / N; // The growth

    if (vital == true)
    {
        value +=  - d * S + e * N; // The growth if vital dynamics is enabled
    }
    if (vacc == true)
    {
        value += - f;   // The growth if vacsines are enabled
    }

    if(abs(value) < 1e-12)  // if the growth is really small, it is set to 0
    {
        return 0;
    }
    else
    {
        return value;
    }
} // end of dSdt

double SIRS::dIdt(double t, double y, bool vital = false)
{
    // A function calculating the growth of I

    double value = (a * S * I / N) - b * y; // The growth

    if (vital == true)
    {
        value += - d * I - dI * I;    // The growth if vital dynamics is enabled
    }

    if(abs(value) < 1e-12)
    {
        return 0;
    }
    else
    {
        return value;
    }
} // end of dIdt

double SIRS::dRdt(double t, double y, bool vital = false, bool vacc = false)
{
    // A function calculating the growth of I

    double value = b * I - c * R;   // The growth

    if (vital == true)
    {
        value += - d * R;   // The growth if vital dynamics is enabled
    }

    if (vacc == true)
    {
        value += f;
    }

    if(abs(value) < 1e-12)
    {
        return 0;
    }
    else
    {
        return value;
    }
} // end of dRdt

double SIRS::a_t(double omega, double a_0, double A, double t_n)
{
    // A function calculating the rate of infection if season dynamics are enabled

    return A * cos(omega * t_n) + a_0;
} // end of a_t

double SIRS::f_t(double t)
{
    // A function calculating the rate of vaccination

    return f * t;
} // end of f_t

void SIRS::rungekutta(double t_0, double t, double S_0, double I_0, double h, char letter, bool vital = false, bool season = false, bool vacc = false)
{
    /* Runge Kutta 4 solver for the SIRS modell
     * It takes these parameters:
       - t_0    = Time at the start of simulation
       - t      = Time at the end of the simulation
       - S_0    = Population susceptible at the start
       - I_0    = Population infected at the start
       - h      = Stepsize of simulation
       - letter = Variable used to name the class when datarecording
       - vital  = Enables vital dynamics
       - season = Enables season variations
     * Results can be found in the file created by this function
     * or the last values can be found as this->S, this->I and this->R.
    */

    int n = (int)((t - t_0) / h);   // Number of iterations using step size or step height h

    t_ = t_0;   // Variable used to recorde time under simulation

    double k1_S, k2_S, k3_S, k4_S;
    double k1_I, k2_I, k3_I, k4_I;
    double k1_R, k2_R, k3_R, k4_R;

    if(N < S_0 + I_0)   // Checking if the amount of people in S and I are less then or equal to the total population
    {
        cout << "N ble endret fra " << N << " til " << S_0 + I_0 << endl;
        N = S_0 + I_0;
    }

    // Initialising values
    S = S_0;
    I = I_0;
    R = N - S - I;

    // Open and setting up file to save values if testing is not enabled
    ofstream myfile;

    if(test == false)
    {
        string filename = "RK_vac.txt";

        if (letter == 'A')  // Opens file at the beginning if letter equals A
        {
            myfile.open(filename);
        }
        else
        {
            myfile.open(filename, ios::app);    // Opens the file at the end else
        }
        myfile << letter << endl << "t S I R" << endl;
        myfile << t_ << " " << S << " " << I << " " << R << endl;
    }

    // Iterate n times
    for (int i=1; i<=n; i++) 
    { 
        if(season == true)
        {
            a = a_t(2*M_PI/365.25, 4, 1, t_);  // Calculate the variating a if seasons are enabled
        }

        if (vacc == true)
        {
            f = f_t(t_);  // Calculation of the variating f
        }

        // Apply Runge Kutta Formulas to find next value of y

        k1_S = h * this->dSdt(t_0, S, vital, vacc);
        k1_I = h * this->dIdt(t_0, I, vital);
        k1_R = h * this->dRdt(t_0, R, vital, vacc);

        k2_S = h * this->dSdt(t_0 + 0.5 * h, S + 0.5 * k1_S, vital, vacc);
        k2_I = h * this->dIdt(t_0 + 0.5 * h, I + 0.5 * k1_I, vital);
        k2_R = h * this->dRdt(t_0 + 0.5 * h, R + 0.5 * k1_R, vital, vacc);

        k3_S = h * this->dSdt(t_0 + 0.5 * h, S + 0.5 * k2_S, vital, vacc);
        k3_I = h * this->dIdt(t_0 + 0.5 * h, I + 0.5 * k2_I, vital);
        k3_R = h * this->dRdt(t_0 + 0.5 * h, R + 0.5 * k2_R, vital, vacc);

        k4_S = h * this->dSdt(t_0 + h, S + k3_S, vital, vacc);
        k4_I = h * this->dIdt(t_0 + h, I + k3_I, vital);
        k4_R = h * this->dRdt(t_0 + h, R + k3_R, vital, vacc);

        // Update next value of y
        S += (1.0/6.0) * (k1_S + 2 * k2_S + 2 * k3_S + k4_S);
        I += (1.0/6.0) * (k1_I + 2 * k2_I + 2 * k3_I + k4_I);
        R += (1.0/6.0) * (k1_R + 2 * k2_R + 2 * k3_R + k4_R);

        // Round values under half a person to zeros to avoid zombies
        if(S < 0.5)
        {
            S = 0;
        }
        if(I < 0.5)
        {
            I = 0;
        }
        if(R < 0.5)
        {
            R = 0;
        }

        // Update next value of t
        t_ = t_ + h;

        if(test == false)
        {
            // Write to file if test is not enabled
            myfile << t_ << " " << S << " " << I << " " << R << endl;
        }
    }

    if(test == false)
    {
        // Marking the ende of this model in the result file
        myfile << "-----------------------------------------" << endl;
        myfile.close();
    }
} // end of rungekutta

void SIRS::montecarlo(double t_0, double t, double S_0, double I_0, double h, char letter, int cycle = 100, bool vital = false, bool season = false, bool vacc = false, bool multicycle = false)
{
    /* Monte Carlo solver for the SIRS modell
     * It takes these parameters:
       - t_0    = Time at the start of simulation
       - t      = Time at the end of the simulation
       - S_0    = Population susceptible at the start
       - I_0    = Population infected at the start
       - h      = Not used
       - letter = Variable used to name the class when datarecording
       - vital  = Enables vital dynamics
       - season = Enables season variations
     * Results can be found in the file created by this function
     * or the last values can be found as this->S, this->I and this->R.
    */

    t_ = t_0;   // Time variable

    if(N < S_0 + I_0)   // Correcting N
    {
        cout << "N ble endret fra " << N << " til " << S_0 + I_0 << endl;;
        N = S_0 + I_0;
    }

    // Initialising values
    S = S_0;
    I = I_0;
    R = N - S - I;

    // Setting up the random number generator, giving us values from zeros to one
    random_device rd;  //Will be used to obtain a seed for the random number engine
    mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    uniform_real_distribution<double> dis(0, 1);

    // Open file to save values
    ofstream myfile;

    if(test == false)
    {
        string filename;
        if(!multicycle) {
            filename = "MC_vac.txt"; // Opens different file then the Runge Kutta function
        }
        else {
            filename = "MC_vac" + to_string(cycle) + ".txt"; // Opens different file then the Runge Kutta function
        }

        if (letter == 'A')
        {
            myfile.open(filename);
        }
        else
        {
            myfile.open(filename, ios::app);
        }

        myfile << letter << endl << "t S I R" << endl;
        myfile << t_ << " " << S << " " << I << " " << R << endl;
    }

    // Sets up probability variables
    double p_si;    // Probability of passing from S to I
    double p_ir;    // Probability of passing from I to R
    double p_rs;    // Probability of passing from R to S
    double p_sd;    // Probability of S population dying
    double p_id;    // Probability of I population dying
    double p_id_;   // Probability of I population dying from the illness
    double p_rd;    // Probability of R population dying
    double p_bs;    // Probability of birth
    double p_sr;    // Probability of vaccination
    double delta_t; // Timestep for this step of the simulation

    // Simulates until the time variable is bigger than or equal to the end time.
    while(t_ < t)
    {
        if(season == true)
        {
            a = a_t(2*M_PI/365.25, 4, 1, t_);  // Calculates the variable infection rate
        }

        if (vacc == true)
        {
            f = f_t(t_);  // Calculation of the variating f
        }

        delta_t = min(min(4 / (a * N), 1 / (b * N)), 1 / (c * N));  // Finds the timestep

        // Callculates the probablities
        p_si = a * S * I * delta_t / N;
        p_ir = b * I * delta_t;
        p_rs = c * R * delta_t;

        if(dis(gen) < p_si) // Randomly move person form S to I
        {
            S -= 1;
            I += 1;
        }
        if(dis(gen) < p_ir) // Randomly move person form I to R
        {
            I -= 1;
            R += 1;
        }
        if(dis(gen) < p_rs) // Randomly move person form R to S
        {
            R -= 1;
            S += 1;
        }

        if (vital == true)
        {
            // Calculating more probabilities if vital is enabled
            p_sd    = delta_t * (d * S);
            p_id    = delta_t * (d * I);
            p_id_   = delta_t * (dI * I);
            p_rd    = delta_t * (d * R);
            p_bs    = delta_t * (e * N);

            if(dis(gen) < p_sd) // Randomly remove person form S
            {
                S -= 1;
            }
            if(dis(gen) < p_id) // Randomly remove person form I
            {
                I -= 1;
            }
            if(dis(gen) < p_id_)    // Randomly remove person form I
            {
                I -= 1;
            }
            if(dis(gen) < p_rd) // Randomly remove person form R
            {
                R -= 1;
            }
            if (dis(gen) < p_bs)    // Randomly adding person form S
            {
                S += 1;
            }
        }

        if (vacc == true)
            // Calculating probability if vaccines are enabled
            p_sr    = delta_t * f;

            if(dis(gen) < p_sr)
            {
                S -= 1;
                R += 1;
            }

        t_ += delta_t;  // Updating time

        if(test == false)
        {
            // Write to file
            myfile << t_ << " " << S << " " << I << " " << R << endl;
        }
    }
    if(test == false)
    {
        // Separating models in result file
        myfile << "-----------------------------------------" << endl;
        myfile.close();
    }
} // end of montecarlo
