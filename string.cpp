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
#define vi vector<int> 
#define pb push_back
#define x first
#define y second
typedef unsigned long long int ll;

//pattern searching kmp algo
//calculate longest prefix length which is also suffix of each prefix-SubString
int* getLps(char pattern[]){
    //int len = pattern.length();
    int len=0;
    for(int i=0;pattern[i]!='\0';i++)len++;
    int* lps = new int[len];
    int i=1,j=0;
    lps[0]=0;
    
    while(i<len){
        if(pattern[i]==pattern[j]){
            lps[i++] = ++j;
        }
        else{
            if(j!=0)
                j = lps[j-1];
            else
                lps[i++] = 0;
        }
    }
    
    return lps;
}


int kmpSearch(char str[], char pat[]){
    //int lenStr = str.length();
    //int lenPat = pat.length();
    int lenStr=0,lenPat=0;
    for(int i=0;str[i]!='\0';i++)lenStr++;
    for(int i=0;pat[i]!='\0';i++)lenPat++;
    int index;
    
    int i=0,j=0;
    int* lps = getLps(pat);
    
    while(i<lenStr && j<lenPat){
        if(str[i] == pat[j]){
            i++;j++;
            if(j==lenPat){
                index = i - lenPat;
                break;
            }
        }
        else{
            if(j!=0)
                j = lps[j-1];
            else
                i++;
        }
    }
    
    if(j == lenPat)
        return index; 
    else
        return -1;
}


//Z - algorithm
//https://www.geeksforgeeks.org/z-algorithm-linear-time-pattern-searching-algorithm/

vector<int> Zalgo(string str, string pat){
    string s = pat + "$" + str;
    int n = s.length();
    int l=0,r=0; // z interval - it is the substring interval in s which is prefix of string s
    int i=1; // for traversing string
    vector<int> Z(n);

    while(i<n){
        if(i > r){
            //create a new interval
            l = i;r = i;
            while(r<n && s[r]==s[r-l]){
                r++;
            }
            Z[i] = r-l;
            r--; //for lieing in interval with closed interval
        }
        else{
            int curr_len = Z[i-l]; //matching length now
            if(curr_len+i < r){
                Z[i] = curr_len;
            }
            else{
                //may match more
                //expand current matching z-interval
                l = i;
                while(r<n && s[r]==s[r-l]){
                    r++;
                }
                Z[i] = r-l;
                r--;
            }
        }
        i++;
    }

    return Z;
}
 
int main(){
  
  #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   #endif
 
 
  int t=1;
  cout<<t;
 
   return 0;
}