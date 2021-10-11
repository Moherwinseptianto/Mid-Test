#include"Calculator.h"
#include<iostream>
using namespace std;


int main() {
	
	int ch;
    Calculator cal;

	while (ch != 0) {
		cout << "[0] Terminate" << endl;
		cout << "[1] Calculator" << endl;
		cout << "[2] History" << endl;
        cout << "[3] Delete History" << endl;

		cout << "\n ENTER YOUR CHOICE : ";
		cin >> ch;

		switch (ch) {
		case 0: return 0;
		case 1: {
            cal.get();
            cout << cal.getResult() << endl << endl;
            break;
        }
		case 2: break;
        case 3: break;
		default:
			cout << "\n\tYOU ENTER THE WRONG NUMBER";
			cout << "\n\tPLEASE TRY AGAIN\n\n";
			break;
		}
	}

	return 0;
}

