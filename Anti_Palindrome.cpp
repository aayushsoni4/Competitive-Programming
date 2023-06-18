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
#define printarray(a,n)   f(i, 0, n) { cout << a[i] << " "; } cout<<endl;
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
    string s;
    cin >> s;
    int ans=0;
    int freq[26]={0};
    f(i,0,n){
        freq[s[i]-'a']++;
    }    
    sort(freq,freq+26);
    int t=0;
    p=0;
    f(i,0,26){
        if(freq[i]>0){
            p++;
            if(freq[i]%2==1){
                t++;
            }
        }
    }
    if(n%2==0){
        if(p==1){
            cout << 1 << endl;
            return;
        }
        if(t>=2){
            cout << 0 << endl;
        }
        else
            cout << 1 << endl;
        return;
    }
    else{
        if(p==1){
            cout << 2 << endl;
            return;
        }
        if(t==1){
            cout << 1 << endl;
        }
        else{
            cout << 0 << endl;
        }
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