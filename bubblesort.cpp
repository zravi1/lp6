#include<iostream>
#include<omp.h>
#include<bits/stdc++.h>
using namespace std;

void swap(int& A, int &B){
    int temp = A;
    A= B;
    B= temp;
}

 void parallel_bubblesort(int array[], int n){
    int temp[n];
    for(int i =0; i <n ; i++){
        temp[i]=array[i];

    }
    for(int i =0; i <n ; i++){
        if(i %2==0){
            #pragma omp parallel for
            for(int j =1; j<n ; j =j+2){
                if(temp[j]>temp[j+1]){
                    swap(temp[j],temp[j+1]);
                }
            }
        }
        else{
            #pragma omp parallel for
        for(int j =0; j<n ; j =j+2){
                if(temp[j]>temp[j+1]){
                    swap(temp[j],temp[j+1]);
                }
            }
        }
    }
    for(int i =0; i <n ;i++){
        cout<<temp[i]<<" ";
    }
 }

  int main (){

    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    int array[n];
    cout<<"Enter the elements in the array : ";
    
    for(int i =0; i <n; i ++){
        cin>>array[i];

    }

    parallel_bubblesort(array, n);

    return 0 ;
  }