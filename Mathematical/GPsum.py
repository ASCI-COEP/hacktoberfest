def GPsum(a,n,r):
    sum1=0.0
    if(r!=1):
        sum1=a*(1-r**n)/(1-r)
    else:
        sum1=a*n
    return sum1
a=float(input('Enter first term of the sequence '))
n=int(input('Enter number of terms in the sequence '))
r=float(input('Enter common ratio '))
print('sum of the given GP upto ',n,' terms is ',GPsum(a,n,r))
