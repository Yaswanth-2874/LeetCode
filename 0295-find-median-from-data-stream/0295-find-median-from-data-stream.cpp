class MedianFinder {
    // I can use something like insertion sort but still time complexity of addNum becomes linear which would be unoptimal
    // I can create a maxHeap and a minHeap
    // In the maxHeap store n/2 minElements
    // In the minHeap store n/2 maxElements
    // while inserting, calculate the size of min heap and max heap
    // Lets say size is 4, 3
    // While inserting, i should insert in the one with smaller size
    
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int maxHeapSize;
    int minHeapSize;
    
public:
    MedianFinder() {
        maxHeapSize = 0;
        minHeapSize = 0;        
    }
    
    void addNum(int num) {
        if(maxHeapSize == 0) {
            maxHeapSize++;
            maxHeap.push(num);
            // cout<<"Inserted "<<num<<" in maxHeap"<<endl;
            return;
        }
        if(maxHeapSize > minHeapSize) {
            maxHeap.push(num);
            int maxValue = maxHeap.top();
            maxHeap.pop();
            // cout<<"Removed "<<maxValue<<" from maxHeap"<<endl;

            minHeap.push(maxValue);
            minHeapSize++;
            // cout<<"Inserted "<<maxValue<<" in minHeap"<<endl;
        } else if(maxHeapSize < minHeapSize) {
            minHeap.push(num);
            int minValue = minHeap.top();
            minHeap.pop();
            cout<<"Removed "<<minValue<<" from minHeap"<<endl;
            
            maxHeap.push(minValue);
            // cout<<"Inserted "<<minValue<<" in maxHeap"<<endl;
            maxHeapSize++;
        } else {
            int maxValue = maxHeap.top();
            if(num <= maxValue) {
                maxHeap.push(num);
                maxHeapSize++;
                // cout<<"Inserted "<<num<<" in maxHeap"<<endl;
            } else {
                minHeap.push(num);
                minHeapSize++;
                // cout<<"Inserted "<<num<<" in minHeap"<<endl;
            }
        }
    }
    
    double findMedian() {
        if((maxHeapSize + minHeapSize) % 2 == 0) {
            int midA = maxHeap.top();
            int midB = minHeap.top();
            
            return (midA + midB) / 2.0;
        }
        if(maxHeapSize > minHeapSize)
            return maxHeap.top();
        return minHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */