class MedianFinder {
private:
    priority_queue<int> small; // max_heap for the first half
    priority_queue<int, std::vector<int>, std::greater<int> > large; // min_heap for the second half
public:
    void addNum(int num) {
        if(small.empty() || (small.top()>num))
            small.push(num);
        else
            large.push(num);
        if(small.size() > (large.size()+1))
        {
            large.push(small.top());
            small.pop();
        }
        else if(large.size() > (small.size())+1)
        {
            small.push(large.top());
            large.pop();
        }
    }
    
    double findMedian() {
        if(small.size() == large.size())
            return small.empty() ? 0 : (small.top()+large.top())/2.0;
        else
            return small.size()>large.size() ? small.top() : large.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
