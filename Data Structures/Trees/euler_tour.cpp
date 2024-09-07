/* ----------------------------------Basic Template---------------------------------- */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define max3(a, b, c) max(c, max(a, b))
#define max4(a, b, c, d) max(d, max(c, max(a, b)))
/*
    वसुधा का नेता कौन हुआ? भूखण्ड-विजेता कौन हुआ?
    अतुलित यश क्रेता कौन हुआ? नव-धर्म प्रणेता कौन हुआ?
    जिसने न कभी आराम किया,
    विघ्नों में रहकर नाम किया।
*/
// Notes :-
// ASCII -> UpperCase letter : [65, 90]
// ASCII -> LowerCase letter : [97, 122]
// ASCII -> Number : [48, 57] for {0, 1, 2, ... 9}


// The graph represented as an adjacency list (0-indexed)
vector<vector<int>> adj{
    {1, 2}, 
    {0}, 
    {0, 3, 4}, 
    {2}, 
    {2}
};
vector<int> euler_tour_arr(2*adj.size());
vector<int> start(adj.size());
vector<int> ending(adj.size());
int timer = 0;

void euler_tour(int node, int prev) {
    timer++;
    start[node] = timer;
    euler_tour_arr[timer] = node;
	for (int nbr : adj[node]) {
		if (nbr != prev) {
            euler_tour(nbr, node); 
        }
	}
	ending[node] = timer;
}



signed main() {
    euler_tour(0, -1);
    cout << "start :";
    for(auto it: start)  cout << it << " ";
    cout << endl;
    cout << "end :";
    for(auto it: ending)  cout << it << " ";
    cout << endl;

    cout << "lt :";
    for(auto it: euler_tour_arr)  cout << it << " ";
    cout << endl;
}