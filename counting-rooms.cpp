/*
*	author:		mkbaloch
*	datetime:	2021-08-14 19:57:54
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
    vector<string> maze(n);
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for(int i=0; i<n; i++){
        cin >> maze[i];
    }

    function<void(int, int)> dfs = [&] (int i, int j){
        int diry[] = {1, 0, -1, 0};
        int dirx[] = {0, 1, 0, -1};

        visited[i][j] = true;

        for(int k=0; k<4; k++){
            int dy = i + diry[k];
            int dx = j + dirx[k];
            if(dy>=0 && dy<n && dx>=0 && dx<m && !visited[dy][dx] && maze[dy][dx] != '#')
                dfs(dy, dx);
        }
    };

    int rooms = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(maze[i][j] != '#' && !visited[i][j]){
                dfs(i, j);
                rooms++;
            }

        }
    }
    cout << rooms << endl;
    //-------End---------//

    #ifdef LOCAL
        auto end = chrono::high_resolution_clock::now();
        auto dur = chrono::duration_cast<chrono::microseconds>(end - start);
        fprintf(stderr, "Execution time: %.6Lf seconds.\n", ((long double)dur.count() / 1e6)); 
    #endif

    return 0;
}