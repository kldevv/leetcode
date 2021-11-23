/*
Number: 1570
Topic: Dot Product of Two Sparse Vectors
Date: 2021/7/30
Rate: Medium
https://leetcode.com/problems/dot-product-of-two-sparse-vectors/

Given two sparse vectors, compute their dot product.

Implement class SparseVector:

SparseVector(nums) Initializes the object with the vector nums
dotProduct(vec) Compute the dot product between the instance of SparseVector and vec
A sparse vector is a vector that has mostly zero values, you should store the sparse vector efficiently and compute the dot product between two SparseVector.

Follow up: What if only one of the vectors is sparse?

Constraints:
* n == nums1.length == nums2.length
* 1 <= n <= 10^5
* 0 <= nums1[i], nums2[i] <= 100
*/

class SparseVector {
private:
    vector<int> idx;
    vector<int> val;
    int len;
public:
    
    SparseVector(vector<int> &nums) {
        this->len = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]) {
                this->idx.push_back(i);
                this->val.push_back(nums[i]);
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        if (this->len != vec.len)
            return -1;

        int out = 0;
        int nextNoZero1 = 0;
        int nextNoZero2 = 0;
        while (nextNoZero1 < this->idx.size() && nextNoZero2 < vec.idx.size()) {
            if (this->idx[nextNoZero1] == vec.idx[nextNoZero2])
                out += this->val[nextNoZero1++] *  vec.val[nextNoZero2++];
            else if (this->idx[nextNoZero1] < vec.idx[nextNoZero2])
                nextNoZero1++;
            else
                nextNoZero2++;
        }
        return out;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);