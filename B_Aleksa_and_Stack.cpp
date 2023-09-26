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

string check(int a[], int n){
    f(i,2,n){
        if((3*a[i])%(a[i-1]+a[i-2])==0){
            return "YES";
        }
    }
    return "NO";
}

void solve(){
    int n, m, p=0, q;
    cin >> n;
    int a[n];
    a[0]=2;    
    a[1]=3;
    f(i,2,n){
        a[i]=a[i-1]+1;
        while((3*a[i])%(a[i-2]+a[i-1])==0){
            a[i]++;
        }
    }    
    printarray(a,n);

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