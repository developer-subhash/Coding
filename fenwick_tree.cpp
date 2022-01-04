#include<bits/stdc++.h>
#include<math.h>
using namespace std;

void update(int* fenwick,int in,int n,int val){
	for(int i=in;i<=n;i+=(i&(-i))){
		fenwick[i]+=val;
	}
}

int query(int* fenwick,int in){
	int sum=0;
	for(int i=in;i>0;i-=(i&(-i))){
		sum+=fenwick[i];
	}
	return sum;
}
 
int main(){
  
  #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   #endif
 
   int n;
  cin>>n;
  int* arr=new int[n+1];
  for (int i = 1; i <= n; ++i)
  {
  	cin>>arr[i];
  }

  int* fenwick=new int[n+1]();
  for(int i=1;i<=n;i++){
  	update(fenwick,i,n,arr[i]);
  }

  cout<<query(fenwick,n);
  
   return 0;
}