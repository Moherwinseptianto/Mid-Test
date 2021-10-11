#ifndef CALCULATORH
#define CALCULATORH

#include<iostream>
using namespace std;

class Calculator {
    private :
        double a, b;
        char sym, e;
        double result;
    public :
        Calculator();
        void get();
        void calculate(double a, double b, char sym);
        double getResult();
};

#endif

