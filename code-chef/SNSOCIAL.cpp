/*
*	author:		mkbaloch
*	datetime:	2021-08-27 14:38:47
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
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        
        int maze[n][m];
        int maxx = INT_MIN;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> maze[i][j];
                maxx = max(maze[i][j], maxx);
            }
        }
        queue<pair<int, int>> q;
        int dist[n][m];
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(maze[i][j] == maxx){
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }

        int hours = 0;

        while(!q.empty()){
            pair<int, int> curr = q.front();
            q.pop();

            if(q.empty()){
                hours = dist[curr.first][curr.second];
            }

            int dx[] = {0, 0, 1, -1, 1, -1, -1, 1};
            int dy[] = {-1, 1, 0, 0, 1, 1, -1, -1};

            for(int k = 0; k<8; k++){
                int x = curr.second + dx[k];
                int y = curr.first + dy[k];
                if(x >= 0 && x < m && y >= 0 && y < n){
                    if(maze[y][x] != maxx){
                       maze[y][x] = maxx;
                       dist[y][x] = dist[curr.first][curr.second] + 1;
                       q.push({y, x}); 
                    }
                }
            }
        }

        cout << hours << endl;
    }
    //-------End---------//

    #ifdef LOCAL
        auto end = chrono::high_resolution_clock::now();
        auto dur = chrono::duration_cast<chrono::microseconds>(end - start);
        fprintf(stderr, "Execution time: %.6Lf seconds.\n", ((long double)dur.count() / 1e6)); 
    #endif

    return 0;
}