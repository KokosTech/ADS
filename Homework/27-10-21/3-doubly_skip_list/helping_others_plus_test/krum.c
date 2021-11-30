#include<stdio.h>
#include<stdlib.h>

#define NARRAY 7
#define NBUCKET 3
#define RANGE 10

typedef struct bucket
 {
    int arr[NARRAY];

}bucket;

void bucket_sort (int arr[]) 
{    
    int num[NBUCKET] = {0};
    bucket **buckets;
    buckets = (bucket **)calloc(NBUCKET, sizeof(bucket *));
    
    for (int i = 0; i < NARRAY; i++)
    {
        for (int j = 0; j < NBUCKET; j++)
        {
            printf("%d\n", arr[i]);
            if ((arr[i] / 10) == j)
            {    
                buckets[j]->arr[num[j]] = (arr[i] / 10);
                num[j]++;            
            }
        }
    }     
    
    for (int j = 0; j < NBUCKET; j++)
    {
        for (int i = 0; i < NARRAY; i++)
        {
            printf("%d\n", buckets[j]->arr[i]);
        }
    }
}

int main() {
    int arr[] = {1, 3, 5 ,9 ,15, 16, 17};
    bucket_sort (arr);
    
    return 0;
}
