import pandas as pd
import statsmodels.api as sm
from statsmodels.stats.outliers_influence import variance_inflation_factor


def main():
    df = pd.read_csv('../Train_knight.csv')
    df.drop('knight', axis=1, inplace=True)

    df = sm.add_constant(df)

    vif = pd.DataFrame()
    vif["variables"] = df.columns
    vif["VIF"] = [variance_inflation_factor(
        df.values, i) for i in range(df.shape[1])]
    vif["Tolerance"] = 1/vif["VIF"]

    print(vif)


if __name__ == "__main__":
    main()
