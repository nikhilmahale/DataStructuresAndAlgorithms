/*
Author: Nikhil Mahale
Description: Code to perform selection sort of values
             provided via command line
 */
#include <iostream>
using namespace std;

#define NUM_OF_TESTS 5

int main() {

    int numOfElements = 6, outer, inner, minVal, test, temp;
    int arr[numOfElements];

    for(test= 0; test < NUM_OF_TESTS; test++) {
        /* Fill array with random integers from 1 t0 100 */
        for(int i=0; i<numOfElements; i++){
            arr[i] = (rand()%100)+1;
        }

        /* print input */
        cout << "Input elements are:";
        for(int i=0; i<numOfElements; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";

        /* selection sort algorithm: O(n2)*/
        for(outer = 0; outer < numOfElements; outer++) {
            minVal = arr[outer];
            for(inner = outer +1; inner < numOfElements; inner++) {
                if(arr[inner] < arr[outer]) {
                    /* Swap elements */
                    temp = arr[outer];
                    arr[outer] = arr[inner];
                    arr[inner] = temp;
                }
            }
        }

        /* print output */
        cout << "sorted elements are: ";
        for(outer = 0; outer < numOfElements; outer++) {
            cout << arr[outer] << " ";
        }
        cout << "\n\n";
    }//END OF for(test= 0; test < NUM_OF_TESTS; test++) {
}

