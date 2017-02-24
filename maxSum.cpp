#include <iostream>
using namespace std;

int findMaxSum(int arr[], int left, int right, int daysPassed) {
	if(left == right) {
		return arr[left] * daysPassed;
	}
	int leftValueItem = findMaxSum(arr,left+1, right, daysPassed + 1) + arr[left] *daysPassed;
	int rightValueItem = findMaxSum(arr, left, right - 1, daysPassed + 1) + arr[right] * daysPassed;
	return leftValueItem > rightValueItem ? leftValueItem : rightValueItem;
}

int sum[100][100];

int dp(int arr[], int left,int right, int n) {
	if(sum[left][right] > 0) {
		return sum[left][right];
	}
	if(left == right) {
		sum[left][right] = arr[left] * (n - right + left);
		return sum[left][right];
	}
	int leftSum = dp(arr, left + 1 , right, n) + arr[left] * (n - right + left);
	int rightSum = dp(arr, left , right - 1 , n) + arr[right] * (n - right + left);
	sum[left][right] = (leftSum > rightSum ? leftSum: rightSum);
	return sum[left][right];
}

int main() {
	// your code goes here
	int arr[]= {10,2, 4, 6, 7, 8,1};
	cout<<findMaxSum(arr, 0, 6, 1)<<endl;
	cout<<dp(arr, 0, 6, 7);
	return 0;
}
