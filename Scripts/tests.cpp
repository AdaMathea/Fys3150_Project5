#include <iostream>
#include <random>

#include "tests.h"
#include "SIRS.h"

using namespace std;

/*
 Tester for funksjonene:

- double dSdt(double t, double y, bool vital);
- double dIdt(double t, double y, bool vital);
- double dRdt(double t, double y, bool vital);
- double a_t(double omega, double a_0, double A, double t_n);
- void rungekutta(double t_0, double t, double S_0, double I_0, double h, char letter, bool vital, bool season);
- void montecarlo(double t_0, double t, double S_0, double I_0, double h, char letter, int cycle, bool vital, bool season);

Alle disse ligger i klassen SIRS
*/


void tests::Test_dSdt(void)
{
    Nr_Tests += 1;  // Adding to total number of functions tested

    double tol = 1e-12; // Tolerance for tests
    int test_res = 0;   // number of tests passed
    int nr_test = 6;    // number of tests for this function

    // Initialises values for first two test
    SIRS * A = new SIRS;
    A->N = 1;
    A->S = 0;
    A->I = 1;
    A->R = 0;
    A->a = 4;
    A->b = 1;
    A->c = 0.5;
    A->d = 0.006;
    A->dI = 0.002;
    A->e = 0.012;

    double t = 0;
    double y = 0;

    // Expected results of the tests
    double exp_1 = 0;
    double exp_2 = 0.012;

    // Calculate the results for test 1 and 2
    double res_1 = A->dSdt(t, y, false);
    double res_2 = A->dSdt(t, y, true);

    // Print info if test is not passed
    if(abs(res_1 - exp_1) > tol)
    {
        cout << "Funksjonen dSdt passerte ikke test 1" << endl;
        cout << "N = " << A->N << endl;
        cout << "S = " << A->S << endl;
        cout << "I = " << A->I << endl;
        cout << "R = " << A->R << endl;
        cout << "a = " << A->a << endl;
        cout << "b = " << A->b << endl;
        cout << "c = " << A->c << endl;
        cout << "Resultat = " << res_1 << " Expected value = " << exp_1 << endl;
        cout << "--------------------------------------------------" << endl;
    }
    else    // if test is passed, add one to passed tests recorder
    {
        test_res += 1;
    }

    // Print info if test is not passed
    if(abs(res_2 - exp_2) > tol)
    {
        cout << "Funksjonen dSdt passerte ikke test 2" << endl;
        cout << "N = " << A->N << endl;
        cout << "S = " << A->S << endl;
        cout << "I = " << A->I << endl;
        cout << "R = " << A->R << endl;
        cout << "a = " << A->a << endl;
        cout << "b = " << A->b << endl;
        cout << "c = " << A->c << endl;
        cout << "d = " << A->d << endl;
        cout << "e = " << A->e << endl;
        cout << "Resultat = " << res_2 << " Expected value = " << exp_2 << endl;
        cout << "--------------------------------------------------" << endl;
    }
    else
    {
        test_res += 1;
    }

    // Initialising values for test 3 and 4
    A->N = 2;
    A->S = 1;
    A->I = 0;
    A->R = 1;

    // Expected values for test 3 and 4
    double exp_3 = 0.5;
    double exp_4 = 0.518;

    // Results for 3 and 4
    double res_3 = A->dSdt(t, y, false);
    double res_4 = A->dSdt(t, y, true);

    // Test 3
    if(abs(res_3 - exp_3) > tol)
    {
        cout << "Funksjonen dSdt passerte ikke test 3" << endl;
        cout << "N = " << A->N << endl;
        cout << "S = " << A->S << endl;
        cout << "I = " << A->I << endl;
        cout << "R = " << A->R << endl;
        cout << "a = " << A->a << endl;
        cout << "b = " << A->b << endl;
        cout << "c = " << A->c << endl;
        cout << "Resultat = " << res_3 << " Expected value = " << exp_3 << endl;
        cout << "--------------------------------------------------" << endl;
    }
    else
    {
        test_res += 1;
    }

    // Test 4
    if(abs(res_4 - exp_4) > tol)
    {
        cout << "Funksjonen dSdt passerte ikke test 4" << endl;
        cout << "N = " << A->N << endl;
        cout << "S = " << A->S << endl;
        cout << "I = " << A->I << endl;
        cout << "R = " << A->R << endl;
        cout << "a = " << A->a << endl;
        cout << "b = " << A->b << endl;
        cout << "c = " << A->c << endl;
        cout << "d = " << A->d << endl;
        cout << "e = " << A->e << endl;
        cout << "Resultat = " << res_4 << " Expected value = " << exp_4 << endl;
        cout << "--------------------------------------------------" << endl;
    }
    else
    {
        test_res += 1;
    }

    // Initialisation for test 5 and 6
    A->N = 6;
    A->S = 1;
    A->I = 2;
    A->R = 3;

    // Expected values for 5 and 6
    double exp_5 = 0.16666666666666666666666666666666666666666666666666666666666666666666666;
    double exp_6 = 0.23266666666666666666666666666666666666666666666666666666666666666666666;

    // Results for 5 and 6
    double res_5 = A->dSdt(t, y, false);
    double res_6 = A->dSdt(t, y, true);

    // Test 5
    if(abs(res_5 - exp_5) > tol)
    {
        cout << "Funksjonen dSdt passerte ikke test 5" << endl;
        cout << "N = " << A->N << endl;
        cout << "S = " << A->S << endl;
        cout << "I = " << A->I << endl;
        cout << "R = " << A->R << endl;
        cout << "a = " << A->a << endl;
        cout << "b = " << A->b << endl;
        cout << "c = " << A->c << endl;
        cout << "d = " << A->d << endl;
        cout << "e = " << A->e << endl;
        cout << "Resultat = " << res_5 << " Expected value = " << exp_5 << endl;
        cout << "--------------------------------------------------" << endl;
    }
    else
    {
        test_res += 1;
    }

    // Test 6
    if(abs(res_6 - exp_6) > tol)
    {
        cout << "Funksjonen dSdt passerte ikke test 6" << endl;
        cout << "N = " << A->N << endl;
        cout << "S = " << A->S << endl;
        cout << "I = " << A->I << endl;
        cout << "R = " << A->R << endl;
        cout << "a = " << A->a << endl;
        cout << "b = " << A->b << endl;
        cout << "c = " << A->c << endl;
        cout << "d = " << A->d << endl;
        cout << "e = " << A->e << endl;
        cout << "Resultat = " << res_6 << " Expected value = " << exp_6 << endl;
        cout << "--------------------------------------------------" << endl;
    }
    else
    {
        test_res += 1;
    }


    // Check if all tests are passed and at one to number of functions that have passed
    if(test_res == nr_test)
    {
        cout << "dSdt passerte alle tester" << endl;
        Nr_Tests_passed += 1;
    }
} // end of Test_dSdt

void tests::Test_dIdt(void)
{
    Nr_Tests += 1;  // Adding to total number of functions tested

    double tol = 1e-12; // Tolerance
    int test_res = 0;   // Passed tests
    int nr_test = 6;    // Number of tests

    // Initialisation
    SIRS * A = new SIRS;
    A->N = 1;
    A->S = 0;
    A->I = 1;
    A->R = 0;
    A->a = 4;
    A->b = 1;
    A->c = 0.5;
    A->d = 0.006;
    A->dI = 0.002;
    A->e = 0.012;

    double t = 0;
    double y = 0;

    // Expectations
    double exp_1 = - 1;
    double exp_2 = - 1.008;

    // results
    double res_1 = A->dIdt(t, y, false);
    double res_2 = A->dIdt(t, y, true);

    // Test 1
    if(abs(res_1 - exp_1) > tol)
    {
        cout << "Funksjonen dIdt passerte ikke test 1" << endl;
        cout << "N = " << A->N << endl;
        cout << "S = " << A->S << endl;
        cout << "I = " << A->I << endl;
        cout << "R = " << A->R << endl;
        cout << "a = " << A->a << endl;
        cout << "b = " << A->b << endl;
        cout << "c = " << A->c << endl;
        cout << "Resultat = " << res_1 << " Expected value = " << exp_1 << endl;
        cout << "--------------------------------------------------" << endl;
    }
    else
    {
        test_res += 1;
    }

    // Test 2
    if(abs(res_2 - exp_2) > tol)
    {
        cout << "Funksjonen dIdt passerte ikke test 2" << endl;
        cout << "N = " << A->N << endl;
        cout << "S = " << A->S << endl;
        cout << "I = " << A->I << endl;
        cout << "R = " << A->R << endl;
        cout << "a = " << A->a << endl;
        cout << "b = " << A->b << endl;
        cout << "c = " << A->c << endl;
        cout << "d = " << A->d << endl;
        cout << "d_I = " << A->dI << endl;
        cout << "Resultat = " << res_2 << " Expected value = " << exp_2 << endl;
        cout << "--------------------------------------------------" << endl;
    }
    else
    {
        test_res += 1;
    }

    // Initialisation
    A->N = 2;
    A->S = 1;
    A->I = 0;
    A->R = 1;

    // Expectations
    double exp_3 = 0;
    double exp_4 = 0;

    // Results
    double res_3 = A->dIdt(t, y, false);
    double res_4 = A->dIdt(t, y, true);

    // Test 3
    if(abs(res_3 - exp_3) > tol)
    {
        cout << "Funksjonen dIdt passerte ikke test 3" << endl;
        cout << "N = " << A->N << endl;
        cout << "S = " << A->S << endl;
        cout << "I = " << A->I << endl;
        cout << "R = " << A->R << endl;
        cout << "a = " << A->a << endl;
        cout << "b = " << A->b << endl;
        cout << "c = " << A->c << endl;
        cout << "Resultat = " << res_3 << " Expected value = " << exp_3 << endl;
        cout << "--------------------------------------------------" << endl;

    }
    else
    {
        test_res += 1;
    }

    // Test 4
    if(abs(res_4 - exp_4) > tol)
    {
        cout << "Funksjonen dIdt passerte ikke test 4" << endl;
        cout << "N = " << A->N << endl;
        cout << "S = " << A->S << endl;
        cout << "I = " << A->I << endl;
        cout << "R = " << A->R << endl;
        cout << "a = " << A->a << endl;
        cout << "b = " << A->b << endl;
        cout << "c = " << A->c << endl;
        cout << "d = " << A->d << endl;
        cout << "d_I = " << A->dI << endl;
        cout << "Resultat = " << res_4 << " Expected value = " << exp_4 << endl;
        cout << "--------------------------------------------------" << endl;
    }
    else
    {
        test_res += 1;
    }

    // Initialisation
    A->N = 6;
    A->S = 1;
    A->I = 2;
    A->R = 3;

    // Expectation
    double exp_5 = -0.6666666666666666666666666666666666666666666666666;
    double exp_6 = -0.6826666666666666666666666666666666666666666666666;

    // Results
    double res_5 = A->dIdt(t, y, false);
    double res_6 = A->dIdt(t, y, true);

    // Test 5
    if(abs(res_5 - exp_5) > tol)
    {
        cout << "Funksjonen dIdt passerte ikke test 5" << endl;
        cout << "N = " << A->N << endl;
        cout << "S = " << A->S << endl;
        cout << "I = " << A->I << endl;
        cout << "R = " << A->R << endl;
        cout << "a = " << A->a << endl;
        cout << "b = " << A->b << endl;
        cout << "c = " << A->c << endl;
        cout << "Resultat = " << res_5 << " Expected value = " << exp_5 << endl;
        cout << "--------------------------------------------------" << endl;
    }
    else
    {
        test_res += 1;
    }

    // Test 6
    if(abs(res_6 - exp_6) > tol)
    {
        cout << "Funksjonen dIdt passerte ikke test 6" << endl;
        cout << "N = " << A->N << endl;
        cout << "S = " << A->S << endl;
        cout << "I = " << A->I << endl;
        cout << "R = " << A->R << endl;
        cout << "a = " << A->a << endl;
        cout << "b = " << A->b << endl;
        cout << "c = " << A->c << endl;
        cout << "d = " << A->d << endl;
        cout << "d_I = " << A->dI << endl;
        cout << "Resultat = " << res_6 << " Expected value = " << exp_6 << endl;
        cout << "--------------------------------------------------" << endl;
    }
    else
    {
        test_res += 1;
    }


    // Update the number of functions passed
    if(test_res == nr_test)
    {
        cout << "dIdt passerte alle tester" << endl;
        Nr_Tests_passed += 1;
    }
} // end of Test_dIdt

void tests::Test_dRdt(void)
{
    Nr_Tests += 1;

    double tol = 1e-12;
    int test_res = 0;
    int nr_test = 6;

    SIRS * A = new SIRS;
    A->N = 1;
    A->S = 0;
    A->I = 1;
    A->R = 0;
    A->a = 4;
    A->b = 1;
    A->c = 0.5;
    A->d = 0.006;
    A->dI = 0.002;
    A->e = 0.012;

    double exp_1 = 1;
    double exp_2 = 1;
    double t = 0;
    double y = 0;

    double res_1 = A->dRdt(t, y, false);
    double res_2 = A->dRdt(t, y, true);

    if(abs(res_1 - exp_1) > tol)
    {
        cout << "Funksjonen dRdt passerte ikke test 1" << endl;
        cout << "N = " << A->N << endl;
        cout << "S = " << A->S << endl;
        cout << "I = " << A->I << endl;
        cout << "R = " << A->R << endl;
        cout << "a = " << A->a << endl;
        cout << "b = " << A->b << endl;
        cout << "c = " << A->c << endl;
        cout << "Resultat = " << res_1 << " Expected value = " << exp_1 << endl;
        cout << "--------------------------------------------------" << endl;
    }
    else
    {
        test_res += 1;
    }

    if(abs(res_2 - exp_2) > tol)
    {
        cout << "Funksjonen dRdt passerte ikke test 2" << endl;
        cout << "N = " << A->N << endl;
        cout << "S = " << A->S << endl;
        cout << "I = " << A->I << endl;
        cout << "R = " << A->R << endl;
        cout << "a = " << A->a << endl;
        cout << "b = " << A->b << endl;
        cout << "c = " << A->c << endl;
        cout << "d = " << A->d << endl;
        cout << "Resultat = " << res_2 << " Expected value = " << exp_2 << endl;
        cout << "--------------------------------------------------" << endl;
    }
    else
    {
        test_res += 1;
    }

    A->N = 2;
    A->S = 1;
    A->I = 0;
    A->R = 1;

    double exp_3 = - 0.5;
    double exp_4 = - 0.506;

    double res_3 = A->dRdt(t, y, false);
    double res_4 = A->dRdt(t, y, true);

    if(abs(res_3 - exp_3) > tol)
    {
        cout << "Funksjonen dRdt passerte ikke test 3" << endl;
        cout << "N = " << A->N << endl;
        cout << "S = " << A->S << endl;
        cout << "I = " << A->I << endl;
        cout << "R = " << A->R << endl;
        cout << "a = " << A->a << endl;
        cout << "b = " << A->b << endl;
        cout << "c = " << A->c << endl;
        cout << "Resultat = " << res_3 << " Expected value = " << exp_3 << endl;
        cout << "--------------------------------------------------" << endl;
    }
    else
    {
        test_res += 1;
    }

    if(abs(res_4 - exp_4) > tol)
    {
        cout << "Funksjonen dRdt passerte ikke test 4" << endl;
        cout << "N = " << A->N << endl;
        cout << "S = " << A->S << endl;
        cout << "I = " << A->I << endl;
        cout << "R = " << A->R << endl;
        cout << "a = " << A->a << endl;
        cout << "b = " << A->b << endl;
        cout << "c = " << A->c << endl;
        cout << "d = " << A->d << endl;
        cout << "Resultat = " << res_4 << " Expected value = " << exp_4 << endl;
        cout << "--------------------------------------------------" << endl;
    }
    else
    {
        test_res += 1;
    }

    A->N = 6;
    A->S = 1;
    A->I = 2;
    A->R = 3;

    double exp_5 = 0.5;
    double exp_6 = 0.482;

    double res_5 = A->dRdt(t, y, false);
    double res_6 = A->dRdt(t, y, true);

    if(abs(res_5 - exp_5) > tol)
    {
        cout << "Funksjonen dRdt passerte ikke test 5" << endl;
        cout << "N = " << A->N << endl;
        cout << "S = " << A->S << endl;
        cout << "I = " << A->I << endl;
        cout << "R = " << A->R << endl;
        cout << "a = " << A->a << endl;
        cout << "b = " << A->b << endl;
        cout << "c = " << A->c << endl;
        cout << "d = " << A->d << endl;
        cout << "Resultat = " << res_5 << " Expected value = " << exp_5 << endl;
        cout << "--------------------------------------------------" << endl;
    }
    else
    {
        test_res += 1;
    }

    if(abs(res_6 - exp_6) > tol)
    {
        cout << "Funksjonen dRdt passerte ikke test 6" << endl;
        cout << "N = " << A->N << endl;
        cout << "S = " << A->S << endl;
        cout << "I = " << A->I << endl;
        cout << "R = " << A->R << endl;
        cout << "a = " << A->a << endl;
        cout << "b = " << A->b << endl;
        cout << "c = " << A->c << endl;
        cout << "d = " << A->d << endl;
        cout << "Resultat = " << res_6 << " Expected value = " << exp_6 << endl;
        cout << "--------------------------------------------------" << endl;
    }
    else
    {
        test_res += 1;
    }


    if(test_res == nr_test)
    {
        cout << "dRdt passerte alle tester" << endl;
        Nr_Tests_passed += 1;
    }
} // end of Test_dRdt

void tests::Test_a_t(void)
{
    Nr_Tests += 1;

    double tol = 1e-12;
    int test_res = 0;
    int nr_test = 4;

    SIRS * A = new SIRS;
    double utslag = 0;  // Diviation from a_0 caused by cosin function
    double omega = 2 * M_PI / 100;  // Angle speed for cosin function
    double t = 0;   // Time value
    double a_0 = 0; // Base value for variating infection rate

    double exp_1 = 0;

    double res_1 = A->a_t(omega, a_0, utslag, t);

    if(abs(res_1 - exp_1) > tol)
    {
        cout << "Funksjonen a_t passerte ikke test 1" << endl;
        cout << "A = " << utslag << endl;
        cout << "Omega = " << omega << endl;
        cout << "t_n = " << t << endl;
        cout << "a_0 = " << a_0 << endl;
        cout << "Resultat = " << res_1 << " Expected value = " << exp_1 << endl;
        cout << "--------------------------------------------------" << endl;
    }
    else
    {
        test_res += 1;
    }


    utslag = 1;

    double exp_2 = 1;

    double res_2 = A->a_t(omega, a_0, utslag, t);

    if(abs(res_2 - exp_2) > tol)
    {
        cout << "Funksjonen a_t passerte ikke test 2" << endl;
        cout << "A = " << utslag << endl;
        cout << "Omega = " << omega << endl;
        cout << "t_n = " << t << endl;
        cout << "a_0 = " << a_0 << endl;
        cout << "Resultat = " << res_2 << " Expected value = " << exp_2 << endl;
        cout << "--------------------------------------------------" << endl;
    }
    else
    {
        test_res += 1;
    }


    t = 50;

    double exp_3 = -1;

    double res_3 = A->a_t(omega, a_0, utslag, t);

    if(abs(res_3 - exp_3) > tol)
    {
        cout << "Funksjonen a_t passerte ikke test 3" << endl;
        cout << "A = " << utslag << endl;
        cout << "Omega = " << omega << endl;
        cout << "t_n = " << t << endl;
        cout << "a_0 = " << a_0 << endl;
        cout << "Resultat = " << res_3 << " Expected value = " << exp_3 << endl;
        cout << "--------------------------------------------------" << endl;
    }
    else
    {
        test_res += 1;
    }


    utslag = 4;
    t = 50. / 3;
    a_0 = 4;

    double exp_4 = 6;

    double res_4 = A->a_t(omega, a_0, utslag, t);

    if(abs(res_4 - exp_4) > tol)
    {
        cout << "Funksjonen a_t passerte ikke test 4" << endl;
        cout << "A = " << utslag << endl;
        cout << "Omega = " << omega << endl;
        cout << "t_n = " << t << endl;
        cout << "a_0 = " << a_0 << endl;
        cout << "Resultat = " << res_4 << " Expected value = " << exp_4 << endl;
        cout << "--------------------------------------------------" << endl;
    }
    else
    {
        test_res += 1;
    }


    if(test_res == nr_test)
    {
        cout << "a_t passerte alle tester" << endl;
        Nr_Tests_passed += 1;
    }
} // end of Test_a_t

void tests::Test_rungekutta(void)
{
    Nr_Tests += 1;

    double tol = 1e-12;
    int test_res = 0;
    int nr_test = 12;

    SIRS * A = new SIRS;
    A->test = true;
    A->N = 0;
    A->a = 4;
    A->b = 1;
    A->c = 0.5;
    A->d = 0.006;
    A->dI = 0.002;
    A->e = 0.012;

    double t_0 = 0;
    double t = 1;
    double S_0 = 0;
    double I_0 = 0;
    double h = 0.1;
    char letter = 'A';

    A->rungekutta(t_0, t, S_0, I_0, h, letter, false, false);

    double exp_1 [3] = {0, 0, 0};
    double res_1 [3] = {A->S, A->I, A->R};

    if(abs(res_1[0] - exp_1[0]) > tol or abs(res_1[1] - exp_1[1]) > tol or abs(res_1[2] - exp_1[2]) > tol)
    {
        cout << "Funksjonen rungekutta passerte ikke test 1" << endl;
        cout << "N = " << A->N << endl;
        cout << "S_0 = " << S_0 << endl;
        cout << "I_0 = " << I_0 << endl;
        cout << "a = " << A->a << endl;
        cout << "b = " << A->b << endl;
        cout << "c = " << A->c << endl;
        cout << "d = " << A->d << endl;
        cout << "d_I = " << A->dI << endl;
        cout << "e = " << A->e << endl;
        for(int i = 0; i < 3; i++)
            cout << "Resultat = " << res_1[i] << " Expected value = " << exp_1[i] << endl;
        cout << "--------------------------------------------------" << endl;
    }
    else
    {
        test_res += 1;
    }


    A->N = 10;
    A->c = 1;

    S_0 = 9;
    h = 1;

    A->rungekutta(t_0, t, S_0, I_0, h, letter, false, false);

    double exp_2 [3] = {10, 0, 0};
    double res_2 [3] = {A->S, A->I, A->R};

    if(abs(res_2[0] - exp_2[0]) > tol or abs(res_2[1] - exp_2[1]) > tol or abs(res_2[2] - exp_2[2]) > tol)
    {
        cout << "Funksjonen rungekutta passerte ikke test 2" << endl;
        cout << "N = " << A->N << endl;
        cout << "S_0 = " << S_0 << endl;
        cout << "I_0 = " << I_0 << endl;
        cout << "a = " << A->a << endl;
        cout << "b = " << A->b << endl;
        cout << "c = " << A->c << endl;
        cout << "d = " << A->d << endl;
        cout << "d_I = " << A->dI << endl;
        cout << "e = " << A->e << endl;
        for(int i = 0; i < 3; i++)
            cout << "Resultat = " << res_2[i] << " Expected value = " << exp_2[i] << endl;
        cout << "--------------------------------------------------" << endl;
    }
    else
    {
        test_res += 1;
    }


    A->d = 10;
    A->dI = 2.3;
    A->e = M_PI;

    A->rungekutta(t_0, t, S_0, I_0, h, letter, false, false);

    double exp_3 [3] = {10, 0, 0};
    double res_3 [3] = {A->S, A->I, A->R};

    if(abs(res_3[0] - exp_3[0]) > tol or abs(res_3[1] - exp_3[1]) > tol or abs(res_3[2] - exp_3[2]) > tol)
    {
        cout << "Funksjonen rungekutta passerte ikke test 3" << endl;
        cout << "N = " << A->N << endl;
        cout << "S_0 = " << S_0 << endl;
        cout << "I_0 = " << I_0 << endl;
        cout << "a = " << A->a << endl;
        cout << "b = " << A->b << endl;
        cout << "c = " << A->c << endl;
        cout << "d = " << A->d << endl;
        cout << "d_I = " << A->dI << endl;
        cout << "e = " << A->e << endl;
        for(int i = 0; i < 3; i++)
            cout << "Resultat = " << res_3[i] << " Expected value = " << exp_3[i] << endl;
        cout << "--------------------------------------------------" << endl;
    }
    else
    {
        test_res += 1;
    }

    A->N = 0;
    A->c = 0.5;
    A->d = 0.006;
    A->dI = 0.002;
    A->e = 0.012;

    S_0 = 0;
    h = 0.1;

    A->rungekutta(t_0, t, S_0, I_0, h, letter, true, false);

    double exp_4 [3] = {0, 0, 0};
    double res_4 [3] = {A->S, A->I, A->R};

    if(abs(res_4[0] - exp_4[0]) > tol or abs(res_4[1] - exp_4[1]) > tol or abs(res_4[2] - exp_4[2]) > tol)
    {
        cout << "Funksjonen rungekutta passerte ikke test 4" << endl;
        cout << "N = " << A->N << endl;
        cout << "S_0 = " << S_0 << endl;
        cout << "I_0 = " << I_0 << endl;
        cout << "a = " << A->a << endl;
        cout << "b = " << A->b << endl;
        cout << "c = " << A->c << endl;
        cout << "d = " << A->d << endl;
        cout << "d_I = " << A->dI << endl;
        cout << "e = " << A->e << endl;
        for(int i = 0; i < 3; i++)
            cout << "Resultat = " << res_4[i] << " Expected value = " << exp_4[i] << endl;
        cout << "--------------------------------------------------" << endl;
    }
    else
    {
        test_res += 1;
    }


    A->N = 10;
    A->c = 1;
    S_0 = 9;
    h = 1;

    A->rungekutta(t_0, t, S_0, I_0, h, letter, true, false);

    double exp_5 [3] = {10.066, 0, 0};
    double res_5 [3] = {A->S, A->I, A->R};

    if(abs(res_5[0] - exp_5[0]) > tol or abs(res_5[1] - exp_5[1]) > tol or abs(res_5[2] - exp_5[2]) > tol)
    {
        cout << "Funksjonen rungekutta passerte ikke test 5" << endl;
        cout << "N = " << A->N << endl;
        cout << "S_0 = " << S_0 << endl;
        cout << "I_0 = " << I_0 << endl;
        cout << "a = " << A->a << endl;
        cout << "b = " << A->b << endl;
        cout << "c = " << A->c << endl;
        cout << "d = " << A->d << endl;
        cout << "d_I = " << A->dI << endl;
        cout << "e = " << A->e << endl;
        for(int i = 0; i < 3; i++)
            cout << "Resultat = " << res_5[i] << " Expected value = " << exp_5[i] << endl;
        cout << "--------------------------------------------------" << endl;
    }
    else
    {
        test_res += 1;
    }


    A->d = 10;
    A->dI = 2.3;
    A->e = M_PI;

    A->rungekutta(t_0, t, S_0, I_0, h, letter, true, false);

    double exp_6 [3] = {0, 0, 0};
    double res_6 [3] = {A->S, A->I, A->R};

    if(abs(res_6[0] - exp_6[0]) > tol or abs(res_6[1] - exp_6[1]) > tol or abs(res_6[2] - exp_6[2]) > tol)
    {
        cout << "Funksjonen rungekutta passerte ikke test 6" << endl;
        cout << "N = " << A->N << endl;
        cout << "S_0 = " << S_0 << endl;
        cout << "I_0 = " << I_0 << endl;
        cout << "a = " << A->a << endl;
        cout << "b = " << A->b << endl;
        cout << "c = " << A->c << endl;
        cout << "d = " << A->d << endl;
        cout << "d_I = " << A->dI << endl;
        cout << "e = " << A->e << endl;
        for(int i = 0; i < 3; i++)
            cout << "Resultat = " << res_6[i] << " Expected value = " << exp_6[i] << endl;
        cout << "--------------------------------------------------" << endl;
    }
    else
    {
        test_res += 1;
    }


    A->N = 0;
    A->c = 0.5;
    A->d = 0.006;
    A->dI = 0.002;
    A->e = 0.012;

    S_0 = 0;
    h = 0.1;

    A->rungekutta(t_0, t, S_0, I_0, h, letter, false, true);

    double exp_7 [3] = {0, 0, 0};
    double res_7 [3] = {A->S, A->I, A->R};

    if(abs(res_7[0] - exp_7[0]) > tol or abs(res_7[1] - exp_7[1]) > tol or abs(res_7[2] - exp_7[2]) > tol)
    {
        cout << "Funksjonen rungekutta passerte ikke test 7" << endl;
        cout << "N = " << A->N << endl;
        cout << "S_0 = " << S_0 << endl;
        cout << "I_0 = " << I_0 << endl;
        cout << "a = " << A->a << endl;
        cout << "b = " << A->b << endl;
        cout << "c = " << A->c << endl;
        cout << "d = " << A->d << endl;
        cout << "d_I = " << A->dI << endl;
        cout << "e = " << A->e << endl;
        for(int i = 0; i < 3; i++)
            cout << "Resultat = " << res_7[i] << " Expected value = " << exp_7[i] << endl;
        cout << "--------------------------------------------------" << endl;
    }
    else
    {
        test_res += 1;
    }


    A->N = 10;
    A->c = 1;
    S_0 = 9;
    h = 1;

    A->rungekutta(t_0, t, S_0, I_0, h, letter, false, true);

    double exp_8 [3] = {10, 0, 0};
    double res_8 [3] = {A->S, A->I, A-> R};

    if(abs(res_8[0] - exp_8[0]) > tol or abs(res_8[1] - exp_8[1]) > tol or abs(res_8[2] - exp_8[2]) > tol)
    {
        cout << "Funksjonen rungekutta passerte ikke test 8" << endl;
        cout << "N = " << A->N << endl;
        cout << "S_0 = " << S_0 << endl;
        cout << "I_0 = " << I_0 << endl;
        cout << "a = " << A->a << endl;
        cout << "b = " << A->b << endl;
        cout << "c = " << A->c << endl;
        cout << "d = " << A->d << endl;
        cout << "d_I = " << A->dI << endl;
        cout << "e = " << A->e << endl;
        for(int i = 0; i < 3; i++)
            cout << "Resultat = " << res_8[i] << " Expected value = " << exp_8[i] << endl;
        cout << "--------------------------------------------------" << endl;
    }
    else
    {
        test_res += 1;
    }


    A->d = 10;
    A->dI = 2.3;
    A->e = M_PI;

    A->rungekutta(t_0, t, S_0, I_0, h, letter, false, true);

    double exp_9 [3] = {10, 0, 0};
    double res_9 [3] = {A->S, A->I, A-> R};

    if(abs(res_9[0] - exp_9[0]) > tol or abs(res_9[1] - exp_9[1]) > tol or abs(res_9[2] - exp_9[2]) > tol)
    {
        cout << "Funksjonen rungekutta passerte ikke test 9" << endl;
        cout << "N = " << A->N << endl;
        cout << "S_0 = " << S_0 << endl;
        cout << "I_0 = " << I_0 << endl;
        cout << "a = " << A->a << endl;
        cout << "b = " << A->b << endl;
        cout << "c = " << A->c << endl;
        cout << "d = " << A->d << endl;
        cout << "d_I = " << A->dI << endl;
        cout << "e = " << A->e << endl;
        for(int i = 0; i < 3; i++)
            cout << "Resultat = " << res_9[i] << " Expected value = " << exp_9[i] << endl;
        cout << "--------------------------------------------------" << endl;
    }
    else
    {
        test_res += 1;
    }


    A->N = 0;
    A->c = 0.5;
    A->d = 0.006;
    A->dI = 0.002;
    A->e = 0.012;

    S_0 = 0;
    h = 0.1;

    A->rungekutta(t_0, t, S_0, I_0, h, letter, true, true);

    double exp_10 [3] = {0, 0, 0};
    double res_10 [3] = {A->S, A->I, A->R};

    if(abs(res_10[0] - exp_10[0]) > tol or abs(res_10[1] - exp_10[1]) > tol or abs(res_10[2] - exp_10[2]) > tol)
    {
        cout << "Funksjonen rungekutta passerte ikke test 10" << endl;
        cout << "N = " << A->N << endl;
        cout << "S_0 = " << S_0 << endl;
        cout << "I_0 = " << I_0 << endl;
        cout << "a = " << A->a << endl;
        cout << "b = " << A->b << endl;
        cout << "c = " << A->c << endl;
        cout << "d = " << A->d << endl;
        cout << "d_I = " << A->dI << endl;
        cout << "e = " << A->e << endl;
        for(int i = 0; i < 3; i++)
            cout << "Resultat = " << res_10[i] << " Expected value = " << exp_10[i] << endl;
        cout << "--------------------------------------------------" << endl;
    }
    else
    {
        test_res += 1;
    }


    A->N = 10;
    A->c = 1;
    S_0 = 9;
    h = 1;

    A->rungekutta(t_0, t, S_0, I_0, h, letter, true, true);

    double exp_11 [3] = {10.066, 0, 0};
    double res_11 [3] = {A->S, A->I, A-> R};

    if(abs(res_11[0] - exp_11[0]) > tol or abs(res_11[1] - exp_11[1]) > tol or abs(res_11[2] - exp_11[2]) > tol)
    {
        cout << "Funksjonen rungekutta passerte ikke test 11" << endl;
        cout << "N = " << A->N << endl;
        cout << "S_0 = " << S_0 << endl;
        cout << "I_0 = " << I_0 << endl;
        cout << "a = " << A->a << endl;
        cout << "b = " << A->b << endl;
        cout << "c = " << A->c << endl;
        cout << "d = " << A->d << endl;
        cout << "d_I = " << A->dI << endl;
        cout << "e = " << A->e << endl;
        for(int i = 0; i < 3; i++)
            cout << "Resultat = " << res_11[i] << " Expected value = " << exp_11[i] << endl;
        cout << "--------------------------------------------------" << endl;
    }
    else
    {
        test_res += 1;
    }


    A->d = 10;
    A->dI = 2.3;
    A->e = M_PI;

    A->rungekutta(t_0, t, S_0, I_0, h, letter, true, true);

    double exp_12 [3] = {0, 0, 0};
    double res_12 [3] = {A->S, A->I, A-> R};

    if(abs(res_12[0] - exp_12[0]) > tol or abs(res_12[1] - exp_12[1]) > tol or abs(res_12[2] - exp_12[2]) > tol)
    {
        cout << "Funksjonen rungekutta passerte ikke test 12" << endl;
        cout << "N = " << A->N << endl;
        cout << "S_0 = " << S_0 << endl;
        cout << "I_0 = " << I_0 << endl;
        cout << "a = " << A->a << endl;
        cout << "b = " << A->b << endl;
        cout << "c = " << A->c << endl;
        cout << "d = " << A->d << endl;
        cout << "d_I = " << A->dI << endl;
        cout << "e = " << A->e << endl;
        for(int i = 0; i < 3; i++)
            cout << "Resultat = " << res_12[i] << " Expected value = " << exp_12[i] << endl;
        cout << "--------------------------------------------------" << endl;
    }
    else
    {
        test_res += 1;
    }


    if(test_res == nr_test)
    {
        cout << "rungekutta passerte alle tester" << endl;
        Nr_Tests_passed += 1;
    }
} // end of Test_rungekutta

void tests::Test_montecarlo(void)
{
    Nr_Tests += 1;

    double tol = 1e-12;
    int test_res = 0;
    int nr_test = 12;

    SIRS * A = new SIRS;
    A->test = true;
    A->N = 0;
    A->a = 4;
    A->b = 1;
    A->c = 0.5;
    A->d = 0.006;
    A->dI = 0.002;
    A->e = 0.012;

    double t_0 = 0;
    double t = 100;
    double S_0 = 0;
    double I_0 = 0;
    double h = 0.1;
    char letter = 'A';

    A->montecarlo(t_0, t, S_0, I_0, h, letter, 0, false, false, false);

    double exp_1 [3] = {0, 0, 0};
    double res_1 [3] = {A->S, A->I, A->R};

    if(abs(res_1[0] - exp_1[0]) > tol or abs(res_1[1] - exp_1[1]) > tol or abs(res_1[2] - exp_1[2]) > tol)
    {
        cout << "Funksjonen montecarlo passerte ikke test 1" << endl;
        cout << "N = " << A->N << endl;
        cout << "S_0 = " << S_0 << endl;
        cout << "I_0 = " << I_0 << endl;
        cout << "a = " << A->a << endl;
        cout << "b = " << A->b << endl;
        cout << "c = " << A->c << endl;
        cout << "d = " << A->d << endl;
        cout << "d_I = " << A->dI << endl;
        cout << "e = " << A->e << endl;
        for(int i = 0; i < 3; i++)
            cout << "Resultat = " << res_1[i] << " Expected value = " << exp_1[i] << endl;
        cout << "--------------------------------------------------" << endl;
    }
    else
    {
        test_res += 1;
    }


    A->N = 10;
    A->c = 1;

    S_0 = 9;

    A->montecarlo(t_0, t, S_0, I_0, h, letter, 0, false, false, false);

    double exp_2 [3] = {10, 0, 0};
    double res_2 [3] = {A->S, A->I, A->R};

    if(abs(res_2[0] - exp_2[0]) > tol or abs(res_2[1] - exp_2[1]) > tol or abs(res_2[2] - exp_2[2]) > tol)
    {
        cout << "Funksjonen montecarlo passerte ikke test 2" << endl;
        cout << "N = " << A->N << endl;
        cout << "S_0 = " << S_0 << endl;
        cout << "I_0 = " << I_0 << endl;
        cout << "a = " << A->a << endl;
        cout << "b = " << A->b << endl;
        cout << "c = " << A->c << endl;
        cout << "d = " << A->d << endl;
        cout << "d_I = " << A->dI << endl;
        cout << "e = " << A->e << endl;
        for(int i = 0; i < 3; i++)
            cout << "Resultat = " << res_2[i] << " Expected value = " << exp_2[i] << endl;
        cout << "--------------------------------------------------" << endl;
    }
    else
    {
        test_res += 1;
    }


    A->d = 10;
    A->dI = 2.3;
    A->e = M_PI;

    A->montecarlo(t_0, t, S_0, I_0, h, letter, 0, false, false, false);

    double exp_3 [3] = {10, 0, 0};
    double res_3 [3] = {A->S, A->I, A->R};

    if(abs(res_3[0] - exp_3[0]) > tol or abs(res_3[1] - exp_3[1]) > tol or abs(res_3[2] - exp_3[2]) > tol)
    {
        cout << "Funksjonen montecarlo passerte ikke test 3" << endl;
        cout << "N = " << A->N << endl;
        cout << "S_0 = " << S_0 << endl;
        cout << "I_0 = " << I_0 << endl;
        cout << "a = " << A->a << endl;
        cout << "b = " << A->b << endl;
        cout << "c = " << A->c << endl;
        cout << "d = " << A->d << endl;
        cout << "d_I = " << A->dI << endl;
        cout << "e = " << A->e << endl;
        for(int i = 0; i < 3; i++)
            cout << "Resultat = " << res_3[i] << " Expected value = " << exp_3[i] << endl;
        cout << "--------------------------------------------------" << endl;
    }
    else
    {
        test_res += 1;
    }

    A->N = 0;
    A->c = 0.5;
    A->d = 0.006;
    A->dI = 0.002;
    A->e = 0.012;

    S_0 = 0;
    h = 0.1;

    A->montecarlo(t_0, t, S_0, I_0, h, letter, 0, true, false, false);

    double exp_4 [3] = {0, 0, 0};
    double res_4 [3] = {A->S, A->I, A->R};

    if(abs(res_4[0] - exp_4[0]) > tol or abs(res_4[1] - exp_4[1]) > tol or abs(res_4[2] - exp_4[2]) > tol)
    {
        cout << "Funksjonen montecarlo passerte ikke test 4" << endl;
        cout << "N = " << A->N << endl;
        cout << "S_0 = " << S_0 << endl;
        cout << "I_0 = " << I_0 << endl;
        cout << "a = " << A->a << endl;
        cout << "b = " << A->b << endl;
        cout << "c = " << A->c << endl;
        cout << "d = " << A->d << endl;
        cout << "d_I = " << A->dI << endl;
        cout << "e = " << A->e << endl;
        for(int i = 0; i < 3; i++)
            cout << "Resultat = " << res_4[i] << " Expected value = " << exp_4[i] << endl;
        cout << "--------------------------------------------------" << endl;
    }
    else
    {
        test_res += 1;
    }


    A->N = 10;
    A->c = 1;
    A->d = 0;
    A->e = 1;

    S_0 = 10;
    t   = 1;
    h = 1;

    A->montecarlo(t_0, t, S_0, I_0, h, letter, 0, true, false, false);

    double exp_5 [3] = {21, 0, 0};
    double res_5 [3] = {A->S, A->I, A->R};

    if(abs(res_5[0] - exp_5[0]) > tol or abs(res_5[1] - exp_5[1]) > tol or abs(res_5[2] - exp_5[2]) > tol)
    {
        cout << "Funksjonen montecarlo passerte ikke test 5" << endl;
        cout << "N = " << A->N << endl;
        cout << "S_0 = " << S_0 << endl;
        cout << "I_0 = " << I_0 << endl;
        cout << "a = " << A->a << endl;
        cout << "b = " << A->b << endl;
        cout << "c = " << A->c << endl;
        cout << "d = " << A->d << endl;
        cout << "d_I = " << A->dI << endl;
        cout << "e = " << A->e << endl;
        for(int i = 0; i < 3; i++)
            cout << "Resultat = " << res_5[i] << " Expected value = " << exp_5[i] << endl;
        cout << "--------------------------------------------------" << endl;
    }
    else
    {
        test_res += 1;
    }


    A->S = 10;
    A->d = 1;
    A->dI = 0;
    A->e = 1;

    A->montecarlo(t_0, t, S_0, I_0, h, letter, 0, true, false, false);

    double exp_6 [3] = {10, 0, 0};
    double res_6 [3] = {A->S, A->I, A->R};

    if(abs(res_6[0] - exp_6[0]) > tol or abs(res_6[1] - exp_6[1]) > tol or abs(res_6[2] - exp_6[2]) > tol)
    {
        cout << "Funksjonen montecarlo passerte ikke test 6" << endl;
        cout << "N = " << A->N << endl;
        cout << "S_0 = " << S_0 << endl;
        cout << "I_0 = " << I_0 << endl;
        cout << "a = " << A->a << endl;
        cout << "b = " << A->b << endl;
        cout << "c = " << A->c << endl;
        cout << "d = " << A->d << endl;
        cout << "d_I = " << A->dI << endl;
        cout << "e = " << A->e << endl;
        for(int i = 0; i < 3; i++)
            cout << "Resultat = " << res_6[i] << " Expected value = " << exp_6[i] << endl;
        cout << "--------------------------------------------------" << endl;
    }
    else
    {
        test_res += 1;
    }


    A->N = 0;
    A->a = 4;
    A->c = 0.5;
    A->d = 0.006;
    A->dI = 0.002;
    A->e = 0.012;

    S_0 = 0;
    h = 0.1;

    A->montecarlo(t_0, t, S_0, I_0, h, letter, 0, false, true, false);

    double exp_7 [3] = {0, 0, 0};
    double res_7 [3] = {A->S, A->I, A->R};

    if(abs(res_7[0] - exp_7[0]) > tol or abs(res_7[1] - exp_7[1]) > tol or abs(res_7[2] - exp_7[2]) > tol)
    {
        cout << "Funksjonen montecarlo passerte ikke test 7" << endl;
        cout << "N = " << A->N << endl;
        cout << "S_0 = " << S_0 << endl;
        cout << "I_0 = " << I_0 << endl;
        cout << "a = " << A->a << endl;
        cout << "b = " << A->b << endl;
        cout << "c = " << A->c << endl;
        cout << "d = " << A->d << endl;
        cout << "d_I = " << A->dI << endl;
        cout << "e = " << A->e << endl;
        for(int i = 0; i < 3; i++)
            cout << "Resultat = " << res_7[i] << " Expected value = " << exp_7[i] << endl;
        cout << "--------------------------------------------------" << endl;
    }
    else
    {
        test_res += 1;
    }


    A->N = 10;
    A->a = 4;
    A->c = 1;
    S_0 = 9;
    h = 1;

    A->montecarlo(t_0, t, S_0, I_0, h, letter, 0, false, true, false);

    double exp_8 [3] = {10, 0, 0};
    double res_8 [3] = {A->S, A->I, A-> R};

    if(abs(res_8[0] - exp_8[0]) > tol or abs(res_8[1] - exp_8[1]) > tol or abs(res_8[2] - exp_8[2]) > tol)
    {
        cout << "Funksjonen montecarlo passerte ikke test 8" << endl;
        cout << "N = " << A->N << endl;
        cout << "S_0 = " << S_0 << endl;
        cout << "I_0 = " << I_0 << endl;
        cout << "a = " << A->a << endl;
        cout << "b = " << A->b << endl;
        cout << "c = " << A->c << endl;
        cout << "d = " << A->d << endl;
        cout << "d_I = " << A->dI << endl;
        cout << "e = " << A->e << endl;
        for(int i = 0; i < 3; i++)
            cout << "Resultat = " << res_8[i] << " Expected value = " << exp_8[i] << endl;
        cout << "--------------------------------------------------" << endl;
    }
    else
    {
        test_res += 1;
    }


    A->a = 4;
    A->d = 10;
    A->dI = 2.3;
    A->e = M_PI;

    S_0 = 10;

    A->montecarlo(t_0, t, S_0, I_0, h, letter, 0, false, true, false);

    double exp_9 [3] = {10, 0, 0};
    double res_9 [3] = {A->S, A->I, A-> R};

    if(abs(res_9[0] - exp_9[0]) > tol or abs(res_9[1] - exp_9[1]) > tol or abs(res_9[2] - exp_9[2]) > tol)
    {
        cout << "Funksjonen montecarlo passerte ikke test 9" << endl;
        cout << "N = " << A->N << endl;
        cout << "S_0 = " << S_0 << endl;
        cout << "I_0 = " << I_0 << endl;
        cout << "a = " << A->a << endl;
        cout << "b = " << A->b << endl;
        cout << "c = " << A->c << endl;
        cout << "d = " << A->d << endl;
        cout << "d_I = " << A->dI << endl;
        cout << "e = " << A->e << endl;
        for(int i = 0; i < 3; i++)
            cout << "Resultat = " << res_9[i] << " Expected value = " << exp_9[i] << endl;
        cout << "--------------------------------------------------" << endl;
    }
    else
    {
        test_res += 1;
    }


    A->N = 0;
    A->a = 4;
    A->c = 0.5;
    A->d = 0.006;
    A->dI = 0.002;
    A->e = 0.012;

    S_0 = 0;
    h = 0.1;

    A->montecarlo(t_0, t, S_0, I_0, h, letter, 0, true, true, false);

    double exp_10 [3] = {0, 0, 0};
    double res_10 [3] = {A->S, A->I, A->R};

    if(abs(res_10[0] - exp_10[0]) > tol or abs(res_10[1] - exp_10[1]) > tol or abs(res_10[2] - exp_10[2]) > tol)
    {
        cout << "Funksjonen montecarlo passerte ikke test 10" << endl;
        cout << "N = " << A->N << endl;
        cout << "S_0 = " << S_0 << endl;
        cout << "I_0 = " << I_0 << endl;
        cout << "a = " << A->a << endl;
        cout << "b = " << A->b << endl;
        cout << "c = " << A->c << endl;
        cout << "d = " << A->d << endl;
        cout << "d_I = " << A->dI << endl;
        cout << "e = " << A->e << endl;
        for(int i = 0; i < 3; i++)
            cout << "Resultat = " << res_10[i] << " Expected value = " << exp_10[i] << endl;
        cout << "--------------------------------------------------" << endl;
    }
    else
    {
        test_res += 1;
    }


    A->N = 10;
    A->a = 4;
    A->c = 1;
    A->d = 0;
    A->e = 0;

    S_0 = 10;
    t   = 1;
    h = 1;

    A->montecarlo(t_0, t, S_0, I_0, h, letter, 0, true, true, false);

    double exp_11 [3] = {10, 0, 0};
    double res_11 [3] = {A->S, A->I, A-> R};

    if(abs(res_11[0] - exp_11[0]) > tol or abs(res_11[1] - exp_11[1]) > tol or abs(res_11[2] - exp_11[2]) > tol)
    {
        cout << "Funksjonen montecarlo passerte ikke test 11" << endl;
        cout << "N = " << A->N << endl;
        cout << "S_0 = " << S_0 << endl;
        cout << "I_0 = " << I_0 << endl;
        cout << "a = " << A->a << endl;
        cout << "b = " << A->b << endl;
        cout << "c = " << A->c << endl;
        cout << "d = " << A->d << endl;
        cout << "d_I = " << A->dI << endl;
        cout << "e = " << A->e << endl;
        for(int i = 0; i < 3; i++)
            cout << "Resultat = " << res_11[i] << " Expected value = " << exp_11[i] << endl;
        cout << "--------------------------------------------------" << endl;
    }
    else
    {
        test_res += 1;
    }


    A->a = 4;
    A->dI = 2.3;
    A->e = 0;

    A->montecarlo(t_0, t, S_0, I_0, h, letter, 0, true, true, false);

    double exp_12 [3] = {10, 0, 0};
    double res_12 [3] = {A->S, A->I, A-> R};

    if(abs(res_12[0] - exp_12[0]) > tol or abs(res_12[1] - exp_12[1]) > tol or abs(res_12[2] - exp_12[2]) > tol)
    {
        cout << "Funksjonen montecarlo passerte ikke test 12" << endl;
        cout << "N = " << A->N << endl;
        cout << "S_0 = " << S_0 << endl;
        cout << "I_0 = " << I_0 << endl;
        cout << "a = " << A->a << endl;
        cout << "b = " << A->b << endl;
        cout << "c = " << A->c << endl;
        cout << "d = " << A->d << endl;
        cout << "d_I = " << A->dI << endl;
        cout << "e = " << A->e << endl;
        for(int i = 0; i < 3; i++)
            cout << "Resultat = " << res_12[i] << " Expected value = " << exp_12[i] << endl;
        cout << "--------------------------------------------------" << endl;
    }
    else
    {
        test_res += 1;
    }


    if(test_res == nr_test)
    {
        cout << "montecarlo passerte alle tester" << endl;
        Nr_Tests_passed += 1;
    }
} // end of Test_montecarlo

bool tests::Run_Tests(void)
{
    Test_dSdt();    // Run test of dSdt function
    Test_dIdt();    // Run test of dIdt function
    Test_dRdt();    // Run test of dRdt function
    Test_a_t();     // Run test of a_t function
    Test_rungekutta();  // Run test of rungekutta function
    Test_montecarlo();  // Run test of montecarlo function

    // Checks if all tests are passed
    if(Nr_Tests == Nr_Tests_passed)
    {
        return true;
    }

    else
    {
        return false;
    }
} // end of Run_Tests
