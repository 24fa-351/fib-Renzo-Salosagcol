#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Main Program Functions
int recursiveFib (int targetFibIndex, int fibSeries[], int maxIndex) {

   if (maxIndex + 1 == targetFibIndex) {
      return fibSeries[maxIndex];
   } else if (maxIndex + 1 < targetFibIndex) {
      fibSeries[maxIndex + 1] = fibSeries[maxIndex] + fibSeries[maxIndex - 1];
      return recursiveFib(targetFibIndex, fibSeries, maxIndex + 1);
   }

   return 0;
}
int iterativeFib (int targetFibIndex, int fibSeries[], int maxIndex) {

   while (maxIndex + 1 < targetFibIndex) {
      fibSeries[maxIndex + 1] = fibSeries[maxIndex - 1] + fibSeries[maxIndex];
      maxIndex++;
   }

   return fibSeries[maxIndex];
}

int main (int argc, char *information[]) {

   const int INFORMATION_NUMBER = atoi(information[1]);
   const char INFORMATION_TYPE = information[2][0];
   const char *FILE_NAME = information[3];

   FILE *file_pointer = fopen(FILE_NAME, "r");
   char fileText[256];
   fgets(fileText, sizeof(fileText), file_pointer);
   const int FILE_NUMBER = atoi(fileText);

   const int TARGET_FIB_INDEX = INFORMATION_NUMBER + FILE_NUMBER;

   int fib_series[TARGET_FIB_INDEX + 1];
   fib_series[0] = 0;
   fib_series[1] = 1;
   int max_index = 1;
   int result = 0;

   if (INFORMATION_TYPE == 'r') {
      result = recursiveFib(TARGET_FIB_INDEX, fib_series, max_index);
   }
   else if (INFORMATION_TYPE == 'i') {
      result = iterativeFib(TARGET_FIB_INDEX, fib_series, max_index);
   }

   printf("%d\n", result);
   
   fclose(file_pointer);
   return 0;
}
