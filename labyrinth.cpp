/*
*	author:		mkbaloch
*	datetime:	2021-08-14 20:46:43
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

    int ex, ey;
    int sx, sy;

    for(int i=0; i<n; i++){
        cin >> maze[i];
        for(int j=0; j<m; j++){
            if(maze[i][j] == 'A'){
                sx = j;
                sy = i;
            } else if (maze[i][j] == 'B'){
                ex = j;
                ey = i;
            }
        }
    }

    vector<vector<bool>> visited(n, vector<bool> (m, false));
    vector<vector<pair<int, int>>> path(n, vector<pair<int, int>>(m));

    queue<pair<int, int>> bfs_queue;
    bfs_queue.push({sy, sx});
    visited[sy][sx] = true;

    int dirx[] = {0, 1, 0, -1};
    int diry[] = {1, 0, -1, 0};

    bool found = false;
    while(!bfs_queue.empty() && !found){
        pair<int, int> curr = bfs_queue.front();

        int cy = curr.first;
        int cx = curr.second;

        bfs_queue.pop();

        for(int k=0; k<4; k++){
            int dx = cx + dirx[k];
            int dy = cy + diry[k];
            
            if( dx >= 0 && dx < m && dy >= 0 && dy < n && !visited[dy][dx] && maze[dy][dx] != '#'){
                visited[dy][dx] = true;
                path[dy][dx] = curr;
                bfs_queue.push({dy, dx});
                if(dx == ex && dy == ey) found = true;
            }
        }
    }

    if(!found){
        cout << "NO" << endl;
        return 0;
    }

    string answer = "";

    char dir[] = {'D', 'R', 'U', 'L'};
    while(ex != sx || ey != sy){
        pair<int, int> parent = path[ey][ex];

        for(int k=0; k<4; k++){
            int dy = parent.first + diry[k];
            int dx = parent.second + dirx[k];
            if(dx == ex && dy == ey){
                answer += dir[k];
                ex = parent.second;
                ey = parent.first;
            }
        }
    }

    reverse(all(answer));

    cout << "YES" << endl;
    cout << answer.size() << endl;
    cout << answer << endl;

    //-------End---------//

    #ifdef LOCAL
        auto end = chrono::high_resolution_clock::now();
        auto dur = chrono::duration_cast<chrono::microseconds>(end - start);
        fprintf(stderr, "Execution time: %.6Lf seconds.\n", ((long double)dur.count() / 1e6)); 
    #endif

    return 0;
}