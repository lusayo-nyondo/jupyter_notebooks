import heapq

array = [
    1, 2, 4, 3, 21, 12, 5, 23, 8, 6, 7, 9, 11, 15
]

heapq.heapify(array)
print(array)

heapq.heappop(array)
print(array)

heapq.heappush(array, 13)
print(array)
