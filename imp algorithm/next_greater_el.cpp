#include<bits/stdc++.h>
using namespace std;

// code for finding next greater or equal element of any element present at any index i 
// problem link ->  https://www.geeksforgeeks.org/next-greater-element/

vector<int> nge(){
	int n;cin>>n;
	std::vector<int> v(n);
	for (int i = 0; i < n; ++i)
	{
		/* code */cin>>v[i];
	}

	std::vector<int> ans(n);  //this will store the next greater or equal element 
	stack<int> s;

	for (int i = n-1; i > -1; --i)
	{
		while(s.empty() == false && s.top() < v[i])
			s.pop();

		if(s.empty())
			ans[i] = -1;
		else
			ans[i] = s.top();

		s.push(v[i]);
	}

	for (int i = 0; i < n; ++i)
	{
		cout<<v[i]<<" ---> "<<ans[i]<<endl;
	}

	return ans;
}

//code for next greater or equal element on both side of current element
void nge_on_both_side(){
	int n;cin>>n;
	std::vector<int> v(n);
	for (int i = 0; i < n; ++i)
	{
		/* code */cin>>v[i];
	}

	std::vector<int> ans_right(n);  //this will store the next greater or equal element for 
	//right side of curr element
	std::vector<int> ans_left(n); //for left side next greater elemnt
	stack<int> s;

	for (int i = n-1; i > -1; --i)
	{
		while(s.empty() == false && s.top() < v[i])
			s.pop();

		if(s.empty())
			ans_right[i] = -1;
		else
			ans_right[i] = s.top();

		s.push(v[i]);
	}

	//empty stack
	while(!s.empty())s.pop();

	for (int i = 0; i < n; ++i)
	{
		while(s.empty() == false && s.top() < v[i])
			s.pop();

		if(s.empty())
			ans_left[i] = -1;
		else
			ans_left[i] = s.top();

		s.push(v[i]);
	}

	for (int i = 0; i < n; ++i)
	{
		cout<<v[i]<<" ---> "<<ans_right[i]<<endl;
		cout<<v[i]<<" ---> "<<ans_left[i]<<endl;
		cout<<endl;
	}
}

//code for next shorter or equal element
void nse(){
	int n;cin>>n;
	std::vector<int> v(n);
	for (int i = 0; i < n; ++i)
	{
		/* code */cin>>v[i];
	}

	std::vector<int> ans(n);  //this will store the next greater or equal element 
	stack<int> s;

	for (int i = n-1; i > -1; --i)
	{
		while(s.empty() == false && s.top() > v[i])
			s.pop();

		if(s.empty())
			ans[i] = -1;
		else
			ans[i] = s.top();

		s.push(v[i]);
	}

	for (int i = 0; i < n; ++i)
	{
		cout<<v[i]<<" ---> "<<ans[i]<<endl;
	}
}

int main(){
	#ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
    #endif

   int t=1;
   //cin>>t;
   while(t--){
   	std::vector<int> v = nge_on_both_side();
   }
}