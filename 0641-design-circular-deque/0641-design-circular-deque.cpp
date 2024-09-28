class MyCircularDeque {
    vector<int> deque;
    int front, rear;
    int filledElements;
    int k;
    
public:
    MyCircularDeque(int k) {
        deque = vector<int> (k);
        this->k = k;
        front = rear = -1;
        filledElements = 0;
    }
    
    bool insertFront(int value) {
        if(filledElements == k)
            return false;
        if(front == -1) 
            front = rear = 0; 
        else
            front--;
        if(front < 0)
            front = k-1;
        filledElements++;
        deque[front] = value;
        return true;
    }
    
    bool insertLast(int value) {
        if(filledElements == k)
            return false;
        if(rear == -1) {
            front = 0;
        }
        rear++;
        rear %= k;
        filledElements++;
        deque[rear] = value;
        return true;
    }
    
    bool deleteFront() {
        if(filledElements == 0)
            return false;
        filledElements--;
        front++;
        front %= k;
        if(filledElements == 0)
            front = rear = -1;
        return true;        
    }
    
    bool deleteLast() {
        if(filledElements == 0)
            return false;
        rear--;
        if(rear < 0)
            rear = k-1;
        filledElements--;
        if(filledElements == 0) 
            front = rear = -1;
        return true;        
    }
    
    int getFront() {
        if(front == -1)
            return -1;
        return deque[front];
        
    }
    
    int getRear() {
        if(rear == -1) {
            return -1;
        }
        return deque[rear];
        
    }
    
    bool isEmpty() {
        return filledElements == 0;
    }
    
    bool isFull() {
        return filledElements == k;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */