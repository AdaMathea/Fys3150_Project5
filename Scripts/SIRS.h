#ifndef SIRS_H
#define SIRS_H

class SIRS {
    private:
        
    public:
        //Values
        double a;
        double b;
        double c;
        double d;
        double dI;
        double e;
        double f;
        double S;
        double I;
        double N;
        double R;

        //Variables
        double t_;
        bool test = false;

        //Functions
        double f_t(double);
        double dSdt(double, double, bool, bool);
        double dIdt(double, double, bool);
        double dRdt(double, double, bool, bool);
        double a_t(double, double, double, double);
        void rungekutta(double, double, double, double, double, char, bool, bool, bool);
        void montecarlo(double, double, double, double, double, char, int, bool, bool, bool, bool);
    
};

#endif //ISING_H
