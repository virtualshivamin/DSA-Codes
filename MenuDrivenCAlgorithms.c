#include <stdio.h>
#define SIZE 100

void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insert(int arr[], int *n, int pos, int val) {
    if (*n >= SIZE) {
        printf("Array Overflow\n");
        return;
    }
    if (pos < 0 || pos > *n) {
        printf("Invalid Position\n");
        return;
    }
    for (int i = *n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = val;
    (*n)++;
}

void delete(int arr[], int *n, int pos) {
    if (*n == 0) {
        printf("Array Underflow\n");
        return;
    }
    if (pos < 0 || pos >= *n) {
        printf("Invalid Position\n");
        return;
    }
    for (int i = pos; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
}

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) return i;
    }
    return -1;
}

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) return mid;
        else if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

void reverse(int arr[], int n) {
    for (int i = 0, j = n - 1; i < j; i++, j--) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void mergeSortedArrays(int arr1[], int size1, int arr2[], int size2, int merged[]) {
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        if (arr1[i] <= arr2[j]) 
            merged[k++] = arr1[i++];
        else 
            merged[k++] = arr2[j++];
    }

    while (i < size1) {
        merged[k++] = arr1[i++];
    }

    while (j < size2) {
        merged[k++] = arr2[j++];
    }
}

int main() {
    int arr[SIZE], n, choice, val, pos;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n < 0 || n > SIZE) {
        printf("Invalid size\n");
        return 1;
    }

    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Search (Linear)\n4. Search (Binary)\n5. Reverse\n6. Display\n7. Merge two Arrays\n8. EXIT\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter position and value: ");
                scanf("%d %d", &pos, &val);
                insert(arr, &n, pos, val);
                break;
            case 2:
                printf("Enter position: ");
                scanf("%d", &pos);
                delete(arr, &n, pos);
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &val);
                pos = linearSearch(arr, n, val);
                if (pos == -1)
                    printf("Not Found\n");
                else 
                    printf("Found at %d\n", pos);
                break;
            case 4:
                printf("Enter value to search: ");
                scanf("%d", &val);
                pos = binarySearch(arr, n, val);
                if (pos == -1)
                    printf("Not Found\n");
                else 
                    printf("Found at %d\n", pos);
                break;
            case 5:
                reverse(arr, n);
                printf("Array reversed.\n");
                break;
            case 6:
                display(arr, n);
                break;
            case 7: {
                int size1, size2;
                printf("Enter size of first sorted array: ");
                scanf("%d", &size1);
                int arr1[size1];
                printf("Enter %d elements in sorted order: ", size1);
                for (int i = 0; i < size1; i++) {
                    scanf("%d", &arr1[i]);
                }

                printf("Enter size of second sorted array: ");
                scanf("%d", &size2);
                int arr2[size2];
                printf("Enter %d elements in sorted order: ", size2);
                for (int i = 0; i < size2; i++) {
                    scanf("%d", &arr2[i]);
                }

                int merged[size1 + size2];
                mergeSortedArrays(arr1, size1, arr2, size2, merged);
                printf("Merged array: ");
                display(merged, size1 + size2);
                break;
            }
            case 8:
                return 0;
            default:
                printf("Wrong Input\n");
        }
    }
}
