class Solution {
private:
int getPivot(vector<int>& arr) {
    int s = 0;
    int e = arr.size()-1;
    int mid = s + (e-s)/2;
    while(s<e) {
        if(arr[mid] >= arr[0])
        {
            s = mid+1;
        }
        else{
            e = mid;
        }
        mid = s + (e-s)/2;
    }
    return s;
}
int binarySearch(vector<int>& nums, int target , int start , int end) {
        while(start <= end){
            int mid = start + (end - start)/2;
            if(nums[mid] == target){
                return mid;
            }
            if(nums[mid] > target){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return -1;
    }
int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot = getPivot(nums);
        if(target >= nums[pivot] && target<=nums[n-1]){
            return binarySearch(nums,target,pivot,n-1);
        }
        else{
            return binarySearch(nums,target,0,pivot-1);
        }
    }
};