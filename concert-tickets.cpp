/*
*	author:		mkbaloch
*	datetime:	2021-08-18 04:39:38
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
    multiset<int, greater<int>> h;
    for(int i=0; i<n; i++){
        int p;
        cin >> p;
        h.insert(p);
    } 
    for(int i=0; i<m; i++){
        int bid;
        cin >> bid;
        multiset<int>::const_iterator elem_it = h.lower_bound(bid);
        if(elem_it == h.end()) cout << "-1" << endl;
        else{
            cout << *elem_it << endl;
            h.erase(elem_it);
        }
    }
    //-------End---------//

    #ifdef LOCAL
        auto end = chrono::high_resolution_clock::now();
        auto dur = chrono::duration_cast<chrono::microseconds>(end - start);
        fprintf(stderr, "Execution time: %.6Lf seconds.\n", ((long double)dur.count() / 1e6)); 
    #endif

    return 0;
}