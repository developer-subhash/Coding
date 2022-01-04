#include<bits/stdc++.h>
#include<math.h>
using namespace std;
#define pii pair<int,int>
#define uii unordered_map<int,int>
#define usi unordered_map<string,int>
#define ui unordered_set<int>
#define umi unordered_multiset<int>
#define fon(i,n,j) for(int i=j;i<n;i++)
#define mid(x,y) (x+y)/2
#define vvi vector<vector<int>>
#define vi vector<int> 
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define pq priority_queue
typedef long long ll;
#define PI 3.14159265
#define pli pair<ll,int>
typedef long long ll;

class Node
{
    public:
    int data;
    Node* left, *right;
};


#define N 9

/***********************************************************LCA OF BINARY TREE *****************************************/

/******************************** FIRST METHOD *************************************/

//LCA in O(log(n)) n- no.of Node in tree
//rooted tree at Node 1
int euler[2*N-1];  // For Euler tour sequence
int level[2*N-1];  //level of Nodes in tour
int firstOccurence[N+1]; //check first occur. of Nodes
int ind;  //index to fill in euler and level arr

void eulerTour(int Node,int par,vvi& adj,int l){
	euler[ind] = Node; //insert in euler arr 
	level[ind] = l;  //insert l in level arr
	ind++;
	if(firstOccurence[Node] == -1)
		firstOccurence[Node] = ind-1;

	for(int child:adj[Node]){
		if(child==par)
			continue;
		eulerTour(child,Node,adj,l+1);
		euler[ind] = Node; //insert in euler arr 
		level[ind] = l;  //insert l in level arr
		ind++;
	}
}

void lca1(){
	int n,m;cin>>n>>m;
	vvi adj(m);
	fon(i,m,0){
		int a,b;cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	//euler = new int[2*n-1];
	//level = new int[2*n-1];
	//firstOccurence = new int[n+1];
	memset(firstOccurence, -1, sizeof(int)*(n+1));
	ind = 0;
	//eulerTour(1,1,adj,0);

	for(int i=0;i<2*n-1;i++)
		cout<<euler[i]<<" ";
	cout<<endl;
	for(int i=0;i<2*n-1;i++)
		cout<<level[i]<<" ";
	cout<<endl;
	for(int i=1;i<=n;i++)
		cout<<firstOccurence[i]<<" ";
}


/******************************************  SECOND METHOD *******************************************/

// TIME COMPLEXITY - O(N) - worst case

// Finds the path from root Node to given node of the tree, Stores the
// path in a vector path[], returns true if path exists otherwise false
bool findPath(Node *root, vector<int> &path, int k)
{
    // base case
    if (root == NULL) return false;
 
    // Store this Node in path vector. The Node will be removed if
    // not in path from root to k
    path.push_back(root->data);
 
    // See if the k is same as root's key
    if (root->data == k)
        return true;
 
    // Check if k is found in left or right sub-tree
    if ( (root->left && findPath(root->left, path, k)) ||
         (root->right && findPath(root->right, path, k)) )
        return true;
 
    // If not present in subtree rooted with root, remove root from
    // path[] and return false
    path.pop_back();
    return false;
}
 
// Returns LCA if Node n1, n2 are present in the given binary tree,
// otherwise return -1
int findLCA(Node *root, int n1, int n2)
{
    // to store paths to n1 and n2 from the root
    vector<int> path1, path2;
 
    // Find paths from root to n1 and root to n1. If either n1 or n2
    // is not present, return -1
    if ( !findPath(root, path1, n1) || !findPath(root, path2, n2))
          return -1;
 
    /* Compare the paths to get the first different value */
    int i;
    for (i = 0; i < path1.size() && i < path2.size() ; i++)
        if (path1[i] != path2[i])
            break;
    return path1[i-1];
}

/******************************************* THIRD METHODS ***************************************/


/*********** RMQ(range min query) USING SPARSE TABLE *************/
#define MAX 500
 
// lookup[i][j] is going to
// store index of minimum value in
// arr[i..j]. Ideally lookup
// table size should not be fixed
// and should be determined using
// n Log n. It is kept
// constant to keep code simple.
int lookup[MAX][MAX];

void preprocess(int arr[], int n)
{
    // Initialize M for the
    // intervals with length 1
    for (int i = 0; i < n; i++)
        lookup[i][0] = i;
 
    // Compute values from smaller
    // to bigger intervals
    for (int j = 1; (1 << j) <= n; j++)
    {
        // Compute minimum value for
        // all intervals with size
        // 2^j
        for (int i = 0; (i + (1 << j) - 1) < n; i++)
        {
            // For arr[2][10], we
            // compare arr[lookup[0][3]]
            // and arr[lookup[3][3]]
            if (arr[lookup[i][j - 1]]
                < arr[lookup[i + (1 << (j - 1))][j - 1]])
                lookup[i][j] = lookup[i][j - 1];
            else
                lookup[i][j]
                    = lookup[i + (1 << (j - 1))][j - 1];
        }
    }
}
 
// Returns minimum of arr[L..R]
int query(int arr[], int L, int R)
{
    // For [2,10], j = 3
    int j = (int)log2(R - L + 1);
 
    // For [2,10], we compare arr[lookup[0][3]] and
    // arr[lookup[3][3]],
    if (arr[lookup[L][j]]
        <= arr[lookup[R - (1 << j) + 1][j]])
        return arr[lookup[L][j]];
 
    else
        return arr[lookup[R - (1 << j) + 1][j]];
}

struct Query {
    int L, R;
};

// Prints minimum of given
// m query ranges in arr[0..n-1]
void RMQ(int arr[], int n, Query q[], int m)
{
    // Fills table lookup[n][Log n]
    preprocess(arr, n);
 
    // One by one compute sum of all queries
    for (int i = 0; i < m; i++)
    {
        // Left and right boundaries
        // of current range
        int L = q[i].L, R = q[i].R;
 
        // Print sum of current query range
        cout << "Minimum of [" << L << ", "
             << R << "] is "
             << query(arr, L, R) << endl;
    }
}





/********* LCA OF BST ************/

// TIME COMPLEXITY - O(N) in worst case
/* Function to find LCA of n1 and n2.
The function assumes that both n1 and n2
are present in BST */
Node* lca(Node* root, int n1, int n2)
{
    while (root != NULL)
    {
        // If both n1 and n2 are smaller than root,
        // then LCA lies in left
        if (root->data > n1 && root->data > n2)
        root = root->left;
 
        // If both n1 and n2 are greater than root,
        // then LCA lies in right
        else if (root->data < n1 && root->data < n2)
        root = root->right;
 
        else break;
    }
    return root;
}
  


int main(){
  
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
  #endif

 	lca1();
   return 0;
}