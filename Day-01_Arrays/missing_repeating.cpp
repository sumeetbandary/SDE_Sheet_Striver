/*
    problem link: 
    https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1
    
    YouTube link:
    https://www.youtube.com/watch?v=5nMGY4VUoRY&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=4
*/

/*
    Method 1 (Use Sorting)
    Approach: 
    * Sort the input array.
    * Traverse the array and check for missing and repeating.
    TC - O(nlogn)
    SC - O(1)
*/

/*
    Method 2 (Use count array)
    Approach: 
    Create a temp array temp[] of size n with all initial values as 0.
    Traverse the input array arr[], and do following for each arr[i] 
    if(temp[arr[i]] == 0) temp[arr[i]] = 1;
    if(temp[arr[i]] == 1) output “arr[i]” //repeating
    Traverse temp[] and output the array element having value as 0 (This is the missing element)
    TC - O(2n)
    SC - O(n)
*/

/*
    Method 3 (Using two equations)
    https://www.geeksforgeeks.org/find-the-repeating-and-the-missing-number-using-two-equations/
    Note: This method can cause arithmetic overflow as we calculate product and sum of all array elements.
    TC - O(n)
    SC - O(1)
*/
void findNumbers(int arr[], int n)
    {
 
        // Sum of first n natural numbers
        int sumN = (n * (n + 1)) / 2;
 
        // Sum of squares of first n natural numbers
        int sumSqN = (n * (n + 1) * (2 * n + 1)) / 6;
 
        // To store the sum and sum of squares
        // of the array elements
        int sum = 0, sumSq = 0, i;
 
        for (i = 0; i < n; i++) {
            sum += arr[i];
            sumSq = sumSq + (pow(arr[i], 2));
        }
 
        int B = (((sumSq - sumSqN) / (sum - sumN)) + sumN - sum) / 2;
        int A = sum - sumN + B;
         cout << "A = " ;
         cout << A << endl;
         cout << "B = " ;
         cout << B << endl;
    }


    



