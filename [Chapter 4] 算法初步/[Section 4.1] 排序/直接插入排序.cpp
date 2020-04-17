void insertSort(int a[]) {
    for (int i = 1; i < N; i++) {  // n-1趟排序
        int temp = a[i], j = i;
        while (temp < a[j - 1]) {  //比较temp和temp-1
            a[j] = a[j - 1];
            j--;  //开始比较temp与temp-2
        }
        a[j] = temp;  //插入位置为j
    }
}
