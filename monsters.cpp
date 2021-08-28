/*
*	author:		mkbaloch
*	datetime:	2021-08-28 14:05:37
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

    vector<string> maze(n);
    vector<pair<int,int>> monsters;
    pair<int, int> st;
    for(int i=0; i<n; i++){
        cin >> maze[i];
        for(int j=0; j<m; j++){
            if (maze[i][j] == 'M') monsters.push_back({i, j});
            if (maze[i][j] == 'A') st = {i, j};
        }
    }

    if(st.first == 0 || st.second == 0 || st.first == n-1 || st.second == m-1){
        cout << "YES" << endl;
        cout << "0" << endl;
        return 0;
    }

    vector<vector<int>> steps(n, vector<int>(m, -1));
    queue<pair<int, int>> q;
    for(auto mon: monsters){
       q.push(mon);
       steps[mon.first][mon.second] = 0;
    } 
    vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    while(!q.empty()){
        pair<int, int> curr = q.front();
        q.pop();

        for(auto dir: dirs){
            int dy = curr.first + dir.first;
            int dx = curr.second + dir.second;
            if(dx >= 0 && dx < m && dy < n && dy >= 0 && steps[dy][dx] == -1 && maze[dy][dx] != '#'){
                steps[dy][dx] = steps[curr.first][curr.second] + 1;
                q.push({dy, dx});
            }
        }
    }

    map<pair<int, int>, pair<int, int>> parent;
    pair<int, int> en = {-1, -1};

    queue<pair<pair<int, int>, int>> qq;
    qq.push(make_pair(st, 0));

    while(!qq.empty() && en.first == -1){
        auto next = qq.front();
        qq.pop();

        int y = next.first.first;
        int x = next.first.second;
        int timer = next.second;

        timer++;

        for(int k=0; k<4; k++){
            int dy = y + dirs[k].first, dx = x + dirs[k].second;
            if(dx >= 0 && dx < m && dy >= 0 && dy < n && maze[dy][dx] != '#'){
                if((dx == 0 || dy == 0 || dx == m-1 || dy == n-1) && (timer < steps[dy][dx] || steps[dy][dx] == -1)){
                    en = {dy, dx};
                    parent[en] = {y, x};
                    break;
                }

                if( (steps[dy][dx] == -1 || timer < steps[dy][dx]) && parent.count(make_pair(dy, dx)) == 0){
                    qq.push({{dy, dx}, timer});
                    parent[{dy, dx}] = make_pair(y, x);
                }
            }
        }
    }

    vector<string> dir_val = {"R", "L", "D", "U"};

    if(en.first == -1){
        cout << "NO" << endl;
    } else {
        vector<string> path;
        while(en != st){
            auto par = parent[en];
            for(int k = 0; k<4; k++){
                if(en.first - par.first == dirs[k].first && en.second - par.second == dirs[k].second){
                    path.push_back(dir_val[k]);
                    break;
                }
            }
            en = par;
        }
        reverse(all(path));
        cout << "YES" << endl;
        cout << path.size() << endl;
        for(auto d: path) cout << d;
        cout << endl;
    }
    //-------End---------//

    #ifdef LOCAL
        auto end = chrono::high_resolution_clock::now();
        auto dur = chrono::duration_cast<chrono::microseconds>(end - start);
        fprintf(stderr, "Execution time: %.6Lf seconds.\n", ((long double)dur.count() / 1e6)); 
    #endif

    return 0;
}