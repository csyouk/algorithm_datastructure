#-*- coding: utf-8 -*-

import sys, time
data = []
def main():
    global data
    # inject data
    with open("test_data.txt") as td:
        for value in td:
            data = value
        data = data.split(" ")
        data.pop()
        data = [int(i) for i in data]
    print("data injection done!")

def represent():
    print(data)

def bubble_sort(arr):
    tmp = 0
    for i in range(0, len(arr), 1):
        for j in range(0, len(arr) - 1 - i):
            if arr[j] > arr[j+1]:
                tmp = arr[j]
                arr[j] = arr[j+1]
                arr[j+1] = tmp

def selection_sort(arr):
    tmp = 0
    # arr = [33,7,2,3,-3,0]
    for i in range(0, len(arr)):
        j = 0
        t = 0
        for _ in range(0, len(arr) - 1 - i):
            if arr[j+1] > arr[t]: t = j+1
            j += 1
        if t is not j:
            tmp = arr[t]
            arr[t] = arr[j]
            arr[j] = tmp

def insertion_sort(arr):
    tmp = 0
    # arr = [33,7,2,3,-3,0, -2,-9, 100]
    for i in range(1, len(arr)-1):
        for j in range(0, i):
            if arr[j] > arr[i]: break;
        tmp = arr[i]
        for k  in range(i, j, -1):
            arr[k] = arr[k-1]
        arr[j] = tmp
        # print(arr, tmp, i, j, k)
    # print(arr)


def quick_sort(arr, start, end):
    tmp = 0
    pivot = end
    target = start
    if(end <= start): return
    for left in range(start, end+1):
        if(arr[pivot] > arr[left]):
            if(left != target):
                tmp = arr[left]
                arr[left] = arr[target]
                arr[target] = tmp
            target += 1
    if target < pivot:
        tmp = arr[pivot]
        arr[pivot] = arr[target]
        arr[target] = tmp
    quick_sort(arr, start, target - 1)
    quick_sort(arr, target + 1, end)
    # print(arr)

# command : python sort.py ALGORITHM_NAME
# ex : python sort.py bubble
if __name__ == '__main__':
    main()
    print("start %s sort algorithm for %d data" % (sys.argv[1], len(data)))
    startTime = time.time()
    algorithm = sys.argv[1]
    if(algorithm == "quick"):
        # quick sort의 stack overflowr가 날 수 있어서, 이렇게 설정을 풀어줘야 한다.
        sys.setrecursionlimit(100000)
        # data = [10,9,8,7,33,6,5,4,3,2,1,-1]
        quick_sort(data, 0,len(data)-1);
        # print(data)
    else:
        eval(algorithm + "_sort(data)")
    # quick_sort(data)
    endTime = time.time()
    print("execution time : ", endTime - startTime)

'''
# Bench mark @ window

>>>> CPU :
>>>> RAM :

   bubble sort time for 10000 data : 20.977199
selection sort time for 10000 data : 14.92385
insertion sort time for 10000 data : 9.346534490
    quick sort time for 10000 data : 

   bubble sort time for 20000 data : 87.0769805
selection sort time for 20000 data : 57.98831677
insertion sort time for 20000 data : 33.8139338
    quick sort time for 20000 data :
'''


'''
# Bench mark @ Macintishi

>>>> CPU : 2 GHz Intel Core i5
>>>> RAM : 16GB 1867 MHz LPDDR3

   bubble sort time for 10000 data : 7.007555961608887
selection sort time for 10000 data : 4.786497116088867
insertion sort time for 10000 data : 3.345464944839477
    quick sort time for 10000 data : 0.02640700340270996

   bubble sort time for 20000 data : 29.793501138687134
selection sort time for 20000 data : 18.135602951049805
insertion sort time for 20000 data : 15.205499172210693
    quick sort time for 20000 data : 0.059430837631225586
'''
