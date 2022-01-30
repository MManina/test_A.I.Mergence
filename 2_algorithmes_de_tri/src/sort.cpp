#include "sort.h"

using namespace std;

void swap(std::string& tab, int i, int j){
	char tmp = tab[i];
	tab[i] = tab[j];
	tab[j] = tmp;
}

// Place each value inferior to the pivot to its left and each value superior to the pivot to its right
int partition(std::string& tab, int first, int last, int pivot){
	swap(tab, pivot, last);
	int j = first;
	for(int i=first; i<last; i++){
		if(tab[i] <= tab[last]){
			swap(tab, i, j);
			j++;
		}
	}
	swap(tab, last, j);
	return j;
}

int getPivot(int first, int last){
	// Randomly get a number between first and last
	return rand() % (last-first) + first;
}

void quickSort(std::string& tab, int first, int last){
	int pivot;
	if(first < last){
		pivot = getPivot(first, last);
		pivot = partition(tab, first, last, pivot);
		quickSort(tab, first, pivot-1);
		quickSort(tab, pivot+1, last);
	}
}
