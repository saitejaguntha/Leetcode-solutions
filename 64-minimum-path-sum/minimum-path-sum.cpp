class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size() ,n = grid[0].size() ;
        vector<vector<int>> dist(m,vector<int>(n,-1)) ;
        dist[m-1][n-1] = grid[m-1][n-1] ;
        for ( int j = m-1 ; j >=0  ; j-- ) {
            for (int i = n-1 ; i >= 0 ; i-- ){
                if ( i == n-1 && j == m-1 ) continue ;
                else if ( i == n-1 ) dist[j][i] = grid[j][i] +  dist[j+1][i] ;
                else if ( j == m-1 ) dist[j][i] = grid[j][i] +  dist[j][i+1] ;
                else dist[j][i] = grid[j][i] + min( dist[j][i+1] , dist[j+1][i] ) ;
            }
        }
        return dist[0][0] ;
    }
};