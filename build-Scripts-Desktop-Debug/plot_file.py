import matplotlib.pyplot as plt
import numpy as np

liste = ["A", "B", "C", "D", "t"]

t = [[], [], [], []]
S = [[], [], [], []]
I = [[], [], [], []]
R = [[], [], [], []]
dok = ["| %7s | %9s | %9s | %9s |"%("t", "S", "I", "R")]

Filename = input("Navn på datafil som skal åpnes: ")
Metode = input("Metode brukt for modelen: ")
Fignum = eval(input("Første nummer på lagrede figurer: "))
Plot_choice = input("Plot S, I, R separat? (y/n): ")

i = 0
with open(Filename, 'r') as infile:
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
            dok.append("| %7s | %9s | %9s | %9s |"%(temp[0], temp[1], temp[2], temp[3]))
            t[i].append(float(temp[0]))
            S[i].append(float(temp[1]))
            I[i].append(float(temp[2]))
            R[i].append(float(temp[3]))



"""
with open(Filename, "w") as outfile:
    for line in dok:
        outfile.write("%s\n"%line)
"""
values_plotted = 5000
t_lim = 730
t = np.array([np.array(i) for i in t])
S = np.array([np.array(i) for i in S])
I = np.array([np.array(i) for i in I])
R = np.array([np.array(i) for i in R])



if Plot_choice == "y":
    plt.figure()
    for i in range(len(t)):
        plt.plot(t[i][0:values_plotted], S[i][0:values_plotted], label = "S_%s"%liste[i])

    plt.xlabel("Time")
    plt.ylabel("Susceptible")
    plt.legend()
    plt.savefig(f"{Filename[:-4]}{Fignum}.png")

    plt.figure()
    for i in range(len(t)):
        plt.plot(t[i][0:values_plotted], I[i][0:values_plotted], label = "I_%s"%liste[i])

    plt.xlabel("Time")
    plt.ylabel("Infected")
    plt.legend()
    plt.savefig(f"{Filename[:-4]}{Fignum + 1}.png")

    plt.figure()
    for i in range(len(t)):
        plt.plot(t[i][0:values_plotted], R[i][0:values_plotted], label = "R_%s"%liste[i])

    plt.xlabel("Time")
    plt.ylabel("Recovered")
    plt.legend()
    plt.savefig(f"{Filename[:-4]}{Fignum + 2}.png")

    plt.show()

elif Plot_choice == "n":
    for i in range(len(t)):
        plt.figure()
        plt.plot(t[i][t[i] < t_lim], S[i][t[i] < t_lim], label = "S_%s"%liste[i])
        plt.plot(t[i][t[i] < t_lim], I[i][t[i] < t_lim], label = "I_%s"%liste[i])
        plt.plot(t[i][t[i] < t_lim], R[i][t[i] < t_lim], label = "R_%s"%liste[i])
        plt.xlabel("Time")
        plt.ylabel("Population")
        plt.legend()
        plt.savefig(f"{Filename[:-4]}{Fignum + i}.png")
    plt.show()
    plt.clf()

else:
    raise(Exception("Plot_choice must be y or n"))