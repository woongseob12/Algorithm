#include <iostream>
#include <vector>
using namespace std;

int arr[] = { 5, 3, 8, 4, 9 ,1, 2, 7 };
vector<int> sorted;

void quickSort(int l, int r);
void partition(int l, int r);
void merge(int l, int r);
void insertionSort();
void heapify(int len, int parent);
void heapSort();

int main() {
	int len = sizeof(arr) / sizeof(arr[0]);
	//quickSort(0, len -1);
	sorted.resize(len);
	//partition(0, len - 1);
	//insertionSort();
	heapSort();
	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
}

void quickSort(int l, int r) {
	if (l >= r) return;
	int pivot = l, start = l + 1, end = r;
	while (start < end) {
		while (start <= r && arr[pivot] >= arr[start]) {
			start++;
		}
		while (end > l && arr[pivot] <= arr[end]) {
			end--;
		}
		if (start <= end) {
			swap(arr[start], arr[end]);
		}
		else {
			swap(arr[pivot], arr[end]);
		}
	}

	quickSort(l, end - 1);
	quickSort(end + 1, r);
}

void partition(int l, int r) {
	if (l < r) {
		int mid = (l + r) / 2;
		partition(l, mid);
		partition(mid + 1, r);
		merge(l, r);
	}
}

void merge(int l, int r) {
	int mid = (l + r) / 2;
	int i = l, j = mid + 1, k = l;
	while (i <= mid && j <= r) {
		if (arr[i] < arr[j]) {
			sorted[k++] = arr[i++];
		}
		else {
			sorted[k++] = arr[j++];
		}
	}
	
	int temp = i > mid ? j : i;
	while (k <= r) {
		sorted[k++] = arr[temp++];
	}

	for (int idx = l; idx <= r; idx++) {
		arr[idx] = sorted[idx];
	}
}

void insertionSort() {
	int len = sizeof(arr) / sizeof(arr[0]);

	for (int i = 1; i < len; i++) {
		int key = arr[i], j;
		for (j = i - 1; j >= 0; j--) {
			if (arr[j] <= key) break;
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = key;
	}
}

void heapSort() {
	int len = sizeof(arr) / sizeof(arr[0]);
	for (int i = len / 2 - 1; i >= 0; i--) {
		heapify(len, i);
	}
	for (int i = len - 1; i >= 0; i--) {
		swap(arr[0], arr[i]);
		heapify(i, 0);
	}
}

void heapify(int len, int parent) {
	int root = parent;
	int l = 2 * parent + 1;
	int r = 2 * parent + 2;

	if (l < len && arr[l] > arr[root]) {
		root = l;
	}
	if (r < len && arr[r] > arr[root]) {
		root = r;
	}

	if (root != parent) {
		swap(arr[parent], arr[root]);
		heapify(len, root);
	}
}