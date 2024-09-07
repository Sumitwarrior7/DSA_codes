#include<bits/stdc++.h>
using namespace std;


/*   ----------------------------------------Policy Based Ordered set----------------------------------------   */
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
// Define the ordered set
template <typename my_data_type>
using ordered_set = tree<my_data_type, null_type, less<my_data_type>, rb_tree_tag, tree_order_statistics_node_update>;



int main() {
    // Define an ordered set
    ordered_set<int> os;

    int sz =  os.size();  // Size of the ordered set

    os.insert(5);  // Insert elements
    os.insert(5);  // Insert elements
    os.insert(1);  // Insert elements
    os.insert(7);  // Insert elements
    cout << "os :";
    for(auto it: os) cout << it << " ";
    cout << "\n";

    int ind = 3;
    int elment_by_index = *os.find_by_order(ind);  // returns the iterator to the element at index '0'
    cout << "element at index " << ind << " :" << elment_by_index << endl; 

    // os.erase(7);  // Erase an element

    int query = 4;
    int total_elments = os.order_of_key(query); // Number of elments strictly smaller than 'query'
    cout << "no. of elemnts strictly smaller than " << query << " :" << total_elments << endl; 

    // Check if an element exists
    // if (os.find(10) != os.end()) {
    //     cout << "10 exists in the set" << endl;
    // }
}
