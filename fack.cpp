#include <stdio.h>
#include <stdlib.h>
#define MAX_n 1000
#define MAX_N 2650
#define K 10 
    // 数组每位的进位值

void deal_ff(int *arr, int m)
{   // 只对一位进行进位
    // 为处理每一位而添加这个函数
    // 同时也可以用到 deal_f 中
	*(arr+m+1) += *(arr+m)/10;
	*(arr+m) %= 10;
	return ;
}

void deal_all(int *arr)
{   // 全部处理
    // 应对大数相加时
    // 高位进位低位不进位的情况
	for(int z=0; z<MAX_N-1; z++)
		deal_ff(arr, z);
	return ;
}

void bignum_cheng(int *arr, int k)
{   // 乘法
	for(int z=0; z<MAX_N; z++)
		*(arr+z) *= k;
	deal_all(arr);
	return ;
}

int print_bignum(int *arr)
{   // 去高位 0 的打印大数
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
	    *(arr+z)=0; // 初始化，初值为 0
	*(arr)=1; // 累乘的初值为 1

    int n=MAX_n;
    printf("%d!=", n);
    for(int k=1; k<=n; k++)
    	bignum_cheng(arr, k);
	int dlen=print_bignum(arr);
    printf("\n长度 : %d", dlen);

	return 0;
}


