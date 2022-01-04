#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int long long
// for finding gcd of a and b

/******  GCD - EUCLID ALGO  *******/
//time complexity - O(log(max(a,b)))
int gcd(int a,int b){
	if(b==0)
		return a;
	return gcd(b,a%b);
}
// inbuilt for gcd calculation ->  __gcd(a,b)

/******** EXTENDED EUCLID ALGO *********/
// ax + by = gcd(a,b)  -> in this we can find x and y using euclid algo
//since gcd(a,b) = gcd(b,a%b)
// bx1 + (a%b)y1 = gcd(a,b)  -> we can write this  
//a%b = a - b*(a/b).. so comparing above two equation we get x = y1 , y = x1 - y1*(a/b)
//code
//The time complexity of the extended Euclidean algorithm is O(log(max(a,b))).

int extended_euclid(int a,int b,int& x,int& y){
	//base case of euclid algo
	if(b==0){
		//when b=0 then gcd(a,b)=a -> ay1 = a -> y1=1 ->x1=0
		x = 1;
		y = 0;
		return a;//return gcd
	}
	int x1,y1; //to store result of recursive call
	int gcd = extended_euclid(b,a%b,x1,y1);
	x = y1;
	y = x1 - y1*(a/b);
	return gcd;
}

/***** CHECK PRIME ******/
//Time complexity: Time complexity of this function is O(sqrt(N)).
bool isPrime(long long n){
	if(n==1)
		return false;
	if(n==2)
		return true;
	for(long long i=2;i*i<=n;i++){
		if(n%i==0)
			return false;
	}
	return true;
}

/******* SIEVE OF ERATOSTHENES **********/
// Total complexity: N * (½ + ⅓ + ⅕ + … ) = O(NloglogN)
void sieve(int* isPrime,int N) {
    //bool isPrime[N+1];
    for(int i = 0; i <= N;++i) {
        isPrime[i] = true;
    }
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i = 2; i * i <= N; ++i) {
         if(isPrime[i] == true) {
             // Mark all the multiples of i as composite numbers
             for(int j = i * i; j <= N ;j += i)
                 isPrime[j] = false;
        }
    }
}


vector<bool> sieve(int N) {
    vector<bool> isPrime(N+1);
    for(int i = 0; i <= N;++i) {
        isPrime[i] = true;
    }
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i = 2; i * i <= N; ++i) {
         if(isPrime[i] == true) {
             // Mark all the multiples of i as composite numbers
             for(int j = i * i; j <= N ;j += i)
                 isPrime[j] = false;
        }
    }
    return isPrime;
}

/******** ALL PRIME BETWEEN 1 TO N ********/
//return all prime between 1 to n
vector<int> all_prime(int n){
	vector<bool> sieve = sieve(n);
	vector<int> ans;
	fon(i,n+1,1){
		if(sieve[i])
			ans.push_back(i);
	}
	return ans;
}

/********* MODULAR EXPONENTIATION *********/
//modular exponentiation (a^b)%c
// best time complexity -> O( log2(b) ) (number of digits present in binary notation of number ‘b’)
int modpowIter(int a, int b, int c) {
        int ans=1;
        a%=c;
        while(b != 0) {
                if(b%2 == 1)
                    ans=(ans*a)%c;

                a=(a*a)%c;
                b /= 2;
        }
        return ans;
}



/******** MULTIPLICATIVE MODULO INVERSE *********/
// a.b = 1 => a is multiplicatuve inverse of b and vice-versa
// (a.b)%m = 1 => b is multiplicative modulo inverse of a and vice-versa
// (ab - 1)%m=0 => ab-1=mq for some q integer => ab + m(-q) = 1 => now it become extended euclid algo so,
// An inverse exists only when a and m are coprime i.e. . gcd(a,m) = 1
// ab + mQ = 1 -> a is mul. modulo inverse of b under modulo m and vice-versa ..so similarly for ax+by=1
// x is mult. modulo inverse of a under modulo b 
//so given a and m, calculate b
// ab + m(-q) = 1

int modInverse(int a,int m){
	int x,y;
	a%=m;
	int gcd = extended_euclid(a,m,x,y);
	return x%m;
}

/********* ALL PRIME FACTOR OF N ********/
// all prime factor of n. - important
// time - O(sqrt(n)*(log(n)))
vector<int> all_prime_factor(int n){
	vector<int> ans;

	for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            ans.push_back(i);
            while(n%i == 0){
            	n /= i;
            }
        }
    }
    if (n != 1) {
        ans.push_back(n);
    }
	return ans;
}

/***** GET ALL PRIME FACTOR **********/
vvi get(){
	int N = 1e5 + 1;
    vvi primes(N);
    
    
    vi sieve(N,1);
    
    //get all prime factor 
    for(int i=2;i<N;i++){
       if(sieve[i]){
           for(int j=1;j*i<N;j++){
               primes[i*j].pb(i);
               sieve[i*j] = 0;
           }
       }
    }

    return primes;
}


/********* PRIME FACTORIZATION *******/
//prime factorization of n in O(sqrt(n))
unordered_map<int,int> prime_factorization(int n){
	//first find all prime factor of n
	vector<int> prime = all_prime_factor((n));
	unordered_map<int,int> ans;
	for(int i=0;i<prime.size();i++){
		int count=0;
		while(n%prime[i]==0){
			count++;
			n/=prime[i];
		}
		ans[prime[i]] = count;
	}
	return ans;
}

/******** PRIME FACTORIZATION - 2nd APPROACH ***********/
//if it is allowed to work in O(n),then we can calculate factorization in O(log(n)) time
unordered_map<int,int> eff_prime_factorization(int n){
	
	unordered_map<int,int> ans;
	int* minPrime=new int[n + 1]();
	for (int i = 2; i * i <= n; ++i) {
    	if (minPrime[i] == 0) {         //If i is prime
        	for (int j = i * i; j <= n; j += i) {
            	if (minPrime[j] == 0) {
                	minPrime[j] = i;
            	}
        	}
    	}		
	}
	for (int i = 2; i <= n; ++i) {
    	if (minPrime[i] == 0) {
        	minPrime[i] = i;
    	}
	}

	
    while (n != 1) {
    	int t = minPrime[n];
        //res.push_back(minPrime[n]);
        ans[t]++;
        n /= minPrime[n];
    }
    
    delete[] minPrime;
    return ans;
}

/******** NO. OF DIVISOR ********/
//number of divisor of n
int num_divisor(int n){
	int ans=1;
	unordered_map<int,int> mp;
	mp = prime_factorization(n);
	for(auto it:mp){
		ans *= (it.second+1);
	}
	return ans;
}

#define N 100

//no. of prime factor of each i from 1 to n
vector<ll> prime_factor(){
  vi minPrime(N+1);
  //apply sieve concept
  for(int i=2; i*i<=N; i++){
    if(minPrime[i] == 0){
      for(int j=i*i; j<=N; j+=i){
        if(minPrime[j] == 0)
          minPrime[j] = i;
      }
    }
  }

  for(int i=1; i<=N; i++){
    if(minPrime[i] == 0)
      minPrime[i] = i;
  }

  vector<ll> factor(N+1,1);

  for(int i=4; i<=N; i++){
    int x = i,count=0;
    if(minPrime[i] == i){
      continue;
    }
    while(x%minPrime[i] == 0){
      count++;x/=minPrime[i];
    }

    ll y = (x==1)?0:factor[x];

    factor[i] = (1ll*(1+count)*(y+1)) - 1;  //except 1 as prime factor
  }

  return factor;
}

/******** EULER'S TOTIENT FUNCTION ******/ 
//thus function find no. of integer less than n which is co-prime with n
//formula = n*(1-1/p1)*(1-1/p2)*....till all prime factor p1,p2,p3,...
int euler_totient(int n){
	// first find all prime factor of n;
	vector<int> prime = all_prime_factor(n);
	int ans=n;
	for(int i=0;i<prime.size();i++){
		ans/=prime[i];
		ans*=(prime[i]-1);
	}
	return ans;
}

//using sieve concept , finding no. pf co-prime of all integer between from 1 to n
void euler_seive(int n){
	vector<int> v(n+1);
	for (int i = 0; i < n+1; ++i)
	{
		v[i]=i;
	}

	for(int i=2;i*i<=n;i++){
		if(v[i]!=i)  //if v[i] is not a prime no.
			continue;
		for(int j=i*i;j<=n;j+=i){
			v[j]/=v[i];
			v[j]*=(v[i]-1);
		}
		v[i] = i-1;  //prime no. p have p-1 co-primes 
	}
	for(int i=1;i<=n;i++){
		cout<<v[i]<<" ";
	}
}

/***** multiplicative modulo inverse - IMPORTANT ********/
// (a/b)%m = (a.b^-1)%m
// if m is prime -> (b^-1)%m = (b^(m-2))%m .. use fermat's little theorem
// else (b^-1)%m = (b^(euler_totient(m)-1))%m
// calculating (a/b)%m
int moduloM(int a,int b,int m){
	int ans;
	if(isPrime(m)){
		int t = modpowIter(b,m-2,m);
		ans = ((a%m)*(t%m))%m;
	}
	else{
		int t = modpowIter(a,(euler_totient(m)-1),m);
		ans = ((a%m)*(t%m))%m;
	}
	return ans;
}

/***** SEGMENTED SIEVE OF ERATOSTHENES *******/
//finding all prime between range [l,r] where r-l+1 <= (10^6)
void segmented_sieve(long long l,long long r){
	bool isPrime[r - l + 1]; //filled by true
	for (long long i = 2; i * i <= r; ++i) {
    	for (long long j = max(i*i, (l+(i-1))/i*i); j <= r; j += i) {
        	isPrime[j - l] = false;
    	}
	}
	for (long long i = max(l, ll(2)); i <= r; ++i) {
    	if (isPrime[i - l]) {
        	//then i is prime
    	}
	}
}

/******* FACTORIAL CALCULATION ********/
//calculating array of size n where arr[i] contain fact(i)%m 
vector<int> factorial(int n,int m){
	vector<int> arr(n+1,1);
	for(int i=2;i<=n;i++){
		arr[i] = ((arr[i]%m)*(arr[i-1]%m))%m;
	}
	return arr;
}

/******* nCr CALCULATION ******/
int nCr(int n,int r,int m){
	vector<int> fact = factorial(n,m);
	int ans=1;
	ans = fact[n];
	ans = ((ans%m)*(moduloM(1,fact[r],m)%m)*(moduloM(1,fact[n-r],m)%m)%m);
	return ans;
}

/****** GET ALL DIVISOR OF N ********/
vector<pii> get_factor(int n){
  vector<pii> ans;

  for (int i = 2; i * i <= n; ++i) {

        if (n % i == 0) {
            int count=0;
            while(n%i == 0){
              n /= i;
              count++;
            }
            ans.pb({i,count});
        }
    }
    if (n != 1) {
        ans.push_back({n,1});
    }
  return ans;
}

void divisors(vector<pii>& factors, int in, vi& ans,int res){
  if(factors.size() == in){
    ans.pb(res);
    return;
  } 

  for(int i=0;i<=factors[in].second;i++){
    divisors(factors,in+1,ans,res);
    res *= factors[in].first;
  }
}

vi get_divisor(int n){
  vector<pii> factors = get_factor(n);

  vi ans; 
  int res=1;
  divisors(factors,0,ans,res);
  return ans;
}

int main(){
	#ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   #endif
   int x=1e6,y=1e6;
   //int z = x*y;
   //cout<<x<<endl;
}