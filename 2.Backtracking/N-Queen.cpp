#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair


int counter = 0;
int board[1000][1000];


void printsol(int n){
    for(int i = 0; i< n;i++){
            for(int j = 0; j< n;j++){
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
}

bool issafe(int board[1000][1000],int row,int col,int n){

    for(int i = 0; i< col;i++){
        if(board[row][i]){
            return false;
        }
    }
    for(int i = row,j = col;i >= 0 && j >= 0;i--,j--){
        if(board[i][j]){
            return false;
        }
    }
    for(int i = row,j = col;j >= 0 && i < n;i++,j--){
        if(board[i][j]){
            return false;
        }
    }
    return true;

}

bool solveNQ(int board[1000][1000],int col,int n){

    bool result = false;

    //Base condition:
    if(col >= n){
        printsol(n);
        cout << endl;
        counter++;
        return true;
    }//recur
    else{
        for(int i = 0; i< n;i++){
            if(issafe(board,i,col,n)){
                board[i][col] = 1;
                if(result = solveNQ(board,col+1,n) || result){
                    
                    //return true;
                    //uncomment to stop at first solution available
                }
                //backtrack:
                board[i][col] = 0;
            }

        }
    }
    return result;

}

void solve(){
    int n;
    cin >> n;
    
    memset(board,0,sizeof(board));
    if(solveNQ(board,0,n) == false){
        cout << "NO solution" << endl;
    }
    


}


int main()
 {

    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();



    //uncomment to print number of solutions
    //cout << counter << "\n\n";

       
}
