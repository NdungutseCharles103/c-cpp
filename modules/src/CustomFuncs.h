#ifndef CUSTOMFUNCS_H
#define CUSTOMFUNCS_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

// Function to split a string into a vector of strings
vector<string> split(string str, char delimiter);

// Function to read a file into a vector of strings
vector<string> readFile(string filename);

// merge Function
void merge(vector<int> &v, int start, int mid, int end){
    int i = start;
    int j = mid + 1;
    int k = 0;
    vector<int> temp(end - start + 1);

    while (i <= mid && j <= end){
        if (v[i] < v[j]){
            temp[k] = v[i];
            i++;
        }
        else{
            temp[k] = v[j];
            j++;
        }
        k++;
    }

    while (i <= mid){
        temp[k] = v[i];
        i++;
        k++;
    }

    while (j <= end){
        temp[k] = v[j];
        j++;
        k++;
    }

    for (i = start; i <= end; i++){
        v[i] = temp[i - start];
    }
}

// recursive merge sort function
void mergeSort(vector<int> &v, int start, int end){
    if (start < end){
        int mid = (start + end) / 2;
        mergeSort(v, start, mid);
        mergeSort(v, mid + 1, end);
        merge(v, start, mid, end);
    }
}

#endif  