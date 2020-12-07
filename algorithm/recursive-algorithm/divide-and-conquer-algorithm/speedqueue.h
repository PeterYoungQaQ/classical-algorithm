/**
 * @author: PeterYoung
 * @date: 2020/12/5 17:01
 * @description: ��������
 */

#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 10

/**************************************************
 *��������display
 *���ã���ӡ����Ԫ��
 *������array - ��ӡ�����飬maxlen - ����Ԫ�ظ���
 *����ֵ����
 **************************************************/
void display(int array[], int maxlen)
{
    int i;

    for(i = 0; i < maxlen; i++)
    {
        printf("%-3d", array[i]);
    }
    printf("\n");
}

/************************************
 *��������QuickSort
 *���ã����������㷨
 *������
 *����ֵ����
 ************************************/
void QuickSort(int *arr, int low, int high)
{
    if (low < high)
    {
        int i = low;
        int j = high;
        int k = arr[low];
        while (i < j)
        {
            while(i < j && arr[j] >= k)     // ���������ҵ�һ��С��k����
            {
                j--;
            }
            if(i < j)
            {
                arr[i++] = arr[j];
            }
            while(i < j && arr[i] < k)      // ���������ҵ�һ�����ڵ���k����
            {
                i++;
            }
            if(i < j)
            {
                arr[j--] = arr[i];
            }
        }
        arr[i] = k;

        // �ݹ����
        QuickSort(arr, low, i - 1);     // ����k���
        QuickSort(arr, i + 1, high);    // ����k�ұ�
    }
}

// ������
void speedqueue()
{
    int array[BUF_SIZE] = {12,85,25,16,34,23,49,95,17,61};
    int maxlen = BUF_SIZE;

    printf("����ǰ������\n");
    display(array, maxlen);
    QuickSort(array, 0, maxlen-1);  // ��������
    printf("����������\n");
    display(array, maxlen);


}
