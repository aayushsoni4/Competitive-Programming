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

void numberOfNodes(int s, int e, int count[], vector<int>adj[]) 
{ 
    vector<int>::iterator u; 
    count[s] = 1; 
    for (u = adj[s].begin(); u != adj[s].end(); u++) { 
        if (*u == e) 
            continue; 
        numberOfNodes(*u, s,count,adj); 
        count[s] += count[*u]; 
    } 
}

void solve(){
    int n, m;
    cin >> n;
    vector<int>adj[n];
    vector<int>indegree(n,0);
    f(i,0,n-1){
        int p,q;
        cin >> p >> q;
        p--;
        q--;
        adj[p].pb(q);
        indegree[q]++;
    }
    int count[n]={0};

    queue<int>q;
    vector<int>ans(n+1,0);
    
    f(i,0,n){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    ans[0]++;
    ans[1]--;
    numberOfNodes(q.front(),-1,count,adj); 
    f(i,0,n){
        count[i]--;
    }
    m  = n;
    int ptr = 1;
    while(!q.empty()){
        int n = q.size();
        f(i,0,n){
            int p = q.front();
            q.pop();
            for(auto j:adj[p]){
                indegree[j]--;
                if(indegree[j]==0){
                    // cout << j << " " << ptr << " " << m-count[j] << endl;
                    ans[ptr]++;
                    ans[m-count[j]]--;
                    q.push(j);
                }
            }
        }
        ptr++;
    }
    // printarray(count,n);
    // cout << endl;
    // printarray(indegree,n);
    // printarray(outdegree,n);
    cout << ans[0] << " ";
    f(i,1,n){
        ans[i]+=ans[i-1];
        cout << ans[i] << " ";
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