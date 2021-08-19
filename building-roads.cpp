/*
*	author:		mkbaloch
*	datetime:	2021-08-19 23:26:38
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

    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }

    vector<bool> visited(n, false);

    function<void(int)> dfs = [&](int u){
        if(visited[u]) return;
        visited[u] = true;
        for(auto v: adj[u]) dfs(v);
    };

    vector<int> components;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            dfs(i);
            components.push_back(i + 1);
        }
    }

    cout << components.size() - 1 << endl;
    for(unsigned int i=0; i<components.size() - 1; i++)
        cout << components[i] << " " << components[i + 1] << endl;
    //-------End---------//

    #ifdef LOCAL
        auto end = chrono::high_resolution_clock::now();
        auto dur = chrono::duration_cast<chrono::microseconds>(end - start);
        fprintf(stderr, "Execution time: %.6Lf seconds.\n", ((long double)dur.count() / 1e6)); 
    #endif

    return 0;
}