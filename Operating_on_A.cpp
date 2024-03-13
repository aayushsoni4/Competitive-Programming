#include <bits/stdc++.h>
#define int               long long
#define f(i,a,b)          for(int i=a;i<b;i++)
#define mp                make_pair
#define pb                push_back
#define rall(a)           a.rbegin(),a.rend()
#define all(a)            a.begin(),a.end()
#define arraysort(a,n)      sort(a,a+n)
#define endl              "\n"    
#define inputarray(a, n)  f(i, 0, n) { cin >> a[i]; }
#define printarray(a,n)   f(i, 0, n) { cout << a[i] << " "; } cout << endl;
using namespace std;

int power(int a, int b, int p){
    if(a==0)
        return 0;
    int res=1;
    a%=p;
    while(b>0){
        if(b&1)
        res=(1ll*res*a)%p;
        b>>=1;
        a=(1ll*a*a)%p;
    }
    return res;
}

int lcm(int a, int b){
    if(a==0 || b==0)
        return 0;
    return (a*b)/__gcd(a,b);
}

void solve(){
    int n, m, p=0, q;
    cin >> n;
    int arr[n];
    int brr[n];
    inputarray(arr,n);
    inputarray(brr,n);
    int a,b,c,d;
    a = arr[0];
    b = arr[1];
    c = arr[2];
    d = arr[3];
    f(i,0,n){
        p+=arr[i];
        p-=arr[i];
    }
    if(p==0 and (brr[0]==a+b+c || brr[0]==arr[0]) && brr[n-1]==arr[n-1]+arr[n-2]+arr[n-3] || brr[n-1]==arr[n-1]){
        cout << "YES" << endl;
        return;
    }
    else{
        cout << "NO" << endl;
    }
}

signed main (){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int testcases=1;
    cin >> testcases;
    while (testcases--){
        solve();
    }
}