#ifndef QUEUEH
#define QUEUEH

#include<iostream>
#include<stdlib.h>
#include<cmath>
using namespace std;

class Queue {
private:
	int front, rear, size;
	double* array;
public :
    Queue(int size);
    ~Queue();
    bool isFull();
    bool isEmpty();
    void numEnqueue(double K);
    void charEnqueue(char C);
    void Dequeue();
    double getFront();
    double getRear();
};

#endif

