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
   for (int index = maxIndex; index < targetFibIndex; index++) {
      fibSeries[index + 1] = fibSeries[index - 1] + fibSeries[index];
   }

   while (maxIndex + 1 < targetFibIndex) {
      fibSeries[maxIndex + 1] = fibSeries[maxIndex - 1] + fibSeries[maxIndex];
      maxIndex++;
   }

   return fibSeries[maxIndex];
}

int main(int argc, char *information[]) {
   // Parameter Information Retrieval:
   int num = atoi(information[1]);
   char type = information[2][0];
   char *fileName = information[3];

   // Get File Information:
   FILE *filePointer = fopen(fileName, "r");
   char fileText[256];
   fgets(fileText, sizeof(fileText), filePointer);
   int fileNum = atoi(fileText);

   // Problem Setup:
   int targetFibIndex = num + fileNum;

   // Initializations: 
   int fibSeries[targetFibIndex + 1];
   fibSeries[0] = 0;
   fibSeries[1] = 1;
   int maxIndex = 1;
   int result = 0;

   if (type == 'r') {
      result = recursiveFib(targetFibIndex, fibSeries, maxIndex);
      // printf("r function was used");
   }
   else if (type == 'i') {
      result = iterativeFib(targetFibIndex, fibSeries, maxIndex);
      // printf("i function was used");
   }

   printf("%d\n", result);
   
   fclose(filePointer);
   return result;
}
