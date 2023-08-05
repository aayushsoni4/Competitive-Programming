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

bool search(vector<string>&v, char ch){
    if(v[0][0]==v[1][1] and v[1][1]==v[2][2] and v[2][2]==ch){
        return true;
    }  
    if(v[0][2]==v[1][1] and v[1][1]==v[2][0] and v[2][0]==ch){
        return true;
    }  

    if(v[0][0]==v[0][1] and v[0][1]==v[0][2] and v[0][2]==ch){
        return true;
    }  
    if(v[1][0]==v[1][1] and v[1][1]==v[1][2] and v[1][2]==ch){
        return true;
    }  
    if(v[2][0]==v[2][1] and v[2][1]==v[2][2] and v[2][2]==ch){
        return true;
    }
    if(v[0][0]==v[1][0] and v[1][0]==v[2][0] and v[2][0]==ch){
        return true;
    }
    if(v[0][1]==v[1][1] and v[1][1]==v[2][1] and v[2][1]==ch){
        return true;
    }
    if(v[0][2]==v[1][2] and v[1][2]==v[2][2] and v[2][2]==ch){
        return true;
    }
    return false;

}

void solve(){
    int n, m, p=0, q;
    vector<string>v(3);
    cin >> v[0];
    cin >> v[1];
    cin >> v[2];
    if(search(v,'X')){
        cout << "X" << endl;
    }
    else if(search(v,'O')){
        cout << "O" << endl;
    }
    else if(search(v,'+')){
        cout << "+" << endl;
    }
    else{
        cout << "DRAW" << endl;
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