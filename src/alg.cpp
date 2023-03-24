// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int counter1 = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        counter1 +=1;
      }
    }
  }
  return counter1;
}
int countPairs2(int *arr, int len, int value) {
  int counter2 = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = len - 1; i < j; j--) {
      if (arr[i] + arr[j] == value) {
        counter2 += 1;
      }
    }
  }
  return counter2;
}
int countPairs3(int *arr, int len, int value) {
  int counter3 = 0;
  for (int i = 0; i < len - 1; i++) {
    int right = len, left = i;
    while (right - 1 > left) {
      int mid1 = (left + right) / 2;
      if (arr[i] + arr[mid1] == value) {
        counter3++;
        int middle = mid1 + 1;
        while (arr[i] + arr[middle] == value && middle < right) {
          counter3++;
          middle++;
        }
        middle = mid1 - 1;
        while (arr[i] + arr[middle] == value && middle > left) {
          counter3++;
          middle--;
        }
        break;
      }
       if (arr[i] + arr[mid1] > value) {
        right = mid1;
      } else {
        left = mid1;
      }
    }
  }
  return counter3;
}
