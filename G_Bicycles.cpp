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


vector<int> dijkstra(const vector<vector<pair<int, int>>>& adj, int source, int n) {
    vector<int> dist(n + 1, INT_MAX); // Initialize distances with infinity
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[source] = 0; // Distance from source to itself is 0
    pq.push({0, source}); // Push the source node with distance 0 to start

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        // If the distance to u from the source is greater than the stored distance, ignore
        if (d > dist[u]) continue;

        // Iterate through all adjacent nodes of u
        for (const auto& neighbor : adj[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            // If a shorter path is found to v through u, update distance
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}


// Function to find the shortest time to reach city n from city 1
int shortestTime(vector<vector<pair<int, int>>>& adj, vector<int>& sT, int n) {
    vector<int> dist(n + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        int u = pq.top().second;
        int timeSoFar = pq.top().first;
        pq.pop();

        if (timeSoFar > dist[u]) continue;

        for (auto& neighbor : adj[u]) {
            int v = neighbor.first;
            int weight = neighbor.second * sT[u]; // Considering slowness factor of the bike

            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return dist[n]; // Shortest time to reach city n from city 1
}


void solve(){
    int n, m, p=0, q;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adjList(n + 1); 
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }
    vector<int>sT(n+1,0);
    f(i,0,n){
        cin >> sT[i+1];
    }
    vector<vector<pair<int, int>>> adj(n + 1); 
    for(int i=1;i<=n;i++){
        for(auto j:adjList[i]){
            adj[i].push_back({j.first,j.second*sT[i]});
        }
    }

    // vector<int> distances = dijkstra(adj, 1, n);
    // cout << distances[n] << endl;

    cout << shortestTime(adjList, sT, n) << endl;
 
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