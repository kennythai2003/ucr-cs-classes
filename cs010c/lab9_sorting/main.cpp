#include <iostream>
#include <ctime>

using namespace std;


const int NUMBERS_SIZE = 50000; //array size
const int CLOCKS_PER_MS = CLOCKS_PER_SEC / 1000; //clock per milliseconds

int genRandInt(int, int);
void fillArrays(int [], int [], int []);
void Quicksort_midpoint(int [], int, int);
void Quicksort_medianOfThree(int [], int, int);
void InsertionSort(int [], int);
int partition_midpoint(int [], int, int);
int median (int, int, int);
int partition_median(int [], int, int);

int main(){
    int arr1[NUMBERS_SIZE], arr2[NUMBERS_SIZE], arr3[NUMBERS_SIZE];
    // cout << sizeof(arr1) << " " << sizeof(arr2) << " " << sizeof(arr3)>> endl;
    fillArrays(arr1, arr2, arr3);
    cout << NUMBERS_SIZE << endl << endl;

    clock_t Start = clock();
    Quicksort_midpoint(arr1, 0, NUMBERS_SIZE);
    clock_t End = clock();
    int elapsedTime = (End - Start)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.
    cout << "Quicksort midpoint test 1: " << elapsedTime << endl;

    Start = clock();
    Quicksort_midpoint(arr2, 0, NUMBERS_SIZE);
    End = clock();
    elapsedTime = (End - Start)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.
    cout << "Quicksort midpoint test 2: " << elapsedTime << endl;

    Start = clock();
    Quicksort_midpoint(arr3, 0, NUMBERS_SIZE);
    End = clock();
    elapsedTime = (End - Start)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.
    cout << "Quicksort midpoint test 3: " << elapsedTime << endl;

    cout << endl;

    Start = clock();
    Quicksort_medianOfThree(arr1, 0, NUMBERS_SIZE);
    End = clock();
    elapsedTime = (End - Start)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.
    cout << "Quicksort median test 1: " << elapsedTime << endl;

    Start = clock();
    Quicksort_medianOfThree(arr2, 0, NUMBERS_SIZE);
    End = clock();
    elapsedTime = (End - Start)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.
    cout << "Quicksort median test 2: " << elapsedTime << endl;

    Start = clock();
    Quicksort_medianOfThree(arr3, 0, NUMBERS_SIZE);
    End = clock();
    elapsedTime = (End - Start)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.
    cout << "Quicksort median test 3: " << elapsedTime << endl;

    cout << endl;

    Start = clock();
    InsertionSort(arr1, NUMBERS_SIZE);
    End = clock();
    elapsedTime = (End - Start)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.
    cout << "Insertion Sort test 1: " << elapsedTime << endl;

    Start = clock();
    InsertionSort(arr2, NUMBERS_SIZE);
    End = clock();
    elapsedTime = (End - Start)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.
    cout << "Insertion Sort test 2: " << elapsedTime << endl;

    Start = clock();
    InsertionSort(arr3, NUMBERS_SIZE);
    End = clock();
    elapsedTime = (End - Start)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.
    cout << "Insertion Sort test 3: " << elapsedTime << endl;
}

int genRandInt(int low, int high){
   return low + rand() % (high - low + 1);
}

void fillArrays(int arr1[], int arr2[],int arr3[]){
    for(int i = 0; i < NUMBERS_SIZE; ++i){
        arr1[i] = genRandInt(0,NUMBERS_SIZE);
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
    }
}

void Quicksort_midpoint(int numbers[], int i, int k){
 //This function sorts the given array in the range from i to k using quicksort method. 
 //In this function, pivot is the midpoint element (numbers[(i+k)/2]).
 // (implementation of this function is given in section 21.5)    
    if (i >= k){
        return;
    }

    int partitionIndex = partition_midpoint(numbers, i, k);

    Quicksort_midpoint(numbers, i, partitionIndex);
    Quicksort_midpoint(numbers, partitionIndex + 1, k);
}

int partition_midpoint(int numbers[], int i, int k){
    int pivot = numbers[i + (k - i) / 2];

    bool done = false;

    while(!done){
        while (numbers[i] < pivot){
            i += 1;
        }
        while (numbers[k] > pivot){
            k -= 1;
        }    

        if (i >= k){
            done = true;
        }
        else{
            swap(numbers[i], numbers[k]);
            i += 1;
            k -= 1;
        }    
    }
    return k;
}

int partition_median(int numbers[], int i, int k){
    int pivot = numbers[median(numbers[i], numbers[i + (k - i) / 2], numbers[k])];

    bool done = false;

    while(!done){
        while (numbers[i] < pivot){
            i += 1;
        }
        while (numbers[k] > pivot){
            k -= 1;
        }    

        if (i >= k){
            done = true;
        }
        else{
            swap(numbers[i], numbers[k]);
            i += 1;
            k -= 1;
        }    
    }
    return k;
}

int median (int left, int midpoint, int right){
    if (left > midpoint){
        if (midpoint > right){
            return midpoint;
        }
        else if (left > right){
            return right;
        }
        else{
            return left;
        }
    }
    else{
        if (left > right){
            return left;
        }
        else if (midpoint > right){
            return right;
        }
        else{
            return midpoint;
        }
    }
}

void Quicksort_medianOfThree(int numbers[], int i, int k){
    if (i >= k){
        return;
    }

    int partitionIndex = partition_median(numbers, i, k);

    Quicksort_midpoint(numbers, i, partitionIndex);
    Quicksort_midpoint(numbers, partitionIndex + 1, k);
}

void InsertionSort(int numbers[], int numbersSize){
    int i = 1;
    int j;
    for (i = 1; i < numbersSize; ++i){      
        j = i;
        while (j > 0 && numbers[j] < numbers[j - 1]){
            swap(numbers[j], numbers[j - 1]);
            --j;
        }
    }
}