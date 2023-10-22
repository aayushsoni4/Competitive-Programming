def Log2int(n):
    p=0
    while n!=1:
        p+=1
        n//=2
    return p
        

for _ in range(1):
    a = (int)(input())
    b = (int)(input())
    c = (int)(input())
    k = (int)(input())
        
    ans = 0
    l=1
    r=1e20
    while l<=r:
        mid = (l+r)//2
        value = (a*mid) + b*mid*(Log2int(mid)) + c*(mid**3)
        
        if(value>=k):
            ans=(int)(mid)
            r=mid-1
        else:
            l=mid+1
        
    value = (int)((a*ans) + b*ans*(Log2int(ans)) + c*(ans**3))
    # print(value)
    if value!=k:
        ans=0
        
    print(f"{_+1}: {ans}")