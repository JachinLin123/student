#include <math.h>
#include <stdio.h>
#include <stdlib.h>
double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    int m = nums1Size;
    int n = nums2Size;
    if (m > n)
    {
        int *temp = nums1;
        nums1 = nums2;
        nums2 = temp;
        int tmp = m;
        m = n;
        n = tmp;
    }
    int mini = 0, maxi = m, halflen = (m + n + 1) / 2;
    while (mini <= maxi)
    {
        int i = (maxi + mini) / 2;
        int j = halflen - i;
        if (i < maxi && nums1[i - 1] > nums2[j])
        {
            mini = i + 1;
        }
        else if (i > mini && nums2[j - 1] > nums1[i])
        {
            mini = i - 1;
        }
        else
        {
            int maxleft = 0;
            if (i == 0)
            {
                maxleft = nums2[j - 1];
            }
            else if (j == 0)
            {
                maxleft = nums1[i - 1];
            }
            else
            {
                maxleft = nums1[i - 1] > nums2[j - 1] ? nums1[i - 1] : nums2[j - 1];
            }
            if ((m + n) % 2 == 1)
            {
                return maxleft;
            }
            int minright = 0;
            if(i==m){
                minright = nums2[j];
            }
            else if(j==n){
                minright = nums1[i];
            }
            else{
                minright = nums1[i] < nums2[j] ? nums1[i] : nums2[j];
            }
            return (minright + maxleft) / 2.0;
        }
    }
    return 0.0;
}

int main()
{
    int m = 3, n = 3;
    int A[] = {1, 2, 3};
    int B[] = {4, 5,6};
    double result = findMedianSortedArrays(A, m, B, n);
    printf("%f", result);
    return 0;
}