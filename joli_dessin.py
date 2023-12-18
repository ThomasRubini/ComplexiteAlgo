import matplotlib.pyplot as plt
import pandas as pd

df = pd.read_csv("output.csv")
x = df[df.columns[0]]
for col in df.columns[1:]:
    print()
    print(df[col])
    plt.plot(x, df[col], label=df[col].name)

plt.title('Sorting algorithm time complexity')
plt.xlabel('Entry size')
plt.ylabel('Time in seconds')
plt.legend(loc="upper left")
plt.show()
