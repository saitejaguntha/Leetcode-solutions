class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size() ;
        vector<int> suff(n) ;

        int temp = nums[n-1] ;
        for (int  i = n-1 ; i >= 0 ; i-- ){
            if ( temp > nums[i] ) temp = nums[i] ;
            suff[i] = temp ;
        } 
    
        int maxi = nums[0] ;
        for ( int i = 0 ; i < n ; i++) {
            if ( maxi < nums[i] ) maxi = nums[i] ;
            if ( (maxi - suff[i]) <=k ) return i ;
        }

        return -1;
    }
};