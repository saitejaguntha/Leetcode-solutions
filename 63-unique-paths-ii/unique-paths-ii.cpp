class Solution {
public:
    // int recc ( int m , int n , int i , int j , vector<vector<int>>& obstacleGrid) {
    //     if ( i == n-1 && j == m-1 ) return 1 ;
    //     if ( i >= n || j >= m || obstacleGrid[i][j] == 1 || obstacleGrid[0][0] == 1 ) return 0 ;

    //     return recc (m,n,i,j+1) + recc(m,n,i+1,j) ;
    // }
    // int recc ( int m , int n , int i , int j , vector<vector<int>>& data , vector<vector<int>>& obstacleGrid ) {
    //    if ( obstacleGrid[0][0] == 1)return 0 ;
    //     if ( i == n-1 && j == m-1 ) {
    //         return 1-obstacleGrid[i][j] ;
    //     }
    //     if ( i >= n || j >= m ) return 0 ;
    //     if( data[i][j] != -1 ){
    //         return data[i][j] ;
    //     } 
    //     if ( obstacleGrid[i][j] == 1 )  data[i][j] = 0 ;
    //     else  data[i][j] = recc (m,n,i,j+1) + recc(m,n,i+1,j) ;
    //     return data[i][j] ;
    // }
    // vector<vector<int>> data (m,vector<int> (n,-1));
    //     if ( obstacleGrid[m-1][n-1] == 1 || obstacleGrid[0][0] == 1 ) return 0;
    //     data[m-1][n-1] = 1  ;
    //     for( int i = m-1 ; i >= 0  ; i-- ) {
    //         for (int j = n-1 ;  j >= 0 ; j-- ) {
    //              if ( data[i][j] == -1 ) {
    //                 if ( obstacleGrid[i][j] == 1 ) data[i][j] = 0 ;
    //                 else if ( j == n-1) data[i][j] = data[i+1][j] ;
    //                 else if ( i == m-1 ) data[i][j] = data[i][j+1] ;
    //                 else data[i][j] = data[i+1][j] + data[i][j+1] ;
    //             }
    //         }
    //     }
    // return data[0][0] ;
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size() , n = obstacleGrid[0].size() ;
        if ( obstacleGrid[m-1][n-1] == 1 || obstacleGrid[0][0] == 1 ) return 0;

        vector<long long> data (n,0);  data[n-1] = 1 ;

        for( int i = m-1 ; i >= 0  ; i-- ) {
            for (int j = n-1 ;  j >= 0 ; j-- ) {
                if ( obstacleGrid[i][j] == 1 ) data[j] = 0 ;
                else if (  j != n-1 ) data[j] = data[j] + data[j+1] ;
            }
        }
        
        return data[0];
    }
};