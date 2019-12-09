#ifndef LIB_H
#define LIB_H


class lib
{
    public:
        void Set_up_lists(int, int, int, int, int);

        double S_f(double, double, double, double, double);
        double I_f(double, double, double, double, double);

        void RK4(double, double, int , int);

        int Pop;
        int Pop_S;
        int Pop_I;
        int Pop_R;
        int N;

        double ** S [4];
        double ** I [4];
        double ** R [4];

        double * a = new double [4];
        double * b = new double [4];
        double * c = new double [4];
};

#endif // LIB_H
