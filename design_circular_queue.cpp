#include <iostream>
#include <vector>
#include <deque>
using namespace std;

//https://leetcode.com/problems/design-circular-queue/

class MyCircularQueue {
    vector <int> queue;
    int rear = 0, front, size;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        cout << endl;
        front = -1;
        rear = -1;
        size = k;
        queue.resize(k);
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        cout << "a";
        if (isFull())
            return false;
        if (isEmpty())
            front = 0;
        rear = (rear + 1) % size;
        queue[rear] = value;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        cout << "b";
        
        if(!isEmpty()) {
            if (front == rear) {
                front = -1; rear = -1;
                return true;
            }
            front = (front + 1) % size;
            return true;
        }
        return false;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        cout << "c";
        if (!isEmpty())
            return queue[front];
        return -1;
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        cout << "d";
        if (!isEmpty())
            return queue[rear];
        return -1;
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        cout << "e";
        return (front == -1);
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        cout << "f";
        return ((rear + 1) % size == front);
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */