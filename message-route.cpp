/*
*	author:		mkbaloch
*	datetime:	2021-08-19 23:36:12
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
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    int st=0;
    int en=n-1;

    queue<int> bfs_queue;

    vector<bool> visited(n, false);
    vector<int> parents(n, -1);

    bfs_queue.push(st);
    visited[st] = true;

    while(!bfs_queue.empty()){
        int current = bfs_queue.front();
        bfs_queue.pop();

        if(current == en)
            break;

        for(auto v: adj[current]){
            if(!visited[v]){
                visited[v] = true;
                parents[v] = current;
                bfs_queue.push(v);
            }
        }
    }

    vector<int> path;
    if(visited[en]){
        while(en != st){
            path.push_back(en + 1);
            en=parents[en];
        }
        path.push_back(st + 1);
        reverse(all(path));

        cout << path.size() << endl;
        for(auto v: path){
            cout << v << " ";
        }
        cout << endl;
        return 0;
    }

    cout << "IMPOSSIBLE" << endl;

    //-------End---------//

    #ifdef LOCAL
        auto end = chrono::high_resolution_clock::now();
        auto dur = chrono::duration_cast<chrono::microseconds>(end - start);
        fprintf(stderr, "Execution time: %.6Lf seconds.\n", ((long double)dur.count() / 1e6)); 
    #endif

    return 0;
}