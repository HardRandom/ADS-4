// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (arr[i] + arr[j] == value) {
                ++count;
            }
        }
    }
    return count;
}
int countPairs2(int *arr, int len, int value) {
    int left = 0;
    int right = len - 1;
    int count = 0;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            if (arr[left] == arr[right]) {
                int total = right - left + 1;
                count += total * (total - 1) / 2;
                break;
            } else {
                int count_left = 1;
                while (left + 1 < right && arr[left + 1] == arr[left]) {
                    ++left;
                    ++count_left;
                }
                int count_right = 1;
                while (right - 1 > left && arr[right - 1] == arr[right]) {
                    --right;
                    ++count_right;
                }
                count += count_left * count_right;
                ++left;
                --right;
            }
        } else if (sum < value) {
            ++left;
        } else {
            --right;
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
        int first = binarySearch(arr, i + 1, len - 1, target, true);
        if (first == -1) continue;
        int last = binarySearch(arr, i + 1, len - 1, target, false);
        if (last == -1) last = first;
        count += (last - first + 1);
    }
    return count;
}
