#ifndef SIRS_H
#define SIRS_H

class SIRS {
    private:
        
    public:
        //Values
        int a;
        int b;
        double c;
        int S;
        int I;
        int N;
        int R;

        //Functions
        double dSdt(double, double);
        double dIdt(double, double);
        //double dRdt();
        double rungekutta(double, double, double, double, double);
    
};

#endif //ISING_H