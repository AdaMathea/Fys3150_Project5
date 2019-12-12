#ifndef TESTS_H
#define TESTS_H


class tests
{
public:
    bool Run_Tests(void);

    int Nr_Tests = 0;
    int Nr_Tests_passed = 0;

private:
    void Test_dSdt(void);
    void Test_dIdt(void);
    void Test_dRdt(void);
    void Test_a_t(void);
    void Test_rungekutta(void);
    void Test_montecarlo(void);

};

#endif // TESTS_H
