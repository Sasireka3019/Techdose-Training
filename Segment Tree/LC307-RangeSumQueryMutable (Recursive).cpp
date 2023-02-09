class NumArray {
public:
    vector <int> tree;
    int n;
    void buildTree(vector<int> &nums, int treeIdx, int lo, int hi)
    {
        if(lo == hi)
        {
            tree[treeIdx] = nums[lo];
            return;
        }
        int mid = lo + (hi - lo)/2;
        buildTree(nums, 2*treeIdx+1, lo, mid);
        buildTree(nums, 2*treeIdx+2, mid+1, hi);
        tree[treeIdx] = tree[2*treeIdx+1] + tree[2*treeIdx+2];
    }
    NumArray(vector<int>& nums) {
        int size = nums.size();
        n = size;
        tree.resize(4*size+1);
        buildTree(nums, 0, 0, size-1);
    }
    
    void update_helper(int treeIdx, int lo, int hi, int index, int val)
    {
        if(lo == hi)
        {
            tree[treeIdx] = val;
            return;
        }
        int mid = lo + (hi - lo)/2;
        if(mid < index)
            update_helper(2*treeIdx+2, mid+1, hi, index, val);
        else
            update_helper(2*treeIdx+1, lo, mid, index, val);
        tree[treeIdx] = tree[2*treeIdx+1] + tree[2*treeIdx+2];
    }
    void update(int index, int val) {
        update_helper(0, 0, n-1, index, val);
    }
    
    int query(int treeIdx, int lo, int hi, int i, int j)
    {
        if(lo > j || hi < i)
            return 0;
        if(lo >= i && hi <= j)
            return tree[treeIdx];
        int mid = lo + (hi - lo)/2;
        if(mid < i)
            return query(2 * treeIdx + 2, mid + 1, hi, i, j);
        else if(j <= mid)
            return query(2 * treeIdx + 1, lo, mid, i, j);
        int leftQuery = query(2*treeIdx+1, lo, mid, i, j);
        int rightQuery = query(2*treeIdx+2, mid+1, hi, i, j);
        return leftQuery+rightQuery;
    }
    int sumRange(int left, int right) {
        return query(0, 0, n-1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
