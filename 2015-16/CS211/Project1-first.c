#include<stdio.h>
#include<stdlib.h>

/* Assignment: Project 1
   Name: Ibrahiem Mohammad
   Net ID: imoham3
   Date Due: 9/6/15
*/


/*Function 1
  Copies values from one array to another
 */
void arrayCopy (int fromArray[], int toArray[], int size){
	
	printf("size: %d", size);
	int i, j;
	//clone array
	for (i = 0; i < size; i++){
		toArray[i] = fromArray[i];
	}
	
	//print cloned array
	for (j = 0; j < size; j++){
		printf("\nCloned Array: %d", toArray[j]); 
	}
}

/*Function 2
  Sorts an array in ascending order
*/
void sort (int arr[], int size){

	int i, j, temp, k;
	
	for (i = 0; i < (size - 1); i++){
		
		for (j = 0; j < (size - i - 1); j++){
			
			if (arr[j] > arr[j+1]){
				
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}

	for (k = 0; k < size; k++){
		printf("\nsorted Array: %d\n", arr[k]); 
	}

}

/*Function 3
  Performs a linear search on an unsorted array
*/
int linear_search (int arr[], int size, int target, int *numComparisons){

	int i;
	for (i = 0; i < size; i++){
		if (arr[i] == target){
			printf("\nTarget found at position: %d", i);
			printf("\nNumber of comparisons: %d", i+1);
			*numComparisons = i + 1;
			return i, *numComparisons;			
		}
	
	}
	
	printf("\nTarget not found: NO MATCH\n");	
	return -1;
}

/*Function 4
  Performs a binary search on a sorted array
*/
int binary_search (int arr[], int size, int target, int *numComparisons){
	
	int divider = size - 1;
	int i = 0;
	int middle = (i+divider)/2;
	*numComparisons = 0;

	while (i <= divider){
		middle = (i+divider)/2;
		*numComparisons++;
		if (target==arr[middle]){
			printf("target found at pos: %d", middle);
			*numComparisons++;
			printf("\nNumber of Comparisons: %i", *numComparisons);
			return middle, *numComparisons;
		}
		else if (target > arr[middle]){
			i = middle + 1;
			*numComparisons++;
		}
		else if (target < arr[middle]){
			divider = middle - 1;
			*numComparisons++;
		}
	}
	
	return -1;
}


int main(){
	
	int *fromArray;
	int size = 10;
	fromArray = (int *)malloc (size * sizeof(int));
	
	int *temp;
	temp = (int *)malloc (size * 2 * sizeof(int));
	
	int val = 0;
	int pos = 0;	

	//loop to fill in array
	printf("\nEnter your value\n");
	while (val != -999){
		
		scanf("%d", &val);
		fromArray[pos] = val;
		printf("val: %d, pos: %d, array_val: %d\n", val, pos, fromArray[pos]);

		pos++;
	}	
	
	size = pos;
	int toArray[size];
	int numComparisons;

	arrayCopy (fromArray, toArray, size);

	sort (fromArray, size);
	
	binary_search (fromArray, size, 8, &numComparisons);

	/*linear_search (fromArray, size, 8, &numComparisons);
	printf("\nnum of comparisons: %d", numComparisons);*/

	/*int i;
	for (i = 0; i < size; i++){
		temp[i] = fromArray[i];
	}	

	//free(fromArray);
	fromArray = temp;
	size = size * 2; */
	

}
