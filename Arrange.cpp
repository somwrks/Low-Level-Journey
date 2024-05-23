#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SortingAlgorithm {
public:
    virtual void sort(vector<int>& arr) = 0;
};

class InsertionSort : public SortingAlgorithm {
public:
    void sort(vector<int>& arr) override {
        for (int i = 1; i < arr.size(); i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }
};

class SelectionSort : public SortingAlgorithm {
public:
    void sort(vector<int>& arr) override {
        for (int i = 0; i < arr.size() - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < arr.size(); j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            swap(arr[i], arr[minIndex]);
        }
    }
};

class BubbleSort : public SortingAlgorithm {
public:
    void sort(vector<int>& arr) override {
        for (int i = 0; i < arr.size() - 1; i++) {
            bool swapped = false;
            for (int j = 0; j < arr.size() - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped) {
                break;
            }
        }
    }
};

class QuickSort : public SortingAlgorithm {
public:
    void sort(vector<int>& arr) override {
        quickSort(arr, 0, arr.size() - 1);
    }

    void quickSort(vector<int>& arr, int low, int high) {
        if (low < high) {
            int pivot = partition(arr, low, high);
            quickSort(arr, low, pivot - 1);
            quickSort(arr, pivot + 1, high);
        }
    }

    int partition(vector<int>& arr, int low, int high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return i + 1;
    }
};

class MergeSort : public SortingAlgorithm {
public:
    void sort(vector<int>& arr) override {
        mergeSort(arr, 0, arr.size() - 1);
    }

    void mergeSort(vector<int>& arr, int low, int high) {
        if (low < high) {
            int mid = (low + high) / 2;
            mergeSort(arr, low, mid);
            mergeSort(arr, mid + 1, high);
            merge(arr, low, mid, high);
        }
    }

    void merge(vector<int>& arr, int low, int mid, int high) {
        vector<int> left(arr.begin() + low, arr.begin() + mid + 1);
        vector<int> right(arr.begin() + mid + 1, arr.begin() + high + 1);
        int i = 0, j = 0, k = low;
        while (i < left.size() && j < right.size()) {
            if (left[i] <= right[j]) {
                arr[k++] = left[i++];
            } else {
                arr[k++] = right[j++];
            }
        }
        while (i < left.size()) {
            arr[k++] = left[i++];
        }
        while (j < right.size()) {
            arr[k++] = right[j++];
        }
    }
};

int main() {
    int choice;
    cout << "Choose a sorting algorithm:\n";
    cout << "1. Insertion Sort\n";
    cout << "2. Selection Sort\n";
    cout << "3. Bubble Sort\n";
    cout << "4. Quick Sort\n";
    cout << "5. Merge Sort\n";
    cin >> choice;

    vector<int> arr;
    cout << "Enter the array elements (separated by spaces):\n";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        arr.push_back(num);
    }

    SortingAlgorithm* algorithm;
    switch (choice) {
        case 1:
            algorithm = new InsertionSort();
            break;
        case 2:
            algorithm = new SelectionSort();
            break;
        case 3:
            algorithm = new BubbleSort();
            break;
        case 4:
            algorithm = new QuickSort();
            break;
        case 5:
            algorithm = new MergeSort();
            break;
        default:
            cout << "Invalid choice.\n";
            return 1;
    }

    algorithm->sort(arr);

    cout << "Sorted array:\n";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << "\n";

    return 0;
}