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
    cin >> n >> m >> p;
    vector<pair<int,int>>vp;
    f(i,0,m){
        cin >> q;
        string s;
        cin >> s;
        int num = -1;
        if(s!="?"){
            num = stoi(s);
        }
        vp.pb({q,num});
    }   
    set<int>st;
    st.insert(p);
    f(i,0,m){
        set<int>temp;
        if(vp[i].second!=-1){
            for(auto j: st){
                if(vp[i].second==0){
                    if(j+vp[i].first<=n)
                        temp.insert(j+vp[i].first);
                    else{
                        temp.insert(j+vp[i].first-n);
                    }
                }
                else{
                    if(j+n-vp[i].first<=n)
                        temp.insert(j+n-vp[i].first);
                    else{
                        temp.insert(j+n-vp[i].first-n);
                    }
                }
            }
        }
        else{
            for(auto j: st){
                if(j+vp[i].first<=n)
                    temp.insert(j+vp[i].first);
                else{
                    temp.insert(j+vp[i].first-n);
                }
                if(j+n-vp[i].first<=n)
                    temp.insert(j+n-vp[i].first);
                else{
                    temp.insert(j+n-vp[i].first-n);
                }
            }
        }
        st.clear();
        st=temp;
    }
    cout << st.size() << endl;
    for(auto j: st){
        cout << j << " ";
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