#ifndef INSTANCIAS_H
#define INSTANCIAS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>
#include <algorithm>
#include <stdbool.h>
#include <limits.h>
#include <climits>

using namespace std;

#define INF INT_MAX

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

#endif