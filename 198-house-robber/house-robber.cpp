class Solution {
public:
    int plan( vector<int>& nums , int sum , int& ans , int index , vector<int> &possible ) {

        if ( index >= nums.size() ) {
            return 0 ;
        }

        if ( possible[index] == -1 ) 
            possible[index] = nums[index] + max ( plan ( nums, sum, ans, index+2, possible ), 
                                                  plan ( nums, sum, ans, index+3, possible) ); 
        return possible[index] ;
    }
    int rob(vector<int>& nums) {

        int ans = -1 , n  = nums.size() ;
        if ( n == 1 ) return nums[0] ; 

        vector<int> possible ( n , -1 ) ;
        plan( nums, 0, ans, 0, possible ) ;
        plan( nums, 0, ans, 1, possible ) ;

        return max ( possible[0] , possible[1] ) ;
    }
};