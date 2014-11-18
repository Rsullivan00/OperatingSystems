import sys
import random
import math

NUM_INPUT_LINES = 500
ID_RANGE = 50


def writeInputFiles(numInputLines=NUM_INPUT_LINES, idRange=ID_RANGE):
    f = open("inputs/uniform.txt", 'w')
    for i in range(0, numInputLines):
        r = random.randint(0, idRange - 1)
        f.write(str(r) + '\n')

    f = open("inputs/triangular.txt", 'w')
    for i in range(0, numInputLines):
        r = int(random.triangular(0, idRange - 1))
        f.write(str(r) + '\n')

    f = open("inputs/onePage.txt", 'w')
    for i in range(0, numInputLines):
        r = random.randint(0, idRange - 1)
        # 25% of the time, request the same page
        r2 = random.randint(0, 4)
        if r2 == 0:
            r = 0
        f.write(str(r) + '\n')

writeInputFiles(NUM_INPUT_LINES, ID_RANGE)
