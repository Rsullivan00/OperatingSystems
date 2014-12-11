import sys
import random
import math

NUM_INPUT_LINES = 1000000
PAGE_RANGE = 10000 

FREQUENTLY_REQUESTED = int(PAGE_RANGE/10)
FREQUENTLY_RATE = 80 # 80%
RARELY_REQUESTED = int(2 * (PAGE_RANGE/10))

EXTERNAL_READ_SIZE = int(PAGE_RANGE/10)

def getProgramPage():
    r = random.randint(0, 100)
    if r < FREQUENTLY_RATE:
        pageNum = random.randint(0, FREQUENTLY_REQUESTED)
    else:
        pageNum = random.randint(FREQUENTLY_REQUESTED,  FREQUENTLY_REQUESTED + RARELY_REQUESTED)
    return pageNum

def getExternalPage(externalReadCount):
    offset = FREQUENTLY_REQUESTED + RARELY_REQUESTED
    previousReads = EXTERNAL_READ_SIZE * externalReadCount
    return random.randint(offset + previousReads, offset + previousReads + EXTERNAL_READ_SIZE)

def writeInputFiles(numInputLines=NUM_INPUT_LINES, pageRange=PAGE_RANGE):
    # Input file with page requests mimicking a real program.
    f = open("workload.txt", 'w')
    externalRead = False
    externalReadCount = 0
    for i in range(0, numInputLines):
        if i % (int(numInputLines/14) * 2) == 0:
            externalRead = False
            externalReadCount += 1
        # Seven times, do an external read
        elif i % int(numInputLines/14) == 0:
            # Switch to an external read of 100000 pages
            externalRead = True

        if externalRead:
            pageNum = getExternalPage(externalReadCount)
        else:
            pageNum = getProgramPage()
            
        f.write(str(pageNum) + '\n')

writeInputFiles(NUM_INPUT_LINES, PAGE_RANGE)
