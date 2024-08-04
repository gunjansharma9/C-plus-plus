#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (i <= j) {
        while (i <= high && arr[i] <= pivot) {
            i++;
        }

        while (j >= low && arr[j] > pivot) {
            j--;
        }

        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[low], arr[j]);
    return j;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    vector<int> arr = {34, 22, 2, 5, 8, 9, 76, 80, 1, 1, 2, 2,3,3,3,3,5,5,7};
    int n = arr.size();

    quickSort(arr, 0, n - 1);

    cout << "Sorted array:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}


// quick sort by using last element as pivot element
void quickSORT(int a[],int start,int end){
    if(start >= end){
        return;
    }

    int pivot = end;
    int i = start - 1;
    int j = start;

    while(j < pivot){
        if(a[j] < a[pivot]){
            ++i;
            swap(a[i],a[j]);
        }
        j++;
    }
    ++i;
    swap(a[i],a[pivot]);
    quickSORT(a,start,i-1);
    quickSORT(a,i+1,end);
}