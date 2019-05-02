/* This problem was asked by Microsoft.
 * Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
 * For example, given [100, 4, 200, 1, 3, 2], the longest consecutive element sequence is [1, 2, 3, 4]. Return its length: 4.
 * Your algorithm should run in O(n) complexity.
 */


#include "libinc.h"

#define MAX(a,b) a > b ? a : b

/* Search if number is present . This is O(1) */
int searchnum(int *arr, int len, int num)
{
    int i;

    for(i=0; i < len; i++)
    {
	if(arr[i] == num)
	    return 1;
    }
    return 0;
}

int main(void)
{
    int arr[] = {100, 200, 3, 201, 99, 199, 2, 98, 97, 1, 101};
    int i,j;
    int arrlen;
    int ret;
    int result = 0;
    int count;

    arrlen = sizeof(arr)/sizeof(int);

    /* Going through each element of array of size n takes O(n) */
    for(i=0; i < arrlen; i++)
    {
	/* Check if previous number is part of the array */
	ret = searchnum(arr, arrlen, arr[i] - 1);
	/* If present, continue with next number in array */
	if(ret) {
	    //printf("%d is present\n",arr[i]);
	    continue;
	} else {
	    /* Previous number is not present in array
	     * So this is the first number in our consecutive sequence
	     * Now search for next numbers in sequence starting with a[i]
	     */
	    //printf("%d is NOT present\n",arr[i]);
	    j=1;
	    count=1;
	    while(1)
	    {
		ret = searchnum(arr, arrlen, arr[i] + j);
		if(ret) {
		    j++;
		    count++;
		} else
		    break;
	    }

	}
	result = MAX(count, result);

    }
    printf("Longest Sequence equals --> %d\n", result);

    return 0;
}

