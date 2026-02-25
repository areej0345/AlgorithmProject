#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <vector>

void merge(std::vector<int>& arr, int l, int m, int r);
void mergeSort(std::vector<int>& arr, int l, int r);

int binarySearch(const std::vector<int>& arr, int low, int high, int x);

int knapsack(int W, const std::vector<int>& wt, const std::vector<int>& val, int n);

#endif