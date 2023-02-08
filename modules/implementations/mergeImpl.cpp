#include "../src/CustomFuncs.h"

int main(int argc, char const *argv[])
{
    int arr[] = { 1, 3, 5, 7, 2, 4, 6, 8, 0, -4, 29, 11 };
    vector<int> v(arr, arr + sizeof(arr) / sizeof(int));
    mergeSort(v, 0, v.size() - 1);
    for (int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    return 0;
}