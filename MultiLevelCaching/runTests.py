import os
import subprocess

from createInputs import *

progs = ['lru', 'lfu', 'secondChance', 'random']
infile = 'workload.txt'
infile = 'cat ' + infile + ' '
linecount = ' wc -l '

# Print number of lines in input
cmd = infile + ' | ' + linecount
print cmd
p = subprocess.Popen(cmd, shell=True)
p.communicate()

for i in range(len(progs)):
    progA = progs[i]
    cmds = [infile +  ' | ./' + progA + ' 250 | ' + linecount]
    for j in range(len(progs)):
        progB = progs[j]
        cmds.append(infile +  ' | ./' + progA + ' 250 | ./' + progB + ' 250 | ' + linecount)

    cmds.append(infile +  ' | ./' + progA + ' 500 | ' + linecount)

    for cmd in cmds:
        print(cmd)
        p = subprocess.Popen(cmd, shell=True)
        p.communicate()
