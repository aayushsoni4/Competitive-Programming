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
    int a[n];
    inputarray(a,n);
    string s;
    cin >> s;
    vector<int>v(n,0);   
    cin >> q;
    int ans1 = 0;
    int ans0 = 0;
    f(i,0,n){
        if(s[i]=='0'){
            ans0^=a[i];
        }else{
            ans1^=a[i];
        }
    }
    bool flag = false;
    while(q--){
        cin >> m;
        if(m==1){
            int l,r;
            cin >> l >> r;
            v[l-1]++;
            if(r<n)
                v[r]--;
            flag = true;
        }
        else{
            int p;
            cin >> p;
            if(flag == true){
                ans1=0;
                ans0=0;
                v[0]%=2;
                if(v[0]==1)
                    s[0] = '0'+1-(s[0]-'0');
                f(i,1,n){
                    v[i]+=v[i-1];
                    v[i]%=2;
                    v[i]+=2;
                    v[i]%=2;
                    if(v[i]==1){
                        s[i] = '0'+1-(s[i]-'0');
                    }
                }   
                f(i,0,n){
                    v[i]=0;
                    if(s[i]=='1'){
                        ans1^=a[i];
                    }
                    else{
                        ans0^=a[i];
                    }
                }
                flag = false;
            }
            // cout << s << endl;
            if(p==0){
                cout << ans0 << " ";
            }
            else{
                cout << ans1 << " ";
            }
        }
    }
    cout << endl;
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