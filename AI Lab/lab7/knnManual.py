import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from math import sqrt

# Read the data from Excel
df = pd.read_excel('knn.xlsx')

X = df[['matches', 'runs', 'wickets']]  # Features
y = df['classname']  # Target variable

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3)

print("X Training Data is: \n")
print(X_train)
print("X Testing Data is: \n")
print(X_test)


X_test_Euclidean = []


for i in range(len(X_test)):
    distances = []
    for j in range(len(X_train)):
        dist = np.sqrt(((X_test.iloc[i] - X_train.iloc[j]) ** 2).sum())
        distances.append(dist)
    X_test_Euclidean.append(distances)

# Convert the result to a DataFrame
X_test_Euclidean = pd.DataFrame(X_test_Euclidean)
print("X Test Euclidean Data is: \n")
print(X_test_Euclidean)

X_test_sorted=sorted(X_test_Euclidean)
print("X Test Euclidean Data is: \n")
print(X_test_Euclidean)


# Get indices of nearest neighbors for each test instance
k = 2  
nearest_indices = X_test_Euclidean.apply(lambda x: x.argsort()[:k], axis=1)

# Determine the majority class among the nearest neighbors
predictions = []
for i in range(len(nearest_indices)):
    neighbor_classes = y_train.iloc[nearest_indices.iloc[i]]
    majority_class = neighbor_classes.mode()[0]
    predictions.append(majority_class)

# Convert predictions to a DataFrame for easier comparison
predictions_df = pd.DataFrame({'Predicted': predictions})

# Combine predictions with the actual classes for comparison
result_df = pd.concat([predictions_df, y_test.reset_index(drop=True)], axis=1)
print(result_df)


# Determine the majority class among the nearest neighbors and predict for test data
def predict_majority_class(nearest_indices, y_train):
    predictions = []
    for i in range(len(nearest_indices)):
        neighbor_classes = y_train.iloc[nearest_indices.iloc[i]]
        majority_class = neighbor_classes.mode()[0]
        predictions.append(majority_class)
    return predictions