/*
Author: Nikhil Mahale
Description: Code to perform insertion sort of values
             provided random number generator
 */
#include <iostream>
using namespace std;

#define NUM_OF_TESTS 10
#define RANDOM_RANGE 100

int main() {

    int numOfElements = 5, outer, inner, currentVal, test, temp, index, iter;
    iter = 0;
    int arr[numOfElements];

    for(test= 0; test < NUM_OF_TESTS; test++) {
        /* Fill array with random integers from 1 to 100 */
        for(int i=0; i<numOfElements; i++){
            arr[i] = (rand()%RANDOM_RANGE)+1;
        }

        /* print input */
        cout << "Input elements are:";
        for(int i=0; i<numOfElements; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";

        /* insertion sort algorithm: O(n2)*/
        for(outer = 1; outer < numOfElements; outer++) {
            //cout << "Outer element number " << outer << " is " << arr[outer] << "\n";
            /* Take one element to insert */
            currentVal = arr[outer];
            for(inner = 0; inner <= outer - 1; inner++) {
                //cout << "Inner element number " << inner << " is " << arr[inner] << "\n";
                if(arr[inner] > currentVal) {
                    //cout << "Value " << currentVal << " is less than " << arr[inner] << "\n";
                    index = inner;//
                    /* shift rest of the elements */
                    for(iter = outer-1; iter  >= inner; iter--) {
                        arr[iter+1] = arr[iter];
                    }
                    arr[index] = currentVal;
                    break;
                }
            }

            //cout << "ARRAY AFTER ITERATION " << outer << "is: ";
//            int k;
//            for(k = 0; k < numOfElements; k++) {
//                cout << arr[k] << " ";
//            }
        }

        /* print output */
        cout << "sorted elements are: ";
        for(outer = 0; outer < numOfElements; outer++) {
            cout << arr[outer] << " ";
        }
        cout << "\n\n";
    }//END OF for(test= 0; test < NUM_OF_TESTS; test++) {
}

