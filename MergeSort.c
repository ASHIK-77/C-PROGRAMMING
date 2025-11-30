#include <stdio.h>

void merge(int arr[], int left, int mid, int right) {
    int i = left;       // pointer for left array
    int j = mid + 1;    // pointer for right array
    int k = 0;          // pointer for temp array

    int temp[100];

    // Merge two sorted halves
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    // Copy remaining elements of left half
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    // Copy remaining elements of right half
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Copy temp array back into original arr
    for (int x = 0; x < k; x++) {
        arr[left + x] = temp[x];
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {  // **important base condition**
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, n - 1);

    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
