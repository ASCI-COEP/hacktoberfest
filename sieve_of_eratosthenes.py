
#Time Complexity:o(nlog(log(n)))
#Space Complexity:o(n)
def seive(n):
    l=2*[False]+[True]*(n-1)
    for i in range(2,int(n**.5)+1):
        for j in range(i*i,n+1,i):
            l[j]=False
    ans=[]
    for i in range(n+1):
        if l[i]==True:
            ans.append(i)
            
    return ans


n=11
print(*seive(n))
