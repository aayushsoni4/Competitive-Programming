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

string bin(int a){
    string s="";
    while(a>0){
        s+=to_string(a%2);
        a/=2;
    }
    reverse(s.begin(),s.end());
    return s;
}

int lcm(int a, int b){
    if(a==0 || b==0)
        return 0;
    return (a*b)/__gcd(a,b);
}

void solve(){
    int n, m, p=0, q;
    cin >> n >> m >> p;
    if(n<m){
        swap(n,m);
    }
    int mini = abs(n-m);
    bool f = false;
    for(int i=62;i>=0;i--){
        if(((1LL<<i)&n) == ((1ll<<i)&m)){
            continue;
        }
        if(((1ll<<i)&n)>0 and !f){
            f = true;
            continue;
        }
        if((1LL<<i)<=p){
            int temp = n^(1ll<<i);
            int temp2 = m^(1ll<<i);
            if(abs(temp-temp2)<mini){
                n=temp;
                m=temp2;
                mini = abs(temp-temp2);
                p-=(1LL<<i);
            }
            if(n<m){
                swap(n,m);
            }
        }
    }
    cout << mini << endl;
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