s = input()
a = [0 for i in range(0, 26)]
for x in s:
    a[ord(x) - ord('a')] += 1 
res = ""
for i in range(0, 26):
    x = a[i]
    while x > 0:
        res = res + chr(ord('a') + i)
        x -= 1
print(res)
