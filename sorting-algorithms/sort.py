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
    print("done!")

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


def quick_sort(arr):
    raise("Not yet implemented")

# command : python sort.py ALGORITHM_NAME
# ex : python sort.py bubble
if __name__ == '__main__':
    main()
    print("start %s sort" % (sys.argv[1]))
    startTime = time.time()
    eval(sys.argv[1] + "_sort(data)")
    # quick_sort(data)
    endTime = time.time()
    print("execution time : ", endTime - startTime)



# selection sort time for 10000 data : 14.92385
#    bubble sort time for 10000 data : 20.977199
# insertion sort time for 10000 data : 9.346534490

# selection sort time for 20000 data : 57.98831677
#    bubble sort time for 20000 data : 87.0769805
# insertion sort time for 20000 data : 33.8139338
