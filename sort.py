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
    for i in range(0, len(arr)):
        j = 0
        t = 0
        for _ in range(0, len(arr) - 1 - i):
            # 내림차순
            if arr[t] > arr[j+1]: t = j+1
            j += 1
        if t is not j:
            tmp = arr[t]
            arr[t] = arr[j]
            arr[j] = tmp


if __name__ == '__main__':
    main()
    # print("arg : ", sys.argv)
    if(sys.argv[1] == "bubble"):
        print("start bubble sort")
        startTime = time.time()
        bubble_sort(data)
        endTime = time.time()
        print("execution time : ", endTime - startTime)
        # represent()

    if(sys.argv[1] == "selection"):
        print("start selection sort")
        startTime = time.time()
        selection_sort(data)
        endTime = time.time()
        print("execution time : ", endTime - startTime)
        # represent()


# selection sort time for 10000 data : 14.92385
#    bubble sort time for 10000 data : 20.977199

# selection sort time for 20000 data : 57.98831677
#    bubble sort time for 20000 data : 87.0769805
