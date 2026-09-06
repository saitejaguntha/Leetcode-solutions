class Solution {
public:
    int partwise( vector<int> arr ){
        int n =  arr.size() ;
        if ( n==1 ) return arr[0] ;
        int prev2 = 0 ;
        int prev1 = arr[n-1] ; 
        int ans = 0 ;
        for ( int i = n-2 ; i >=0 ; i-- ) {
            ans = max( { ans , arr[i] + prev2 , prev1 } ) ;
            prev2 = prev1 ;
            prev1 = ans ;
        }
        return ans ;
    }
    int rob(vector<int>& nums) {
        if ( nums.size() == 1 ) return nums[0] ;
        vector<int> temp1 ,temp2 ;
        for ( int i = 0 ; i < nums.size() ; i++ ) {
            if ( i != 0 ) temp1.push_back(nums[i]) ;
            if ( i != nums.size()-1 ) temp2.push_back(nums[i]) ;
        }
        return max ( partwise(temp2), partwise(temp1) ) ;
    }
};