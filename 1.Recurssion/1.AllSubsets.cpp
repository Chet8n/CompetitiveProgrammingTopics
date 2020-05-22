#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

vector<int> vv;


void subsets(vector<int> v, int n, int z){
	
	

	if(z == n){
		for(int x : vv){
			cout << x << " ";
		}
		cout << endl;
	}else{
		// add that element
		vv.pb(v[z]);
		subsets(v,n,z+1);
		//dont add that element
		vv.pop_back();
		subsets(v,n,z+1);

	}

}


int main()
 {

    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> v;
    v = {1,2,3};
    subsets(v,3,0);
    //O(2^n) - time

    
}
