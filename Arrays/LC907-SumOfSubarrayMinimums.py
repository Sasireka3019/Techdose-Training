class Solution:
    def sumSubarrayMins(self, arr: List[int]) -> int:
        rslt = 0
        n = len(arr)
        stack = []
        arr.append(0)
        for x in range(n + 1):
            while stack and arr[stack[-1]] > arr[x]:
                index = stack.pop()
                rslt += (arr[index] * (x - index) * (index - (stack[-1] if stack else -1)))
            stack.append(x)
        return rslt % (10**9 + 7)
