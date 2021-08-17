/*
*	author:		mkbaloch
*	datetime:	2021-08-18 04:58:51
*/

#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define deb(x) cerr << "[" << #x << ": " << x << "]" << endl;

using namespace std;

typedef long long ll;
typedef unsigned int uint;

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
    vector<pair<uint, uint>> events;
    for(int i=0; i<n; i++){
        int arri, leave;
        cin >> arri >> leave;
        events.push_back({arri, 1});
        events.push_back({leave, -1});
    }

    sort(all(events));
    uint current = 0;
    uint maxx = 0;
    for(auto e:events){
        current += e.second;
        maxx = max(maxx, current);
    }
    cout << maxx << endl;
    //-------End---------//

    #ifdef LOCAL
        auto end = chrono::high_resolution_clock::now();
        auto dur = chrono::duration_cast<chrono::microseconds>(end - start);
        fprintf(stderr, "Execution time: %.6Lf seconds.\n", ((long double)dur.count() / 1e6)); 
    #endif

    return 0;
}