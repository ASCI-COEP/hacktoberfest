money = 63
denom = [1,5,10,12,25]
i = len(denom)-1
count=0
count1 = 9999999999
for n in range(len(denom)-1,-1,-1):
    if money%denom[n] == 0:
        count1 = min(count1,money//denom[n])
while money:
    count+=money//denom[i]
    money = money%denom[i]
    #print('Used {} coin {} times'.format(denom[i],max(money,count)))    
    i-=1
print(min(count,count1))
