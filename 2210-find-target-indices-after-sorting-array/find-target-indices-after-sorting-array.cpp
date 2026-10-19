class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n = nums.size() ;
        int smaller = 0 ;
        int count = 0 ;

        for( int i = 0 ; i < n ; i++ ) {
            if( nums[i] == target ) count++ ;
            else if( nums[i] < target ) smaller++ ;
        }
        vector<int> indeces ;
        for( int i = 0 ; i < count ; i++ ){
            indeces.push_back(smaller++);
        }
        return indeces;
    }
};