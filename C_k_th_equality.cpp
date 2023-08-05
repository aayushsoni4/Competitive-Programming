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

int pow10(int n){
    int ans=1;
    while(n--){
        ans*=10;
    }
    return ans;
}

void solve(){
    int n, m, p=0, q, a, b, c, k;
    cin >> a >> b >> c >> k;
    if(max(a,b)>c || max(a,b)<c-1){
        cout << -1 << endl;
        return;
    }
    a--;
    b--;
    c--;
    int na,nb,nc;
    na=pow10(a);
    int totPer = 0;
    if(a==b and b==c){
        totPer = 8*pow10(c);
        totPer = totPer*(totPer+1)/2;
        nb=pow10(b);
    }
    else{
        nc=pow10(c);
        nb=nc-na;
    }
    k--;
    nc=nb+na;
    int mx_nc = pow10(c+1);
    int mx_nb = pow10(b+1);

    // cout << na << " + " << nb << " = " << nc << endl;

    f(i,na,(na*10)){
        if(a==b and b==c){
            nc = i+nb;
            int total = mx_nc-nc;
            if(total>k){
                na=i;
                break;
            }
            else{
                k-=total;
                if(i+1==(na*10) and k>0){
                    cout << -1 << endl;
                    return;
                }
            }
        }
        else{
            nb = nc - i;
            int total = mx_nb-nb;
            if(total>k){
                na=i;
                break;
            }
            else{
                k-=total;
                if(i+1==(na*10) and k>0){
                    cout << -1 << endl;
                    return;
                }
            }
        }
            // cout << i << " + " << nb << " = " << nc << " " << total << endl;

    }
    if(a==b and b==c){
        nb+=k;
        nc=na+nb;
    }
    else{
        nc+=k;
        nb=nc-na;
    }
    cout << na << " + " << nb << " = " << nc << endl;
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