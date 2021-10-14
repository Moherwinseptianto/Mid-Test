#ifndef CALCULATORH
#define CALCULATORH

#include<iostream>
#include<stdlib.h>
#include<cmath>
using namespace std;

class Calculator{
public :
	double evaluate(string question);
	double applyOP(double val1, double val2, char op);
	double tri(double val1, int y);
	int precedence(char op);
};


#endif

