#include <bits/stdc++.h>
using namespace std;


class DisjointSet {
    // size array will tell you about the total nodes in a component
    vector<int> rank, parent, size; 
public: 
    DisjointSet(int n) {
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0; i <= n; i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    int find_ult_par(int node) {
        if(node == parent[node])
            return node; 
        parent[node] = find_ult_par(parent[node]);  // Path Compression
        return parent[node];
    }

    void union_by_rank(int u, int v) {
        int ulp_u = find_ult_par(u); 
        int ulp_v = find_ult_par(v); 
        if(ulp_u == ulp_v) return; 
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v; 
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u; 
        }
        else {
            parent[ulp_v] = ulp_u; 
            rank[ulp_u]++; 
        }
    }

    void union_by_size(int u, int v) {
        int ulp_u = find_ult_par(u); 
        int ulp_v = find_ult_par(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
}; 

// Small DSU (basic level)
class DSU {
    public: 
    vector<int> rank, parent; 
    DSU(int n) {
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        for(int i = 0; i <= n; i++) {
            parent[i] = i; 
        }
    }

    int find_ult_par(int node) {
        if(node == parent[node])
            return node; 
        parent[node] = find_ult_par(parent[node]);  // Path Compression
        return parent[node];
    }

    void union_by_rank(int u, int v) {
        int ulp_u = find_ult_par(u); 
        int ulp_v = find_ult_par(v); 
        if(ulp_u == ulp_v) return; 
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v; 
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u; 
        }
        else {
            parent[ulp_v] = ulp_u; 
            rank[ulp_u]++; 
        }
    }
}; 



int main() {
    DisjointSet ds(7);
    ds.union_by_size(1, 2); 
    ds.union_by_size(2, 3); 
    ds.union_by_size(4, 5); 
    ds.union_by_size(6, 7); 
    ds.union_by_size(5, 6); 

    // if 3 and 7 same or not 
    if(ds.find_ult_par(3) == ds.find_ult_par(7)) {
        cout << "Same" << endl; 
    }
    else cout << "Not same" << endl; 

    ds.union_by_size(3, 7); 

    if(ds.find_ult_par(3) == ds.find_ult_par(7)) {
        cout << "Same" << endl; 
    }
    else cout << "Not same" << endl; 
    
	return 0;
}











