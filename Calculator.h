#ifndef CALCULATORH
#define CALCULATORH

#include<iostream>
#include<stdlib.h>
#include<cmath>
using namespace std;

class Calculator{
public :
	double evaluate(string question);					//evaluating the question
	double applyOP(double val1, double val2, char op);	//calculate the result of two input
	double tri(double val1, int y);						//calculate the trigonometry
	int precedence(char op);							//to see the precedence of arithmatic
};

#endif

