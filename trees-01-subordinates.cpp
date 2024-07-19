#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void dfs(vector<int> &counts, vector<int> adj_list[], vector<bool> &visited, int current) {
    if(!visited[current]) {
        for(int i=0; i<adj_list[current].size(); i++){
            dfs(counts, adj_list, visited, adj_list[current][i]);
            counts[current] += counts[adj_list[current][i]];
        }

        counts[current] += adj_list[current].size();
        visited[current] = true;
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> adj_list[n];

    fill(adj_list, adj_list + n, vector<int>());

    for(int i=1; i<n; i++){
        int m; 
        cin >> m;
        adj_list[m - 1].push_back(i);
    }

    vector<int> count_subs(n, 0);
    vector<bool> visited(n, false);

    dfs(count_subs, adj_list, visited, 0);

    for(int i=0; i<n; i++){
        cout << count_subs[i] << " ";
    }
    cout << endl;

    return 0;
}