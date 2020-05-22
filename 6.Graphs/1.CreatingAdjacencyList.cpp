#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

class graph{
	int v;
	list<int> *l;

public:

	graph(int v){
		this->v = v;
		l = new list<int>[v];
	}

	void addEdge(int x, int y){
		l[x].pb(y);
		l[y].pb(x);
	}

	void printAdjList(){

		for(int i = 0;i<v;i++){
			cout << "Vertex: "<< i <<"-> ";
			for(int x : l[i]){
				cout << x << " ";

			}
			cout << endl;
		}
	}

};


int main()
{

	ios::sync_with_stdio(0);
	cin.tie(0);

	graph g(4);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(2,3);
	g.addEdge(1,2);

	g.printAdjList();

	

}
