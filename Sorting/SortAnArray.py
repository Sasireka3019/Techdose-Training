class Solution:
    def solve(self, lst, start, end):
        if start == end: return
        mid = (start + end) // 2
        self.solve(lst, start, mid)
        self.solve(lst, mid + 1, end)
        x = start
        y = mid + 1
        tmp = []
        while x < mid + 1 and y < end + 1:
            if lst[x] < lst[y]:
                tmp.append(lst[x])
                x += 1
            else:
                tmp.append(lst[y])
                y += 1
        while x < mid + 1:
            tmp.append(lst[x])
            x += 1
        while y < end + 1:
            tmp.append(lst[y])
            y += 1
        for x in range(start, end + 1):
            lst[x] = tmp[x - start]
            
            
    def sortArray(self, nums: List[int]) -> List[int]:
        self.solve(nums, 0, len(nums) - 1)
        return nums
