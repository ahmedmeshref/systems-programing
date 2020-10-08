#include <stdio.h>
#include <stdbool.h>
#include <math.h>

const int MAX = 6;
bool linear_search (int arr[], int tar);
int binary_search (int arr[], int len_arr, int tar);

int main (void) 
{
	// get a number from the user, return True if num in array, False otherwise
	int arr[] = {1, 2, 3, 4, 5, 6};
	int num_1 = 10, num_2 = 3; 
	if (linear_search(arr, num_2)) {
		printf("%s\n", "true");
	} else {
		printf("%s\n", "false");
	}
	printf("%d\n", binary_search(arr, MAX, num_2));
	return 0;
}


bool linear_search (int arr[], int tar)
{
	for (int i = 0; arr[i] != '\0'; i++){
		if (arr[i] == tar) {
			return true;
		}
	}
	return false;
}

int binary_search (int arr[], int len_arr, int tar)
{
	int i = 0, j = len_arr, mid; 
	while (i <= j){
		mid = i + (j - i) / 2; 
		if (arr[mid] == tar) return mid;
		else if (arr[mid] > tar) j = mid - 1;
		else i = mid + 1;
	}
	return -1;
}