class Solution {
public:
    // int recc ( int m , int n , int i , int j ) {
    //     if ( i == n-1 && j == m-1 ) return 1 ;
    //     if ( i >= n || j >= m ) return 0 ;

    //     return recc (m,n,i,j+1) + recc(m,n,i+1,j) ;
    // }
    // int recc ( int m , int n , int i , int j , vector<vector<int>>& data ) {
    //     if ( i == n-1 && j == m-1 ) return 1 ;
    //     if ( i >= n || j >= m ) return 0 ;
    //     if( data[i][j] != -1 ) return data[i][j] ;
    //     else  data[i][j] = recc (m,n,i,j+1) + recc(m,n,i+1,j) ;
    //     return data[i][j] ;
    // }
    // vector<vector<int>> data (m,vector<int> (n,-1));
    //     data[m-1][n-1] = 1 ;
    //     for( int i = m-1 ; i >= 0  ; i-- ) {
    //         for (int j = n-1 ;  j >= 0 ; j-- ) {
    //              if ( data[i][j] == -1 ) {
    //                 if ( j == n-1) data[i][j] = data[i+1][j] ;
    //                 else if ( i == m-1 ) data[i][j] = data[i][j+1] ;
    //                 else data[i][j] = data[i+1][j] + data[i][j+1] ;
    //             }
    //         }
    //     }
    // return data[0][0] ;
    int uniquePaths(int m, int n) {
        vector<int> data (n,1);
        for( int i = m-2 ; i >= 0  ; i-- ) {
            for (int j = n-1 ;  j >= 0 ; j-- ) {
                if ( j!= n-1 ) data[j] = data[j] + data[j+1] ;
            }
        }
        return data[0];
    }
};