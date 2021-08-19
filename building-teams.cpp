/*
*	author:		mkbaloch
*	datetime:	2021-08-19 23:56:59
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
        freopen("outputf.txt", "w", stdout);
    #endif

    //-------Start-------//
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    vector<pair<int, int>> edges;

    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
        edges.push_back({u-1, v-1});
    }

    vector<int> colors(n, -1);
    vector<bool> visited(n, false);


    function<void(int, bool)> dfs = [&](int u, bool color){
        if(visited[u]) return;
        visited[u] = true;
        colors[u] = color;

        for(auto v: adj[u]){
            if(!visited[v]){
                dfs(v, !color);
            }
        }

    };


    for(int i=0; i<n; i++){
        if(!visited[i]) dfs(i, true);
    }


    for(auto edge: edges){
        if(colors[edge.first] == colors[edge.second]){
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }

    for(int i=0; i<n; i++){
        if(i > 0) cout << " ";
        if(colors[i] == 0){
            cout << "1";
        } else {
            cout << "2";
        }
    }

    cout << endl;


    //-------End---------//

    #ifdef LOCAL
        auto end = chrono::high_resolution_clock::now();
        auto dur = chrono::duration_cast<chrono::microseconds>(end - start);
        fprintf(stderr, "Execution time: %.6Lf seconds.\n", ((long double)dur.count() / 1e6)); 
    #endif

    return 0;
}