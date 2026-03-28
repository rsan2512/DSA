#include <bits/stdc++.h>
using namespace std;

long long mergeAndCount(vector<int>& arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    long long invCount = 0;

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            invCount += (mid - left + 1);
            right++;
        }
    }

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }

    return invCount;
}

long long mergeSortAndCount(vector<int>& arr, int low, int high) {
    if (low >= high) return 0;

    int mid = (low + high) / 2;
    long long inv = 0;

    inv += mergeSortAndCount(arr, low, mid);
    inv += mergeSortAndCount(arr, mid + 1, high);
    inv += mergeAndCount(arr, low, mid, high);

    return inv;
}

int main() {
    vector<int> nums = {5, 4, 2, 1, 3};
    cout << mergeSortAndCount(nums, 0, nums.size() - 1);
}
