#include <iostream>
using namespace std;

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int l, int h)
{
    int x = arr[h];

    int i = (l - 1);
 
    for (int j = l; j <= h - 1; j++) {

        if (arr[j] <= x) {

            i++;

            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[h]);

    return (i + 1);
}

void quickSortIterative(int arr[], int l, int h)
{
    int stack[h - l + 1];

    int top = -1;

    stack[++top] = l;

    stack[++top] = h;

    while (top >= 0) {

        h = stack[top--];

        l = stack[top--];

        int p = partition(arr, l, h);

        if (p - 1 > l) {

            stack[++top] = l;

            stack[++top] = p - 1;
        }

        if (p + 1 < h) {

            stack[++top] = p + 1;

            stack[++top] = h;
        }

    }
}

void quickSortRecursive(int A[], int l, int h)
{

    if (l < h) {

        int p = partition(A, l, h);

        quickSortRecursive(A, l, p - 1);

        quickSortRecursive(A, p + 1, h);
    }
}

void printArr(int arr[], int n)
{
    int i;
    for (i = 0; i < n; ++i)

        cout << arr[i] << " "<<endl;
}


int main()
{
    int n = 8;
    int arr[n] = { 4, 3, 5, 2, 1, 3, 2, 3 };

    quickSortIterative(arr, 0, n - 1);
    cout<<"Result using Iteration "<<endl;
    printArr(arr, n);

    quickSortRecursive(arr, 0, n - 1);
    cout<<"Result using Recursion "<<endl;
    printArr(arr, n);

    return 0;
}
