class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size() ;

        int count= 0 , score = 0 ;
        bool flag = false ;

        for ( int i = 0 ; i < n ; i++ ){

            if( s[i]  == '(' ) {
                count++;
                flag = true ;
            }
            else {
                count-- ;
                if ( count == 0 && flag ) score++ ;
                else if ( count == 0 ) score = score ;
                else if ( flag ) score += 1<< count ;
                flag = false ;
            }
            
        }

        return score ;
    }
};
