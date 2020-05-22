#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

ll count(ll coins[],ll n, ll sum){

    ll dp[n+1][sum+1];

    for(ll i = 0;i < sum+1;i++){
        dp[0][i] = 0;
    }
    for(ll i = 0; i< n+1;i++){
        dp[i][0]= 1;
    }

    for(int i = 1;i < n+1;i++){
        for(int j = 1;j < sum+1;j++){
            if(coins[i-1]<=j){
                dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

   


    return dp[n][sum];
}


int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, sum;
    cin >> sum;
    cin >> n;
    ll coins[n];
    for(int i = 0;i < n;i++){
        cin >> coins[i];
    }
    cout << count(coins,n,sum);


    

}
