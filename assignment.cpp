#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

/* Implementing merge sort
 * */
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l +  1;
    int n2 = r-m;
    /* create temp arrays
     * */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[]
     *  */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]
     * */
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there are any
     * */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there are any
     * */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the sub-array
 * of arr to be sorted
 */
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2; //Same as (l+r)/2, but avoids overflow for large l and h
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

/* UITLITY FUNCTIONS
 * */
/* Function to print an array
 *  */
void printArray(int A[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

/* Function to find all elements satisfying the constraint
 * */
void find_all(int A[], int size, int sum) {
    int i, j, k, l;
    int remainder;
    int count = 0;

    /* Outer loop for the first number in the sum
     * */
    for (int i = 0; i < size - 1; i++) {

        /* Inner loop for the second number in the sum
         * */
        for (int j = i + 1; j < size; j++) {

            /* The third and fourth numbers are located from a subset of numbers
             * */
            if (sum >= (A[i] + A[j])) {
                remainder = sum - (A[i] + A[j]);
                for (int k = 0; k < size; k++) {
                    if (A[k] <= remainder && (k != i && k != j)) {
                        for (int l = 0; l < size; l++) {
                            if ((A[l] <= remainder / A[k] && l != i)
                                    && (l != j && l != k)) {
                                cout << count << ") " << A[i] << " " << A[j]
                                     << " " << A[k] << " " << A[l] << endl;
                                count = count + 1;
                                if(!(A[i]==A[j] && A[k]==A[l])) {
                                    cout << count << ") " << A[j] << " " << A[i]
                                         << " " << A[k] << " " << A[l] << endl;
                                    count = count + 1;
                                }
                            }
                        }
                    }

                }
            }
        }
    }

}

/* Driver program to test above functions
 * */
int main() {

    string line;


    cout<<"enter comma seperated string"<<endl;
    std::getline( std::cin, line );

    vector<int> vect;

    std::stringstream ss(line);
    int i;
    while (ss >> i)
    {
        vect.push_back(i);

        if (ss.peek() == ',')
            ss.ignore();
    }

    int arr_size=vect.size()-1;
    int sum=vect[0];
    int A[arr_size];
    for(i=0; i<arr_size; i++) {
        A[i]=vect[i+1];
    }

    printf("Given array is \n");
    printArray(A, arr_size);

    mergeSort(A, 0, arr_size - 1);

    printf("\nSorted array is \n");
    printArray(A, arr_size);

    find_all(A, arr_size, sum);

    return 0;
}

