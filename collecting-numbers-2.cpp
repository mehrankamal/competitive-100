/*
*	author:		mkbaloch
*	datetime:	2021-08-23 05:49:28
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
    vector<int> arr(n + 2);
    vector<int> pos(n + 2);
    for(int i=1; i<=n; i++){
        cin >> arr[i];
        pos[arr[i]] = i;
    }

    arr[0] = 0;
    arr[n+1] = n+1;

    pos[0] = 0;
    pos[n+1] = n+1;

    int rounds=1;
    for(int i=2; i<=n; i++){
        if(pos[i-1] > pos[i]) rounds++;
    }

    cerr << rounds << endl;

    for(int i=0; i<m; i++){
        int l, r;
        cin >> l >> r;
        set<pair<int, int>> invertPairs;
        
        invertPairs.insert({arr[l], arr[l]+1});
        invertPairs.insert({arr[l] - 1, arr[l]});
        invertPairs.insert({arr[r], arr[r] + 1});
        invertPairs.insert({arr[r] - 1, arr[r]});

        for (auto swapped: invertPairs)
            rounds -= (pos[swapped.first] > pos[swapped.second]);

        swap(arr[l], arr[r]);
        pos[arr[r]] = r;
        pos[arr[l]] = l;

        for(auto swapped: invertPairs)
            rounds += (pos[swapped.first] > pos[swapped.second]);
        
        cout << rounds << endl;
    }
    //-------End---------//

    #ifdef LOCAL
        auto end = chrono::high_resolution_clock::now();
        auto dur = chrono::duration_cast<chrono::microseconds>(end - start);
        fprintf(stderr, "Execution time: %.6Lf seconds.\n", ((long double)dur.count() / 1e6)); 
    #endif

    return 0;
}