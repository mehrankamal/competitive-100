/*
*	author:		mkbaloch
*	datetime:	2021-08-23 06:45:04
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
    int n;
    cin >> n;
    vector<int> songs(n);
    for(int i=0; i<n; i++) cin >> songs[i];
    int seq_len = 0;
    
    set<int> current;

    for(int i=0, j=0; i<n && j<n;){
        while(j<n && current.count(songs[j]) == 0) current.insert(songs[j]), j++;
        seq_len = max(seq_len, (int)current.size());
        current.erase(songs[i]), i++;
    }
    cout << seq_len << endl;
    //-------End---------//

    #ifdef LOCAL
        auto end = chrono::high_resolution_clock::now();
        auto dur = chrono::duration_cast<chrono::microseconds>(end - start);
        fprintf(stderr, "Execution time: %.6Lf seconds.\n", ((long double)dur.count() / 1e6)); 
    #endif

    return 0;
}