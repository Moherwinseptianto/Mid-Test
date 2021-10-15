#include"Calculator.h"
#include"Queue.h"
#include<iostream>
#include<stdlib.h>
#include<cmath>
using namespace std;

//Precedence of the arithmatic
//If the precendence is low, then the return number is small
//vice versa
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

//Calculate two number according to operator
double Calculator::applyOP(double val1, double val2, char op){
	switch(op){
		case '+' : return val2 + val1;
		case '-' : return val2 - val1;
		case '*' : return val2 * val1;
		case '/' : return val2 / val1;
		case '^' : return pow(val2, val1);
	}
}

//Calculate the trigonometry
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

//Evaluating the question
double Calculator::evaluate(string question){
	int i;				//i is index for the question
	Queue values(100);	//new queue for the values
	Queue ops(100);		//new queue for the operators
	
	//Looping so the entire question can be evaluated
	for (i=0; i < question.length(); i++){
		
		//continue if blank or whitespace 
		if (question[i] == ' '){
			continue;
		}
		
		//if the open bracket
		//push the bracked to the ops queue
		else if (question[i] == '('){
			ops.charEnqueue(question[i]);
		}
		
		//if cos
		//calculate the values
		else if (question[i] == 'c') {
			int y=1;						//to symbolize the cos
			double result = 0;				//to store the values of the cos(num)
			
			//checking the number until we find the close bracket
			while (i<question.length() && question[i] != ')'){
				i++;
				double val = 0; //set the val to 0
				if(isdigit(question[i])){
					while (i<question.length() && isdigit(question[i])){
						val = (val*10) + (question[i]-'0'); //calculating the number
						i++;
						//if the number is float
						if (question[i] == '.' || question[i] == ','){
							i=i+1;
							int j=-1; //index of the how many number behind the comas
							while (i<question.length() && isdigit(question[i])){
								//calculating number behind the comas
								float point = ((question[i]-'0') * pow(10,j--)); 
								val = (double) (val) + point;
								i++;
							}
						}
					}
					//Need to decrease the index to correct the order of checking				
					i--;
					//Get the value of cos
					result = tri(val, y); 
				}
			}
			values.numEnqueue(result); //push the values to the values queue
		}
		
		//if sin
		//same with cos
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

		//if tan
		//same with cos and sin
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
		
		//if arc
		//same with cos, sin, tan with the difference
		//we need to see if this is acos, asin, or atan
		else if (question[i] == 'a') {
			int y;
			double result = 0;
			i++;
			//checking the acos, asin, or atan
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
	
		//if log or ln
		//same with arc
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

		//if digit
		else if (isdigit(question[i])){
			double val = 0;
			
			//we need to calculate the number
			while (i<question.length() && isdigit(question[i])){
				val = (val*10) + (question[i]-'0');
				i++;
				// if the input number is float
				if (question[i] == '.' || question[i] == ','){
					i=i+1;
					int j=-1; //index how many number behind the comas
					while (i<question.length() && isdigit(question[i])){
						float point = ((question[i]-'0') * pow(10,j--)); 	//calculate the number behind the comas
						val = (double) (val) + point; 						//combine the number
						i++;
					}
				}
			}
			
			values.numEnqueue(val); //push number to queue values
			i--; 					//correcting the order
		}

		//if square root
		//same with cos, sin, tan
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
					result = sqrt(val); //the difference is in the result
				}
			}
			values.numEnqueue(result);
		}
		
		//if closed bracket
		//we need to solve the entire bracket
		//ex : a * (b+c)
		else if(question[i] == ')'){
			//see if the ops queue is empty and the ops queue is not the open bracket
			while (!ops.isEmpty() && ops.getRear() != '('){
				//take the values
				double val1 = values.getRear();
				values.Dequeue(); //pop the values
				
				//take the values
				double val2 = values.getRear();
				values.Dequeue(); //pop the values
				
				//take the operator
				char op = ops.getRear();
				ops.Dequeue(); //pop the operator
				
				values.numEnqueue(applyOP(val1, val2, op)); //push the values we get from the result to values queue
			}
			
			//pop the open bracket
			if (!ops.isEmpty()){
				ops.Dequeue();
			}
		}
		
		//if operators
		else {
			//check if the queue is empty and the precendance the current
			//is higher than the lastest one is correct
			//evaluate it
			while (!ops.isEmpty() && precedence(ops.getRear()) >= precedence(question[i])){
				double val1 = values.getRear();
				values.Dequeue();
				
				double val2 = values.getRear();
				values.Dequeue();
				
				char op = ops.getRear();
				ops.Dequeue();
				
				values.numEnqueue(applyOP(val1, val2, op)); //push the result to values queue
			}
			
			//if the precendance is wrong
			//push the operator to queue
			ops.charEnqueue(question[i]);
		}
	}
	
	//after checking all of the question
	//the values inside the queue is already in order
	//evaluate it
	while(!ops.isEmpty()){
		double val1 = values.getRear();
		values.Dequeue();
		
		double val2 = values.getRear();
		values.Dequeue();
		
		char op = ops.getRear();
		ops.Dequeue();
		
		values.numEnqueue(applyOP(val1, val2, op));
	}
	
	//after all of the values and operator have been evaluated
	//queue values will have one values inside the queue
	return values.getRear();
}
