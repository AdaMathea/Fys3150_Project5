#ifndef SIRS_H
#define SIRS_H

class SIRS {
    private:
        
    public:
        //Values
        double a;
        double b;
        double c;
        double S;
        double I;
        double N;
        double R;

        //Functions
        double dSdt(double, double);
        double dIdt(double, double);
        double dRdt(double, double);
        double a_t(double, double, double, double);
        void rungekutta(double, double, double, double, double, bool);
        void montecarlo(double, double, double, double, double, bool);
    
};

#endif //ISING_H