import random
import string
import timeit
from matplotlib import pyplot as plt
import numpy as np

# 두 개의 string sequence 입력
# str1 = input()
# str2 = input()

# 문자열의 길이는 10
LENGTH = [5, 10, 15, 20, 25, 30, 35, 40]
# 모든 대소문자 저장

# 각 문자열 길이의 LENGTH 별로 10번의 랜덤 인풋 실행 결과 시간 값의 평균을 저장을 위한 List
ylist = []

# 랜덤한 문자열 생성


for l in range(len(LENGTH)):

    sum = 0.0
    average = 0.0
    for _ in range(10):
        string_pool = string.ascii_letters
        str1 = 'ACGT'
        str2 = 'ACGT'

        for _ in range(LENGTH[l]-4):
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
                    LCS[i][j] = LCS[i-1][j-1] + 1
                else:
                    LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1])

        end_time = timeit.default_timer()
        print(str1)
        print(str2)
        # LCS 알고리즘 수행 시간
        sum = sum + (end_time-start_time)

    average = sum / 10

    ylist.append(average)

    print(average)


xp = LENGTH
plt.plot(xp, ylist)
plt.xlabel('string length')
plt.ylabel('average actual running time(secs)')
plt.title('average actual running time graph')
plt.show()