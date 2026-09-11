class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        map<int,int> freq ;
        int ans = 0 ;
        int n = digits.size() ;
        for ( int i = 0 ; i < n ; i++ ) {
            freq[digits[i]]++ ;
        }

       
        for ( int i = 100 ; i < 999 ; i += 2 ) {
            map<int,int> temp ;
            int k = i ;
            int flag = 1 ;
            for ( int j = 0 ; j < 3 ; j++ ) {
                temp[k%10]++ ;
                k /= 10 ;
            }
            for ( auto &it : temp ) {
                 if ( it.second > freq[it.first] ) flag = 0 ;
            }
            ans += flag ;
        }
        return ans ;
    }
};