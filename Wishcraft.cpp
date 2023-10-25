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
    cin >> p >> q;
    int a[n];
    inputarray(a,n);
    multiset<int>mp,mn;
    f(i,0,n){
        if(a[i]>=0){
            mp.insert(a[i]);
        }
        else{
            mn.insert(a[i]);
        }
    }
    int ans=0;
    while(q>0){
        if(mp.size()>0 and mn.size()>0){
            int a1 = *mp.rbegin();
            mp.erase(mp.find(a1));

            int a2 = *mn.begin();
            mn.erase(mn.find(a2));

            q--;
            
            int a3 = INT_MIN, a4 = INT_MIN;
            if(mp.size()>0 and mn.size()>0){
                a3 = *mp.rbegin();
                mp.erase(mp.find(a3));
                
                a4 = *mn.begin();
                mn.erase(mn.find(a4));
                q--;
            }
            mp.insert(a1-a2);
            if(a3!=INT_MIN)
                mn.insert(a4-a3);
        }
        else{
            break;
        }
    }
    // if(mp.size()==1 and mn.size()==0){
    //     cout << *mp.begin() << endl;
    //     return;
    // }
    
    // for(auto i: mp){
    //     cout << i << " ";
    // }
    // cout << endl;
    
    // for(auto i: mn){
    //     cout << i << " ";
    // }
    // cout << endl;

    while(p>0 and mp.size()+mn.size()>2){
        int a1=INT_MIN,a2=INT_MIN,a3=INT_MIN,a4=INT_MIN;
        if(mp.size()>=2){
            a1 = *mp.rbegin();
            auto it = mp.rbegin();
            it--;
            a2 = *it;
        }
        else if(mn.size()>=2){
            a3 = *mn.begin();
            auto it = mn.begin();
            it++;
            a4 = *it;
        }
        else{
            break;
        }
        if(a1==INT_MIN){
            mn.erase(mn.find(a3));
            mn.erase(mn.find(a4));
            mn.insert(a3+a4);
        }
        else if(a3==INT_MIN){ 
            mp.erase(mp.find(a1));
            mp.erase(mp.find(a2));
            mp.insert(a1+a2);
        }
        else{
            if(a2>abs(a4)){
                mp.erase(mp.find(a1));
                mp.erase(mp.find(a2));
                mp.insert(a1+a2);
            }
            else{
                mn.erase(mn.find(a3));
                mn.erase(mn.find(a4));
                mn.insert(a3+a4);
            }
        }
        p--;
    }

    
    // for(auto i: mp){
    //     cout << i << " ";
    // }
    // cout << endl;
    
    // for(auto i: mn){
    //     cout << i << " ";
    // }
    // cout << endl;
    // cout << endl;

    int x = 0;
    int y = 0;
    if(mp.size()>0){
        x = *mp.rbegin();
    }
    else if(mn.size()!=1){
        x = *mn.rbegin();
    }
    if(mn.size()>0){
        y = *mn.begin();
    }
    else if(mp.size()!=1){
        y = *mp.begin();
    }
    cout << x-y << endl;
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