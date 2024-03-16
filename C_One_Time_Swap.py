from collections import Counter
S = input()
c = list(Counter(S).values())

ans = 1 if any(x>1 for x in c) else 0
for i in range(len(c)):
    for j in range(i+1,len(c)):
        ans+=c[i]*c[j]

print(ans)
