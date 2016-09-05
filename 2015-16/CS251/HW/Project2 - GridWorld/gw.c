#include <stdio.h>
#include <stdlib.h>

//int rows; int cols;

typedef struct members
	{
	int mem;
	struct members *next;
	struct members *prev;
	} Mem;

typedef struct district
	{
	int dist_pop;
	Mem *members;
	} Dis;

typedef struct GridWorld
	{
	int population;
	int *notalive;
	Dis* **district;
	} GW;

GW *gw_build(int nrows, int ncols, int pop, int rnd)
	{
	
//	rows = nrows; cols = ncols;
	int k = 0;
	GW *A;	
	
	A = (GW *) malloc(sizeof(GW));
	A->population = pop;
	A->notalive = 0;

//	A->district = (Dis* **) malloc(sizeof(Dis) * nrows * ncols);
	A->district[nrows][ncols];
	A->district[0][0]->dist_pop = pop;

	while(k != pop)
		{
	//	A->district[0][0]->members = (Mem *) malloc(sizeof(Mem));
		A->district[0][0]->members->mem = k + 1;
		A->district[0][0]->members->next;
		k++;
		}

//	if(B == '-rand')
//		{
//		B++;
//		}
	
	return A;

	}


int * gw_members(GW *g, int i, int j, int *n)
	
	{
	
	int *arr; int k = 0;
	arr = (int *) malloc(sizeof(int) * (*n));

	while(k != *n)
	
		{
		arr[k] = g->district[i][j]->members->mem;
		g->district[i][j]->members->next;
		k++;
		}
	
	return arr;

	}





int gw_district_pop(GW *g, int i, int j)

	{
	
	int people = g->district[i][j]->dist_pop;

	return people;

	}


int gw_total_pop(GW *g)

	{
	
	int population = g->population;

	return population;

	}





int main()
	{
	gw_build(5, 5, 10, 0);

	return 0;
	}
