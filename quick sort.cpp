#pragma once
#include <iostream>

#define ITEM_SIZE 10

using namespace std;
int n, cnt, quick[1001];

void print_arr(int a[], int size);
void merge(int a[], int left, int mid, int right);
void merge_sort(int a[], int left, int right);
void quickSort(int i, int j);

void print_arr(int a[], int size) {
    for (int i = 0; i < size; i++) {
        cout << a[i] << ' ';
    }
    cout << '\n';
}

void merge(int a[], int left, int mid, int right) {
    int i, j, k;

    i = left;
    j = mid + 1;
    k = left;

    int tmp_arr[ITEM_SIZE];

    // left 부터 mid 까지의 블록과 mid + 1 부터 right 까지의 블록을 서로 비교
    while (i <= mid && j <= right) {
        if (a[i] <= a[j]) {
            tmp_arr[k] = a[i];
            i++;
        }
        else {
            tmp_arr[k] = a[j];
            j++;
        }
        k++;
    }

    // left 블록의 값이 다 처리되었지만, right 블록의 index가 남아 있는 경우
    // right 블록의 남은 부분을 순차적으로 tmp_arr에 복사
    if (i > mid) {
        for (int m = j; m <= right; m++) {
            tmp_arr[k] = a[m];
            k++;
        }
    }
    // left 블록의 남은 부분을 순차적으로 tmp_arr에 복사
    else {
        for (int m = i; m <= mid; m++) {
            tmp_arr[k] = a[m];
            k++;
        }
    }

    // 임시 배열인 tmp_arr의 값을 원본 배열에 복사한다.
    for (int m = left; m <= right; m++) {
        a[m] = tmp_arr[m];
    }
}

void merge_sort(int a[], int left, int right) {
    int mid;

    if (left < right) {
        // 절반으로 나누기 위해 중간 위치 찾기
        mid = (left + right) / 2;

        // 분할
        merge_sort(a, left, mid);
        merge_sort(a, mid + 1, right);

        // 합병
        merge(a, left, mid, right);
    }

   
}


void quickSort(int i, int j)
{
    if (i >= j) return;
    int pivot = quick[(i + j) / 2];
    int left = i;
    int right = j;

    while (left <= right)
    {
        while (quick[left] < pivot)
            left++;
        while (quick[right] > pivot)
            right--;
        if (left <= right)
        {
            swap(quick[left], quick[right]);
            left++; right--;
        }
    }
    quickSort(i, right);
    quickSort(left, j);
}