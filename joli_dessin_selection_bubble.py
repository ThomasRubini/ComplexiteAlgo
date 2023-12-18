#!/usr/bin/env python3

# Bold lines represent algorithms, other lines are for reference
import matplotlib.pyplot as plt
import pandas as pd
import numpy as np

df = pd.read_csv("output_selection_bubble.csv")
data_x = df[df.columns[0]]
for col in df.columns[1:]:
    # print()
    # print(df[col])
    plt.plot(data_x, df[col], label=df[col].name, linewidth=3)

x = np.arange(0.01, 50, 0.01)
FACTOR = 10000

plt.plot(x*FACTOR, np.log(x), label="O(log(n))")
plt.plot(x*FACTOR, x*np.log(x), label="O(nlog(n))")
plt.plot(x*FACTOR, x, label="O(n)")
plt.plot(x*FACTOR, x**2, label="O(n²)")

plt.xlim(0, 200000)
plt.ylim(0, 50)

plt.title('Sorting algorithm time complexity')
plt.xlabel('Entry size')
plt.ylabel('Time in seconds')
plt.legend(loc="upper left")
plt.show()
