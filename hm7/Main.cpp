#include <iostream>
#include <algorithm>

void sortArray(int arr[], int size, bool descending = false) {
    if (descending) {
        std::sort(arr, arr + size, std::greater<int>());
    }
    else {
        std::sort(arr, arr + size);
    }
}

int main() {
    int arr[10] = { 5, 9, -2, 10, 4, 3, -6, 8, 7, 0 };
    sortArray(arr, 10, true);

    std::cout << "Sorted array: ";
    for (int i = 0; i < 10; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

//task2
#include <iostream>

void insertionSort(int arr[], int start, int end, bool descending = false) {
    for (int i = start + 1; i <= end; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= start && ((descending && arr[j] < key) || (!descending && arr[j] > key))) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void sortHalfArray(int arr[], int size) {
    int middle = size / 2;
    insertionSort(arr, 0, middle - 1, true);

    insertionSort(arr, middle, size - 1, false);
}

int main() {
    int arr[10] = { 12, 3, -7, 14, 5, 0, -1, 8, 10, -5 };
    sortHalfArray(arr, 10);

    std::cout << "Sorted array: ";
    for (int i = 0; i < 10; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

//task3
#include <iostream>
#include <algorithm>

void sortBetweenNegative(int arr[], int size) {
    int leftNegative = -1, rightNegative = -1;

    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            leftNegative = i;
            break;
        }
    }

    for (int i = size - 1; i >= 0; i--) {
        if (arr[i] < 0) {
            rightNegative = i;
            break;
        }
    }

    if (leftNegative != -1 && rightNegative != -1 && leftNegative < rightNegative) {
        std::sort(arr + leftNegative + 1, arr + rightNegative);
    }
}

int main() {
    int arr[10] = { 3, -5, 7, -2, 10, 6, -1, 8, 15, -9 };
    sortBetweenNegative(arr, 10);

    std::cout << "Sorted array between extreme negative elements: ";
    for (int i = 0; i < 10; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
