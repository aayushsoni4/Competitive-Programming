#include<bits/stdc++.h>
using namespace std;
 
const int MAX = 10001;
 
// Comparator to sort queries based on the end position
bool cmp(vector<int> x, vector<int> y){
    return x[1] < y[1];
}
 
// Update function of BIT
void update(int i, int val, int bit[], int n){
    for (; i <= n; i += i&-i){
        bit[i] += val;
    }
}
 
// Query function of BIT
int query(int i, int bit[], int n){
    int sum = 0;
    for (; i>0; i-=i&-i)
        sum += bit[i];
    return sum;
}
 
// Function to solve the problem
vector<string> solve(int arr[], int n, vector<vector<int>> queries, int q)
{
    // Sort queries based on the end position
    sort(queries.begin(), queries.end(), cmp);

    // Initialize BIT
    int bit[n+1];
    memset(bit, 0, sizeof(bit));
 
    // Initialize prev array
    int prev[MAX];
    memset(prev, -1, sizeof(prev));
 
    // Array to store answer for all queries
    vector<string> ans(q, "NO"); // Initialize all answers to "NO"
    int qind = 0;

    // Iterate over input array
    for (int i = 0; i < n; i++){

        // If prev is not -1, update BIT
        if (prev[arr[i]] != -1){
            update(prev[arr[i]] + 1, -1, bit, n);
        }

        // Set prev[arr[i]] as i and update BIT
        prev[arr[i]] = i;
        update(i + 1, 1, bit, n);
 
        // Check if the end position of any query is equal to i
        while (qind < q && queries[qind][1] == i + 1){
            int l = queries[qind][0], r = queries[qind][1];
            int idx = queries[qind][2];

            // Calculate the number of distinct elements in the subarray
            int distinct_count = query(r, bit, n) - query(l - 1, bit, n);
            
            // Check if the subarray is "good"
            if (distinct_count > 1){
                ans[idx] = "YES"; // Update answer to "YES" if the subarray is "good"
            }
            qind++;
        }
    }
    
    return ans;
}
 
// Driver code
int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        vector<vector<int>> queries(q, vector<int>(3));
        // Queries of the form - {l, r, idx}
        for(int i = 0; i < q; i++){
            int x, y;
            cin >> x >> y;
            queries[i][0] = x;
            queries[i][1] = y;
            queries[i][2] = i;
        }
        vector<string> ans = solve(a, n, queries, q);
        for(int i = 0; i < q; i++){
            cout << ans[i] << endl;
        }
    }
    return 0;
}
