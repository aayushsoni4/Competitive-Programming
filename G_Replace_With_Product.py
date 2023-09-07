def solve():
    n = int(input())
    a = list(map(int, input().split()))
    prefixSum = [0] * n
    suffixSum = [0] * n
    prefixProd = [1] * n
    suffixProd = [1] * n

    prefixSum[0] = a[0]
    prefixProd[0] = a[0]
    for i in range(1, n):
        prefixSum[i] = prefixSum[i - 1] + a[i]
        prefixProd[i] = prefixProd[i - 1] * a[i]
        
    i = 0
    j = n - 1
    l = i
    r = j 
    maxSum = 0
    while i <= j:
        _sum = prefixSum[n-1]
        _sum -= prefixSum[j]
        if i > 0:
            _sum += prefixSum[i - 1]
        prod = prefixProd[j]
        if i > 0:
            prod //= prefixProd[i - 1]
        if _sum + prod >= maxSum:
            maxSum = _sum + prod
            l = i+1
            r = j+1
        if a[j] < a[i]:
            j -= 1
        else:
            i += 1
    print(f'{l} {r}')

t = int(input())
for _ in range(t):
    solve()
