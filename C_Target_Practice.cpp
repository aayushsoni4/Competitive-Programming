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
    vector<string>v;
    f(i,0,10){
        string s;
        cin >> s;
        v.pb(s);
    }    
    f(i,0,10){
        f(j,0,10){
            if(v[i][j]=='X'){
                if(i==0||j==0||i==9||j==9){
                    p+=1;
                }
                else if(i==1||j==1||i==8||j==8){
                    p+=2;
                }
                else if(i==2||j==2||i==7||j==7){
                    p+=3;
                }
                else if(i==3||j==3||i==6||j==6){
                    p+=4;
                }
                else{
                    p+=5;
                }
            }
        }
    }
    cout << p << endl;
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