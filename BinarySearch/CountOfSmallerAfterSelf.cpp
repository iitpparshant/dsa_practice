//   https://leetcode.com/problems/count-of-smaller-numbers-after-self/description/


//           315. Count of Smaller Numbers After Self



class Solution {
public:
    void merge(vector<int>& nums, int l, int mid, int r, vector<int>& count,
               vector<int>& idx) {
        int n = mid - l + 1;
        int m = r - mid;
        vector<int> left(n), right(m);
        for (int i = 0; i < n; i++) {
            left[i] = idx[l + i];
        }
        for (int i = 0; i < m; i++) {
            right[i] = idx[mid + 1 + i];
        }
        int i = 0, j = 0;
        int k = l;
        while (i < n && j < m) {
            if (nums[left[i]] > nums[right[j]]) {
                count[left[i]] += (m - j);
                idx[k] = left[i];
                k++;
                i++;
            } else {
                idx[k] = right[j];
                j++;
                k++;
            }
        }
        while (i < n) {
            idx[k] = left[i];
            k++;
            i++;
        }
        while (j < m) {
            idx[k] =right[j];
            j++;
            k++;
        }
    }
    void mergeSort(vector<int> &nums, int s, int e, vector<int>& count,
                   vector<int>& idx) {
        if (s >= e) {
            return;
        }
        int mid = (s + e) / 2;
        mergeSort(nums, s, mid, count, idx);
        mergeSort(nums, mid + 1, e, count, idx);
        merge(nums, s, mid, e, count, idx);
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> index(n, 0);
        for (int i = 0; i < n; i++) {
            index[i] = i;
        }
        vector<int> count(n, 0);
        mergeSort(nums, 0, n - 1, count, index);
        return count;
    }
};