#include <iostream>
#include <vector>

using namespace std;

// Initialize the array with random values between min and max
void initMasRandom(vector<int>& mas, int min = 0, int max = 10) {
   for (size_t i = 0; i < mas.size(); ++i) {
      mas[i] = rand() % (max - min + 1) - min;
   }
}

// Print the array
void printMas(const vector<int>& mas) {
   for (size_t i = 0; i < mas.size(); ++i) {
      cout << "mas [ " << i << " ] = " << mas[i] << "\n";
   }
}

// Merge function for Merge Sort
void merge(vector<int>& mas, int left, int mid, int right) {
   int n1 = mid - left + 1;
   int n2 = right - mid;

   // Create temporary vectors
   vector<int> L(n1), R(n2);

   // Copy data to temporary vectors L[] and R[]
   for (int i = 0; i < n1; i++)
      L[i] = mas[left + i];
   for (int i = 0; i < n2; i++)
      R[i] = mas[mid + 1 + i];

   // Merge the temporary vectors back into mas[left..right]
   int i = 0, j = 0, k = left;
   while (i < n1 && j < n2) {
      if (L[i] <= R[j]) {
         mas[k] = L[i];
         i++;
      }
      else {
         mas[k] = R[j];
         j++;
      }
      k++;
   }

   // Copy the remaining elements of L[], if any
   while (i < n1) {
      mas[k] = L[i];
      i++;
      k++;
   }

   // Copy the remaining elements of R[], if any
   while (j < n2) {
      mas[k] = R[j];
      j++;
      k++;
   }
}

// Merge Sort function
void mergeSort(vector<int>& mas, int left, int right) {
   if (left < right) {
      int mid = left + (right - left) / 2;

      // Recursively sort first and second halves
      mergeSort(mas, left, mid);
      mergeSort(mas, mid + 1, right);

      // Merge the sorted halves
      merge(mas, left, mid, right);
   }
}

int main() {
   const int size = 10;
   vector<int> mas(size);

   // Initialize the array with random values
   initMasRandom(mas);

   // Call Merge Sort
   mergeSort(mas, 0, size - 1);

   // Print the array after sorting
   printMas(mas);

   return 0;
}
