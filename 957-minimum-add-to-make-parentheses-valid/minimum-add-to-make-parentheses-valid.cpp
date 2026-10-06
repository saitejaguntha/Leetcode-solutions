class Solution {
public:
    int minAddToMakeValid(string s) {
      int n = s.size() ;

      int ans = 0 , count = 0 ; 
      for ( int i = 0 ; i  < n ; i ++ ) {
        if ( s[i] == '(' ) ans++ ;
        else ans-- ;
        if ( ans < 0 ) {
          count++ ;
          ans = 0 ;  
        } 
      } 
      return abs(ans) + count ;
    }
};