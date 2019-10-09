def factorial(nfrom, nto):
  if(nfrom == nto): return nto
  return nfrom * factorial(nfrom-1, nto)
 
def nCr(n, r):
  return int(factorial(n, (n-r) + 1 )/factorial(r, 1))
 
print(nCr(5,2))
print(nCr(10,4))