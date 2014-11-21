import os
import subprocess

from createInputs import *

progs = ['lru', 'lfu', 'secondChance', 'random']
inputDir = 'inputs/'
outputDir = 'outputs/'
tableSizes = ['10', '100', '500']
inputSizes = ['500', '1000', '2000']
idRanges = ['50', '200', '1000']
for fileName in os.listdir(inputDir):
    fout = open(outputDir + fileName, 'w')
    for tableSize in tableSizes:
        fout.write('Table size: ' + tableSize + '\n')
        fout.write('X=# of elements in input files. Y=Range of page IDs in input files.\n\n')

        counts = [] 
        for inputSize in inputSizes:
            row = []
            for idRange in idRanges:
                writeInputFiles(int(inputSize), int(idRange))
                element = {}
                
                for prog in progs:
                    cmd = 'cat ' + inputDir + fileName + '| ./' + prog + ' ' + tableSize + ' | wc -l'
                    p = subprocess.Popen(cmd, shell=True, stdout=subprocess.PIPE)
                    output, errors = p.communicate()
                    element[prog] = int(output)

                row.append(element)
            counts.append(row)

        colWidth = 12 
        for inputSize in inputSizes:
            fout.write(' ' + inputSize.ljust(colWidth) + ' ')
        fout.write('\n')

        for i in range(len(idRanges)):
            fout.write(idRanges[i] + '\n')
            for prog in progs:
                for j in range(len(inputSizes)):
                    numMissed = counts[j][i][prog]
                    percentMissed = (int(numMissed) * 100) / int(inputSizes[j])
                    content = prog[0:3] + ': ' + str(numMissed) + ' ' + str(percentMissed) + '%'
                    fout.write(' ' + content.ljust(colWidth) + ' |')
                fout.write('\n')
            fout.write('\n')
                
        fout.write('\n')
