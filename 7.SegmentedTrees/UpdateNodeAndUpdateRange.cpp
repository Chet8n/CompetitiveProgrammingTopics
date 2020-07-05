/****************************************


        MIN QUERY SEGMENT TREE


Chethan J
*****************************************/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define pb push_back
#define mp make_pair
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int n = 6;
int tree[400005]; //will store our segment tree structure
int a[6] = {1, 3, 2, -5, 6, 4}; //input array
const int inf = 1e9;

void buildTree(int node, int s, int e) {

    if (s == e) {
        tree[node] = a[s];
        return;
    }

    int mid = (s + e) >> 1;

    buildTree(2 * node, s, mid);
    buildTree(2 * node + 1, mid + 1, e);

    tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    return;
}

int query(int node, int s, int e, int i, int j) {

    //complete overlap:
    if (s >= i and e <= j) {
        return tree[node];
    }

    //no Overlap:
    if (s > j or e < i) {
        return inf;
    }

    //Partial Overlap:
    int mid = (s + e) >> 1;
    int left = query(2 * node, s, mid, i, j);
    int right = query(2 * node + 1, mid + 1, e, i, j);
    return min(left, right);
}

void updateNode(int node,int s,int e,int i,int val){

    //outta bounds;
    if(s > i or e < i){
        return;
    }

    //leaf node:
    if(s == e){
        tree[node] += val; 
        return;
    }

    //update left and right childs:
    int mid = (s+e)>>1;
    updateNode(2*node,s,mid,i,val);
    updateNode(2*node+1,mid+1,e,i,val);

    tree[node] = min(tree[2*node],tree[2*node+1]); 
    return;
}

void updateRange(int node,int s,int e,int i,int j,int val){

     //outta bounds:
    if(i>e or j<s){
        return;
    }

    //leaf node:
    if(s==e){
        tree[node] += val;
        return;
    }

    //otherwise:
    int mid = (s+e)>>1;
    updateRange(2*node,s,mid,i,j,val);
    updateRange(2*node+1,mid+1,e,i,j,val);

    tree[node] = min(tree[2*node],tree[2*node+1]);

    return;

}

int32_t main()
{

    IOS

    buildTree(1, 0, n - 1);
    updateNode(1,0,n-1,3,10);
    int ans = query(1, 0, n - 1, 3, 4);
    cout << ans << endl;

    /*
    for (int i = 1; i < 4 * n; i++) {
        cout << tree[i] << " ";
    }
    cout << endl;
    */


}
