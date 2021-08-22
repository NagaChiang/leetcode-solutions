class MedianFinder {
private:
    priority_queue<int> lowMaxHeap;
    priority_queue<int, vector<int>, greater<int>> highMinHeap;
    
public:
    MedianFinder() {}
    
    void addNum(int num) {
        lowMaxHeap.push(num);
        
        highMinHeap.push(lowMaxHeap.top());
        lowMaxHeap.pop();
        
        if (lowMaxHeap.size() < highMinHeap.size()) {
            lowMaxHeap.push(highMinHeap.top());
            highMinHeap.pop();
        }
    }
    
    double findMedian() {
        if (lowMaxHeap.size() > highMinHeap.size()) {
            return lowMaxHeap.top();
        } else {
            return (lowMaxHeap.top() + highMinHeap.top()) / 2.0f;
        }
    }
};