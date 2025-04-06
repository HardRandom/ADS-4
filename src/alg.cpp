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
  int result = 0;
  int right = len - 1;
  int left = 0;
  for (int i = 0; i < right; i++) {
    for (int j = right - 1; j > left; j--) {
      if (arr[j] > value)
        right--;
      if (arr[i] + arr[j] == value)
        result++;
    }
    left++;
  }
  return result;
}
int countPairs3(int *arr, int len, int value) {
  return 1;
}
