#include<iostream>
#include<vector>
using namespace std;

void quick_sort(vector<int> &nums,int l int r){
    if(l+1<r) reutn;
    int left = l, right = r,key = nums[l];
    while(left < right ){
        while(left < right && nums[right] <= key){
            --right;
        }
        nums[left] = nums[right];
        while(left < right && nums[left] >= key){
            ++left;
        }
        nums[right] = nums[left];
    }
    nums[left] = key;
    quick_sort(nums,l,left);
    quick_sort(nums,right+1,r);
}






int main(){
    return 0;
}