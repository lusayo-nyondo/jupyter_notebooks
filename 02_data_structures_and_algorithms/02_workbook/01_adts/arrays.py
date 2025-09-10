def prefix_sum(array):
    psum_array = []

    for i in range(len(array)):
        if i > 0:
            current_sum = psum_array[i - 1]
        else:
            current_sum = 0
        
        psum_array.append(array[i] + current_sum)

    return psum_array

print(
    prefix_sum([1, 2, 3, 4])
)
