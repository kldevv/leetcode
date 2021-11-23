'''
Number: 4
Topic: Median of Two Sorted Arrays
Date: 2021/5/4
Rate: Hard

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
'''

# 參照
# https://leetcode.com/problems/median-of-two-sorted-arrays/discuss/2481/Share-my-O(log(min(mn)))-solution-with-explanation
class Solution:
    def findMedianSortedArrays(self, nums1: [int], nums2: [int]) -> float:
        len_short, len_long = len(nums1), len(nums2)
        # 確定哪個 array 長，哪個短
        if len_short <= len_long:
            short_arr, long_arr = nums1, nums2
        else:
            return self.findMedianSortedArrays(num2, num1)

        # 我們要找的就是一個 i ，這個 i 是一個在於 short_arr 裡的切割點
        # 這個切割點會把 short_arr 分成 short_arr[0],..,short_arr[i-1] 和 short[i],...,short[len_short]
        # 前面那一部分會是在 smaller_half 裡面
        # 可能的解會是在[0, len_short]
        imin, imax = 0, len_short

        # 中位數把一個 array 切成兩部分， smaller_half 和 bigger_half
        # 而 (1) smaller_half 裡的 max 會小於 bigger_half 裡的 min
        # 又 (2) len(smaller_half) = len(bigger_half) (或 len(bigger_half) + 1，當有基數個 elemenet，我們讓 smaller_half 多一個)
        len_smaller_half = (len_short+len_long+1) // 2

        # 在 [0, len_short] 裡做 binary search
        while imin <= imax:
            i = imin + (imax-imin)//2
            j = len_smaller_half - i
            # i 決定了 short_arr 裡面有幾個 element 要放進 smaller_half 裡
            # 而因為我們知道 len(smaller_half)，我們可以推出 j ，也就是 long_arr 裡面要有多少個 element 丟進去 smaller_half
            
            # 當 i 不是範圍的極值，而 short[i](應該放進 bigger_half 裡的 short_arr 的最小值) 小於 long_arr[j-1] (應該放進 smaller_half 裡的 long_arr 的最大值)
            # 代表 short[i] 太小了， i 要變大
            if i < len_short and long_arr[j-1] > short_arr[i]:
                imin = i + 1
            # 反之亦然
            elif i > 0 and long_arr[j] < short_arr[i-1]:
                imax = i - 1
            # 遇到極值或是符合條件 (1)(2)（看上方）時，我們拿到了正確的 i
            else:
                if i == 0: 
                    max_of_left = long_arr[j-1]
                elif j == 0 : 
                    max_of_left = short_arr[i-1]
                else: 
                    max_of_left = max(long_arr[j-1], short_arr[i-1])
                # 當有基數個 element 時，中位數會是在 smaller_half 裡面
                if (len_long+len_short) % 2 == 1:
                    return max_of_left

                if i == len_short:
                    min_of_right = long_arr[j]
                elif j == len_long:
                    min_of_right = short_arr[i]
                else:
                    min_of_right = min(long_arr[j], short_arr[i])
                # 當有偶數個 element 時，中位數會是在 smaller_half 裡面的最大值和 bigger_half 裡的最小值的平均
                return (max_of_left+min_of_right) / 2
'''
grade / pass
tc / Olog(min(m, n))
sc / O(1)
'''