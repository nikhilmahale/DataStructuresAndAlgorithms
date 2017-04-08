/*
Author: Nikhil Mahale
Description: Code to perform merge sort of values
             provided by random number generator
 */
#include <iostream>
using namespace std;

/* macros and global variables */
#define NUM_OF_TESTS 1
#define RANDOM_RANGE 100
int NumOfElements = 5;

/* Function Prototypes */
void MergeList(int[], int, int, int);
void MergeSort(int[], int, int);

int main() {
    int arr[NumOfElements];
    int outer, inner, currentVal, test, temp, index, iter;
    iter = 0;


    for(test= 0; test < NUM_OF_TESTS; test++) {
        /* Fill array with random integers from 1 to 100 */
        for(int i=0; i<NumOfElements; i++){
            arr[i] = (rand()%RANDOM_RANGE)+1;
        }

        /* print input */
        cout << "Input elements are:";
        for(int i=0; i<NumOfElements; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";

        MergeSort(arr, 0, NumOfElements);

        /* print output */
        cout << "sorted elements are: ";
        for(outer = 0; outer < NumOfElements; outer++) {
            cout << arr[outer] << " ";
        }
        cout << "\n\n";
    }//END OF for(test= 0; test < NUM_OF_TESTS; test++) {
}

/***************************************************************
 * Function Name:   MergeSort
 * Description:     This function uses a recursive call
 *                  to break down array into small chunks
 *                  and merge them after sorting.
 * *************************************************************/
void MergeSort(int myarr[],int left,int right) {
    int center;
    if(left < right) {
        center = (left+right)/2;
        MergeSort(myarr, left, center);
        MergeSort(myarr, center + 1, right);
        MergeList(myarr, left, center+1, right);
    }
}

/***************************************************************
 * Function Name:   MergeList
 * Description:     This function merges two sorted lists to
 *                  Ultimately create a final sorted list.
 * *************************************************************/
void MergeList(int arr[], int leftStart, int center, int rightEnd)  {
    int numberOfElements = rightEnd - leftStart + 1;
    int leftEnd = center -1;
    int rightStart = center;

    /* arr[] given to this function has two sorted parts.
     * Lets Create temporary array where we will merge and store them */
    int tempArr[numberOfElements];
    int tempArrPos = leftEnd;

    /* Both should be within bounds to be able to merge */
    while((leftStart < leftEnd) && (rightStart < rightEnd)) {
        if(arr[leftStart] > arr[rightStart]) {
            tempArr[tempArrPos++] = arr[rightStart++];
        }
        else {
            tempArr[tempArrPos++] = arr[leftStart++];
        }
    }

    /* At least one array is not fully exhausted. Fill the remaining elements */
    while(leftStart < leftEnd) {
        tempArr[tempArrPos++] = arr[leftStart++];
    }
    while(rightStart < rightEnd) {
        tempArr[tempArrPos++] = arr[rightStart++];
    }

    /* Fill back input array with our merged list */
    int count;
    for(count = 0; count < numberOfElements; count++) {
        arr[count] = tempArr[count];
    }
}
