class Solution:
    # @param nums, a list of integer
    # @param k, num of steps
    # @return nothing, please modify the nums list in-place.
    def rotate(self, nums, k):
        len_nums = len(nums)
        nums[0:0] = nums[len_nums - k:len_nums]
        del nums[len_nums:len_nums + k]
