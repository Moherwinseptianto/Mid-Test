#include<iostream> 
#include<math.h>
using namespace std;
 
int main (){ 
float a,b,PI,Euler_constant; 
int c; 
cout<<endl; 
cout<<"******************** Calculator ****************************************************************\n"; 
cout<<"------------------------------------------------------------------------------------------------\n"; 
cout<<"Operations\t"<<"\tTrigonometric Functions"<<"\t\tLogarithmic Functions\n"; 
cout<<"------------------------------------------------------------------------------------------------\n"; 
cout<<"1: Division\t\t"<<"7: Sin\t\t"<<"\t\t13: Log"<<endl; 
cout<<"2: Multiplication\t"<<"8: Cos\t\t"<<"\t\t14: Log with base 10"<<endl; 
cout<<"3: Subtraction\t\t"<<"9: Tan\t\t"<<"\t\t15: Integral"<<endl; 
cout<<"4: Addition\t\t"<<"10: Inverse of Sin"<<endl; 
cout<<"5: Exponential\t\t"<<"11: Inverse of Cos"<<endl; 
cout<<"6: Square root\t\t"<<"12: Inverse of Tan"<<endl;
cout<<"Enter the function that you want to perform : "; 
cin>>c;
if (c==1||c==2||c==3||c==4||c==5){
	cout<<"Enter 1st number : "; 
	cin>>a; 
	cout<<"Enter 2nd number : "; 
	cin>>b;}
else{
	cout<<"Enter the number : ";
	cin>>a;
}
PI = 3.14159265;
Euler_constant =  2.71828;
switch(c){
	case 1: 
		cout<<"Division = "<<a/b<<endl; 
		break; 
	case 2: 
		cout<<"Multiplication = "<<a*b<<endl; 
		break; 
	case 3: 
		cout<<"Subtraction = "<<a-b<<endl; 
		break; 
	case 4: 
		cout<<"Addition = "<<a+b<<endl; 
		break; 
	case 5:  
		cout<<"Exponent = "<<pow(a,b)<<endl; 
		break; 
	case 6: 
		cout<<"Square Root = "<<sqrt(a)<<endl; 
		break; 
	case 7: 
		cout<<"Sin = "<<sin(a)<<endl; 
		break; 
	case 8: 
		cout<<"Cos = "<<cos(a)<<endl; 
		break; 
	case 9: 
		cout<<"Tan = "<<tan(a)<<endl; 
		break; 
	case 10: 
		cout<<"Inverse of Sin = "<<asin(a)*180.0/PI<<endl; 
		break; 
	case 11: 
		cout<<"Inverse of Cos = "<<acos(a)*180.0/PI<<endl; 
		break; 
	case 12: 
		cout<<"Inverse of tan = "<<atan(a)*180.0/PI<<endl; 
		break; 
	case 13: 
		cout<<"Log = "<<log(a)<<endl; 
		break; 
	case 14: 
		cout<<"Log with base 10 = "<<log10(a)<<endl; 
		break;
	case 15:
		cout<<"Integral = Log10 "<<log(a)/Euler_constant<<endl;break;
	default: 
		cout<<"Wrong Input"<<endl; 
	}
}
