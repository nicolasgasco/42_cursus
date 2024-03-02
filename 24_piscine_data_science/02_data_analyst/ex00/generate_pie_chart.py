import matplotlib.pyplot as plt
import pandas as pd

df = pd.read_csv("../customers.csv")

event_counts = df['event_type'].value_counts()
print(event_counts)

plt.pie(event_counts, labels=event_counts.index.tolist(), autopct='%1.1f%%')
plt.show()
plt.savefig('event_types.jpg', bbox_inches='tight', pad_inches=0, dpi=600)
