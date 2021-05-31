import random
import string
import timeit
from matplotlib import pyplot as plt
import numpy as np

# 두 개의 string sequence 입력
# str1 = input()
# str2 = input()

# 문자열의 길이는 10
LENGTH = 25

# 모든 대소문자 저장
string_pool = string.ascii_letters
str1 = ""
str2 = ""

# 랜덤한 문자열 생성
for _ in range(LENGTH):
    str1 += random.choice(string_pool)
    str2 += random.choice(string_pool)

# 입력 받은 두 string sequence 의 길이
length1 = len(str1)
length2 = len(str2)
start_time = timeit.default_timer()
# 모든 값이 0 으로 된 가로 length2+1, 세로 length+1 길이의 2차원 리스트 선언
LCS = [[0]*(length2+1) for _ in range(length1+1)]

for i in range(1, length1 + 1):
    for j in range(1, length2+1):
        if str1[i-1] == str2[j-1]:
            LCS[i][j] = LCS[i-1][j-1]+1
        else:
            LCS[i][j] = max(LCS[i -1][j], LCS[i][j-1])
end_time = timeit.default_timer()
print(str1)
print(str2)
print(end_time-start_time)
print(LCS[-1][-1])

plt.plot([5,10,15,20,25], [0.0000157, 0.0000461, 0.0000957, 0.00016, 0.00025])
plt.show()