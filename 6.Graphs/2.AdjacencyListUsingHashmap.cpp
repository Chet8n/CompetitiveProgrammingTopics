#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

class graph{

    unordered_map<string,list<pair<string,int>>> l;

public:
    void addEdge(string x, string y,bool isBi,int wt){
        l[x].pb(mp(y,wt));
        if(isBi){
            l[y].pb(mp(x,wt));
        }
    }

    void printGraph(){
        for(auto s:l){
            string edge = s.first;
            list<pair<string,int>> vertices = s.second;
            cout << edge << "->";

            for(auto vertex : vertices){
                string keyConected = vertex.first;
                int weight = vertex.second;

                cout << "(" <<keyConected <<"," <<weight <<")";
            }
            cout << endl;

        }
    }


};


int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    graph g;
    g.addEdge("a","b",true,20);
    g.addEdge("b","d",true,30);
    g.addEdge("a","c",true,10);
    g.addEdge("c","d",true,20);
    g.addEdge("a","d",false,50);

    g.printGraph();


    

}
