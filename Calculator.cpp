#include"Calculator.h"
#include"Queue.h"
#include<iostream>
#include<stdlib.h>
#include<cmath>
using namespace std;

int Calculator::precedence(char op){
	if (op == '+' || op == '-'){
		return 1;
	}
	if (op == '*' || op == '/'){
		return 2;
	}
	if (op == '^'){
		return 3;
	}
	else {
		return 0;
	}
}

double Calculator::applyOP(double val1, double val2, char op){
	switch(op){
		case '+' : return val2 + val1;
		case '-' : return val2 - val1;
		case '*' : return val2 * val1;
		case '/' : return val2 / val1;
		case '^' : return pow(val2, val1);
	}
}

double Calculator::tri(double val1, int y){
	switch(y){
		case 1: return cos(val1);
		case 2: return sin(val1);
		case 3: return tan(val1);
		case 4: return acos(val1);
		case 5: return asin(val1);
		case 6: return atan(val1);
		case 7: return log10(val1);
		case 8: return log(val1);
	}
}

double Calculator::evaluate(string question){
	int i;
	Queue values(100);
	Queue ops(100);
	
	for (i=0; i < question.length(); i++){
		
		if (question[i] == ' '){
			continue;
		}
		
		else if (question[i] == '('){
			ops.charEnqueue(question[i]);
		}
		
		else if (question[i] == 'c') {
			int y=1;
			double result = 0;
			while (i<question.length() && question[i] != ')'){
				i++;
				double val = 0;
				if(isdigit(question[i])){
					while (i<question.length() && isdigit(question[i])){
						val = (val*10) + (question[i]-'0');
						i++;
						if (question[i] == '.' || question[i] == ','){
							i=i+1;
							int j=-1;
							while (i<question.length() && isdigit(question[i])){
								float point = ((question[i]-'0') * pow(10,j--));
								val = (double) (val) + point;
								i++;
							}
						}
					}					
					i--;
					result = tri(val, y);
				}
			}
			values.numEnqueue(result);
		}

		else if (question[i] == 's') {
			int y=2;
			double result = 0;
			while (i<question.length() && question[i] != ')'){
				i++;
				double val = 0;
				if(isdigit(question[i])){
					while (i<question.length() && isdigit(question[i])){
						val = (val*10) + (question[i]-'0');
						i++;
						if (question[i] == '.' || question[i] == ','){
							i=i+1;
							int j=-1;
							while (i<question.length() && isdigit(question[i])){
								float point = ((question[i]-'0') * pow(10,j--));
								val = (double) (val) + point;
								i++;
							}
						}
					}					
					i--;
					result = tri(val, y);
				}
			}
			values.numEnqueue(result);
		}

		else if (question[i] == 't') {
			int y=3;
			double result = 0;
			while (i<question.length() && question[i] != ')'){
				i++;
				double val = 0;
				if(isdigit(question[i])){
					while (i<question.length() && isdigit(question[i])){
						val = (val*10) + (question[i]-'0');
						i++;
						if (question[i] == '.' || question[i] == ','){
							i=i+1;
							int j=-1;
							while (i<question.length() && isdigit(question[i])){
								float point = ((question[i]-'0') * pow(10,j--));
								val = (double) (val) + point;
								i++;
							}
						}
					}					
					i--;
					result = tri(val, y);
				}
			}
			values.numEnqueue(result);
		}

		else if (question[i] == 'a') {
			int y;
			double result = 0;
			i++;
			switch(question[i]){
				case 'c': y=4; break;
				case 's': y=5; break;
				case 't': y=6; break;
			}
			while (i<question.length() && question[i] != ')'){
				i++;
				double val = 0;
				if(isdigit(question[i])){
					while (i<question.length() && isdigit(question[i])){
						val = (val*10) + (question[i]-'0');
						i++;
						if (question[i] == '.' || question[i] == ','){
							i=i+1;
							int j=-1;
							while (i<question.length() && isdigit(question[i])){
								float point = ((question[i]-'0') * pow(10,j--));
								val = (double) (val) + point;
								i++;
							}
						}
					}					
					i--;
					result = tri(val, y);
				}
			}
			values.numEnqueue(result);
		}

		else if (question[i] == 'l') {
			int y;
			double result = 0;
			i++;
			switch(question[i]){
				case 'o': y=7; break;
				case 'n': y=8; break;
			}
			while (i<question.length() && question[i] != ')'){
				i++;
				double val = 0;
				if(isdigit(question[i])){
					while (i<question.length() && isdigit(question[i])){
						val = (val*10) + (question[i]-'0');
						i++;
						if (question[i] == '.' || question[i] == ','){
							i=i+1;
							int j=-1;
							while (i<question.length() && isdigit(question[i])){
								float point = ((question[i]-'0') * pow(10,j--));
								val = (double) (val) + point;
								i++;
							}
						}
					}					
					i--;
					result = tri(val, y);
				}
			}
			values.numEnqueue(result);
		}

		
		else if (isdigit(question[i])){
			double val = 0;
			
			while (i<question.length() && isdigit(question[i])){
				val = (val*10) + (question[i]-'0');
				i++;
				if (question[i] == '.' || question[i] == ','){
					i=i+1;
					int j=-1;
					while (i<question.length() && isdigit(question[i])){
						float point = ((question[i]-'0') * pow(10,j--));
						val = (double) (val) + point;
						i++;
					}
				}
			}
			
			values.numEnqueue(val);
			i--;
		}

		else if (question[i] == 'r') {
			double result = 0;
			while (i<question.length() && question[i] != ')'){
				i++;
				double val = 0;
				if(isdigit(question[i])){
					while (i<question.length() && isdigit(question[i])){
						val = (val*10) + (question[i]-'0');
						i++;
						if (question[i] == '.' || question[i] == ','){
							i=i+1;
							int j=-1;
							while (i<question.length() && isdigit(question[i])){
								float point = ((question[i]-'0') * pow(10,j--));
								val = (double) (val) + point;
								i++;
							}
						}
					}					
					i--;
					result = sqrt(val);
				}
			}
			values.numEnqueue(result);
		}
		
		else if(question[i] == ')'){
			while (!ops.isEmpty() && ops.getRear() != '('){
				double val1 = values.getRear();
				values.Dequeue();
				
				double val2 = values.getRear();
				values.Dequeue();
				
				char op = ops.getRear();
				ops.Dequeue();
				
				values.numEnqueue(applyOP(val1, val2, op));
			}
			
			if (!ops.isEmpty()){
				ops.Dequeue();
			}
		}
		
		else {
			while (!ops.isEmpty() && precedence(ops.getRear()) >= precedence(question[i])){
				double val1 = values.getRear();
				values.Dequeue();
				
				double val2 = values.getRear();
				values.Dequeue();
				
				char op = ops.getRear();
				ops.Dequeue();
				
				values.numEnqueue(applyOP(val1, val2, op));
			}
			
			ops.charEnqueue(question[i]);
		}
	}
	
	while(!ops.isEmpty()){
		double val1 = values.getRear();
		values.Dequeue();
		
		double val2 = values.getRear();
		values.Dequeue();
		
		char op = ops.getRear();
		ops.Dequeue();
		
		values.numEnqueue(applyOP(val1, val2, op));
	}
	
	return values.getRear();
}
