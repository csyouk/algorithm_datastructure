import sys
from random import randint

DATA_LEN = 20000

f = open("test_data.txt", 'w')
sys.stdout = f
# print(DATA_LEN)
for _ in range(1, DATA_LEN + 1):
    print(randint(-DATA_LEN, DATA_LEN), end = " ")

f.close()
