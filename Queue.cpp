#include"Queue.h"
#include<iostream>
#include<stdlib.h>
#include<cmath>
using namespace std;

Queue::Queue(int size) {
    this->front = 0;
    this->rear = 0;
    this->size = size;
    this->array = new double[size];
    
    if (array == NULL){
    	cout << "Error" << endl;
    	exit(EXIT_FAILURE);
	}
}

Queue::~Queue() {
    delete[] this->array;
}

bool Queue::isFull() {
    return (this->size == this->rear);
}

bool Queue::isEmpty(){
    return (this->front == this->rear);
}

void Queue::numEnqueue(double K) {
    if (isFull()) {
        cout << "\n\tOverflow" << endl;
        return;
    }
    else {
        this->array[this->rear] = K;
        this->rear = this->rear + 1;
    }
    return;
}

void Queue::charEnqueue(char C) {
    if (isFull()) {
        cout << "\n\tOverflow" << endl;
        return;
    }
    else {
        this->array[this->rear] = C;
        this->rear = this->rear + 1;
    }
    return;
}

void Queue::Dequeue(){
    if (isEmpty()){
        cout << "\n\tUnderflow" << endl;
        return;
    }
    else {
        this->rear = this->rear - 1;;
    }
    return;
}

double Queue::getFront(){
    if (isEmpty()){
        cout << "\n\tUnderflow" << endl;
    }
	return this->array[this->front];
}

double Queue::getRear(){
    if (isEmpty()){
        cout << "\n\tUnderflow" << endl;
    }
	return this->array[this->rear - 1];
}

