//1021449 許雅涵 2015/10/26(PG1)
//Input: array={}; Output: the left index, the right index, and the total sum for the maximum-subarray.
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;
//int maxLeft = 0;
//int maxRight = 0;
int maxSubarraySum(int array[], int n)
{
    //如果只有一個值，就直接回傳。
    if(n==1)
    {
        return array[0];
    }
    //分成兩半
    int mid = n/2;
    //(A)左邊的最大值
    int left_mss = maxSubarraySum(array, mid);
    //(B)右邊的最大值
    int right_mss = maxSubarraySum(array+mid, n-mid);
    //從右子樹中找出總和最大的值，從左到右。
    int rightsum = INT_MIN;
    int sum=0;
    for(int i=mid ; i<n ; i++)
    {
        sum += array[i];
        if(sum > rightsum)
        {
            rightsum = sum;
            //maxRight = i;
        }
        //rightsum = max(rightsum, sum);
    }
    //從左子樹找出總和最大的值，從右到左。
    int leftsum = INT_MIN;
    sum = 0;
    for(int i=(mid-1) ; i>=0 ; i--)
    {
        sum += array[i];
        if(sum > leftsum)
        {
            leftsum = sum;
      //      maxLeft = i;
        }
        //leftsum = max(leftsum, sum);
    }
    //(C)leftsum + rightsum
    //A、B、C三者比較，找出最大者即為回傳值(答案)
    int ans = max(left_mss, right_mss);
    return max(ans, leftsum+rightsum);
}
int main()
{
//    int a[] = {17, 100, 113, 110, 85, 105, 102, 86, 63, 81, 105,102,86, 63, 81, 101, 94, 106,101, 79, 94, 90, 97};
    int a[] = {35, -37, 17, 10, -8, 24, -27, 15, 13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    int n = sizeof(a)/sizeof(a[0]);
    int max_sum = maxSubarraySum(a, n);
    cout << "Left index: " << endl;
    cout << "Right index: " << endl;
    cout << "The total sum for the maximum-subarray: " << max_sum <<endl;
 //   system("pause");
}
