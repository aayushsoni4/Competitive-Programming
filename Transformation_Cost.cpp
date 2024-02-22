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

string inttobin(int x){
    string s="";
    while(x){
        s+=to_string(x%2);
        x/=2;
    }
    reverse(all(s));
    return s;
}

int cnt(int n){
    int c = 0;

    while(n!=0){
        if(n%2==1){
            c++;
        }
        n/=2;
    }
    return c;
}

int st_one(int n){
    int c = 0;
    int lst = 0;
    f(i,0,31){
        if(n&(1LL<<i)){
            lst = i;
        }
    }
    while((n&(1LL<<lst)) && lst>=0){
        c++;
        lst--;
    }
    return c;
}

void solve(){
    int n, m, p=0, q;
    cin >> n;
    int ans = 0;
    if(st_one(n)==cnt(n)){
        cout << ans << endl;
    }
    else{
        p=0;
        while(st_one(n)!=cnt(n)){
            if(n&(1LL<<p)){
                ans+=(1LL<<p);
                n+=(1LL<<p);
            }
            p++;
        }
        cout << ans << endl;
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