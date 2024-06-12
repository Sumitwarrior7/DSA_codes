/* Multi-Source shortest path algorithm */
/* Helps to detect negative cycles as well */
#include <bits/stdc++.h>
using namespace std;
#define int long long


void floyd_warshall(vector<vector<int>> &matrix) {
	int n = matrix.size();
    // Initialization of matrix with already known shortest distances
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (matrix[i][j] == -1) {
				matrix[i][j] = INT_MAX;
			}
			if (i == j) matrix[i][j] = 0; // sd from node itself is zero
		}
	}

    // Iterating through each node, here each node works as an intermediary node
	for (int k = 0; k < n; k++) {
        // For each intermediary node, updating the matrix with more shorter distance
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
			}
		}
	}
}

bool detect_negative_cycle(vector<vector<int>> &mat) {
	int n = mat.size();
    // Applied Floyd Warshall algorithm to the given matrix
    floyd_warshall(mat);
    // If shortest distance from node itself is negative ----> Negative cycle is present
	for (int i = 0; i < n; i++) {
        if (mat[i][i] < 0) return true;
	}
    return false;
}



signed main() {
	int n = 4;
	vector<vector<int>> matrix(n, vector<int>(n, -1));
	matrix[0][1] = 2;
	matrix[1][0] = 1;
	matrix[1][2] = 3;
	matrix[3][0] = 3;
	matrix[3][1] = 5;
	matrix[3][2] = 4;

	floyd_warshall(matrix);
	for (auto row : matrix) {
		for (auto cell : row) {
			cout << cell << " ";
		}
		cout << endl;
	}

    // Checking negative cycle detection 
    vector<vector<int>> mat(4, vector<int>(4, -1));
    mat[0][1] = 2;
    mat[1][0] = 1;
    mat[1][2] = 3;
    mat[3][0] = 3;
    mat[3][1] = 5;
    mat[3][2] = 4;
    mat[2][0] = -6;

    bool neg_cycle_detection = detect_negative_cycle(mat); 
    cout << "Negative cycle detection :" << neg_cycle_detection << endl;

	return 0;
}