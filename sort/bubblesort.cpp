#include<iostream>
using namespace std;
void bubble_sort(vector<int> &nums,int n){
    bool swapped;
    for(int i = 1; i < n;++i){
        swapped = false;
        for(int j = 1; j< n-i+1;++j){
            swap(nums[j],nums[j-1]);
            swapped= true;
        }
    }
    if(!swapped) break;
}

void mybubble_sort(vector<int> &nums,int n){
    for(int i = 0,i<n-1;++i){
        for(int j = i+1,j<n;++j){
            if(nums[j]<nums[j-1]){
                swap(nums[j],nums[j-1]);
            }
        }
    }

}