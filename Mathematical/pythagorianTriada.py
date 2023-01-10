for i in range(1,50):
    for j in range(1,i):
        for k in range(1,j):
            if(k*k+j*j==i*i):
                flag=0
                for l in range(2,i):
                    if i%l==0 and j%l==0 and k%l==0:
                        flag=1
                        break
                if(flag):continue
                print("a=",k,"b=",j,"c=",i)
