#include<bits/stdc++.h>
#include<math.h>
using namespace std;
#define all(s) s.begin(),s.end()
#define pii pair<int,int>
#define uii unordered_map<int,int>
#define usi unordered_map<string,int>
#define ui unordered_set<int>
#define umi unordered_multiset<int>
#define fon(i,n,j) for(int i=j;i<n;i++)
#define mid(x,y) (x+y)/2
#define vi vector<int> 
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define pq priority_queue
typedef long long ll;

//disjoint set union_find algo in min time complexity O(m*log(n))  //m- no. of operation of take_union
class DSU1{
	int n;
	vector<int>* list;
	int* location;
public:
	//constructor calling
	DSU1(int n){
		this->n=n;
		list = new vector<int>[n+1];
		location = new int[n+1];
		for(int i=1;i<=n;i++){
			list[i].push_back(i);
			location[i] = i;
		}
	}

	~DSU1(){
		delete[] location;
	}

	int index(int num){
		return location[num];
	}


	void take_union(int num1,int num2){
		int id1 = index(num1);
		int id2 = index(num2);

		if(id1==id2)
			return;

		//we will put less sizer vector's element in large sizer vector for reducing time complexity
		// if we don't swap ..time complexity -> O(n*(e))  e -> no. of time we do operation of union 
		//after swaping time reduce to O(n*(log(e)))
		if(list[id1].size()>list[id2].size()){
			swap(id1,id2);
			int t = id1;
			id1 = id2;
			id2 = t;
		}

		while(list[id1].size()!=0){
			int element = list[id1].back();
			list[id2].push_back(element);
			location[element] = id2;
			list[id1].pop_back();
		}
	}

	//checking if two element are in same subset or in different
	bool find(int num1,int num2){
		return (index(num1) == index(num2));
	}
};

//disjoint set union_find algo in O(n*(m)) time complexity m-> no. of operation 
class DSU2{
	int n;
	int* arr;
public:
	DSU2(int n){
		this->n = n;
		arr = new int[n+1];
		for(int i=1;i<=n;i++){
			arr[i] = i;
		}
	}

	~DSU2(){
		delete[] arr;
	}

	int findpar(int x){
		while(x!=arr[x]){
			x = arr[x];
		}
		return x;
	}

	void take_union(int n1,int n2){
		int par1 = findpar(n1);
		int par2 = findpar(n2);
		if(par2==par1)
			return;
		arr[par1] = par2;
	}

	bool find(int n1,int n2){
		return (findpar(n1) == findpar(n2));
	}
};

//disjoint set union_find algo in O(m) in average..best for maximum no. of operation when we apply
// ..max O(m*log(n)) time complexity e-> no. of operation 
//in this we can't separate a component in to two different component
class DSU3{
	int n;
	int* par;  //for storing root or parent of node
	int* len; //for storing the total no. of node
	int num_of_comp; //num of different components
public:
	DSU3(int n){
		this->n = n;
		par = new int[n+1];
		len = new int[n+1];
		for(int i=1;i<=n;i++){
			par[i] = i;
			len[i] = 1;
		}
		num_of_comp = n;
	}

	~DSU3(){
		delete[] par;
		delete[] len;
	}

	int findpar(int x){
		if(par[x] == x)
			return x;
		return par[x] = findpar(par[x]);   //path compression...when we find parent first time then 
		                //we assign root as parent so that next time we will get root in O(1)
	}
		

	void take_union(int n1,int n2){
		int par1 = findpar(n1);
		int par2 = findpar(n2);
		if(par2==par1)
			return;
		
		if(len[par1]>len[par2]){
			int t = par2;
			par2 = par1;
			par1 = t;
		}

		par[par1] = par2;  //make smaller size tree as child of larger tree
		len[par2] += len[par1];  //larger size tree will have now size increased
		num_of_comp--;
	}

	bool find(int n1,int n2){
		return (findpar(n1) == findpar(n2));
	}

	int components(){
		return num_of_comp;
	}
};

//kruskal's algo .. MST
vector<vi> kruskal_algo(int n,int m,vector<vi> edge){
	sort(all(edge));
	int t=0;
	int i=0;
	vector<vi> mst;
	int cost = 0;
	DSU3 dsu(n);

	while(t<n-1){
		int v1 = edge[i][1];
		int v2 = edge[i][2];
		if(!dsu.find(v1,v2)){
			mst.push_back(edge[i]);
			dsu.take_union(v1,v2);
			cost += edge[i][0];
			t++;
		}
		i++;
	}

	cout<<cost<<endl;
}

//****prim's algo ..time complexity -> O(v*v) v - no. of vertices *****//
int minKey(vector<int> &key,vector<int> &mstSet,int v){
	int min=INT_MAX,nextMinNode;
	for(int i=1;i<=v;i++){
		if(!mstSet[i] && key[i]<min){
			min = key[i];
			nextMinNode = i;
		}
	}
	return nextMinNode;
}

vector<int> primMST(int v ,int** adj){
	vector<int> par(v+1);     //for storing parent of any vertex in MST
	vector<int> mstSet(v+1);  //for storing vertex which are in MST
	vector<int> key(v+1 , INT_MAX);     //associating a value that is key to each node , initially set big value

	//first include one arbitrary node in MST , let's select first node
	key[1] = 0;
	par[1] = -1;

	//run loop till v-1 time as v-1 edge require
	for(int i=1 ; i<v ; i++){
		int u = minKey(key, mstSet,v);

		mstSet[u] = 1;
		for(int i=1;i<=v;i++){
			if(!mstSet[i] && adj[u][i] && adj[u][i] < key[i]){
				par[i] = u;
				key[i] = adj[u][i];
			}
		}
	}

	return par;
}

/*** prim's algo ..time complexity  ->  O((E+V)*LogV) V-no. of vertices , E-no. of edges ****/

int prim(int n,vector<vector<pii>> adj){
	pq<pii,vector<pii>,greater<pii>> q;
	q.push({0,1}); // first-distance, second-vertex

	vi visited(n+1);
	int minCost = 0;

	while(!q.empty()){
		//select edge with minimum weight
		pii p = q.top();
		q.pop();

		int node = p.second, distance = p.first;

		//check for cycle
		if(visited[node])
			continue;

		minCost += distance;
		visited[node] = 1;

		for(int i=0;i<adj[node].size();i++){
			int adj_node = adj[node][i].first;  //in adjacency matrix - first->vertex, second->weight
			if(!visited[adj_node])
				q.push({adj[node][i].second , adj_node});
		}

	}

	return minCost;
}

//BFS... breadth first search.. reference -> https://cp-algorithms.com/graph/breadth-first-search.html
// total n vertices, source vertices = s, adj = adjacency list
// time complexity -> O(v+2*e)... if graph is fully connected then we traverse 2*e times as for each 
//vertices we traverse to all it's edge so any edge will be traversed maximum two time so O(2*e) ,but
//if graph is fully discoonected then we traverse each vertices so, O(v) so finally -> O(v+e) 
void BFS(int n,int s,vector<vi> adj,int dest){
	queue<int> q;
	vector<bool> used(n);
	//d vector store distance from source to any vertex
	//p vector store the parent of any vertex
	vector<int> d(n), p(n);

	q.push(s);
	used[s] = true;
	p[s] = -1;
	while (!q.empty()) {
    	int v = q.front();
    	q.pop();
    	for (int u : adj[v]) {
        	if (!used[u]) {
            	used[u] = true;
            	q.push(u);
            	d[u] = d[v] + 1;  //distance between two vertex is assumed as 1
            	p[u] = v;   //parent of vertex u is v
        	}
    	}
	}

	vector<int> path; //store path of vertex u from source vertes s
	int u=dest;

	if (!used[u]) {
    	//cout << "No path!";
	}
	else{
    	for (int v = u; v != -1; v = p[v])
        	path.push_back(v);
    	reverse(path.begin(), path.end());
    	/*cout << "Path: ";
    	for (int v : path)
        	cout << v << " ";*/
	}
}



//different connected component  -> use dfs and no. of times we call dfs is no. of diff component
int num_of_component(int n,vector<vi> adj){
	vector<bool> visited(n+1);
	int ans=0;

	for(int i=1;i<=n;i++){
		if(!visited[i]){
			ans++;
			//dfs(i,visited,adj);
		}
	}

	return ans;
}

//topological sorting -> link https://www.geeksforgeeks.org/topological-sorting/
// after DFS of each node ..push it to stack ..

void dfs1(int v,vector<bool>& visited,vector<vi>& adj,stack<int> &ans) {
    visited[v] = true;
    for (int u : adj[v]) {
      //  if (!visited[u])
          //  dfs1(u);
    }
    ans.push(v);	
}

stack<int> top_sort(int n,vector<vi> adj){
	stack<int> ans;
	vector<bool> visited(n+1);

	for(int i=1;i<=n;i++){
		if(!visited[i]){
			//DFS_topologic(i,visited,adj,ans);
		}
	}

	return ans;
}

//topological sorting using BFS
//first we well calculate indegree of each node using dfs and store it in an array and then we will 
//start BFS from node having 0 indegree and unlike normal BFS, we push any node into queue only when
//it's indegree is zero also we will decrease indegree of all children of front node ..

void dfs2(int v,vector<int>& visited,vector<vi> &adj,vi& indegree){
	visited[v] = true;
	for(int i:adj[v]){
		indegree[i]++;
		if(!visited[i]){
			dfs2(i,visited,adj,indegree);
		}
	}
}

vi BFS(int n,vector<vi> adj){
	vi indegree(n+1);
	vi visited(n+1);
	
	for(int i=1;i<=n;i++){
		if(!visited[i])
			dfs2(i,visited, adj,indegree);
	}

	queue<int> q;

	for(int i=1;i<=n;i++){
		if(indegree[i]==0)
			q.push(i);
	}
	vi ans;
	while(q.size()!=0){
		int f = q.front();
		q.pop();
		ans.push_back(f);
		for(int i:adj[f]){
			indegree[i]--;
			if(indegree[i]==0)
				q.push(i);
		}
	}

	return ans;
}

//check if graph is cyclic or not for connected graph....so for this we use BFS and will also 
//maintain a parent array for storing parent of node while trsversing
bool isCyclic1(int n, vector<vi> adj){
	queue<int> q;
	q.push(1);
	vector<bool> visited(n+1);
	visited[1]=true;
	vi parent(n+1);

	for(int i:parent)parent[i]=i;

	while(!q.empty()){
		int node = q.front();
		q.pop();
		for(auto i:adj[node]){
			if(visited[i] && parent[i]!=node)   //check here
				return true;   //cycle is there
			if(!visited[i]){
				visited[i]=true;
				parent[i]=node;
				q.push(i);
			}
		}
	}

	return false;
}

//we can also check cycle detection using the no. of nodes and no. of edges present in a connected 
//component. so for this we use dfs

void dfs(int v,vector<bool> &visited,vector<vi> &adj,int& node,int& edge){
	visited[v] = true;
	node++;
	edge += (adj[v].size());
	for(int i:adj[v]){
		if(!visited[i])
			dfs(i,visited,adj,node,edge);
	}
}

bool isCyclic2(int n,vector<vi> adj){
	vector<bool> visited(n+1);

	for(int i=1;i<=n;i++){
		if(!visited[i]){
			int node=0,edge=0;
			dfs(i,visited,adj,node,edge);
			edge/=2;
			if(edge>=node)
				return true;
		}
	}

	return false;
}
/**** CYCLE property
   no. of cycle = 1 + no. of uniqe path between any two node

*****/




/*****  shortest path algo btn src s and destination d   *****/

//for unweighted and undirected graph - simply use BFS

int shortest_path(int n,vector<vector<int>> adj,int src,int des){
	int dis=0;
	queue<int> q;
	q.push(src);
	std::vector<int> visited;
	visited[src]=1;

	while(q.size()!=0){
		int f = q.front();
		q.pop();
		dis++;
		for(auto x:adj[f]){
			if(x==des){
				return dis;
			}
			if(!visited[x]){
				q.push(x);
				visited[x]=1;
			}
			
		}
	}

	return -1;  //if no path between src and des
}
/*####  NOTE  #####*/
// for finding min distance from many src to every other node, we will apply multiBFS , in that we
// push all src inside queue first and maintain an array for updating distance of each node


//for weighted and undirected graph

//   DIJKSTRA'S algorithm
// here we apply same concept as we applied in unweighted graph, there we used BFS , here main key point
// is also same , for visualisation for any edge of weight w between any two vertex , insert w node of 
//edge weight 1 and then this question will become same as above.. so finally , after observation, we can
// know that we have to move to that adjacent node of src which is at min dist or whose edge wt is min..
// so at each step , we add a node in our path 


// time complexity  - O((n+e)*log(n+e))  can be improved a little bit using priority queue
int dijkstra(int n,vector<vector<pair<int,int>>> &adj,int src,int des){
	set<pair<int,int>> s; //insert distance, node
	s.insert({0,src});
	vector<int> distance(n+1,1e9);
	vi visited(n+1);
	visited[src]=1;

	while(s.size()!=0){
		int dis = s.begin()->first;
		int node = s.begin()->second;

		distance[node] = min(dis,distance[node]);

		//cout<<node<<" "<<dis<<endl;

		s.erase(s.begin());
		/*if(visited[node])
			continue;*/
		visited[node]=1;
		for(auto x:adj[node]){
			if(!visited[x.first])
				s.insert({(dis+x.second),x.first});
		}
	}

	if(distance[des]==0)
		return -1;  //no any path between src and des node

	return distance[des];
}
// NOTE : like multiBFS , we can do multidijkstra's too, here we will insert all src in set 


int main(){
  
  #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   #endif
 
   int n=10;
   /*DSU1 s1(n);
   DSU2 s2(n);
   int q;cin>>q;
   while(q--){
   	int n1,n2;cin>>n1>>n2;
   	s1.take_union(n1,n2);
   	s2.take_union(n1,n2);
   }

   cout<<s1.find(1,2)<<" "<<s2.find(1,2);*/
   vector<vector<pair<int,int>>> adj(n+1);
   adj[1].pb({2,3});
   adj[1].pb({3,4});
   adj[2].pb({1,3});
   adj[2].pb({8,2});
   adj[2].pb({4,1});adj[3].pb({1,4});adj[3].pb({4,2});adj[3].pb({6,2});adj[4].pb({2,1});
   adj[4].pb({5,5});adj[4].pb({3,2});adj[4].pb({7,6});adj[5].pb({4,5});adj[6].pb({3,2});
   adj[6].pb({10,7});adj[7].pb({4,6});adj[7].pb({10,5});adj[8].pb({2,2});adj[8].pb({9,3});
   adj[9].pb({8,3});adj[9].pb({10,4});adj[10].pb({6,7});adj[10].pb({7,5});adj[10].pb({9,4});

   cout<<dijkstra(n,adj,1,10);
   return 0;
}