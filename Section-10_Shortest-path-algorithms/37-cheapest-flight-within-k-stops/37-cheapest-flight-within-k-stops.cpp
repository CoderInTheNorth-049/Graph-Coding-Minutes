#include<bits/stdc++.h>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>> flights, int src, int dst, int k) {
    vector<int> dist( n, 1e9 );
    dist[src] = 0;
    
    // Run only K+1 times since we want shortest distance in atmost k stops
    for( int i=0; i <= k; i++ ) {
        vector<int> tmp( dist );
        for( auto flight : flights ) {
            if( dist[ flight[0] ] != 1e9 ) {
                tmp[ flight[1] ] = min( tmp[flight[1]], dist[ flight[0] ] + flight[2] );
            }
        }
        dist = tmp;
    }
    return dist[dst] == 1e9 ? -1 : dist[dst];
}