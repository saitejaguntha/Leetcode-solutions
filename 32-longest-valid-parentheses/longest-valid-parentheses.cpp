class Solution {
public:
    int longestparantheses ( string s ) {
        int n = s.size() ;
        int count = 0 , ans = 0 ;
        int i = 0 , j = 0 ;

        while( j < n ) {
            if ( s[j] == '(' ) {
                j++ ;
                count++ ;
            }
            else {
                j++;
                count--;
            }
            if ( count == 0 ) {
                ans = max ( ans , j - i ) ;
            }
            if ( count < 0 ) {
                i = j ; 
                count = 0 ;
            }
        }
        return ans ;
    }
    int longestValidParentheses(string s) {
        int n = s.size() ;
        if ( n < 2 ) return 0 ;
        string t = s;
        reverse(t.begin(), t.end());

        for ( int  i = 0 ; i < n ; i++ ) {
            if ( t[i] == '(' ) t[i] = ')' ;
            else t[i] = '(' ; 
        }
       
        return  max ( longestparantheses(s) , longestparantheses(t) );
    }
};