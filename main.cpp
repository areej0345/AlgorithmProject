#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <iomanip>
#include "algorithms.h"

using namespace std;
using namespace std::chrono;

void runTests(int n) {
    cout << "\n--- Testing with Input Size: " << n << " ---" << endl;

    vector<int> data(n);
    for(int i=0; i<n; i++) data[i] = rand() % 100000;

    auto start = high_resolution_clock::now();
    mergeSort(data, 0, n - 1);
    auto stop = high_resolution_clock::now();
    auto duration_ms = duration_cast<microseconds>(stop - start);
    cout << "Merge Sort Time:   " << setw(10) << duration_ms.count() << " microseconds" << endl;

    int target = data[n/2]; 
    auto start_ns = high_resolution_clock::now();
    binarySearch(data, 0, n - 1, target);
    auto stop_ns = high_resolution_clock::now();
    auto duration_ns = duration_cast<nanoseconds>(stop_ns - start_ns);
    cout << "Binary Search Time: " << setw(10) << duration_ns.count() << " nanoseconds" << endl;
}

int main() {
    cout << "===============================================" << endl;
    cout << "   ALGORITHM PERFORMANCE ANALYSIS PROJECT      " << endl;
    cout << "===============================================" << endl;

    int sizes[] = {1000, 5000, 10000, 20000};
    for(int s : sizes) {
        runTests(s);
    }

    cout << "\n--- Testing 0/1 Knapsack (Dynamic Programming) ---" << endl;
    vector<int> val = {60, 100, 120, 50, 70, 80, 150};
    vector<int> wt = {10, 20, 30, 15, 25, 35, 40};
    int W = 100;
    auto k_start = high_resolution_clock::now();
    int res = knapsack(W, wt, val, val.size());
    auto k_stop = high_resolution_clock::now();
    auto k_dur = duration_cast<nanoseconds>(k_stop - k_start);
    
    cout << "Knapsack Max Value: " << res << endl;
    cout << "Knapsack Runtime:   " << k_dur.count() << " nanoseconds" << endl;
    cout << "===============================================" << endl;

    return 0;
}