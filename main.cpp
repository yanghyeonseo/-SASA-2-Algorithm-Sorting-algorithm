//file ÀÔÃâ·Â
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int n, a[100005];

FILE *in = fopen("in.txt", "rb");
FILE *out = fopen("out.txt", "wb");

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapify(int a[], int k, int n) {
    int left = 2*k;
    int right = 2*k+1;
    int small;

    if(right<=n)
        small = a[left] < a[right] ? left : right;
    else if(left<=n)
        small = left;
    else
        return;

    if(a[k] > a[small]) {
        swap(&a[k], &a[small]);
        heapify(a, small, n);
    }
}

void buildHeap(int a[], int n) {
    for(int i=n/2; i>0; i--) {
        heapify(a, i, n);
    }
}

void heapSort(int a[], int n) {
    buildHeap(a, n);
    for(int i=1; i<=n; i++) {
        fprintf(out, "%d ", a[1]);
        swap(&a[1], &a[n-i+1]);
        heapify(a, 1, n-i);
    }
}

int main() {
    n=9;
    srand(time(NULL));
//    for(int i=1; i<=n; i++)
//        a[i] = rand();

    for(int i=1; i<=n; i++)
        fscanf(in,"%d",&a[i]);

    int start = clock();
    heapSort(a, n);
    printf("result=%.4lf(sec)\n",(double)(clock()-start)/CLOCKS_PER_SEC);
    return 0;
}


//testcase generator
/*#include<stdio.h>
#include<stdlib.h>
#include<time.h>
FILE *out=fopen("n=_rand.txt","wb");
int main()
{
    int n;
    scanf("%d",&n);
    srand((unsigned)time(NULL));
    for(int i=0;i<n;i++)
    {
        long long int k=(((long)rand()<<15)|rand());
        fprintf(out,"%lld ",k);
    }
    return 0;
}*/


//sort
/*#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
FILE *in=fopen("n=10000000_rand.txt","rb");
FILE *out=fopen("n=10000000_rsorted.txt","wb");
long long int arr[10000005];
//bool cmp(long long int a,long long int b)
//{
//    return a>b?1:0;
//}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        fscanf(in,"%lld",arr+i);
    }
    std::sort(arr,arr+n);  //std::sort(arr,arr+n,cmp);
    for(int i=0;i<n;i++)
    {
        fprintf(out,"%lld ",arr[i]);
    }
    printf("end");
    return 0;
}*/


//rand generator
/*void arr_random(long long int arr[],int n,int s,int e)
{
    srand(time(NULL));
    for(int i=s;i<=e;i++)
    {
        arr[i]=(((long)rand()<<15|rand());
    }
}*/


//File scan function
/*void FileScan(FILE *file,int arr[],int s,int e)
{
    for(int i=s;i<=e;i++)
    {
        fscanf(file,"%d",arr+i);
    }
}*/


//File print function
/*void FilePrint(FILE *file,int arr[],int s,int e)
{
    for(int i=s;i<=e;i++)
    {
        fprintf(file,"%d ",arr[i]);
    }
}*/


//선택정렬
/*#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<algorithm>
FILE *out=fopen("out.txt","wb");
FILE *t=fopen("time.txt","wb");
void arr_random(long long int arr[],int s,int e)
{
    srand(time(NULL));
    for(int i=s;i<=e;i++)
    {
        arr[i]=((long)rand()<<15)|rand();
    }
}
void FilePrint(FILE *file,int long long arr[],int s,int e)
{
    for(int i=s;i<=e;i++)
    {
        fprintf(file,"%lld ",arr[i]);
    }
}
bool cmp(long long int a,long long int b)
{
    return a>b?1:0;
}
long long int arr[10000005];
int d[10]={1,5,10,15,20,25,30,35,40};
int main()
{
    int cnt=0;
    again:
    int n=d[cnt/3]*10000;
    arr_random(arr,0,n-1);
    //std::sort(arr,arr+n,cmp);
    time_t start=clock();
    for(int i=n;i>0;i--)
    {
        int max_i=0;
        for(int j=1;j<i;j++)
        {
            if(arr[j]>arr[max_i]) max_i=j;
        }
        int temp=arr[i-1];
        arr[i-1]=arr[max_i];
        arr[max_i]=temp;
    }
    time_t end=clock();
    fprintf(t,"%d exe time: %fs\n",n,(float)(end-start)/CLOCKS_PER_SEC);
    printf("%d exe time: %fs\n",n,(float)(end-start)/CLOCKS_PER_SEC);
    FilePrint(out,arr,0,n-1);
    if(cnt++<26) goto again;
    printf("END\n");
    return 0;
}*/


//삽입정렬
/*#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<algorithm>
FILE *out=fopen("out.txt","wb");
void arr_random(long long int arr[],int s,int e)
{
    srand(time(NULL));
    for(int i=s;i<=e;i++)
    {
        arr[i]=((long)rand()<<15)|rand();
    }
}
bool cmp(long long int a,long long int b)
{
    return a>b?1:0;
}
long long int arr[10000005];
int d[10]={1,5,10,15,20,25,30,35,40};
int main()
{
    int cnt=0;
    again:
    int n=d[cnt/3]*10000;
    arr_random(arr,0,n-1);
    //std::sort(arr,arr+n);
    time_t start=clock();
    for(int i=1;i<n;i++)
    {
        long long int temp=arr[i];
        int j;
        for(j=i-1;j>=0;j--)
        {
            if(temp<arr[j]) arr[j+1]=arr[j];
            else break;
        }
        arr[j+1]=temp;
    }
    time_t end=clock();
    printf("%d exe time: %fs\n",n,(float)(end-start)/CLOCKS_PER_SEC);
    if(cnt++<26) goto again;
    printf("END\n");
    return 0;
}*/


//병합 정렬
/*#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<algorithm>
FILE *out=fopen("out.txt","wb");
void arr_random(long long int arr[],int s,int e)
{
    srand(time(NULL));
    for(int i=s;i<=e;i++)
    {
        arr[i]=((long)rand()<<15)|rand();
    }
}
long long int temp[10000005];
void merge(long long int a[],int p,int q,int r)
{
    int i=p,j=q+1;
    int cnt=p;
    while(i<=q&&j<=r)
    {
        if(a[i]<a[j]) temp[cnt++]=a[i++];
        else temp[cnt++]=a[j++];
    }
    while(i<=q) temp[cnt++]=a[i++];
    while(j<=r) temp[cnt++]=a[j++];
    for(int i=p;i<=r;i++)
    {
        a[i]=temp[i];
    }
}
void mergesort(long long int a[],int p,int r)
{
    if(p>=r) return;
    int q=(p+r)/2;
    mergesort(a,p,q);
    mergesort(a,q+1,r);
    merge(a,p,q,r);
}
bool cmp(long long int a,long long int b)
{
    return a>b?1:0;
}
long long int arr[10000005];
int d[10]={1,2,3,4,5,6,7,8,9,10};
int main()
{
    int cnt=0;
    again:
    int n=d[cnt/3]*1000000;
    arr_random(arr,0,n-1);
    //std::sort(arr,arr+n,cmp);
    time_t start=clock();
    mergesort(arr,0,n-1);
    time_t end=clock();
    printf("%d exe time: %f\n",n,(float)(end-start)/CLOCKS_PER_SEC);
    if(cnt++<29) goto again;
    printf("END\n");
    return 0;
}*/


//힙 정렬
/*#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<algorithm>
long long int ans[10000005];
void arr_random(long long int arr[],int s,int e)
{
    srand(time(NULL));
    for(int i=s;i<=e;i++)
    {
        arr[i]=((long)rand()<<15)|rand();
    }
}
void swap(long long int *a,long long int *b)
{
    long long int temp=*a;
    *a=*b;
    *b=temp;
}
void heapify(long long int a[],int k,int n)
{
    int left,right;
    int small;
    left=2*k;
    right=2*k+1;  //=left+1
    if(right<=n) small=a[left]<a[right]?left:right;  //자식이 2개
    else if(left<=n) small=left;  //자식이 1개
    else return;
    if(a[k]>a[small])
    {
        swap(&a[k],&a[small]);
        heapify(a,small,n);
    }
}
void buildHeap(long long int a[],int n)
{
    for(int i=n/2;i>0;i--)
    {
        heapify(a,i,n);
    }
}
void heapSort(long long int a[],int n)
{
    buildHeap(a,n);
    for(int i=1;i<=n;i++)
    {
        ans[i]=a[1];
        swap(&a[1],&a[n-i+1]);
        heapify(a,1,n-i);
    }
}
bool cmp(long long int a,long long int b)
{
    return a>b?1:0;
}
long long int arr[10000005];
int d[10]={1,2,3,4,5,6,7,8,9,10};
int main()
{
    int cnt=0;
    again:
    int n=d[cnt/3]*1000000;
    arr_random(arr,1,n);
    //std::sort(arr+1,arr+n+1,cmp);
    time_t start=clock();
    heapSort(arr,n);
    time_t end=clock();
    printf("%d exe time: %fs\n",n,(float)(end-start)/CLOCKS_PER_SEC);
    //if(cnt++<29) goto again;
    printf("END\n");
    return 0;
}*/


//퀵 정렬
/*#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<algorithm>
void arr_random(long long int arr[],int s,int e)
{
    srand(time(NULL));
    for(int i=s;i<=e;i++)
    {
        arr[i]=((long)rand()<<15)|rand();
    }
}
int partition(long long int a[],int p,int r)
{
    long long int pivot=a[r];
    int i=p,j=p;
    for(j=p;j<r;j++)
    {
        if(a[j]<pivot)
        {
            long long int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            i++;
        }
    }
    a[r]=a[i];
    a[i]=pivot;
    return i;
}
void quicksort(long long int a[],int p,int r)
{
    if(p>=r) return;
    int q=partition(a,p,r);
    quicksort(a,p,q-1);
    quicksort(a,q+1,r);
}
bool cmp(long long int a,long long int b)
{
    return a>b?1:0;
}
long long int arr[10000005];
int d[10]={1,2,3,4,5,6,7,8,9,10};
int main()
{
    int cnt=0;
    again:
    int n=d[cnt/3]*10000;
    arr_random(arr,0,n-1);
    //std::sort(arr,arr+n,cmp);
    time_t start=clock();
    quicksort(arr,0,n-1);
    time_t end=clock();
    printf("%d exe time: %fs\n",n,(float)(end-start)/CLOCKS_PER_SEC);
    if(cnt++<29) goto again;
    return 0;
}*/


//코드 예시
/*#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<algorithm>
void arr_random(long long int arr[],int s,int e)
{
    srand(time(NULL));
    for(int i=s;i<=e;i++)
    {
        arr[i]=((long)rand()<<15)|rand();
    }
}
bool cmp(long long int a,long long int b)
{
    return a>b?1:0;
}
long long int arr[10000005];
int d[10]={1,2,3,4,5,6,7,8,9,10};
int main()
{
    int cnt=0;
    again:                              //반복 시작점
    int n=d[cnt/3]*1000000;             //하나의 n을 3번씩 반복
    arr_random(arr,0,n-1);              //배열에 난수 채우기
    std::sort(arr,arr+n,cmp);           //필요에 따라서 배열값을 정렬
    for(int i=0;i<n;i++)
        fprintf(in,"%lld ",arr[i])      //배열의 초기값 확인
    time_t start=clock();               //배열에 난수를 채우는 시간 및 초기 정렬 시간 제외
    SORT(arr,0,n-1);                    //수행 시간을 측정하고자 하는 정렬 알고리즘
    time_t end=clock();                 //출력 시간 제외
    for(int i=0;i<n;i++)
        fprintf(out,"%lld ",arr[i]);    //정렬한 후 매열의 값 확인
    printf("n=%d-> exe time: %fs\n",n,(float)(end-start)/CLOCKS_PER_SEC);  //수행시간 출력
    if(cnt++<29) goto again;            //again 부터 다시 반복
    return 0;
}*/
