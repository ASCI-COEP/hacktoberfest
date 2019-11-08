def APSum(a,n,d):
    sum1=n*(2*a+(n-1)*d)/2
    return sum1
a=float(input('Enter first term of AP '))
n=int(input('Enter number of terms '))
d=float(input('Enter common difference '))
print('Sum is ',APSum(a,n,d),"\n")
