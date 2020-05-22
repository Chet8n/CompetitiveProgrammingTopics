#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair



class graph{

    map<int,list<int>> l;

public:
    void addEdge(int x,int y){
        l[x].pb(y);
        l[y].pb(x);
    }

    void bfs(int source){

        map<int,bool> visited;
        queue<int> q;
        q.push(source);
        visited[source] = true;

        while( !q.empty()  ){
             int node = q.front();
             q.pop();
             cout << node << " ";

             for(int x : l[node]){
                if(!visited[x]){
                    q.push(x);
                    visited[x] = true;
                }
             }
        }
    }
};



int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    graph g;
    g.addEdge(0,1);
    g.addEdge(3,4);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(4,5);

    g.bfs(0);


    

}
