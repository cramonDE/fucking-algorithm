// You are given two sorted arrays, A and B, where A has a large enough buffer at the end to hold B. Write a method to merge B into A in sorted order.

// Initially the number of elements in A and B are m and n respectively.

// Example:

// Input:
// A = [1,2,3,0,0,0], m = 3
// B = [2,5,6],       n = 3

// Output: [1,2,2,3,5,6]

// 归并的过程，由于要节省空间，从最大的数字开始合并，不会溢出数组长度
// 暴力方法，直接合并后重新排序

#include <vector>
using namespace std;
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int index = A.size() - 1;
        m = m - 1;
        n = n - 1;
        while (index != -1)
        {
            if (n == -1 && m != -1) {
                A[index--] = A[m];
                m--;
                continue;
            }
            if (m == -1 && n != -1) {
                A[index--] = B[n];
                n--;
                continue;
            }
            if (A[m] > B[n])
            {
                A[index] = A[m];
                m--;
            }
            else
            {
                A[index] = B[n];
                n--;
            }
            index--;
        }
    }
};

// 该题目应当注意临街条件的判断