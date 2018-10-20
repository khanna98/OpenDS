#include<iostream>

using namespace std;

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify a subtree
// rooted with node i
void heapify(int arr[], int n,int i){
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    // Check if left child is greater than root
    if(l < n && arr[l] > arr[largest]){
        largest = l;
    }

    // Check if right child is greater than 
    // largest
    if(r < n && arr[r] > arr[largest]){
        largest = r;
    }

    if(largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr,n,largest);
    }
}

void heapSort(int arr[],int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }

    for(int i=n-1;i>=0;i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}

void display(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(void){
    int arr[] = {20,6,7,4,1,9,10};
    int n = sizeof(arr)/sizeof(arr[0]);

    heapSort(arr,n);

    cout<<"The Sorted Array is :"<<endl;
    display(arr,n);
}