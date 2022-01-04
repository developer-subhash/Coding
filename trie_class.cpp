#include<bits/stdc++.h>
using namespace std;

//highly recommend when less space need
//trie node representation using hash map
class TrieNode1{
public:
	unordered_map<char,TrieNode1*> children;
	bool flag;  //for representing a word end at node
	TrieNode1(){
		flag = false;
	}
	~TrieNode1();
};

class Trie1{
	private:
		TrieNode1* root;
	public:
		Trie1(){
			root = new TrieNode1();
		}

		//insert a word in Trie data structure
		void insert(string word){
			TrieNode1* temp = root;
			for(int i=0;i<word.length();i++){
				if(temp->children.count(word[i])==0){
					temp->children[word[i]] = new TrieNode1();
				}
				temp = temp->children[word[i]];
			}
			temp->flag = true;   //represent a word end here
		}

		// search a word if it is present in a trie or not
		bool search(string word){
			TrieNode1* temp = root;
			for(auto ch:word){
				if(temp->children.count(ch)==0)
					return false;
				temp = temp->children[ch];
			}
			return temp->flag;
		}

		//search a prefix whether is present or not
		bool startWith(string prefix){
			TrieNode1* temp = root;
			for(auto ch:prefix){
				if(temp->children.count(ch)==0)
					return false;
				temp = temp->children[ch];
			}
			return true;
		}
};




// highly recommended when less time require
//trie node represntation using array.. array statically allocated
class TrieNode2{
public:
	// for storing address of child node, we create a 26 size array
	TrieNode2* children[26];    //statically allocated
	bool flag;
	TrieNode2(){
		for (int i = 0; i < 26; ++i)
		{
			children[i] = NULL;
		}
		flag = false;
	}
	~TrieNode2();
	
};

class Trie2{
	private:
		TrieNode2* root;
	public:
		Trie2(){
			root = new TrieNode2();
		}

		void insert(string word){
			TrieNode2* temp = root;
			for(auto ch:word){
				int index = ch - 'a';
				if(temp->children[index]==NULL)
					temp->children[index] = new TrieNode2();
				temp = temp->children[index];
			}
			temp->flag = true;
		}

		bool search(string word){
			TrieNode2* temp = root;
			for(auto ch:word){
				int index = ch - 'a';
				if(temp->children[index]==NULL)
					return false;
				temp = temp->children[index];
			}
			return temp->flag;
		}

		bool startWith(string prefix){
			TrieNode2* temp = root;
			for(auto ch:prefix){
				int index = ch - 'a';
				if(temp->children[index]==NULL)
					return false;
				temp = temp->children[index];
			}
			return true;
		}
};





//not recommended
//trie node representation using array... array dynamically allocated.. 
class TrieNode3{
	public:
	// for storing address of child node, we create a 26 size array
	TrieNode3** children;  //dynamically allocated
	bool flag;

	TrieNode3(){
		flag=false;
		children = new TrieNode3*[26];
		for(int i=0;i<26;i++){
			children[i] = NULL;
		}
	}
	~TrieNode3(){
		delete[] children;
	}
};

class Trie3{
	private:
		TrieNode3* root;
	public:
		Trie3(){
			root = new TrieNode3();
		}

		void insert(string word){
			TrieNode3* temp = root;
			for(auto ch:word){
				int index = ch - 'a';
				if(temp->children[index]==NULL)
					temp->children[index] = new TrieNode3();
				temp = temp->children[index];
			}
			temp->flag = true;
		}

		bool search(string word){
			TrieNode3* temp = root;
			for(auto ch:word){
				int index = ch - 'a';
				if(temp->children[index]==NULL)
					return false;
				temp = temp->children[index];
			}
			return temp->flag;
		}

		bool startWith(string prefix){
			TrieNode3* temp = root;
			for(auto ch:prefix){
				int index = ch - 'a';
				if(temp->children[index]==NULL)
					return false;
				temp = temp->children[index];
			}
			return true;
		}
};

void solve(){
	Trie3 trie;
	int n;cin>>n;
	for (int i = 0; i < n; ++i)
	{
		string s;cin>>s;
		trie.insert(s);
	}

	int q;cin>>q;
	while(q--){
		int t;cin>>t;
		string s;cin>>s;
		if(t==1)
			cout<<trie.search(s)<<endl;
		else
			cout<<trie.startWith(s)<<endl;
	}
}


/***** conslusion ******/
/*
  using static array - take least time but more space
  using dynamically allocated array - take less time then hashmap but more than static array .. space 
    more than hashmap and little more than static array
  using hashmap - take more time than array but less space than array
*/
 
int main(){
  
  #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   #endif
 
 
  int t=1;
  
  while(t--){
    solve();
   }
 
   return 0;
}