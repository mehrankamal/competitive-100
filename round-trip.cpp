/*
*	author:		mkbaloch
*	datetime:	2021-08-27 13:20:41
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
    int n, m;
    cin >> n >> m;
    vector<int> adj[n+1];
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n+1, 0);
    vector<int> parents(n+1, 0);

    int st=-1, en=-1;
    function<bool(int)> dfs = [&](int u){
        if(visited[u]){
            return false;
        }
        visited[u] = true;
        for(auto v: adj[u]){
            if(parents[u] == v) continue;
            if(visited[v]){
                st = v;
                en = u;
                return true;
            }
            if(!visited[v]){
                parents[v] = u;
                if(dfs(v)) return true;
            }
        }
        return false;
    };

    for(int i=1; i<=n; i++){
        if(!visited[i]){
            if(dfs(i)) break;
        }
    }
    
    if(st != -1){
        vector<int> path;
        path.push_back(st);
        while(en != st){
            path.push_back(en);
            en = parents[en];
        }
        path.push_back(st);
        reverse(all(path));

        cout << path.size() << endl;
        for(auto u: path){
            cout << u << " ";
        }
        cout << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }


    //-------End---------//

    #ifdef LOCAL
        auto end = chrono::high_resolution_clock::now();
        auto dur = chrono::duration_cast<chrono::microseconds>(end - start);
        fprintf(stderr, "Execution time: %.6Lf seconds.\n", ((long double)dur.count() / 1e6)); 
    #endif

    return 0;
}