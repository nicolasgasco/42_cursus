import pandas as pd

import matplotlib.pyplot as plt
import matplotlib.dates as mdates

plt.style.use('seaborn-v0_8')

df = pd.read_csv("./sales_by_month.csv")

df['month'] = pd.to_datetime(df['month'])

months = df['month']
totals = df['total_price']

fig, ax = plt.subplots()

ax.bar(df['month'], df['total_price'], width=20)
ax.set_ylabel('Total sales in million of A')
ax.grid(True)

plt.show()
plt.savefig('charts/sales_by_month.jpg', bbox_inches='tight',
            pad_inches=0.5, dpi=600)
