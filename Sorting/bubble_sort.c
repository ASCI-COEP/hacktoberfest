// Bubble sort in C
#include <stdio.h>

void bubbleSort(int array[], int size, int order)
{
  int step, i;
  for (step = 0; step < size - 1; ++step)
  {
    for (i = 0; i < size - step - 1; ++i)
    {
      // To sort in descending order, change">" to "<".
      if(order == 1) {
	      if (array[i] > array[i + 1])
	      {
	        int temp = array[i];
	        array[i] = array[i + 1];
	        array[i + 1] = temp;
	      }
      }
      //descending order
      else if(order == 0) {
	      if (array[i] < array[i + 1])
	      {
	        int temp = array[i];
	        array[i] = array[i + 1];
	        array[i + 1] = temp;
	      }
      }

    }
  }
}
void printArray(int array[], int size)
{
  int i;
  for (i = 0; i < size; ++i)
  {
    printf("%d  ", array[i]);
  }
  printf("\n");
}
int main()
{
  int data[] = {-2, 45, 0, 11, -9};
  int size = sizeof(data) / sizeof(data[0]);
  int order = 1; //1 for Ascending order and 0 for descending order
  bubbleSort(data, size, order);
  printf("Sorted Array in Ascending Order:\n");
  printArray(data, size);
  return 0;
}
