class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue <double> heap;
        double sum = 0;
        int op = 0;
        for(int i : nums)
        {
            sum += i;
            heap.push(i);
        }
        double temp = sum;
        while(temp > sum/2)
        {
            double top = heap.top();
            temp -= (top/2.0);
            heap.pop();
            heap.push(top/2.0);
            op += 1;
        }
        return op;
    }
};
