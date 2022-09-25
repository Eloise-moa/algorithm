/*
 * Sort.h
 *
 *  Author: Erwin
 */

#ifndef SORT_H_
#define SORT_H_

#include <algorithm>

namespace Sort {

template <typename T>
void selectionSort(T arr[], int n) {
  for (int i = 0; i < n; ++i) {
    // Find the minimum in arr[i...n)
    int minIndex = i;
    for (int j = i + 1; j < n; ++j) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }

    std::swap(arr[minIndex], arr[i]);
  }

  return;
}

template <typename T>
void insertionSort(T arr[], int n) {
  for (int i = 1; i < n; ++i) {
    // Find the insertion position of arr[i]
    // Optimation compared with std::swap()
    T e = arr[i];
    T j;
    for (j = i; j > 0 && arr[j - 1] > e; --j) {
      arr[j] = arr[j - 1];
    }
    arr[j] = e;
  }

  return;
}

}  // namespace Sort

#endif  // SORT_H_
