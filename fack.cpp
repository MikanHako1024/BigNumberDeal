#include <stdio.h>
#include <stdlib.h>
#define MAX_n 1000
#define MAX_N 2650
#define K 10 
    // ����ÿλ�Ľ�λֵ

void deal_ff(int *arr, int m)
{   // ֻ��һλ���н�λ
    // Ϊ����ÿһλ������������
    // ͬʱҲ�����õ� deal_f ��
	*(arr+m+1) += *(arr+m)/10;
	*(arr+m) %= 10;
	return ;
}

void deal_all(int *arr)
{   // ȫ������
    // Ӧ�Դ������ʱ
    // ��λ��λ��λ����λ�����
	for(int z=0; z<MAX_N-1; z++)
		deal_ff(arr, z);
	return ;
}

void bignum_cheng(int *arr, int k)
{   // �˷�
	for(int z=0; z<MAX_N; z++)
		*(arr+z) *= k;
	deal_all(arr);
	return ;
}

int print_bignum(int *arr)
{   // ȥ��λ 0 �Ĵ�ӡ����
    int dlen=MAX_N;
    while( *(arr+dlen-1)==0 && dlen>1 )
        dlen--;
        
    if(dlen==MAX_N)
    {
        printf("MAX SIZE is too small\n");
        return -1;
    }
    
	for(int z=dlen-1; z>=0; z--)
		printf("%d", *(arr+z) );
	return dlen;
}

int main()
{
	int arr[MAX_N];
	for(int z=0; z<MAX_N; z++)
	    *(arr+z)=0; // ��ʼ������ֵΪ 0
	*(arr)=1; // �۳˵ĳ�ֵΪ 1

    int n=MAX_n;
    printf("%d!=", n);
    for(int k=1; k<=n; k++)
    	bignum_cheng(arr, k);
	int dlen=print_bignum(arr);
    printf("\n���� : %d", dlen);

	return 0;
}


