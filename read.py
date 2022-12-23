import matplotlib.pyplot as plt
import numpy as np
f = open('ex2file.txt', 'r')
arr = [[], [], []]

for line in f:
    arr[0].append(int(line.split('   ')[0]))
    arr[1].append(float(line.split('   ')[1]))
    arr[2].append(float(line.split('   ')[2]))

fig, ax = plt.subplots()
Y1, Y2 = arr[1], arr[2]
X = arr[0]

ax.plot(X, Y1, label = 'range_append')
ax.plot(X, Y2, label = 'range_insertion')
ax.set(xlabel = 'List size', ylabel = 'Time', title = 'Temps d\'execution au fonction du temps')
ax.grid(axis= 'y')
ax.legend()
plt.xticks(np.arange(0, 20500, 500), rotation = 90)
plt.yticks(np.arange(0, 1.05, 0.05))
plt.show()
