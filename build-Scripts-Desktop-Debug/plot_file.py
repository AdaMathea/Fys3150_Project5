import matplotlib.pyplot as plt

t = [[], [], [], []]
S = [[], [], [], []]
I = [[], [], [], []]
R = [[], [], [], []]
dok = ["| %5s | %9s | %9s | %9s |"%("t", "S", "I", "R")]

Filename = input("Navn på datafil som skal åpnes: ")
Metode = input("Metode brukt for modelen: ")
Fignum = eval(input("Første nummer på lagrede figurer: "))

i = 0
with open(Filename, 'r') as infile:
    for line in infile.readlines():
        temp = line.split()
        j_= 0
        for j in range(len(temp)):
            print (j - j_, len(temp), temp[j - j_])
            if temp[j - j_] == "|":
                temp.pop(j - j_)
                j_ += 1
        if temp[0] == "-"*41:
            dok.append("-"*41)
            i += 1
        elif temp[0] in ["A", "B", "C", "D", "t"]:
            pass
        else:
            dok.append("| %5s | %9s | %9s | %9s |"%(temp[0], temp[1], temp[2], temp[3]))
            t[i].append(float(temp[0]))
            S[i].append(float(temp[1]))
            I[i].append(float(temp[2]))
            R[i].append(float(temp[3]))




with open(Filename, "w") as outfile:
    for line in dok:
        outfile.write("%s\n"%line)

values_plotted = 300
plt.figure()
for i in range(len(t)):
    plt.plot(t[i][0:values_plotted], S[i][0:values_plotted], label = "S%i"%i)

plt.title("SIRS Model solved by %s"%Metode)
plt.xlabel("Time")
plt.ylabel("Susceptible")
plt.legend()
plt.savefig("Figure%02i.png"%Fignum)

plt.figure()
for i in range(len(t)):
    plt.plot(t[i][0:values_plotted], I[i][0:values_plotted], label = "I%i"%i)

plt.title("SIRS Model solved by %s"%Metode)
plt.xlabel("Time")
plt.ylabel("Infected")
plt.legend()
plt.savefig("Figure%02i.png"%(Fignum + 1))

plt.figure()
for i in range(len(t)):
    plt.plot(t[i][0:values_plotted], R[i][0:values_plotted], label = "R%i"%i)

plt.title("SIRS Model solved by %s"%Metode)
plt.xlabel("Time")
plt.ylabel("Recovered")
plt.legend()
plt.savefig("Figure%02i.png"%(Fignum + 2))

plt.show()