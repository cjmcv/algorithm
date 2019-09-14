#include <iostream>

// O(N2).�ȶ�
// ���αȽ�������Ԫ�أ���ǰһԪ�ش��ں�һԪ���򽻻�֮��ֱ�����һ��Ԫ�ؼ�Ϊ���
// Ȼ�����´���Ԫ�ؿ�ʼ�ظ�ͬ���Ĳ�����ֱ�������ڶ���Ԫ�ؼ�Ϊ�δ�Ԫ�أ��������ơ�
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

// O(N2), �ȶ�
// ����ǰ�沿�ֿ�Ϊ�������ν��������������Ԫ�ز��뵽ǰ������������С���ȡ��
// �������ݺ������Ų������������ȴ������ݴ�Ĳ�����������һλ��Ų���ռ䣬ֱ��
// ��������ݡ�ѭ�������������ݣ��������
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

// O(N2), ���ȶ�
// ���ȳ�ʼ����СԪ������ֵΪ��Ԫ�أ����α������������У�������С�ڸ���С����λ��
// ����Ԫ����ˢ����С����Ϊ�ý�СԪ�ص�λ�ã�ֱ������βԪ�أ�����һ�α�����������
// С������Ԫ������Ԫ�ؽ�����
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