/* //Refer Code360 by coding ninjas

Given an array ‘arr’ of integer numbers, ‘arr[i]’ represents the number of pages in the ‘i-th’ book.



There are ‘m’ number of students, and the task is to allocate all the books to the students.



Allocate books in such a way that:

1. Each student gets at least one book.
2. Each book should be allocated to only one student.
3. Book allocation should be in a contiguous manner.


You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum.



If the allocation of books is not possible, return -1.



Example:
Input: ‘n’ = 4 ‘m’ = 2
‘arr’ = [12, 34, 67, 90]

Output: 113

Explanation: All possible ways to allocate the ‘4’ books to '2' students are:

12 | 34, 67, 90 - the sum of all the pages of books allocated to student 1 is ‘12’, and student two is ‘34+ 67+ 90 = 191’, so the maximum is ‘max(12, 191)= 191’.

12, 34 | 67, 90 - the sum of all the pages of books allocated to student 1 is ‘12+ 34 = 46’, and student two is ‘67+ 90 = 157’, so the maximum is ‘max(46, 157)= 157’.

12, 34, 67 | 90 - the sum of all the pages of books allocated to student 1 is ‘12+ 34 +67 = 113’, and student two is ‘90’, so the maximum is ‘max(113, 90)= 113’.

We are getting the minimum in the last case.

Hence answer is ‘113’.
*/

/*
Low (max(arr)): The smallest possible value for the maximum pages is the largest single book, because a student
 must get at least one book, and the maximum pages a student can get must be at least as much as the largest book.

High (sum(arr)): The largest possible value for the maximum pages is the sum of all books, which occurs when one student
 gets all the books.*/

#include <bits/stdc++.h>
using namespace std;

// Linear Search TC=O(Summation-maxEle) * o(n);

int countStudents(vector<int> &arr, int pages)
{
    int n = arr.size(); // size of array.
    int students = 1;
    long long pagesStudent = 0;
    for (int i = 0; i < n; i++)
    {
        if (pagesStudent + arr[i] <= pages)
        {
            // add pages to current student
            pagesStudent += arr[i];
        }
        else
        {
            // add pages to next student
            students++;
            pagesStudent = arr[i];
        }
    }
    return students;
}

int findPages(vector<int> &arr, int n, int m)
{
    // book allocation impossible:
    if (m > n)
        return -1;

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    for (int pages = low; pages <= high; pages++)
    {
        if (countStudents(arr, pages) == m)
        {
            return pages;
        }
    }
    return low; // why we r returning low see the concept in end of the file
}

// Binary Search TC=O(n log(summation-maxEle));

int countStudents(vector<int> &arr, int pages)
{
    int n = arr.size(); // size of array.
    int students = 1;
    long long pagesStudent = 0;
    for (int i = 0; i < n; i++)
    {
        if (pagesStudent + arr[i] <= pages)
        {
            // add pages to current student
            pagesStudent += arr[i];
        }
        else
        {
            // add pages to next student
            students++;
            pagesStudent = arr[i];
        }
    }
    return students;
}

int findPages(vector<int> &arr, int n, int m)
{
    // book allocation impossible:
    if (m > n)
        return -1;

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    int res = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int studCount = countStudents(arr, mid);

        if (studCount > m)
        {
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return low;
}

/*

Suppose if i use this logic :

        int res=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        int studCount=countStudents(arr, mid) ;
        if(studCount==m){
             res=mid;
            high=mid-1;
        }
       else  if(studCount >m){
             low=mid+1;
        }
        else high=mid-1;
    }
    return res;


    for this test Case: [15 10 19 10 5 18 7] k=5 we get res=-1 bcoz
    for this array
    when mid=25    our findStudents function calculates students like by dividing 15,10 ; 19 ; 10,5; 18,7 our max sum here=25 only
    but i can get same 25 with 15;10;19;10,5;18,7 which gives us 5 books its possible right

    thats why we return low

    And when mid=21  its possible to divide array into 6



*/