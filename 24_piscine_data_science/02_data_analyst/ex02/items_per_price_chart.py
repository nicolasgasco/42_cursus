import pandas as pd
import pandas as pd

import matplotlib.pyplot as plt

plt.style.use('seaborn-v0_8')

df = pd.read_csv("./items_per_price.csv")
prices = df['price']

# Create a horizontal box plot with solid color blocks
plt.boxplot(prices, vert=False, patch_artist=True, widths=0.8)

# Set labels and title
plt.xlabel('Price')

# Show the plot
plt.show()
plt.savefig('items_per_price.jpg', bbox_inches='tight',
            pad_inches=0.5, dpi=600)

plt.clf()  # Reset the plot

narrower_prices = list(filter(lambda x: x >= 0 and x <= 13, prices))

# Create a horizontal box plot with solid color blocks
plt.boxplot(narrower_prices, vert=False, patch_artist=True, widths=0.8)

# Set labels and title
plt.xlabel('Price')

# Show the plot
plt.show()
plt.savefig('items_per_price_narrower.jpg', bbox_inches='tight',
            pad_inches=0.5, dpi=600)
