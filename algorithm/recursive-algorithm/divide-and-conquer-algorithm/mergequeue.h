/**
 * @author: PeterYoung
 * @date: 2020/12/5 16:51
 * @description: �ϲ�����
 */


#include <stdio.h>
#include <stdlib.h>
#define N 7

void merge(int arr[], int low, int mid, int high){
    int i, k;
    int *tmp = (int *)malloc((high-low+1)*sizeof(int));
    //����ռ䣬ʹ���СΪ����
    int left_low = low;
    int left_high = mid;
    int right_low = mid + 1;
    int right_high = high;

    for(k=0; left_low<=left_high && right_low<=right_high; k++){  // �Ƚ�����ָ����ָ���Ԫ��
        if(arr[left_low]<=arr[right_low]){
            tmp[k] = arr[left_low++];
        }else{
            tmp[k] = arr[right_low++];
        }
    }

    if(left_low <= left_high){
        //����һ��������ʣ�ֱ࣬�Ӹ��Ƴ���ճ���ϲ�����β
        //memcpy(tmp+k, arr+left_low, (left_high-left_low+l)*sizeof(int));
        for(i=left_low;i<=left_high;i++)
            tmp[k++] = arr[i];
    }

    if(right_low <= right_high){
        //���ڶ���������ʣ�ֱ࣬�Ӹ��Ƴ���ճ���ϲ�����β
        //memcpy(tmp+k, arr+right_low, (right_high-right_low+1)*sizeof(int));
        for(i=right_low; i<=right_high; i++)
            tmp[k++] = arr[i];
    }

    for(i=0; i<high-low+1; i++)
        arr[low+i] = tmp[i];
    free(tmp);
}

void merge_sort(int arr[], int first, int last){
    int mid;
    if(first<last){
        mid = (first + last) / 2; /* ע���ֹ��� */
        /*mid = first/2 + last/2;*/
        //mid = (first & last) + ((first ^ last) >> 1);
        merge_sort(arr, first, mid);
        merge_sort(arr, mid+1,last);
        merge(arr,first,mid,last);
    }
}

void merge_queue(){
    int i;
    int a[N]={32,12,56,78,76,45,36};

    printf ("����ǰ \n");
    for(i=0;i<N;i++)
        printf("%d\t",a[i]);

    merge_sort(a,0,N-1);  // ����

    printf ("\n����� \n");
    for(i=0;i<N;i++)
        printf("%d\t",a[i]); printf("\n");

    system("pause");
}

