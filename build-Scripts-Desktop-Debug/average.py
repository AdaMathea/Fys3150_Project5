import os
import numpy as np

liste = ["A", "B", "C", "D", "t"]

t = [[], [], [], []]
S = [[], [], [], []]
I = [[], [], [], []]
R = [[], [], [], []]
dok = ["| %7s | %9s | %9s | %9s |"%("t", "S", "I", "R")]
k = 0



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
            elif temp[0] in liste:
                pass
            else:
                dok.append("| %7s | %9s | %9s | %9s |" %(temp[0], temp[1], temp[2], temp[3]))
                t[i].append(float(temp[0]))
                S[i].append(float(temp[1]))
                I[i].append(float(temp[2]))
                R[i].append(float(temp[3]))

        globals()['t%s' % k] = t
        globals()['S%s' % k] = S
        globals()['I%s' % k] = I
        globals()['R%s' % k] = R

        k += 1

t_avg = np.zeros((4, len(t[0])))
S_avg = np.zeros((4, len(t[0])))
I_avg = np.zeros((4, len(t[0])))
R_avg = np.zeros((4, len(t[0])))

for h in range(k):
    for j in range(len(t_avg)):
        for i in range(len(t[0])):
            t_avg[j][-1] += globals()['t%s' % h][j][i]
            S_avg[j][-1] += globals()['S%s' % h][j][i]
print(t_avg[3])
for j in range(len(t_avg)):
    for i in range(len(t[0])):
        t_avg[j][i] = t_avg[j][i]/k
        S_avg[j][i] = S_avg[j][i]/k

with open("5b.txt", "w") as outfile:
    for j in range(len(t_avg)):
        for i in range(len(t[0])):
            outfile.write(str(t_avg[j][i]) + " " + str(S_avg[j][i]) + "\n")