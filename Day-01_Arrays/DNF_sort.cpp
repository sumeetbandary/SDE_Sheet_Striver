/*
    problem link: 
    https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1
    https://leetcode.com/problems/sort-colors/
    
    YouTube link:
    https://www.youtube.com/watch?v=oaVa-9wmpns&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=3
*/ 

 /* 
    Using the sorting function 
    TC - O(nlogn)
    SC - O(n)
*/
void sort012(int a[], int n)
{
    // Using STL sort function
    sort(a,a+n);
}

/*
    Using Counting Method
    Count no of 0s, 1s and 2s and then insert in the array
    TC - O(2n)
    SC - O(1)
*/
void sort012(int a[], int n)
{
    int count0=0,count1=0,count2=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==0)
            count0++;
        else if(a[i]==1)
            count1++;
        else
            count2++;
    }
    int x=0;
    for(int i=1;i<=count0;i++)
    {
        a[x]=0;
        x++;
    }
    for(int i=1;i<=count1;i++)
    {
        a[x]=1;
        x++;
    }
    for(int i=1;i<=count2;i++)
    {
        a[x]=2;
        x++;
    } 
}

/*
    Using Dutch National Flag 
    Three pointers low, mid and high
    TC - O(n)
    SC - O(1)
*/
void sortColors(vector<int>& nums) 
    {
        //region of 0s{0, low}, region of 1s{low, mid}, region of 2s{high, n - 1}
        //uncertain region or unsorted region{mid, high}.
        //we need to shrink this region{mid, high}.
        int n = nums.size();
        int low = 0, mid = 0, high = n - 1;
        while(mid <= high) {
            if(nums[mid] == 0) 
                swap(nums[mid++], nums[low++]);
            else if(nums[mid] == 1)
                mid++;
            else
                swap(nums[mid], nums[high--]);
        }
    }


