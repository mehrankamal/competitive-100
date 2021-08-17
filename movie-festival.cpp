/*
*	author:		mkbaloch
*	datetime:	2021-08-18 05:30:24
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
    vector<pair<int, int>> movies;
    for(int i=0; i<n; i++){
        int st, en;
        cin >> st >> en;
        movies.push_back({st, en});
    }
    sort(movies.begin(), movies.end(), [&] (pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    });
    int current_ending = 0;
    int max_movies = 0;
    for(int i=0; i<n; i++){
        if(movies[i].first >= current_ending){
            current_ending = movies[i].second;
            max_movies += 1;
        }
    }

    cout << max_movies << endl;
    //-------End---------//

    #ifdef LOCAL
        auto end = chrono::high_resolution_clock::now();
        auto dur = chrono::duration_cast<chrono::microseconds>(end - start);
        fprintf(stderr, "Execution time: %.6Lf seconds.\n", ((long double)dur.count() / 1e6)); 
    #endif

    return 0;
}