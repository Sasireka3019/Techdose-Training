from collections import defaultdict as dd
class Solution:
    def uniqueLetterString(self, s: str) -> int:
        dk = dd(list)
        n = len(s)
        rslt = 0
        for x in range(n):
            dk[s[x]].append(x)
        for x in dk:
            x = dk[x]
            x.insert(0, -1)
            x.append(n)
            k = len(x)
            for y in range(1, k - 1):
                rslt += ((x[y] - x[y - 1]) * (x[y + 1] - x[y]))
        return rslt
