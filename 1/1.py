class Solution:
        # @param {integer[]} nums
        # @param {integer} target
        # @return {integer[]
        def twoSum(self, nums, target):
            mymap = {}
            for i in range(len(nums)):
                if nums[i] in mymap:
                    mymap[nums[i]].append(i+1)
                else:
                    mymap[nums[i]] = [i+1]
            for i in nums:
                j = target - i
                index = mymap.get(j)
                index2= mymap.get(i)
                if index and len(index)>1 and index == index2:
                    return index
                elif index and index[0] != index2[0]:
                    min_val = min(index[0], index2[0])
                    max_val = max(index[0], index2[0])
                    return [min_val, max_val]


if __name__ == '__main__':
    s = Solution()
    print( s.twoSum([-1,-2,-3,-4,-5], -8))
    print( s.twoSum([3,2,4], 6))
    print( s.twoSum([2,7,11,15], 9 ))
    print( s.twoSum([7,11,2,15], 9 ))
    print( s.twoSum([0,1,3,0], 0))


                
