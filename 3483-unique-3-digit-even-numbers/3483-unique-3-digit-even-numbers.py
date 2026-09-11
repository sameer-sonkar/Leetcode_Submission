class Solution:
    def totalNumbers(self, digits: List[int]) -> int:
        s=set()
        n=len(digits)
        for i in range (0,n,1):
            for j in range (0,n,1):
                for k in range (0,n,1):
                    if i==j or j==k or i==k or digits[i]==0 or digits[k]%2==1:
                        continue
                    else:
                        num=digits[i]*100+digits[j]*10+digits[k]
                        s.add(num)
        return len(s)
        