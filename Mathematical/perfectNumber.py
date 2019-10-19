import math
def perfectNumber(n):
  sum = 1
  i = 2
  if(n%2 == 1): return False
  while(i<= int(math.sqrt(n)) and (sum < n)):
    print(i)
    if(n%i == 0):
      sum += i
      if(n/i != i):
        sum += n/i
    i += 1
  if(sum == n): return True
  return False


print(perfectNumber(28))
print(perfectNumber(137438691328))