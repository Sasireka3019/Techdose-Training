class Solution
{
    public:
    vector <int> nearlySorted(int arr[], int num, int K){
        priority_queue<int, vector<int>, greater<int>> heap;
        int len = min(K+1, num);
        for(int i=0; i<len; i++)
            heap.push(arr[i]);
        vector <int> result;
        for(int i = len; i < num; i++)
        {
            result.push_back(heap.top());
            heap.pop();
            heap.push(arr[i]);
        }
        while(!heap.empty())
        {
            result.push_back(heap.top());
            heap.pop();
        }
        return result;
    }
};
