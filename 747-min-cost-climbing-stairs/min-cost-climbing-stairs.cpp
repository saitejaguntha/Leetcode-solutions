class Solution {
public:
    // int achievemincost( vector<int>& cost , int index, vector<int>& optimizer ) {

    //     if( index >= cost.size() ) {
    //         return 0;
    //     } 

    //     if ( optimizer[index] == -1 ) {
    //         optimizer[index] = cost[index] + min ( achievemincost(cost, index+1 , optimizer ) , 
    //                                 achievemincost(cost, index+2 , optimizer ) ) ;
    //     }

    //     return optimizer[index] ;
    // }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size() ;
        int ans = 0 ;
        // vector<int> optimizer (n,-1) ;
        int  optimizer1 = cost[n-1] , optimizer2 = cost[n-2] ;
        for ( int i = n-3 ; i >=0 ; i-- ) {
            ans = cost[i] + min ( optimizer1 ,optimizer2 ) ;
            optimizer1 = optimizer2 ;
            optimizer2 = ans ;
        }
        return min ( optimizer1, optimizer2 ) ;
        // /return min ( achievemincost( cost ,  0 , optimizer ), achievemincost( cost , 1 , optimizer ) ) ;
    }
};