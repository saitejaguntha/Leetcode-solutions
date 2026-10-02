class Solution {
public:
    void combinations ( vector<string> & ans , string mini, int open , int close , int n , int side )
    {   
        if ( open >= n/2 && !side) return ;
        if ( close == n/2 ) 
        {
            ans.push_back(mini) ;
            return ;
        }
        if ( close == open && side ) return ;
        if ( !side ) 
        {
            mini += '(' ;
            open++ ;
        }
        else
        {
            mini += ')' ;
            close++ ;
        } 
        combinations ( ans , mini , open , close , n , 0 ) ;
        combinations ( ans , mini , open , close , n , 1 ) ;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans ;
        string mini ;
        combinations ( ans , mini , 0 , 0 , 2*n , 0 ) ;
        return ans ;
    }
};

