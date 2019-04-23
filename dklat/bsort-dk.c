#include <stdio.h>
#include <stdlib.h>

void printIntArray(int* array, int size) {
   printf("[");
   for (int i = 0; i < size; i++) {
      printf("%d%s", array[i], i < size - 1 ? ", " : "");
   }
   printf("]\n");
}

int main(void) {

   int nums[20] = {12,532,1,284,294,201,939,1823,3910,3827,48,2912,481,9382,1823,583,1923,921,192,482};

   const int size = sizeof(nums) / sizeof(nums[0]);

   printIntArray(nums, size);

   for (int i = 0; i < size; i++) {
      for (int j = 0; j < size - i - 1; j++) {
         if (nums[j] > nums[j + 1]) {
            const int temp = nums[j + 1];
            nums[j + 1] = nums[j];
            nums[j] = temp;
         }
      }
   }

   printIntArray(nums,size);
   
   return 0;
}