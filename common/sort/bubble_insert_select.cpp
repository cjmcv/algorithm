#include <iostream>

// O(N2).稳定
// 依次比较相邻两元素，若前一元素大于后一元素则交换之，直至最后一个元素即为最大；
// 然后重新从首元素开始重复同样的操作，直至倒数第二个元素即为次大元素；依次类推。
void BubbleSort(float *a, int len) {
  for (int i = 0; i<len - 1; i++) {
    for (int j = 0; j<len - i - 1; j++) {
      if (a[j]>a[j + 1]) {
        int temp = a[j + 1];
        a[j + 1] = a[j];
        a[j] = temp;
      }
    }
  }
}

// O(N2), 稳定
// 数列前面部分看为有序，依次将后面的无序数列元素插入到前面的有序数列中。在取出
// 待排数据后，在已排部分中搜索，比待排数据大的部分数据右移一位，挪出空间，直至
// 插入该数据。循环插入所有数据，完成排序
void InsertSort(float *a, int len) {
  for (int i = 1; i < len; i++) {
    int priot = a[i];
    int j = i - 1;
    for (; j >= 0; j--) {
      if (a[j] > priot) {
        a[j + 1] = a[j];
      }
      else {
        break;
      }
    }
    a[j + 1] = priot;
  }
}

// O(N2), 不稳定
// 首先初始化最小元素索引值为首元素，依次遍历待排序数列，若遇到小于该最小索引位置
// 处的元素则刷新最小索引为该较小元素的位置，直至遇到尾元素，结束一次遍历，并将最
// 小索引处元素与首元素交换；
void SelectSort(float *a, int len) {
  for (int i = 0; i < len; i++) {
    int t = a[i];
    int t_id = i;
    for (int j = i + 1; j < len; j++) {
      if (t > a[j]) {
        t = a[j];
        t_id = j;
      }
    }
    t = a[t_id];
    a[t_id] = a[i];
    a[i] = t;
  }
}

int main() {
  const int len = 10;
  float arr[len] = { 1,2,5,4,8,-7,9,6,-3,15 };

  BubbleSort(arr, len);
  for (int i = 0; i < len; i++) {
    std::cout << arr[i] << ", ";
  }
  printf(".\n//////////////////////.\n");

  InsertSort(arr, len);
  for (int i = 0; i < len; i++) {
    std::cout << arr[i] << ", ";
  }
  printf(".\n//////////////////////.\n");

  SelectSort(arr, len);
  for (int i = 0; i < len; i++) {
    std::cout << arr[i] << ", ";
  }
  printf(".\n//////////////////////.\n");

  return 0;
}