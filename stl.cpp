#include<bits/stdc++.h>
#include<math.h>
using namespace std;

/**** priority queue for standar datatype ****/
// for max-heap - priority_queue<int> mx;
// for min-heap - priority_queue<int,vector<int>,greater<int>> mn;
// for insert - push(element) - O(log(n))  n is size of heap
// for finding max or min = top()
// for deleting max or min element = pop() - O(log(n))
//for size size()
// check empty = empty() - return boolean value

/*** priority_queue for user defined datatype ***/
/* let's create a user defined datattype
 class person{
	public:
		int age,height;
		string name;
 };

 now we want to create a priority_queue which store data according to age so, 

class compare{
	public:
	bool operator()(person const &p1,person const &p2){
		return p1.age<p2.age ; for max heap
		return p1.age>p2.age; for main heap
	}
};

 priority_queue<person , vector<person> ,compare> pq;

**/


int main(){
   #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   #endif
}