//Reference - https://practice.geeksforgeeks.org/problems/maximum-and-value-1587115620/1

//solution reference - https://www.geeksforgeeks.org/maximum-value-pair-array/


/*  since AND is 1 if both bit are set . so , we will move from most significant bit to LSB and 
	we will find if any two number have sat bit at that bit position then we will include that bit in our solution

*/

class Solution
{
    public:
    
    int Count(int pattern,int* arr,int n){
        int count=0;
        
        for(int i=0;i<n;i++){
            if((pattern&arr[i]) == pattern)
                count++;
        }
        
        return count;
    }
    
    // Function for finding maximum AND value.
    int maxAND (int arr[], int N)
    {
        int ans = 0;
        
        for(int i=31;i>-1;i--){
            int count = Count((ans | (1<<i)),arr,N);
            
            if(count > 1){
                ans = ans | (1<<i) ;
            }
        }
        
        return ans;
    }
};