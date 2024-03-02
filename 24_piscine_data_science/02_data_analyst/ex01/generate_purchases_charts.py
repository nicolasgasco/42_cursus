import matplotlib.pyplot as plt
import pandas as pd

df = pd.read_csv("./purchases_by_day.csv")

df['date'] = pd.to_datetime(df['date'])

dates = df['date']
purchases = df['total_price']
print(dates[:10])
print(purchases[:10])


plt.plot(df['date'], df['total_price'])
plt.ylabel('Number of customers')
plt.grid(True)
plt.show()
plt.savefig('event_types.jpg', bbox_inches='tight', pad_inches=0, dpi=300)
