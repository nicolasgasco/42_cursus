import pandas as pd

df = pd.read_csv("./items_with_price.csv")

prices = df['price']

print(f"count\t{len(prices):>10.6f}")
print(f"mean\t{prices.mean():>10.6f}")
print(f"std\t{prices.std():>10.6f}")
print(f"min\t{prices.min():>10.6f}")
print(f"25%\t{prices.quantile(0.25):>10.6f}")
print(f"50%\t{prices.quantile(0.5):>10.6f}")
print(f"75%\t{prices.quantile(0.75):>10.6f}")
print(f"max\t{prices.max():>10.6f}")
