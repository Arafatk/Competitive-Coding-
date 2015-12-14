#include <iostream>
#include <cstdlib>
using namespace std; 
int resulter[100];
#define forall(i,a,b)               for(long long i=a;i<b;i++)
int mSort(int arr[], int temp[], int left, int right);
int merge(int arr[], int temp[], int left, int mid, int right);
int holder[100];
int mergeSort(int arr[], int array_size)
{
    int *temp = new int [array_size];
    return mSort(arr, temp, 0, array_size - 1);
}

int mSort(int arr[], int temp[], int left, int right)
{
    int mid, inv_count = 0;
    if (right > left)
    {
        mid = (right + left)/2;
        inv_count  = mSort(arr, temp, left, mid);
        inv_count += mSort(arr, temp, mid+1, right);
        inv_count += merge(arr, temp, left, mid+1, right);
    }
    
    return inv_count;
}
int merge(int arr[], int temp[], int left, int mid, int right)
{
    int i, j, k;
    int inv_count = 0;
    i = left;
    j = mid;
    k = left;
    while ((i <= mid - 1) && (j <= right))
    {
        if (arr[i] <= arr[j])
        {   holder[arr[j]]++;
            temp[k++] = arr[i++];
        }
        else
        {
            holder[arr[i]]+=(mid-i);
            temp[k++] = arr[j++];
            inv_count = inv_count + (mid - i);
        }
    }
    while (i <= mid - 1)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];
    for (i = left; i <= right; i++)
        arr[i] = temp[i]; 
    return inv_count;
}
int main()
{
    int arr[] = {7,6,5,4,3,2,1};
    cout<<"Number of inversions are "<<mergeSort(arr, 7)<<endl;
    forall(i,0,8){cout << holder[i] <<"\n";}
    return 0;
}