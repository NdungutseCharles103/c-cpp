#include <iostream>
#include <vector>

using namespace std;
int main() {
    // Create a vector of integers
    vector<int> v;
    // Add elements to the vector
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }

    // Print the vector
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    // get count of elements
    cout << "Size: " << v.size() << endl;

    // get capacity of vector
    cout << "Capacity: " << v.capacity() << endl;

    // get max size of vector
    cout << "Max Size: " << v.max_size() << endl;

    // shrink to fit
    // v.shrink_to_fit();

    return 0;
}