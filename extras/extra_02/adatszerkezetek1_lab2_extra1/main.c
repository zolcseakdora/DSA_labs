#include <stdio.h>
void reverse(int* nums, int start, int end);
void rotate(int* nums, int numsSize, int k);
void printArray(int* nums, int numsSize);
int main(void)
{
    int nums[] = {1, 2, 3, 4, 5, 6, 7};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int k = 3;

    rotate(nums, numsSize, k);
    printArray(nums, numsSize);
    return 0;
}

// Function to reverse a portion of the array
void reverse(int* nums, int start, int end)
{
    while (start < end)
    {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}

// Function to rotate the array to the right by k steps
void rotate(int* nums, int numsSize, int k)
{
    if (numsSize == 0 || k % numsSize == 0) return;

    k = k % numsSize; // Handle cases where k > numsSize

    // Reverse the entire array
    reverse(nums, 0, numsSize - 1);
    // Reverse the first k elements
    reverse(nums, 0, k - 1);
    // Reverse the remaining elements
    reverse(nums, k, numsSize - 1);
}

// Function to print the array
void printArray(int* nums, int numsSize)
{
    for (int i = 0; i < numsSize; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

