#include <iostream>
using namespace std;

//Announcing functions
int Rrand(int range_min, int range_max);
void Fill(int A[], unsigned int m);
void Print(int A[], unsigned int m);
void Unique(int A[], unsigned int m);
void Sort(int A[], unsigned int m);

const int RAND = 10;

int main()
{
	//Create a dynamic array
	int m;
	cout << "Enter the size of the array: ";
	cin >> m;
	if (m <= 0)
	{
		cerr << "Invalid size" << endl;
		return 1;
	}
	int* A = new int[m];
	cout << endl;

	//Fill the array with pseudorandom numbers and output it
	Fill(A, m);
	cout << "Generated array: ";
	Print(A, m);

	//Calculate and output the number of different array numbers
	Unique(A, m);

	//Sort and output the sorted array
	Sort(A, m);
	cout << "Sorted array: ";
	Print(A, m);

	//Free the allocated memory for the dynamic array
	delete[] A;
}

int Rrand(int range_min, int range_max)
{
	static unsigned int rand = 9999;
	rand = (9999999 * rand + 9999999);
	return rand % (range_max - range_min + 1) + range_min;
}

void Fill(int A[], unsigned int m)
{
	for (int i = 0; i < m; i++)
	{
		A[i] = Rrand(-RAND, RAND);
	}
}

void Print(int A[], unsigned int m)
{
	for (int i = 0; i < m; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}

void Unique(int A[], unsigned int m)
{
	unsigned int counter = 0;
	for (int i = 0; i < m; i++)
	{
		bool isUnique = true;
		for (int j = i + 1; j < m; ++j)
		{
			isUnique = isUnique && (A[i] != A[j]);
		}
		if (isUnique)
			counter++;
	}
	cout << "There are " << counter << " different numbers in the generated array: ";
	for (int i = 0; i < m; i++)
	{
		bool isUnique = true;
		for (int j = i + 1; j < m; ++j)
		{
			isUnique = isUnique && (A[i] != A[j]);
		}
		if (isUnique)
			cout << A[i] << " ";
	}
	cout << endl;
}

void Sort(int A[], unsigned int m)
{
	int temp = 0;
	for (int i = 0; i < m - 1; i++)
	{
		for (int j = m - 1; j > i; j--)
		{
			if (A[j] > A[j - 1])
			{
				temp = A[j - 1];
				A[j - 1] = A[j];
				A[j] = temp;
			}
		}
	}
}
