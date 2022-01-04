#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
typedef unsigned long long ll;

//link for c++ math library -  https://www.cplusplus.com/reference/cmath/

//O(log(n))
int power(ll x,int n){
	ll ans=1;
	int mod=1000000007;
	x%=mod;
	while(n!=0){
		if(n&1){
			ans*=x;
			ans%=mod;
		}
		x*=x;
		x%=mod;
		n=n>>1;
	}

	return int(ans);
}

int nCr(int n,int r){
	int mod=1000000007;
	std::vector<ll> v(n+1,1);
	for(int i=2;i<=n;i++){
		v[i]=i*v[i-1];
		v[i]%=mod;
	}

	ll ans=1; 

	// (x/y)%m = ((x%m)*((y^(m-2))%m)) % m;
	ans = ((v[n]%mod)*(power(v[r]*v[n-r],mod-2)%mod))%mod;

	return int(ans);
}



int main(){
   #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   #endif
   int n,r;
   cin>>n>>r;
   cout<<nCr(n,r)<<endl;
   ll mod=1e9+7;

   vector<long long> dp(r+1,1);
        
   for(int i=1;i<=r;i++){
       dp[i] = ((dp[i-1]*(n-i+1))%mod * (power(i,int(mod-2)) % mod))%mod;
   }
   
   cout<<dp[r];

}