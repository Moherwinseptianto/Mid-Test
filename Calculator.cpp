#include"Calculator.h"
#include<iostream>
using namespace std;

Calculator::Calculator() : a(0.0), b(0.0) {}

void Calculator::get() {
    cout << endl;
    cout << endl;
	cout << "Enter the input : " << endl;
    cin >> a >> sym >> b >> e; 

	calculate(a,b,sym);
}

void Calculator::calculate(double a, double b, char sym) {
	if (e == '=') {
		if (sym == '+')
			result = (double) a + b;
		else if (sym == '-')
			result = (double) a - b;
		else if (sym == '/')
			result = (double) a / b;
		else if (sym == '*')
			result = (double) a * b;
		else {
			cout << "You enter the wrong input!!" << endl;
		}
	}
	else {
		cout << "Not the correct format";
	}
}

double Calculator::getResult() {
    return result;
}
