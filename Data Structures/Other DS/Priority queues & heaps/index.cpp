#include <bits/stdc++.h>
using namespace std;


int main () {
    // By default Priority Queues are Max Heaps
    priority_queue<int> pq;
    pq.push(3);
    pq.push(6);
    pq.push(1);
    pq.push(2);
    pq.push(9);

    cout << "Max Heap : ";
    while (!pq.empty()) {
        int elm = pq.top();
        cout << elm << " ";
        pq.pop();
    }
    cout << endl;

    // for Min Heap
    priority_queue<int, vector<int>, greater<int>> pq_min;
    pq_min.push(3);
    pq_min.push(6);
    pq_min.push(1);
    pq_min.push(2);
    pq_min.push(9);

    cout << "Min Heap : ";
    while (!pq_min.empty()) {
        int elm = pq_min.top();
        cout << elm << " ";
        pq_min.pop();
    }
    cout << endl;
}


























