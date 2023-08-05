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
    int n, m, p=0, q=0;
    cin >> n >> m;
    // if((n&(n+1))==0)
    while(m--){
        p=0,q=0;
        int l,r;
        cout<<endl;
        cin >> l >> r;
        l=max(l,n);
        if(l>r){
            cout << 0 << endl;
            continue;
        }    
        int ans=0,c=-1;
        for(int i=62;i>=0;i--){
            int j=(1LL<<i);
            if(c==-1&&j<=n) c=j*2;
            if((j&r)>0 and (j>n)){
                q+=j;
            }
            if((j&l)>0 and (j>n)){
                p+=j;
            }
        }
        p/=c;
        q/=c;
        p=max(p,1ll);
        // cout<<p<<" "<<q<<endl;
        ans+=(q-p+1);
        cout<<ans<<" ";
        p=0;
        q=0;
        for(int i=0;i<=62;i++){
            int j=(1LL<<i);
            if(j<=n){
                p+=j;
            }
        }
        q=p;
        for(int i=0;i<=62;i++){
            int j=(1LL<<i);
            if(j<=n) break;
            if(p+j<=l){
                p+=j;
            }
            else{
                p+=j;
                break;
            }
        }
        int z=0;
        for(int i=62;i>=0;i--){
            int j=(1LL<<i);
            if(j<=n) break;
            if(q+j<=r){
                q+=j;
                z=1;
            }
        }
        if(z==0){
            if(q==n) ans++;
            cout<<ans<<endl;
            continue;
        }
        p/=c;
        q/=c;
        // p=max(p,l/c);
        p=0;
        ans+=q-p+1;
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