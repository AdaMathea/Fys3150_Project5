import os
import numpy as np

liste = ["A", "B", "C", "D", "t"]

t = [[], [], [], []]
S = [[], [], [], []]
I = [[], [], [], []]
R = [[], [], [], []]
dok = ["| %7s | %9s | %9s | %9s |"%("t", "S", "I", "R")]
k = 0

isFirstFile = True

while os.path.exists("5b" + str(k) + ".txt"):
    i = 0
    with open("5b" + str(k) + ".txt", 'r') as infile:
        for line in infile.readlines():
            temp = line.split()
            j_= 0
            for j in range(len(temp)):
                if temp[j - j_] == "|":
                    temp.pop(j - j_)
                    j_ += 1
            if temp[0] == "-"*41:
                dok.append("-"*41)
                i += 1
                l = 0
            elif temp[0] in liste:
                pass
            else:
                # doc.append("| %7s | %9s | %9s | %9s |" %(temp[0], temp[1], temp[2], temp[3]))
                if isFirstFile:
                    t[i].append(float(temp[0]))
                    S[i].append(float(temp[1]))
                    I[i].append(float(temp[2]))
                    R[i].append(float(temp[3]))
                else:
                    t[i][l] += float(temp[0])
                    S[i][l] += float(temp[1])
                    I[i][l] += float(temp[2])
                    R[i][l] += float(temp[3])
                    l += 1
        k += 1
        isFirstFile = False

for j in range(len(t)):
    for i in range(len(t[j])):
        t[j][i] /= k
        S[j][i] /= k
        I[j][i] /= k
        R[j][i] /= k

with open("5b.txt", "w") as outfile:
    for j in range(len(t)):
        if j == 0:
            outfile.write("A\n")
            outfile.write("t S I R\n")
        elif j == 1:
            outfile.write("-"*41 + "\n")
            outfile.write("B\n")
            outfile.write("t S I R\n")
        elif j == 2:
            outfile.write("-"*41 + "\n")
            outfile.write("C\n")
            outfile.write("t S I R\n")
        elif j == 3:
            outfile.write("-"*41 + "\n")
            outfile.write("D\n")
            outfile.write("t S I R\n")
        for ti, Si, Ii, Ri in zip(t[j], S[j], I[j], R[j]):
            outfile.write(str(ti) + " " + str(Si) + " " + str(Ii) + " " + str(Ri) + "\n")