#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*Merging two arrays sorted in ascending order and placing the result inside nums1, which already has size m+n
*Where m is the number of elemnts in nums1 to be included, n is number of elements in nums2.
*/
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    
    int j = n-1;
    int k = m+n-1;
    int i = m-1;
    while(true){
        if(k < 0 || j < 0){ //This means that we either took all elements from nums2 and so nums1 is already sorted or we placed everything already in nums1
            return;
        }
        if(i < 0 || nums2[j] > nums1[i]){
            nums1[k] = nums2[j];
            j--;
        } else {
            nums1[k] = nums1[i];
            i--;
        }
        k--;
    }

}

int main()
{
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};          

    merge(nums1, 3, nums2, 3);
    for(int num : nums1){
        cout << num << " " << endl;
    }
}
