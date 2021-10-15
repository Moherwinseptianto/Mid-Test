#include"Calculator.h"
#include"Queue.h"
#include<iostream>
#include<stdlib.h>
#include<cmath>
using namespace std;


int main() {
    Calculator cal;
    string ques;
    
    cout << "Enter your question : ";
	getline(cin, ques);
	
	cout << "= " << cal.evaluate(ques) << endl;
    return 0;
}
