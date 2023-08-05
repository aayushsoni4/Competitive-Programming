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

bool mycomp(pair<int,int>&a, pair<int,int>&b){
    if(a.first>b.first){
        return true;
    }
    if(a.first==b.first){
        return a.second<b.second;
    }
    return false;
}

void solve(){
    int n, m, p=0, q, t;
    cin >> n >> m >> t;
    vector<vector<int>>v;
    
    f(i,0,n){
        vector<int>temp;
        f(j,0,m){
            int c;
            cin >> c;
            temp.pb(c);
        }
        sort(all(temp));
        v.pb(temp);
    }

    vector<pair<int,int>>ans;
    vector<pair<int,int>>temp;

    f(i,0,1){
        int points=0,penalty=0,tot=0;
        if(v[i][0]<=t){
            points++;
            penalty=v[i][0];
            tot=v[i][0];
        }
        else{
            temp.pb({points,penalty});
            break;
        }
        f(j,1,v[i].size()){
            tot+=v[i][j];
            if(tot<=t){
                points++;
                penalty+=tot;
            }
            else{
                break;
            }
        }
        temp.pb({points,penalty});
    }

    f(i,1,v.size()){
        int points=0,penalty=0,tot=0;
        if(v[i][0]<=t){
            points++;
            penalty=v[i][0];
            tot=v[i][0];
        }
        else{
            temp.pb({points,penalty});
            continue;
        }
        f(j,1,v[i].size()){
            tot+=v[i][j];
            if(tot<=t){
                points++;
                penalty+=tot;
            }
            else{
                break;
            }
        }
        ans.pb({points,penalty});
    }
    sort(all(ans),mycomp);

    int res=1;
    f(i,0,ans.size()){
        if(ans[i].first>temp[0].first){
            res++;
            continue;
        }
        if(ans[i].first==temp[0].first){
            if(ans[i].second<temp[0].second){
                res++;
            }
            else{
                break;
            }
        }
        else{
            break;
        }
    }
    cout << res << endl;
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