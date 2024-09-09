///   ***   ---   |||        In the name of ALLAH       |||   ---   ***   ///



#include<bits/stdc++.h>
using namespace std;


typedef long long ll;

#define F first
#define S second
const ll infLL = 9000000000000000000;


const int mx = 1e5+123;
vector<pair<ll,ll>> adj[mx];
ll dist[mx];

void dijkstra ( int s, int n )
{
    for ( int i = 0; i <= n; i++ ) dist[i] = infLL; /// initilization
    dist[s] = 0; /// initilizing source distance
    priority_queue < pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>> > pq;
    pq.push ( { 0, s } ); /// pushing source in queue

    while ( !pq.empty() ) {
        int u = pq.top().S; /// u = 4
        ll curD = pq.top().F; // curD = 3
        pq.pop();

        if ( dist[u] < curD ) continue; // important

        for ( auto p : adj[u] ) {
            int v = p.F;
            ll w = p.S;
            if ( curD + w < dist[v] ) { // relax operation
                dist[v] = curD + w;
                pq.push ( { dist[v], v } );
            }
        }
    }

}

int main()
{
    
    int n, m;
    cin >> n >> m;
    for ( int i = 1; i <= m; i++ ) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back ( { v, w } );
        adj[v].push_back ( { u, w } );
    }

    dijkstra ( 1, n );

    for ( int i = 0; i <n; i++ ) cout << dist[i] << " ";
    cout << endl;
 
    return 0;
}

/*

5 7
1 3 3
1 2 2
1 4 6
2 0 6
2 3 7
0 4 3
3 4 5


*/
