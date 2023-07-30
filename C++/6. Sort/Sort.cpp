#include <iostream>

using namespace std;

class Sort {
    public:
        void bubbleSort(int array[], int size) {
            for (int i = size - 1; i > 0; i--) {
                for (int j = 0; j < i; j++) {
                    if (array[j] > array[j+1]) {
                        int temp = array[j];
                        array[j] = array[j+1];
                        array[j+1] = temp;
                    }
                }
            }
        }
        void selectionSort(int array[], int size) {
            for (int i = 0; i < size; i++) {
                int minIndex = i;
                for (int j = i + 1; j < size; j++) {
                    if (array[j] < array[minIndex]) {
                        minIndex = j;
                    }
                }
                if (i != minIndex) {
                    int temp = array[i];
                    array[i] = array[minIndex];
                    array[minIndex] = temp;
                }
            }
        }
        void insertionSort(int array[], int size) {
            for (int i = 1; i < size; i++) {
                int j = i;
                while (j > 0 && array[j] < array[j-1]) {
                    int temp = array[j];
                    array[j] = array[j-1];
                    array[j-1] = temp;
                    j--;
                }
            }
        }
        void merge(int array[], int leftIndex, int midIndex, int rightIndex) {
            int leftArraySize = midIndex - leftIndex + 1;
            int rightArraySize = rightIndex - midIndex;

            int leftArray[leftArraySize];
            int rightArray[rightArraySize];

            for (int i = 0; i < leftArraySize; i++)
                leftArray[i] = array[leftIndex+i];
            
            for (int j = 0; j < rightArraySize; j++)
                rightArray[j] = array[midIndex+j+1];

            int index = leftIndex;
            int i = 0;
            int j = 0;

            while (i < leftArraySize && j < rightArraySize) {
                if (leftArray[i] <= rightArray[j]) {
                    array[index] = leftArray[i];
                    index++;
                    i++;
                } else {
                    array[index] = rightArray[j];
                    index++;
                    j++;
                }
            }
            while (i < leftArraySize) {
                array[index] = leftArray[i];
                index++;
                i++;
            }
            while (j < rightArraySize) {
                array[index]= rightArray[j];
                index++;
                j++;
            }
        }

        void mergeSort(int array[], int leftIndex, int rightIndex) {
            if (leftIndex >= rightIndex) return;

            int midIndex = leftIndex + (rightIndex - leftIndex) / 2;
            mergeSort(array, leftIndex, midIndex);
            mergeSort(array, midIndex+1, rightIndex);
            
            merge(array, leftIndex, midIndex, rightIndex);

        }

        void swap(int array[], int firstIndex, int secondIndex) {
            int temp = array[firstIndex];
            array[firstIndex] = array[secondIndex];
            array[secondIndex] = temp;
        }

        int pivot(int array[], int pivotIndex, int endIndex) {
            int swapIndex = pivotIndex;
            for (int i = pivotIndex+1; i <= endIndex; i++) {
                if (array[i] < array[pivotIndex]) {
                    swapIndex++;
                    swap(array, swapIndex, i);
                }
            }
            swap(array, pivotIndex, swapIndex);
            return swapIndex;
        }

        void quickSort(int array[], int leftIndex, int rightIndex) {
            if (leftIndex >= rightIndex) return;
            int pivotIndex = pivot(array, leftIndex, rightIndex);
            quickSort(array, leftIndex, pivotIndex-1);
            quickSort(array, pivotIndex+1, rightIndex);
        }
};

int main() {
    int myArray[] = { 4, 1, 6, 5, 7, 3, 2 };
    int mySize = sizeof(myArray) / sizeof(myArray[0]);
    
    Sort* mySort = new Sort();
    mySort->quickSort(myArray, 0, 6);

    for (auto e : myArray) {
        cout << e << " ";
    }
}