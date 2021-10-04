"""
PanCake Sorting in Python

"""
# supportive function which reversers target array upto index n

def reverse_upto_n(arr,n):
    for i in range(0,(n+1)//2):
        arr[i],arr[n-i]=arr[n-i],arr[i]
    return arr

def pancake_sort(arr):
    s=len(arr)-1 # Last index of non-sorted part of array stored in variable s
    while s>=1:
        t=arr.index(max(arr[:s+1])) # Finding max element from array from index 0 to last index of non-sorted part of array 
        if t!=s:
            arr=reverse_upto_n(arr,t)# First reverse to bring max element at first of non-sorted part of array
            arr=reverse_upto_n(arr,s)# Second reverse to bring max element at it's proper position
            
            # so that From index s+1 to last index of array, array become sorted.(Eventually) 
        s-=1

arr=[100,50,23,28,76,21,75,99,42]

pancake_sort(arr)

print("Sorted Order: ",end="")
for i in range(len(arr)):
    print(arr[i],end=" ")
print()
