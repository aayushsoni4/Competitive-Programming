// #include <bits/stdc++.h>
// #define int               long long
// #define f(i,a,b)          for(int i=a;i<b;i++)
// #define mp                make_pair
// #define pb                push_back
// #define rall(a)           a.rbegin(),a.rend()
// #define all(a)            a.begin(),a.end()
// #define arraysort(a)      sort(a,a+n)
// #define endl              "\n"    
// #define inputarray(a, n)  f(i, 0, n) { cin >> a[i]; }
// #define printarray(a,n)   f(i, 0, n) { cout << a[i] << " "; } cout<<endl;
// using namespace std;

// struct TrieNode{
//     struct TrieNode* children[26];
//     int wordCount;

//     TrieNode(){
//         wordCount = 0;
//         for (int i = 0; i < 26; i++) {
//             childNode[i] = NULL;
//         }
//     }
// };

// void insert(TrieNode* root, string word){
//     TrieNode* currNode = root;
//     for(auto c: word){
//         int p = c-'a';
//         if(currNode->children[p]==nullptr){
//             currNode->children[p] = new TrieNode();
//         }
//         currNode=currNode->children[p];
//     }
//     currNode->wordCount++;
// }

// bool search(TrieNode* root, string word){
//     TrieNode* currNode = root;
//     for(auto c: word){
//         int p = c-'a';
//         if(currNode->children[p]==nullptr){
//             return false;
//         }
//         currNode=currNode->children[p];
//     }
//     if(currNode->wordCount!=0){
//         return true;
//     }
//     return false;
// }

// bool isPref(TrieNode* root, string word){
//     TrieNode* currNode = root;
//     for(auto c: word){
//         int p = c-'a';
//         if(currNode->children[p]==nullptr){
//             return false;
//         }
//         currNode=currNode->children[p];
//     }
//     return true;
// }


// signed main (){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     int testcases=1;
//     cin >> testcases;
//     while (testcases--){
//         int n, m, p=0, q;
//         cin >> n;
//         vector<string>v(n);
//         string v[n];
//         inputarray(v,n);

//         TrieNode* root = new TrieNode();
//         f(i,0,n){
//             insert(root,v[i]);
//         }
//         cout << search(root,"bat") << endl;
//         cout << search(root,"ball") << endl;
//         cout << isPref(root,"bal") << endl;
    
//     }
// }

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

void solve(){
    int n, m, p=0, q;
    cin >> n;
    vector<int>a(n);
    inputarray(a,n);
    int ans;
    int l = a[0];
    int r = *max_element(all(a));
    while(l<=r){
        int mid = (l+r)/2;
        vector<int>temp=a;
        for(int i=n-1;i>0;i--){
            if(temp[i]>mid){
                int p = temp[i]-mid;
                temp[i]=mid;
                temp[i-1]+=p;
            }
        }
        if(temp[0]<=mid){
            ans=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    cout << ans << endl;
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
