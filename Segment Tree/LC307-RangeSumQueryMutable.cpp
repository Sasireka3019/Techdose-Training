class NumArray {
public:
    vector <int> segTree; 
    int N;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        N = n;
        segTree.resize(2*n);
        for(int i=n, j=0; i<2*n; i++, j++)
        {
            segTree[i] = nums[j];
        }
        for(int i=n-1; i>=0; i--)
        {
            segTree[i] = segTree[2*i] + segTree[2*i+1];
        }
    }
    
    void update(int index, int val) {
        index += N;
        segTree[index] = val;
        while(index > 0)
        {
            int left = index, right = index;
            if(index % 2 == 0) //left child
                right = index + 1;
            else //right child
                left = index - 1;
            segTree[index/2] = segTree[left] + segTree[right]; //updating parent
            index /= 2;
        }
    }
    
    int sumRange(int left, int right) {
        int sum = 0;
        left += N;
        right += N;
        while(left <= right)
        {
            if(left % 2 == 1) //its parent has sum of [<left, left] going to its parent is waste
            {
                sum += segTree[left];
                left += 1;
            }
            if(right % 2 == 0) //its parent has sum of [right, >right] going to its parent is waste
            {
                sum += segTree[right];
                right -= 1;
            }
            left /= 2;
            right /= 2;
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
