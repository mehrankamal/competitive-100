/*
*	author: mkbaloch
*	2021-08-30 19:32:32
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
        vector<pair<int, ll>> adj[n+1];
        for(int i=0; i<m; i++){
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back(make_pair(v, w));
        }
        vector<bool> vis(n+1, false);
        vector<ll> d(n+1, LONG_LONG_MAX);

        d[1] = 0;

        priority_queue<pair<ll, int>> dj;
        dj.push(make_pair(0, 1));

        while(!dj.empty()){
            auto curr = dj.top();
            dj.pop();

            if(vis[curr.second]) continue;
            vis[curr.second] = true;

            for(auto edge: adj[curr.second]){
                if(d[edge.first] > d[curr.second] + edge.second){
                    d[edge.first] = d[curr.second] + edge.second;
                    dj.push(make_pair(-d[edge.first], edge.first));
                }
            }
        }


        for(int i=1; i<=n; i++){
            cout << d[i] << " ";
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
