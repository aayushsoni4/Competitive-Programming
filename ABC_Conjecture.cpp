#include <bits/stdc++.h>
#define int               long long
#define f(i,a,b)          for(int i=a;i<b;i++)
#define pb                push_back
#define endl              "\n"    
using namespace std;

void solve(){
    int n, m, p=0, q;
    string s1,s2;
    cin >> n;
    cin >> s1 >> s2;    
    if(s1==s2){
        cout << "Yes" << endl;
        return;
    }
    vector<int>b;
    f(i,0,n){
        if(s1[i]=='b' and s2[i]=='b'){
            b.pb(i);
        }
        else if(s1[i]=='b' || s2[i]=='b'){
            cout << "No" << endl;
            return;
        }
    }
    int b_left = 0;
    int b_right = 0;
    for(auto k: b){
        int i = k-1;
        int j = k+1;
        while(i>=0 and s1[i]!='b'){
            if(s1[i]=='a' and s2[i]=='c'){
                b_left++;
            }
            i--;
        }
        while(j<n and s1[j]!='b'){
            if(s1[j]=='c' and s2[j]=='a'){
                b_right++;
            }
            j++;
        }
    }
    if(b_left!=b_right){
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
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