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
        double S;
        double I;
        double N;
        double R;

        //Variables
        double t_;
        bool test = false;

        //Functions
        double dSdt(double, double, bool);
        double dIdt(double, double, bool);
        double dRdt(double, double, bool);
        double a_t(double, double, double, double);
        void rungekutta(double, double, double, double, double, char, bool, bool);
        void montecarlo(double, double, double, double, double, char, int, bool, bool);
    
};

#endif //ISING_H
