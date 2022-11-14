//creat an array size of n= 10, 100, 500, 5000 and 25000 items. 
//Your program should populate those arrays with randomly generated integers with a value between 0 and the 2n

#include <iostream>
#include <vector>
#include <chrono>
#include <list>
#include <cmath>

using namespace std;

typedef std::chrono::high_resolution_clock Clock;

void bubblesort(int array[] , int size){
    int Change = 1;
    int PlaceHolder;
    while (Change > 0){
        Change = 0;
        for (int i = 0; i < size; i++){
            if (array[i] > array [i+1]){
                PlaceHolder = array[i];
                array[i] = array[i+1];
                array[i+1] = PlaceHolder;
                Change = Change + 1;
            }
        }
    }
}

void Insertionsort(int array[] , int size){
    int Change = 1;
    int PlaceHolder;
    while (Change > 0){
        Change = 0;
        for (int i = 0; i < size; i++){
            if (array[i] > array[i+1]){
                PlaceHolder = array[i+1];
                array[i+1] = array[i];
                array[i] = PlaceHolder;
                Change = Change + 1;
            }
        }
    }
}
void merge(int array[], int const left, int const mid,
           int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;
 
    // Create temp arrays
    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];
 
    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
 
    auto indexOfSubArrayOne
        = 0, // Initial index of first sub-array
        indexOfSubArrayTwo
        = 0; // Initial index of second sub-array
    int indexOfMergedArray
        = left; // Initial index of merged array
 
    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne
           && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne]
            <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray]
                = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray]
            = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray]
            = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}
 
//begin of merge sort - sourced from https://www.geeksforgeeks.org/merge-sort/
void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return; // Returns recursively
 
    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

int partition(int arr[],int start, int end)   //from https://www.geeksforgeeks.org/cpp-program-for-quicksort/
{
    int pivot = arr[start];
 
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
 
    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
 
    // Sorting left and right parts of the pivot element
    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (arr[i] <= pivot) {
            i++;
        }
 
        while (arr[j] > pivot) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
 
    return pivotIndex;
}
 
void quickSort(int arr[],int start, int end)
{
    // base case
    if (start >= end)
        return;
 
    // partitioning the array
    int p = partition(arr, start, end);
 
    // Sorting the left part
    quickSort(arr, start, p - 1);
 
    // Sorting the right part
    quickSort(arr, p + 1, end);
}


//start radix sort - from https://www.tutorialspoint.com/cplusplus-program-to-implement-radix-sort
void radixSort(int *arr, int n, int max) {
   int i, j, m, p = 1, index, temp, count = 0;
   list<int> pocket[10];      //radix of decimal number is 10
   for(i = 0; i< max; i++) {
      m = pow(10, i+1);
      p = pow(10, i);
      for(j = 0; j<n; j++) {
         temp = arr[j]%m;
         index = temp/p;      //find index for pocket array
         pocket[index].push_back(arr[j]);
      }
      count = 0;
      for(j = 0; j<10; j++) {
         //delete from linked lists and store to array
         while(!pocket[j].empty()) {
            arr[count] = *(pocket[j].begin());
            pocket[j].erase(pocket[j].begin());
            count++;
         }
      }
   }
}

void Make10Array(int array[]){
    for (int i = 0; i < 10; i++){
        int random = (1 + rand() % 20);
        array [i] = random;
    }
}
void Make100Array(int array[]){
    for (int i = 0; i < 100; i++){
        int random = (1 + rand() % 200);
        array [i] = random;
    }
}
void Make500Array(int array[]){
    for (int i = 0; i < 500; i++){
        int random = (1 + rand() % 1000);
        array [i] = random;
    }
}
void Make5000Array(int array[]){
    for (int i = 0; i < 5000; i++){
        int random = (1 + rand() % 10000);
        array [i] = random;
    }
}
void Make25000Array(int array[]){
    for (int i = 0; i < 25000; i++){
        int random = (1 + rand() % 50000);
        array [i] = random;
    }
}
int main(){
    int Array10 [10];
    int Array100 [100];
    int Array500 [500];
    int Array5000 [5000];
    int Array25000 [24999];
    int n;

/*
auto t1 = Clock::now();
	  <Some interesting code that does something>
	  auto t2 = Clock::now();
	  std::cout << "Delta t2-t1: " 
	        << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count()
	        << " nanoseconds" << std::endl;
*/
    
    Make10Array(Array10);
    auto t1 = Clock::now();
    bubblesort(Array10, 10);
    auto t2 = Clock::now();
    std::cout << "10 length bubblesort: " << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << " microseconds" << std::endl;

    
    Make10Array(Array10);
    auto t3 = Clock::now();
    Insertionsort(Array10, 10);
    auto t4 = Clock::now();
    std::cout << "10 length Insertionsort: " << std::chrono::duration_cast<std::chrono::microseconds>(t4 - t3).count() << " microseconds" << std::endl;
    
    
    Make10Array(Array10);
    auto t5 = Clock::now();
    mergeSort(Array10, 0, 8);
    auto t6 = Clock::now();
    std::cout << "10 length MergeSort: " << std::chrono::duration_cast<std::chrono::microseconds>(t6 - t5).count() << " microseconds" << std::endl;
    
    
    Make10Array(Array10);
    auto t7 = Clock::now();
    quickSort(Array10, 0, 9);
    auto t8 = Clock::now();
    std::cout << "10 length quickSort: " << std::chrono::duration_cast<std::chrono::microseconds>(t8 - t7).count() << " microseconds" << std::endl;

    
    Make10Array(Array10);
    auto t9 = Clock::now();
    radixSort(Array10, 9, 2);
    auto t10 = Clock::now();
    std::cout << "10 length Radixsort: " << std::chrono::duration_cast<std::chrono::microseconds>(t10 - t9).count() << " microseconds" << std::endl;




    
    Make100Array(Array100);
    auto t11 = Clock::now();
    bubblesort(Array100, 100);
    auto t21 = Clock::now();
    std::cout << "100 length bubblesort: " << std::chrono::duration_cast<std::chrono::microseconds>(t21 - t11).count() << " microseconds" << std::endl;

    
    Make100Array(Array100);
    auto t31 = Clock::now();
    Insertionsort(Array100, 100);
    auto t41 = Clock::now();
    std::cout << "100 length Insertionsort: " << std::chrono::duration_cast<std::chrono::microseconds>(t41 - t31).count() << " microseconds" << std::endl;
    
    
    Make100Array(Array100);
    auto t51 = Clock::now();
    mergeSort(Array100, 0, 99);
    auto t61 = Clock::now();
    std::cout << "100 length MergeSort: " << std::chrono::duration_cast<std::chrono::microseconds>(t61 - t51).count() << " microseconds" << std::endl;
    
    
    Make100Array(Array100);
    auto t71 = Clock::now();
    quickSort(Array100, 0, 99);
    auto t81 = Clock::now();
    std::cout << "100 length quickSort: " << std::chrono::duration_cast<std::chrono::microseconds>(t81 - t71).count() << " microseconds" << std::endl;

    
    Make100Array(Array100);
    auto t91 = Clock::now();
    radixSort(Array100, 99, 3);
    auto t101 = Clock::now();
    std::cout << "100 length Radixsort: " << std::chrono::duration_cast<std::chrono::microseconds>(t101 - t91).count() << " microseconds" << std::endl;




    
    Make500Array(Array500);
    auto t111 = Clock::now();
    bubblesort(Array500, 500);
    auto t211 = Clock::now();
    std::cout << "500 length bubblesort: " << std::chrono::duration_cast<std::chrono::microseconds>(t211 - t111).count() << " microseconds" << std::endl;

    
    Make500Array(Array500);
    auto t311 = Clock::now();
    Insertionsort(Array500, 500);
    auto t411 = Clock::now();
    std::cout << "500 length Insertionsort: " << std::chrono::duration_cast<std::chrono::microseconds>(t411 - t311).count() << " microseconds" << std::endl;
    
    
    Make500Array(Array500);
    auto t511 = Clock::now();
    mergeSort(Array500, 0, 499);
    auto t611 = Clock::now();
    std::cout << "500 length MergeSort: " << std::chrono::duration_cast<std::chrono::microseconds>(t611 - t511).count() << " microseconds" << std::endl;
    
    
    Make500Array(Array500);
    auto t711 = Clock::now();
    quickSort(Array500, 0, 499);
    auto t811 = Clock::now();
    std::cout << "500 length quickSort: " << std::chrono::duration_cast<std::chrono::microseconds>(t811 - t711).count() << " microseconds" << std::endl;

    
    Make500Array(Array500);
    auto t911 = Clock::now();
    radixSort(Array500, 499, 3);
    auto t1011 = Clock::now();
    std::cout << "500 length Radixsort: " << std::chrono::duration_cast<std::chrono::microseconds>(t1011 - t911).count() << " microseconds" << std::endl;




    
    Make5000Array(Array5000);
    auto t1111 = Clock::now();
    bubblesort(Array5000, 5000);
    auto t2111 = Clock::now();
    std::cout << "5000 length bubblesort: " << std::chrono::duration_cast<std::chrono::microseconds>(t2111 - t1111).count() << " microseconds" << std::endl;

    
    Make5000Array(Array5000);
    auto t3111 = Clock::now();
    Insertionsort(Array5000, 5000);
    auto t4111 = Clock::now();
    std::cout << "5000 length Insertionsort: " << std::chrono::duration_cast<std::chrono::microseconds>(t4111 - t3111).count() << " microseconds" << std::endl;
    
    
    Make5000Array(Array5000);
    auto t5111 = Clock::now();
    mergeSort(Array5000, 0, 4999);
    auto t6111 = Clock::now();
    std::cout << "5000 length MergeSort: " << std::chrono::duration_cast<std::chrono::microseconds>(t6111 - t5111).count() << " microseconds" << std::endl;
    
    
    Make5000Array(Array5000);
    auto t7111 = Clock::now();
    quickSort(Array5000, 0, 4999);
    auto t8111 = Clock::now();
    std::cout << "5000 length quickSort: " << std::chrono::duration_cast<std::chrono::microseconds>(t8111 - t7111).count() << " microseconds" << std::endl;

    
    Make5000Array(Array5000);
    auto t9111 = Clock::now();
    radixSort(Array5000, 4999, 4);
    auto t10111 = Clock::now();
    std::cout << "5000 length Radixsort: " << std::chrono::duration_cast<std::chrono::microseconds>(t10111 - t9111).count() << " microseconds" << std::endl;





    
    Make25000Array(Array25000);
    auto t11111 = Clock::now();
    bubblesort(Array25000, 25000);
    auto t21111 = Clock::now();
    std::cout << "25000 length bubblesort: " << std::chrono::duration_cast<std::chrono::microseconds>(t21111 - t11111).count() << " microseconds" << std::endl;

    
    Make25000Array(Array25000);
    auto t31111 = Clock::now();
    Insertionsort(Array25000, 25000);
    auto t41111 = Clock::now();
    std::cout << "25000 length Insertionsort: " << std::chrono::duration_cast<std::chrono::microseconds>(t41111 - t31111).count() << " microseconds" << std::endl;
    
    
    Make25000Array(Array25000);
    auto t51111 = Clock::now();
    mergeSort(Array25000, 0, 24999);
    auto t61111 = Clock::now();
    std::cout << "25000 length MergeSort: " << std::chrono::duration_cast<std::chrono::microseconds>(t61111 - t51111).count() << " microseconds" << std::endl;
    
    
    Make25000Array(Array25000);
    auto t71111 = Clock::now();
    quickSort(Array25000, 0, 24999);
    auto t81111 = Clock::now();
    std::cout << "25000 length quickSort: " << std::chrono::duration_cast<std::chrono::microseconds>(t81111 - t71111).count() << " microseconds" << std::endl;

    
    Make25000Array(Array25000);
    auto t91111 = Clock::now();
    radixSort(Array25000, 24999, 5);
    auto t101111 = Clock::now();
    std::cout << "25000 length Radixsort: " << std::chrono::duration_cast<std::chrono::microseconds>(t101111 - t91111).count() << " microseconds" << std::endl;



    return 0;
}