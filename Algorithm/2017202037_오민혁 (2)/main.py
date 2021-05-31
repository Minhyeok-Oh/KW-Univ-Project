import random
import time
import math
from matplotlib import pyplot as plt
import numpy as np

# for solving (d)
nlist = [5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85]
# 코드 실행시간을 저장하기 위한 list
ylist = []
for n in nlist:
    # for solving (b)
    # n = 5
    v = []
    wt = []
    # 문제 에서 주어진 최대 가방 무게 W 을 구하기 위함
    W = math.floor(math.pow(n, 2)/2)

    # 각 item의 무게를 1부터 2n 범위 사이에서 무작위로 설정
    for i in range(n):
        v.append(random.randrange(1, 2*n))
        wt.append(i+1)

    #알고리즘 실행 시작 시간
    start = time.time()

    #bottom up dynamic programming을 위한 2차원 리스트 선언
    DP = [[0 for x in range(W+1)] for x in range(n+1)]

    print(v, wt)



    for i in range(n+1):
        for w in range(W+1):
            if i == 0 or w == 0:
                DP[i][w] = 0
            elif v[i-1] <= W:
                DP[i][w] = max(DP[i-1][w-wt[i-1]]+v[i-1], DP[i-1][w])
            else:
                DP[i][w] = DP[i-1][w]

    print(DP)
    print(DP[n][W])
    # 알고리즘 실행 종료 시각
    end = time.time()
    ylist.append(end-start)

xp = len(ylist)
plt.plot(nlist, ylist)
plt.xlabel('n')
plt.ylabel('average actual running time(secs)')
plt.title('average actual running time graph')
plt.show()