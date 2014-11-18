import sys
import random
import math

NUM_INPUT_LINES = 500
ID_RANGE = 50

def writeInputFiles(numInputLines=NUM_INPUT_LINES, idRange=ID_RANGE):
    f = open("inputs/uniform.txt", 'w')
    for i in range(0, numInputLines):
        r = random.randint(0, idRange)
        f.write(str(r) + '\n')

    f = open("inputs/triangular.txt", 'w')
    for i in range(0, numInputLines):
        r = int(random.triangular(0, idRange))
        f.write(str(r) + '\n')

    f = open("inputs/onePage.txt", 'w')
    for i in range(0, numInputLines):
        r = random.randint(0, idRange)
        # 25% of the time, request the same page
        if r < idRange/4:
            r = 0
        f.write(str(r) + '\n')

writeInputFiles(NUM_INPUT_LINES, ID_RANGE)
