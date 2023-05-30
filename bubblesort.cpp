#include <iostream>
#include <vector>
#include <omp.h>

void pbs(std::vector<int>& arr){
    int n = arr.size();
    bool swapped = true;
    #pragma omp parallel num_threads(n);
    { while(swapped){
        swapped = false;
        #pragma omp for;
        for(int i=0;i<n-1;i++){
            if(arr[i]>arr[i+1]){
                #pragma critical;
                std::swap(arr[i],arr[i+1]);
                swapped = true;}
        }
    }
    }
}

int main(){
    std::vector<int> arr = {9,8,7,6,5,4,3,2,1};
    for (int num : arr)
        std::cout<<num<<" ";
    std::cout<<std::endl;
    return 0;
    }
