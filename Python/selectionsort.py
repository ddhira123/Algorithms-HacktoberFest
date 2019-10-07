def sort(num):
    for i in range(0, len(nums)):
        lowest_value = i

        for j in range(i + 1, len(num)):
            if num[j] < num[lowest_value]:
                lowest_value = j
        num[i], num[lowest_value] = num[lowest_value], num[i]


nums = [10, 3, 45, 6, 5, 8, 30, 26, 16, 2, 12, 17, 9 ]

sort(nums)

print(nums)
