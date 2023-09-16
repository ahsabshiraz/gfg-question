// // Count Occurrence in sorted array
// #include <iostream>
// using namespace std;
// int IfirstOccurance(int arr[], int n, int key) // efficient iterative
// {
//     int low = 0, high = n - 1;
//     int mid;
//     while (low <= high)
//     {
//         mid = (low + high) / 2;
//         if (arr[mid] < key)
//             low = mid + 1;
//         else if (arr[mid] > key)
//             high = mid - 1;
//         else
//         {
//             if (mid == 0 || arr[mid - 1] != arr[mid])
//                 return mid;
//             else
//                 high = mid - 1;
//         }
//     }
//     return -1;
// }
// int lastIndex(int arr[], int n, int key) // iterative
// {
//     int mid, low = 0, high = n - 1;
//     while (low <= high)
//     {
//         mid = (low + high) / 2;
//         if (arr[mid] < key)
//             low = mid + 1;
//         else if (arr[mid] > key)
//             high = mid - 1;
//         else
//         {
//             if (mid == n - 1 || arr[mid + 1] != arr[mid])
//                 return mid;
//             else
//                 low = mid + 1;
//         }
//     }
//     return -1;
// }
// int countOcc(int arr[], int n, int key)
// {
//     int first = IfirstOccurance(arr, n, key);
//     cout<<first;
//     if (first == -1)
//         return 0;
//     else
//         return lastIndex(arr, n, key) - first + 1;
// }

// int main()
// {
//     int arr[] = {2, 3, 4, 5, 6, 6, 6, 6, 6, 6, 7, 7};
//     int n = sizeof(arr) / sizeof(arr[1]);
//     int key = 6;
//     cout<<"q3";
//     cout << countOcc(arr, n, key);
//     return 0;
// }
#include <iostream>
using namespace std;

int firstOcc(int arr[], int n, int x)
{
	int low = 0, high = n - 1;

	while (low <= high)
	{
		int mid = (low + high) / 2;

		if (x > arr[mid])
			low = mid + 1;

		else if (x < arr[mid])
			high = mid - 1;

		else
		{
			if (mid == 0 || arr[mid - 1] != arr[mid])
				return mid;

			else
				high = mid - 1;
		}
	}

	return -1;
}

int lastOcc(int arr[], int n, int x)
{
	int low = 0, high = n - 1;

	while (low <= high)
	{
		int mid = (low + high) / 2;

		if (x > arr[mid])
			low = mid + 1;

		else if (x < arr[mid])
			high = mid - 1;

		else
		{
			if (mid == n - 1 || arr[mid + 1] != arr[mid])
				return mid;

			else
				low = mid + 1;
		}
	}

	return -1;
}

int countOcc(int arr[], int n, int x)
{
	int first = firstOcc(arr, n, x);

	if (first == -1)
		return 0;
	else
		return lastOcc(arr, n, x) - first + 1;
}

int main()
{

	int arr[] = {2, 3, 4, 5, 6, 6, 6, 6, 6, 6, 7, 7};
	int n = sizeof(arr) / sizeof(arr[1]);

	int x = 6;

	cout << countOcc(arr, n, x);

	return 0;
}