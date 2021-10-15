#include"Queue.h"
#include<iostream>
#include<stdlib.h>
using namespace std;


int main() {
    Queue q(10);
    
	cout << "Push value of 20, 30, and 40 to the queue" << endl;
    //Push the values to the queue
    q.numEnqueue(20);
    q.numEnqueue(30);
    q.numEnqueue(40);
    
    //Print out the front and rear
    cout << "This is the front of queue" << q.getFront() <<endl;
    cout << "This is the rear of queue" << q.getRear() << endl;
    
    cout << "Pop the queue" << endl;
    //Pop the queue
    q.Dequeue();
    
    cout << "The front become" << q.getFront() << endl;
    
    //Pop all of the queue until underflow
    cout << "Pop the queue until underflow" << endl;
    q.Dequeue();
    q.Dequeue();
    
    cout << "The comment is ";
    q.Dequeue();
}
