class KthLargest {
public:
    priority_queue <int, vector<int>, greater<int>> heap;
    int size = 0;
    KthLargest(int k, vector<int>& nums) {
        int n = nums.size();
        size = k;
        for(int i=0; i<n; i++)
        {
            if(i<k)
            {
                heap.push(nums[i]);
            }
            else
            {
                if(nums[i] > heap.top())
                {
                    heap.pop();
                    heap.push(nums[i]);
                }
            }
        }
    }
    
    int add(int val) {
        if(heap.size() < size)
        {
            heap.push(val);
        }
        else if(val > heap.top())
        {
            heap.pop();
            heap.push(val);
        }   
        return heap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
