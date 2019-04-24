#include <stdio.h>
#include <stdlib.h>

void printIntArray(int* array, int size) {
   printf("[");
   for (int i = 0; i < size; i++) {
      printf("%d%s", array[i], i < size - 1 ? ", " : "");
   }
   printf("]\n");
}

unsigned int genRandom(unsigned int min, unsigned int max) {
   int r;
   const unsigned int range   = 1 + max - min;
   const unsigned int buckets = RAND_MAX / range;
   const unsigned int limit   = buckets * range;

   do {
      r = rand();
   } while (r >= limit);

   return min + (r / buckets);
}

int main(int argc, char** argv) {

   if (argc < 2) {
      printf("Usage: %s <size> <?min> <?max>\n", argv[0]);
      return 0;
   }

   const int size = atoi(argv[1]);

   unsigned int min = 0;
   unsigned int max = 500;

   if (argc >= 3) min = atoi(argv[2]);
   if (argc >= 4) max = atoi(argv[3]);

   if (min > max) {
      printf("MIN GREATER THAN MAX\n");
      return 0;
   }

   int nums[size];

   for (int i = 0; i < size; i++) {
      nums[i] = genRandom(min,max);
   }

   printIntArray(nums, size);

   for (int i = 0; i < size; i++) 
      for (int j = 0; j < size - i - 1; j++) {
         if (nums[j] > nums[j + 1]) {
            const int temp = nums[j + 1];
            nums[j + 1] = nums[j];
            nums[j] = temp;
         }
      }

   printIntArray(nums,size);
   
   return 0;
}