/*
*	author: mkbaloch
*	2021-08-30 20:29:54
*/

#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define deb(x) cerr << "[" << #x << ": " << x << "]" << endl;

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
        auto start = chrono::high_resolution_clock::now();
        freopen("inputf.txt", "r", stdin);
    #endif

    //-------Start-------//
        int n, m, q;
        cin >> n >> m >> q;
        vector<vector<ll>> d(n+1, vector<ll>(n+1, LONG_LONG_MAX));

        for(int i=0; i<=n; i++)
            d[i][i] = 0;

        for(int i=0; i<m; i++){
            int u, v, w;
            cin >> u >> v >> w;
            d[u][v] = min(d[u][v], 1LL * w);
            d[v][u] = min(d[v][u], 1LL * w);
        }

        for(int k=1; k<=n; k++){
            for(int i=1; i<=n; i++){
                for(int j=1; j<=n; j++){
                    if(d[i][k] < LONG_LONG_MAX && d[j][k] < LONG_LONG_MAX)
                        d[i][j] = min(d[i][j], d[i][k] + d[j][k]);
                }
            }
        }

        for(int i=0; i<q; i++){
            int u, v;
            cin >> u >> v;
            if(d[u][v] == LONG_LONG_MAX)
                cout << "-1" << endl;
            else
                cout << d[u][v] << endl;
        }


    //-------End---------//

    #ifdef LOCAL
        auto end = chrono::high_resolution_clock::now();
        auto dur = chrono::duration_cast<chrono::microseconds>(end - start);
        fprintf(stderr, "Execution time: %.6Lf seconds.\n", ((long double)dur.count() / 1e6));
    #endif
    return 0;
}
