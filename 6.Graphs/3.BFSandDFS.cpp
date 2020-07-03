#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define pb push_back
#define mp make_pair
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

//adjacency list:
vector<vector<int>> adj(1005);
vector<bool> visited(1005);
vector<int> par(1005);

void bfs(int src) {
    queue<int> q;
    q.push(src);
    visited[src] = true;
    par[src] = -1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto nbr : adj[node]){
            if(!visited[nbr]){
                q.push(nbr);
                visited[nbr] = true;
                par[nbr] = node;
            }
        }
    }
}

void dfs(int src){
    visited[src] = true;
    for(auto nbr : adj[src]){
        if(!visited[nbr]){
            dfs(nbr);
        }
    }
}


void solve() {



    int n; // number of vertices
    int e; // number of edges
    cin >> n >> e;

    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
}


int32_t main()
{

    IOS

    int T;
    T = 1;
    //cin >> T;
    while (T--) {
        solve();
    }




}
