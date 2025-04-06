// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}
int countPairs2(int *arr, int len, int value) {
  int count = 0;
    int left = 0;
    int right = len - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            count++;
            left++;
            right--;
        } else if (sum < value) {
            left++;
        } else {
            right--;
        }
    }
    return count;
}
int binarySearch(int *arr, int len, int target, int exclude_index) {
    int left = 0;
    int right = len - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (mid == exclude_index) {
            mid++;
            if (mid > right) break;
        }
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}
int countPairs3(int *arr, int len, int value) {
  int count = 0;
    for (int i = 0; i < len; ++i) {
        int target = value - arr[i];
        int foundIndex = binarySearch(arr, len, target, i);
        if (foundIndex != -1) {
            count++;
        }
    }
    return count / 2;
}
