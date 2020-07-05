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
int lazy[400005] = {0};
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
void updateRangeLazy(int node, int s, int e, int i, int j, int val) {

    //check if current node as any lazy value:
    if (lazy[node] != 0) {
        tree[node] += lazy[node];
        // if the node is not the leaf node pass lazy to left and right child
        if (s != e) {
            lazy[2 * node] = lazy[node];
            lazy[2 * node + 1] = lazy[node];
        }
        // clear lazy value of current node;
        lazy[node] = 0;
    }

    // no overlap:
    if (s > j or e < i) {
        return;
    }

    //complete overlap:
    if (s >= i and e <= j) {
        tree[node] += val;
        if (s != e) {
            lazy[2 * node] += val;;
            lazy[2 * node + 1] += val;

        }
        return;
    }

    // Partial overlap:
    int mid = (s + e) >> 1;
    updateRangeLazy(2 * node, s, mid, i, j, val);
    updateRangeLazy(2 * node + 1, mid + 1, e, i, j, val);

    tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    return;

}

int queryLazy(int node, int s, int e, int i, int j) {

    //check if current node as any lazy value:
    if (lazy[node] != 0) {
        tree[node] += lazy[node];
        // if the node is not the leaf node pass lazy to left and right child
        if (s != e) {
            lazy[2 * node] = lazy[node];
            lazy[2 * node + 1] = lazy[node];
        }
        // clear lazy value of current node;
        lazy[node] = 0;
    }

    //no overlap:
    if (s > j or e < i) {
        return inf;
    }

    // complete overlap:
    if (s >= i and e <= j) {
        return tree[node];
    }

    //partial overlap:
    int mid = (s + e) >> 1;
    int left = queryLazy(2 * node, s, mid, i, j);
    int right = queryLazy(2 * node + 1, mid + 1, e, i, j);

    return min(left, right);
}


int32_t main()
{

    IOS

    buildTree(1, 0, n - 1);
    updateRangeLazy(1, 0, n - 1, 1, 3, 10);
    /*int ans = query(1, 0, n - 1, 3, 4);
    cout << ans << endl;

    /*
    for (int i = 1; i < 4 * n; i++) {
        cout << tree[i] << " ";
    }
    cout << endl;
    */
    updateRangeLazy(1, 0, n - 1, 0, 2, 10);
    updateRangeLazy(1, 0, n - 1, 0, 4, 10);

    cout << "Q 1 to 1: " << queryLazy(1, 0, n - 1, 1, 1) << endl;

    updateRangeLazy(1, 0, n - 1, 3, 4, 1);

    cout << "Q 3 to 5: " << queryLazy(1, 0, n - 1, 3, 5) << endl;




}
