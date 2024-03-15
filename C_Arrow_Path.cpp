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
    int n, m, p=0;
    cin >> n;
    vector<string>v(2);
    cin >> v[0] >> v[1];
    vector<vector<int>>vis(2,vector<int>(n,0));
    queue<pair<int,int>>q;
    q.push({0,0});
    vis[0][0]=1;
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        if(x==1 && y==n-1){
            cout << "YES" << endl;
            return;
        }
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0 && nx<2 && ny>=0 && ny<n && !vis[nx][ny]){
                vis[nx][ny]=1;
                if(v[nx][ny]=='>'){
                    ny++;
                }
                else{
                    ny--;
                }
                if(ny>=0 && ny<n && !vis[nx][ny]){
                    vis[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
        }
    }
    cout << "NO" << endl;
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