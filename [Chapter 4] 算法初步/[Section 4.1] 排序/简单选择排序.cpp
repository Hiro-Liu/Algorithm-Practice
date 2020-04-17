/*********************************************************/
//简单选择排序，共N轮，每一轮找出剩余部分的最小值放在前面，依次进行。
//复杂度O(N^2)
/*********************************************************/

void selectSort(int a[]) {
    for (int i = 0; i < N; i++) {
        int min = i;                    //假定下标为i的元素最小
        for (int j = i; j < N; j++) {  //找出i~N-1的最小值
            if (a[j] < a[min]) {
                min = j;
            }
        }
        int temp = a[min];  //最小元素和a[i]互换
        a[min] = a[i];
        a[i] = temp;
    }
}
