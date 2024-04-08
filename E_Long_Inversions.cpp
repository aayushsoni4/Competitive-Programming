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

bool minOperation(string S, int K, int N){
    vector<int> flip(N, 0);
    int flipCount = 0, ans = 0;
    for (int i = 0; i < N; i++) {
        if (i >= K)
            flipCount ^= flip[i - K];
        if ((S[i] == '0' && flipCount % 2 == 0) || (S[i] == '1' && flipCount % 2 == 1)) {
            if (i + K > N)
                return false;
            ans++;
            flipCount ^= 1;
            flip[i] = 1;
        }
    }
    return true;
}

void solve(){
    int n, m, p=0, q;
    cin >> n;
    string s;
    cin >> s;
    f(i,0,n+1){
        if(minOperation(s,i,n)){
            p=max(p,i);
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