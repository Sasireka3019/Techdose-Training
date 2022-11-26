class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        stack = []
        n = len(nums)
        rslt = []
        for x in range(n):
            value = nums[x]
            while stack and stack[-1][1] < value:
                stack.pop()
            stack.append((x, value))
            while stack[0][0] <= x - k:
                stack.pop(0)
            if (x - k + 1) >= 0:
                rslt.append(stack[0][1])
        return rslt
