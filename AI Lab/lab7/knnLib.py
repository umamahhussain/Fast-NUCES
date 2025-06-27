import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score
from sklearn.neighbors import KNeighborsClassifier

# Read the data from Excel
df = pd.read_excel('knn.xlsx')

X = df[['matches', 'runs', 'wickets']]  # Features
y = df['classname']  # Target variable

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3)

knn = KNeighborsClassifier(n_neighbors=3)
knn.fit(X_train, y_train)

# Predict the target variable for the test data
y_pred = knn.predict(X_test)
print(y_pred)

accuracy = accuracy_score(y_test, y_pred)
print("Accuracy:", accuracy)

# Create a DataFrame to compare actual and predicted values
df_preds = pd.DataFrame({'Actual': y_test, 'Predicted': y_pred})
print(df_preds)
