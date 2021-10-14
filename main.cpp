#include"Calculator.h"
#include"Queue.h"
#include<iostream>
#include<stdlib.h>
#include<cmath>
using namespace std;


int main() {
    Calculator cal;					//Calling Class Calculator
	double history[100] = {0};		// To store the history
    string ques;					// To store the question
	double r;						// To store the result
	int ch = 1;						// For looping so we can enter question as much as we want
	int key=0;						// Index of the history
	
	//Print out the rules
	
	cout << "This is a calculator science. You can calculate as many as" << endl;
	cout << "you want with some rules : " << endl;
	cout << "1. + is addition, - is subtraction, * is multiply, and / is division." << endl;
	cout << "2. r(num) is square root, ^ is exponen, log(num) is logarithm, ln(num) is natural number." endl;
	cout << "3. You can use cos(num), sin(num), tan(num), acos(num), asin(num), atan(num) for trigonometry." << endl;
	cout << "4. Please be advised that you can input until 100 character including your space." << endl;
	cout << "\nLET'S GET STARTED" << endl;
	
	//Print out the choice
	cout << "[0] Terminate" << endl;
	cout << "[1] Calculator" << endl;
	cout << "[2] History" << endl;
    cout << "[3] Delete History" << endl;

	cout << "\n ENTER YOUR CHOICE : ";
	cin >> ch;
	
	//Loop for inputing the question as many as we can
	while (ch != 0) {
		
		//For calculating
		if (ch == 1) {
			cout << "\nEnter your question : ";
			cin.ignore();
			getline(cin, ques);
			history[key++] = r = cal.evaluate(ques);
			cout << "= " << r << endl;
		}
		
		//For showing the history
		else if (ch == 2){
			//Key as the index if the history is empty or not
			if(key != 0){
				cout << "\nHistory until now : " << endl;
				for (int i = 0; i < key; i++){
					cout << "\t" <<  i << ". " << history[i] << endl;
				}
			}
			else {
				cout << "\nHistory is empty";
			}	
		}
		
		//For deleting the history
		else if (ch == 3){
			//Checking if the user really want to erase the entire history
			cout << "\nDo you want to delete entire history? (Y/N)" << endl;
			char ans;
			cin >> ans;
			
			//if yes
			if (toupper(ans) == 'Y') {
				cout << "All of the story is deleted" << endl;
				//Looping for emptying the history
				for (int i = 0; i < key; i++){
					history[i] = 0;			
				}
				//Set the key to zero to make sure the counting set again to zero for the history index
				key = 0;
			}
			
			//if no then continue
			else {
				continue;
			}
		}
		
		//If the user input the wrong choice
		else {
			cout << "You input the wrong number." << endl;
		}
		
		//We need to reprint out the choice to the user and get the ch again for the looping
		cout << "\n\n[0] Terminate" << endl;
		cout << "[1] Calculator" << endl;
		cout << "[2] History" << endl;
		cout << "[3] Delete History" << endl;

		cout << "\n ENTER YOUR CHOICE : ";
		cin >> ch;
	}
	return 0;
}
