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
                #fout.write('# of inputs: ' + inputSize + '\t')
                #fout.write('Range of inputs: 0-' + idRange + '\t')
                writeInputFiles(int(inputSize), int(idRange))
                element = {}
                
                for prog in progs:
                    cmd = 'cat ' + inputDir + fileName + '| ./' + prog + ' ' + tableSize + ' | wc'
                    p = subprocess.Popen(cmd, shell=True, stdout=subprocess.PIPE)
                    output, errors = p.communicate()
                    linesOut = output.split()[1]
                    #fout.write(prog + '\t' + linesOut + '\n')
                    element[prog] = int(linesOut)

                row.append(element)
            counts.append(row)

        colWidth = 10 
        for inputSize in inputSizes:
            fout.write('\t' + inputSize.ljust(colWidth) + '\t')
        fout.write('\n')

        for i in range(len(idRanges)):
            fout.write(idRanges[i] + '\n')
            for prog in progs:
                for j in range(len(inputSizes)):
                    content = prog[0:3] + ': ' + str(counts[i][j][prog])
                    fout.write('\t' + content.ljust(colWidth) + '\t|')
                fout.write('\n')
            fout.write('\n')
                
        fout.write('\n')
