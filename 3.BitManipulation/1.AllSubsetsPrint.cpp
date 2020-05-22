#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair


int main()
 {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 3;
    int a[n] = {1,2,3};

    for(int i = 0; i<(1<<n);i++){
        for(int j = 0;j< n;j++){
            if(i & (1<<j)){
                cout << a[j] << " ";
            }
        }
        cout << endl;
    }


    
}
