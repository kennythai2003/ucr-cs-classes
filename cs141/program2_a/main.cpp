#include <bits/stdc++.h>
using namespace std;

void mergeSort(int [], int, int, int, int &); 
void merge(int [], int, int, int, int, int &);

//HELP FROM ADHITH
//MERGE SORT ALGORITHM FOLLOWED WHAT I LEARNED IN ZYBOOKS AND GEEKSFORGEEKS
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, score;

    cin >> n;
    cin.ignore();    

    int arr[n];
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> score;
        cin.ignore();

        arr[i] = score;
    }

    mergeSort(arr, 0, n - 1, n, sum);
    printf ("%d", sum);

    return 0;
}

void mergeSort(int arr[], int begin, int end, int n, int &sum)
{
    //n used for future temp array, sum used to keep track of candies
    int mid = (begin + end) / 2; 

    if (begin < end)
    {
        mergeSort(arr, begin, mid, n, sum);
        mergeSort(arr, mid + 1, end, n, sum);
        merge(arr, begin, end, mid, n, sum);
    }

    return;
}

void merge(int arr[], int begin, int end, int middle, int n, int &sum)
{
    //n used for future temp array, sum used to keep track of candies
    int left = begin;
    int right = middle + 1;
    int tempArr[n];
    int temp = begin;

    while (left <= middle && right <= end)
    {
        if (arr[left] < arr[right])
        {
            tempArr[temp] = arr[left];
            temp += 1;
            left += 1;
        }
        else
        {
            tempArr[temp] = arr[right];
            temp += 1;
            right += 1;
        }
    }

    while(left <= middle)
    {
        tempArr[temp] = arr[left];
        temp += 1;
        left += 1;
    }

    while(right <= end)
    {
        tempArr[temp] = arr[right];
        temp += 1;
        right += 1;
    }

    sum += (tempArr[temp - 1] - tempArr[begin]);

    for (left = begin; left < temp; left++)
    {
        arr[left] = tempArr[left];
    }
}