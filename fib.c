#include <stdio.h>
#include <stdlib.h>

unsigned long long int recursiveFib (unsigned long long int target_fib_index, unsigned long long int fib_series[], int max_index) {

   if (max_index == target_fib_index) {
      return fib_series[max_index - 1];
   } else {
      fib_series[max_index + 1] = fib_series[max_index] + fib_series[max_index - 1];
      return recursiveFib(target_fib_index, fib_series, max_index + 1);
   }

   return 0;
}
unsigned long long int iterativeFib (unsigned long long int target_fib_index, unsigned long long int fib_series[], int max_index) {

   while (max_index != target_fib_index) {
      fib_series[max_index + 1] = fib_series[max_index - 1] + fib_series[max_index];
      max_index++;
   }

   return fib_series[max_index - 1];
}

int main (int argc, char *information[]) {

   const unsigned long long int INFORMATION_NUMBER = atoi(information[1]);
   const char INFORMATION_TYPE = information[2][0];
   const char *FILE_NAME = information[3];

   FILE *file_pointer = fopen(FILE_NAME, "r");
   char file_text[256];
   fgets(file_text, sizeof(file_text), file_pointer);
   const int FILE_NUMBER = atoi(file_text);

   const unsigned long long int TARGET_FIB_INDEX = INFORMATION_NUMBER + FILE_NUMBER;

   unsigned long long int fib_series[TARGET_FIB_INDEX + 1];
   fib_series[0] = 0;
   fib_series[1] = 1;
   unsigned long long int max_index = 1;
   unsigned long long int result = 0;

   if (INFORMATION_TYPE == 'r') {
      result = recursiveFib(TARGET_FIB_INDEX, fib_series, max_index);
   }
   else if (INFORMATION_TYPE == 'i') {
      result = iterativeFib(TARGET_FIB_INDEX, fib_series, max_index);
   }

   printf("%lld\n", result);
   
   fclose(file_pointer);
   return 0;
}
