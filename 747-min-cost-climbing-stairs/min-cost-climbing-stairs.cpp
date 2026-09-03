class Solution {
public:
    int achievemincost( vector<int>& cost , int index, vector<int>& optimizer ) {

        if( index >= cost.size() ) {
            return 0;
        } 

        if ( optimizer[index] == -1 ) {
            optimizer[index] = cost[index] + min ( achievemincost(cost, index+1 , optimizer ) , 
                                    achievemincost(cost, index+2 , optimizer ) ) ;
        }

        return optimizer[index] ;
    }
    int minCostClimbingStairs(vector<int>& cost) {

        vector<int> optimizer (cost.size(),-1) ;

        return min ( achievemincost( cost ,  0 , optimizer ), achievemincost( cost , 1 , optimizer ) ) ;
    }
};