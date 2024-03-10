from sortedcontainers import SortedList

def mex(arr):
    m = 0
    for num in arr:
        if num == m:
            m += 1
    return m

def solve():
    n = int(input())
    a = list(map(int, input().split()))

    p = a.count(0)
    if p == 0:
        print(n)
        for i in range(1, n + 1):
            print(i, i)
        return
    if p == 1:
        print(-1)
        return
    st1 = SortedList([])
    st2 = SortedList(a)
    ans = [[1,-1],[-1,n]]
    for i in range(n):
        st1.add(a[i])
        st2.remove(a[i])
        l=0
        r=2000000
        while l < r:
            m = (l + r) // 2
            if st1[m] == m:
                l = m + 1
            else:
                r = m

    for num in st:
        print(num, end=' ')
    print()

testcases = int(input())
for _ in range(testcases):
    solve()
