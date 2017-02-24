#include<iostream>
using namespace std;
int findMidPosition(int arr[], int lo, int hi) {
	int mid = (hi - lo) / 2 + lo;
	if(arr[mid] > arr[mid+1]) return mid;
	if(arr[mid] <= arr[hi]) {
		findMidPosition(arr, lo, mid-1);
	}
	else {
		findMidPosition(arr, mid+1, hi);
	}
}

int bin_search(int arr[], int key, int lo, int hi) {
	int mid = lo + (hi-lo)/2;
//	cout<<"arr[lo] "<<arr[lo]<<" ";
//	cout<<"arr[mid] "<<arr[mid]<<" key:"<<key;
//	cout<<" arr[hi] "<<arr[hi]<<" "<<endl;
	if(arr[lo] == key) {
		return lo;
	}
	if(hi == mid) {
		return -1;
	}
	if(arr[mid] < key) {
		bin_search(arr, key, mid+1, hi);
	} else {
		bin_search(arr, key, lo, mid);
	}
}

int findX(int arr[],int key, int lo, int hi ) {
	int mid = findMidPosition(arr, lo,hi);
	int firstHalf = bin_search(arr, key, lo, mid);
	int secondHalf = bin_search(arr, key, mid+1, hi);
	if(firstHalf >= 0) {
		return firstHalf;
	}
	if(secondHalf >= 0) {
		return secondHalf;
	}
	return -1;
}

int main() {
	int arr[] = {8,9,1,2,3,4,5,6,6,7};
	int len =11;
	cout<<findX(arr,7 ,0,9);
	return 0;
}
