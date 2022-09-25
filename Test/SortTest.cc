/*
 * SortTest.cc
 *
 *  Author: Erwin
 */

#include "Sort/Sort.h"
#include "Util/Util.h"
#include "gtest/gtest.h"

namespace {

class SortTest : public ::testing::Test {
 protected:
  bool testSort(const std::string& sortName, void (*sort)(int[], int),
                int arr[], int n) {
    clock_t startTime = clock();
    sort(arr, n);
    clock_t endTime = clock();

    std::cout << sortName << ": "
              << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s"
              << std::endl;

    return isSorted(arr, n);
  }

  bool isSorted(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
      if (arr[i + 1] < arr[i]) {
        return false;
      }
    }

    return true;
  }
};

// Selection Sort and Insertion Sort for random arrays
TEST_F(SortTest, test1) {
  std::cout << "Compare Selection Sort and Insertion Sort with random arrays" << std::endl;

  int n = 50000;
  std::cout << "Test for random arrays, size = " << n << ", random range [0, "
            << n << "]" << std::endl;
  int* arr1 = Util::generateRandomArray<int>(n, 0, n);
  int* arr2 = Util::copyArray(arr1, n);

  EXPECT_TRUE(testSort("Selection Sort", Sort::selectionSort, arr1, n));
  EXPECT_TRUE(testSort("Insertion Sort", Sort::insertionSort, arr2, n));

  delete[] arr1;
  delete[] arr2;
}

// Selection Sort and Insertion Sort for nearly ordered arrays
TEST_F(SortTest, test2) {
  std::cout << "Compare Selection Sort and Insertion Sort with nearly ordered arrays" << std::endl;

  int n = 100000;
  int swapTime = 10;
  std::cout << "Test for nearly ordered arrays, size = " << n
            << ", swap time = " << swapTime << std::endl;
  int* arr1 = Util::generateNearlyOrderedArray<int>(n, swapTime);
  int* arr2 = Util::copyArray(arr1, n);

  EXPECT_TRUE(testSort("Selection Sort", Sort::selectionSort, arr1, n));
  EXPECT_TRUE(testSort("Insertion Sort", Sort::insertionSort, arr2, n));

  delete[] arr1;
  delete[] arr2;
}

}  // namespace
