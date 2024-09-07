def split_and_sort(nums):

    # check input list length 
    if len(nums) > 20:
        return "Error: Input list should contain less number integers."

    # check if 0 is in the input list
    if 0 in nums:
        return "Error: The number 0 is not a valid input."

    # filter numbers into two separate lists
    pos_nums = [num for num in nums if num > 0]
    neg_nums = [num for num in nums if num < 0]

    # sort
    neg_nums = sorted(neg_nums)
    pos_nums = sorted(pos_nums)

    print("Positive numbers:", pos_nums)
    print("Negative numbers:", neg_nums)

    return neg_nums, pos_nums

