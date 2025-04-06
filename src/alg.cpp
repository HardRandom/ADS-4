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
    
    while (left < right) {  // Изменено с <= на <
        int sum = arr[left] + arr[right];
        
        if (sum == value) {
            if (arr[left] == arr[right]) {
                int k = right - left + 1;
                count += k * (k - 1) / 2;
                break;
            }
            
            int cnt_left = 1;
            while (left + cnt_left < len && arr[left + cnt_left] == arr[left]) {
                cnt_left++;
            }
            
            int cnt_right = 1;
            while (right - cnt_right >= 0 && arr[right - cnt_right] == arr[right]) {
                cnt_right++;
            }
            
            count += cnt_left * cnt_right;
            left += cnt_left;
            right -= cnt_right;  // Теперь безопасно, так как left < right
        } 
        else if (sum < value) {
            left++;
        } 
        else {
            right--;
        }
    }
    
    return count;
}
int countPairs3(int *arr, int len, int value) {
  return 1;
}
