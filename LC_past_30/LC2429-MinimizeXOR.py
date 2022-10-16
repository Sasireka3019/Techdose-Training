class Solution:
    def minimizeXor(self, num1: int, num2: int) -> int:
        bin2 = bin(num2)[2:]
        bin1 = bin(num1)[2:]
        ones = bin2.count('1')
        res = ''
        l = len(bin2)
        l1 = len(bin1)
        res += ('0'*(l-l1))
        for j in bin1:
            if(ones>0 and j=='1'):
                res+=('1')
                ones-=1
            else:
                res+=('0')
        lst = list(res[::-1])
        i = 0 
        while(i<l):
            if(ones==0):
                break 
            if(lst[i]!='1'):
                lst[i]='1' 
                ones-=1
            i+=1 
        res = ''
        lst.reverse()
        for j in lst:
            res+=j 
        res = int(res,2)
        return res
