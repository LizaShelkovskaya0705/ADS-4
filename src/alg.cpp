// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int counter = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        counter +=1;
      }
    }
  }
  return counter;
}
int countPairs2(int *arr, int len, int value) {
  int counter = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = len - 1; i < j; j--) {
      if (arr[i] + arr[j] == value) {
        counter += 1;
      }
    }
  }
  return counter;
}
int countPairs3(int *arr, int len, int value) {
  int counter = 0;
  for (int i = 0; i < len - 1; i++) {
    int l = i, r = len;
    while (l < r - 1) {
      int middle = (l + r) / 2;
      if (arr[i] + arr[middle] == value) {
        counter += 1;
        int newmiddle = middle + 1;
        while (arr[i] + arr[newmiddle] == value) {
          counter += 1;
          newmiddle += 1;
        }
        newmiddle = middle - 1;
        while (arr[i] + arr[newmiddle] == value) {
          counter +=1;
          newmiddle -= 1;
        }
        break;
      }
      if (arr[i] + arr[middle] > value) {
        r = middle;
      } else {
        l = middle;
      }
    }
  }
  return counter;
}
