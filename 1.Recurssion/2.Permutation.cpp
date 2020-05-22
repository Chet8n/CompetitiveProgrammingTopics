#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

vector<int> vv;
bool chosen[3] = {false};


void permutaion(vector<int> v, int n){
	
	

	if(vv.size() == n){
		for(int x : vv){
			cout << x << " ";
		}
		cout << endl;
	}else{
		
		for(int i = 0; i < n;i++){
			if(chosen[i] == true)continue;
			else{
				vv.pb(v[i]);
				chosen[i] = true;
				permutaion(v,n);
				vv.pop_back();
				chosen[i] = false;
				//permutaion(v,n);

			}

		}
	}

}


int main()
{

	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> v;
	v = {1,2,3};
    //self-written
	permutaion(v,3);


	//STL
	do{
		for(int x : v){
			cout << x << " ";
		}
		cout << endl;

	}
	while (next_permutation(v.begin(),v.end()));


}
