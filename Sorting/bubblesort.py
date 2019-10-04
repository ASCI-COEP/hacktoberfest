def BUBBLE_SORT(A):
    Start=0
    End=len(A)-1
    while(End!=Start):
        i=Start
        while(i<End):
            if(A[i+1]<A[i]):
                temp=A[i]
                A[i]=A[i+1]
                A[i+1]=temp
            i=i+1
        End=End-1
    return A

A=[4,5,8,1,3,6,2,7]
print(BUBBLE_SORT(A))
