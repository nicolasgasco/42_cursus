import pandas as pd

import matplotlib.pyplot as plt

plt.style.use('seaborn-v0_8')

df = pd.read_csv("./customers_by_frequency.csv")

orders = df['order_count']
customers = df['customer_count']
total_prices = df['total_price']

# Select every 3rd value
orders = orders[::3]
new_customers = customers[::3]

plt.bar(orders, new_customers, width=5)
plt.show()
plt.savefig('customers_by_frequency.jpg',
            bbox_inches='tight', pad_inches=0, dpi=600)

plt.clf()

plt.bar(total_prices, customers, width=5)
plt.show()
plt.savefig('total_price_by_frequency.jpg',
            bbox_inches='tight', pad_inches=0, dpi=600)
