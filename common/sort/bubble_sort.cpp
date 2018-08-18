#include <iostream>

void bubble_sort(int *io_arr, int len) {
  for (int i = 0; i<len - 1; i++) {
    for (int j = 0; j<len - i - 1; j++) {
      if (io_arr[j]>io_arr[j + 1]) {
        int temp = io_arr[j + 1];
        io_arr[j + 1] = io_arr[j];
        io_arr[j] = temp;
      }
    }
  }
}

int main() {
  const int len = 10;
  int arr[len] = { 1,2,5,4,8,7,9,6,3,15 };
  bubble_sort(arr, len);

  for (int i = 0; i < len; i++) {
    std::cout << arr[i] << ", ";
  }
  return 0;
}