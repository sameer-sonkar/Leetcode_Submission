class Solution:
   
    def sumSubarrayMins(self, arr: List[int]) -> int:
        MOD=10**9+7
        ans=0
        n=len(arr)
        pse=[0]*n
        for i in range(n):
            j=i-1
            while j>-1 and arr[i]<arr[j]:
                j=pse[j]
            pse[i]=j
        nse=[0]*n
        for i in range(n-1,-1,-1):
            j=i+1
            while(j<n and arr[i]<=arr[j]):
                j=nse[j]
            nse[i]=j
        for i in range(n):
            left=i-pse[i]
            right=nse[i]-i
            x=left*right*arr[i]
            ans+=x
        return int(ans)%MOD


        