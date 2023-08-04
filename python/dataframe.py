import pandas as pd
import numpy as np
df = pd.read_csv('../output_extra_clean/output_extra_clean1950.csv')
df.columns = ['explicit', 'language', 'year']


# print(np.sort(pd.unique(df['year'])))

# languages = pd.unique(df['language'])

# with open("languages.txt", "w") as file:
#     for language in languages:
#         file.write(f"{language}\n")