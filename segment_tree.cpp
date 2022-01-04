#include<bits/stdc++.h>
#include<math.h>
using namespace std;
#define mid(x,y) (x+y)/2

void buildTree(int* tree,int* arr,int si,int ei,int ni){
	if(si==ei){
		tree[ni]=arr[si];
		return ;
	}

	int mid = mid(si,ei);
	buildTree(tree,arr,si,mid,2*ni);
	buildTree(tree,arr,mid+1,ei,2*ni+1);
	tree[ni] = tree[2*ni] + tree[2*ni+1];
}

int queryRange(int* tree,int si,int ei,int l,int r,int ni){
	if(r<si||l>ei)
		return 0;
	if(l<=si&&r>=ei)
		return tree[ni];
	int mid = mid(si,ei);
	return (queryRange(tree,si,mid,l,r,2*ni) + queryRange(tree,mid+1,ei,l,r,2*ni+1));
}

void update(int* tree,int* arr,int si,int ei,int in,int value,int ni){
	if(si==ei){
		arr[in]+=value;
		tree[ni]+=value;
		return ;
	}
	int mid = mid(si,ei);
	if(in>=si&&in<=mid)
		update(tree,arr,si,mid,in,value,2*ni);
	else
		update(tree,arr,mid+1,ei,in,value,2*ni+1);

	tree[ni] = tree[2*ni] + tree[2*ni+1];
}

void updateRange(int* tree,int* lazy,int si,int ei,int l,int r,int val,int ni){
	if(si>ei)
		return ;
	if(lazy[ni]!=0){
		tree[ni] += (ei-si+1)*lazy[ni];
		if(si!=ei){
			lazy[2*ni] += (lazy[ni]);
			lazy[2*ni+1] += lazy[ni];
		}
		lazy[ni] = 0;
	}
	if(l>ei ||r<si)
		return;
	if(l>=si && r<=ei){
		tree[ni] += (ei-si+1)*val;
		if(si!=ei){
			lazy[2*ni] += (val);
			lazy[2*ni+1] += val;
		}
		return ;
	}
	int mid = mid(si,ei);
	updateRange(tree,lazy,si,mid,l,r,val,2*ni);
	updateRange(tree,lazy,mid+1,ei,l,r,val,2*ni+1);
	tree[ni] = tree[2*ni] + tree[2*ni+1];
}

int queryRange(int* tree,int* lazy,int si,int ei,int l,int r,int ni){
	if(si>ei || r<si || l>ei)
		return 0;
	if(lazy[ni]!=0){
		tree[ni] += (ei-si+1)*lazy[ni];
		if(si!=ei){
			lazy[2*ni] += (lazy[ni]);
			lazy[2*ni+1] += lazy[ni];
		}
		lazy[ni] = 0;
	}

	if(si>=l && ei<=r)
		return tree[ni];
	int mid = mid(si,ei);
	int s1 = queryRange(tree,lazy,si,mid,l,r,2*ni);
	int s2 = queryRange(tree,lazy,mid+1,ei,l,r,2*ni+1);
	return (s1+s2);

}
 
int main(){
  
  #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   #endif
 
  int n;
  cin>>n;
  int* arr=new int[n];
  for (int i = 0; i < n; ++i)
  {
  	cin>>arr[i];
  }

  int* tree=new int[4*n]();
  int* lazy=new int[4*n]();

  buildTree(tree,arr,0,n-1,1);

  int s = queryRange(tree,lazy,0,n-1,2,n-2,1);
  cout<<s<<endl;
  updateRange(tree,lazy,0,n-1,2,n-2,2,1);
  s = queryRange(tree,lazy,0,n-1,1,3,1);
  cout<<s<<endl;
   return 0;
}