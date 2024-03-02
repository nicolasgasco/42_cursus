import pandas as pd

import matplotlib.pyplot as plt
import matplotlib.dates as mdates

plt.style.use('seaborn-v0_8')

df = pd.read_csv("./customers_by_day.csv")

df['date'] = pd.to_datetime(df['date'])

dates = df['date']
users = df['unique_users']

fig, ax = plt.subplots()

ax.plot(df['date'], df['unique_users'])
ax.set_ylabel('Number of customers')
ax.grid(True)

# Set the X axis tick format to display only the month name
ax.xaxis.set_major_formatter(mdates.DateFormatter('%b'))

# Set the X axis tick locator to show the month name
# only once at the beginning of each month group
ax.xaxis.set_major_locator(mdates.MonthLocator())

# Set the x-axis limits to start from the first date
ax.set_xlim(df['date'].min(), df['date'].max())

plt.show()
plt.savefig('charts/customers_by_day.jpg', bbox_inches='tight',
            pad_inches=0.5, dpi=600)
