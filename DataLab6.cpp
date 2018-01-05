#include <iostream>
#include <time.h> 
#include <iomanip>
using namespace std;

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void partition(int a[], int l, int r, int &i, int &j)
{
	i = l - 1, j = r;
	int p = l - 1, q = r;
	int v = a[r];

	while (true)
	{
		// From left, find the first element greater than
		// or equal to v. This loop will definitely terminate
		// as v is last element
		while (a[++i] < v);

		// From right, find the first element smaller than or
		// equal to v
		while (v < a[--j])
			if (j == l)
				break;

		// If i and j cross, then we are done
		if (i >= j) break;

		// Swap, so that smaller goes on left greater goes on right
		swap(a[i], a[j]);

		// Move all same left occurrence of pivot to beginning of
		// array and keep count using p
		if (a[i] == v)
		{
			p++;
			swap(a[p], a[i]);
		}

		// Move all same right occurrence of pivot to end of array
		// and keep count using q
		if (a[j] == v)
		{
			q--;
			swap(a[j], a[q]);
		}
	}

	// Move pivot element to its correct index
	swap(a[i], a[r]);

	// Move all left same occurrences from beginning
	// to adjacent to arr[i]
	j = i - 1;
	for (int k = l; k < p; k++, j--)
	{
		swap(a[k], a[j]);
	}

	// Move all right same occurrences from end
	// to adjacent to arr[i]
	i = i + 1;
	for (int k = r - 1; k > q; k--, i++)
	{
		swap(a[i], a[k]);
	}
}

// 3-way partition based quick sort
void Quick(int a[], int l, int r) //O(nlogn)
{
	if (r <= l) return;

	int i, j;

	// Note that i and j are passed as reference
	partition(a, l, r, i, j);

	// Recur
	Quick(a, l, j);
	Quick(a, i, r);
}
void selection(int arr[], int n) //O(n^2) T(n)=6n^2+2n
{
	int i, j, min_idx;

	// One by one move boundary of unsorted subarray
	for (i = 0; i < n - 1; i++)
	{
		// Find the minimum element in unsorted array
		min_idx = i;
		for (j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[min_idx])
			{
				min_idx = j;
			}
		}
		// Swap the found minimum element with the first element
		swap(&arr[min_idx], &arr[i]);
	}
}
void insertion(int arr[], int n) //O(n^2) T(n)=3n^2+6n
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}
void shell(int arr[], int n) //O(n^2)
{
	// Start with a big gap, then reduce the gap
	for (int gap = n / 2; gap > 0; gap /= 2)
	{
		// Do a gapped insertion sort for this gap size.
		// The first gap elements a[0..gap-1] are already in gapped order
		// keep adding one more element until the entire array is
		// gap sorted 
		for (int i = gap; i < n; i += 1)
		{
			// add a[i] to the elements that have been gap sorted
			// save a[i] in temp and make a hole at position i
			int temp = arr[i];

			// shift earlier gap-sorted elements up until the correct 
			// location for a[i] is found
			int j;
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
			{
				arr[j] = arr[j - gap];
			}

			//  put temp (the original a[i]) in its correct location
			arr[j] = temp;
		}
	}

}

void bubble(int arr[], int n) //O(n^2) T(n)=6n^2+2n
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	{

		// Last i elements are already in place   
		for (j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}
void print(double dur[5][3])
{
	int a[] = { 1000,10000, 100000 };
	char* b[5] = { "Bubble Sort","Selection Sort","Insertion Sort","Quick Sort","Shell Sort" };
	for (int i = 0; i < 5; i++)
	{
		if (i == 0)
		{
			cout <<setw(20) << " ";
			for (int k = 0; k < 3; k++)
			{
				cout << a[k] << "      ";
			}
			cout << endl;
		}
		cout << setw(14) << b[i];
		for (int j = 0; j < 3; j++)
		{

			cout << setw(11) << dur[i][j];
		}
		cout << endl;
	}
}
int main()
{
	srand(time(NULL));
	double duration;
	double dur[5][3];
	int a[1000], b[10000], c[100000];
	int tmp1[1000], tmp2[10000], tmp3[100000];
	clock_t timeStart, timeEnd;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			dur[5][3] = 0;
		}

	}
	for (int i = 0; i < 1000; i++)
	{
		a[i] = rand() % 100 + 1;
	}
	for (int i = 0; i < 10000; i++)
	{
		b[i] = rand() % 100 + 1;
	}
	for (int i = 0; i < 100000; i++)
	{
		c[i] = rand() % 100 + 1;
	}

	for (int i = 0; i < 5; i++)
	{


		if (i == 0)
		{
			for (int j = 0; j < 1000; j++)
			{
				tmp1[j] = a[j];
			}
			timeStart = clock();
			bubble(tmp1, 1000);
			timeEnd = clock();
			duration = (double)(timeEnd - timeStart) / CLOCKS_PER_SEC;
			dur[0][0] = duration;
		}
		if (i == 1)
		{
			for (int j = 0; j < 1000; j++)
			{
				tmp1[j] = a[j];
			}
			timeStart = clock();
			selection(tmp1, 1000);
			timeEnd = clock();
			duration = (double)(timeEnd - timeStart) / CLOCKS_PER_SEC;
			dur[1][0] = duration;
		}
		if (i == 2)
		{
			for (int j = 0; j < 1000; j++)
			{
				tmp1[j] = a[j];
			}
			timeStart = clock();
			insertion(tmp1, 1000);
			timeEnd = clock();
			duration = (double)(timeEnd - timeStart) / CLOCKS_PER_SEC;
			dur[2][0] = duration;
		}
		if (i == 3)
		{
			for (int j = 0; j < 1000; j++)
			{
				tmp1[j] = a[j];
			}
			timeStart = clock();
			Quick(tmp1, 0, 999);
			timeEnd = clock();
			duration = (double)(timeEnd - timeStart) / CLOCKS_PER_SEC;
			dur[3][0] = duration;
		}
		if (i == 4)
		{

			for (int j = 0; j < 1000; j++)
			{
				tmp1[j] = a[j];
			}
			timeStart = clock();
			shell(tmp1, 1000);
			timeEnd = clock();
			duration = (double)(timeEnd - timeStart) / CLOCKS_PER_SEC;
			dur[4][0] = duration;
		}

	}
	for (int i = 0; i < 5; i++)
	{
		if (i == 0)
		{
			for (int j = 0; j < 10000; j++)
			{
				tmp2[j] = b[j];
			}
			timeStart = clock();
			bubble(tmp2, 10000);
			timeEnd = clock();
			duration = (double)(timeEnd - timeStart) / CLOCKS_PER_SEC;
			dur[i][1] = duration;
		}
		if (i == 1)
		{
			for (int j = 0; j < 10000; j++)
			{
				tmp2[j] = b[j];
			}
			timeStart = clock();
			selection(tmp2, 10000);
			timeEnd = clock();
			duration = (double)(timeEnd - timeStart) / CLOCKS_PER_SEC;
			dur[i][1] = duration;
		}
		if (i == 2)
		{
			for (int j = 0; j < 10000; j++)
			{
				tmp2[j] = b[j];
			}
			timeStart = clock();
			insertion(tmp2, 10000);
			timeEnd = clock();
			duration = (double)(timeEnd - timeStart) / CLOCKS_PER_SEC;
			dur[i][1] = duration;
		}
		if (i == 3)
		{
			for (int j = 0; j < 10000; j++)
			{
				tmp2[j] = b[j];
			}
			timeStart = clock();
			Quick(tmp2, 0, 9999);
			timeEnd = clock();
			duration = (double)(timeEnd - timeStart) / CLOCKS_PER_SEC;
			dur[i][1] = duration;
		}
		if (i == 4)
		{
			for (int j = 0; j < 10000; j++)
			{
				tmp2[j] = b[j];
			}
			timeStart = clock();
			shell(tmp2, 10000);
			timeEnd = clock();
			duration = (double)(timeEnd - timeStart) / CLOCKS_PER_SEC;
			dur[i][1] = duration;
		}

	}
	for (int i = 0; i < 5; i++)
	{
		if (i == 0)
		{
			for (int j = 0; j < 100000; j++)
			{
				tmp3[j] = c[j];
			}
			timeStart = clock();
			/*bubble(tmp3, 100000);*/
			timeEnd = clock();
			duration = (double)(timeEnd - timeStart) / CLOCKS_PER_SEC;
			dur[i][2] = duration;
		}
		if (i == 1)
		{
			for (int j = 0; j < 100000; j++)
			{
				tmp3[j] = c[j];
			}
			timeStart = clock();
			selection(tmp3, 100000);
			timeEnd = clock();
			duration = (double)(timeEnd - timeStart) / CLOCKS_PER_SEC;
			dur[i][2] = duration;
		}
		if (i == 2)
		{
			for (int j = 0; j < 100000; j++)
			{
				tmp3[j] = c[j];
			}
			timeStart = clock();
			insertion(tmp3, 100000);
			timeEnd = clock();
			duration = (double)(timeEnd - timeStart) / CLOCKS_PER_SEC;
			dur[i][2] = duration;
		}
		if (i == 3)
		{

			for (int j = 0; j < 100000; j++)
			{
				tmp3[j] = c[j];
			}
			timeStart = clock();
			Quick(tmp3, 0, 99999);
			timeEnd = clock();
			duration = (double)(timeEnd - timeStart) / CLOCKS_PER_SEC;
			dur[i][2] = duration;
		}
		if (i == 4)
		{
			for (int j = 0; j < 100000; j++)
			{
				tmp3[j] = c[j];
			}
			timeStart = clock();
			shell(tmp3, 100000);
			timeEnd = clock();
			duration = (double)(timeEnd - timeStart) / CLOCKS_PER_SEC;
			dur[i][2] = duration;
		}

	}
	print(dur);
	system("pause");
}