import os
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.metrics import classification_report, roc_curve, roc_auc_score
from sklearn.preprocessing import LabelEncoder
from sklearn.metrics import accuracy_score
from PIL import Image

class MultiLayerPerceptron:
    def __init__(self, input_size, hidden_size, output_size, learning_rate=0.01, max_epochs=10):
        self.input_size = input_size
        self.hidden_size = hidden_size
        self.output_size = output_size
        self.learning_rate = learning_rate
        self.max_epochs = max_epochs
        
        # Initialize weights and biases with random values
        self.weights_input_hidden = np.random.rand(self.input_size, self.hidden_size)
        self.bias_hidden = np.random.rand(self.hidden_size)
        self.weights_hidden_output = np.random.rand(self.hidden_size, self.output_size)
        self.bias_output = np.random.rand(self.output_size)
        
    def sigmoid(self, x):
        return 1 / (1 + np.exp(-x))
    
    def sigmoid_derivative(self, x):
        return x * (1 - x)
    
    def forward(self, X):
        self.hidden_input = np.dot(X, self.weights_input_hidden) + self.bias_hidden
        self.hidden_output = self.sigmoid(self.hidden_input)
        self.output_input = np.dot(self.hidden_output, self.weights_hidden_output) + self.bias_output
        self.output_output = self.sigmoid(self.output_input)
        return self.output_output
    
    def backward(self, X, y, output):
        error = y - output
        d_output = error * self.sigmoid_derivative(output)
        error_hidden = d_output.dot(self.weights_hidden_output.T)
        d_hidden = error_hidden * self.sigmoid_derivative(self.hidden_output)
        
        self.weights_hidden_output += self.hidden_output.T.dot(d_output) * self.learning_rate
        self.bias_output += np.sum(d_output) * self.learning_rate
        self.weights_input_hidden += X.T.dot(d_hidden) * self.learning_rate
        self.bias_hidden += np.sum(d_hidden) * self.learning_rate
        
    def train(self, X, y):
        for epoch in range(self.max_epochs):
            output = self.forward(X)
            self.backward(X, y, output)
    
    def predict(self, X):
        return np.round(self.forward(X))
    
# Load the Flower Recognition dataset
data_dir = "flowers"
classes = os.listdir(data_dir)
num_classes = len(classes)

image_paths = []
labels = []

for flower_class in classes:
    class_path = os.path.join(data_dir, flower_class)
    for image_name in os.listdir(class_path):
        image_path = os.path.join(class_path, image_name)
        image_paths.append(image_path)
        labels.append(flower_class)

image_paths = np.array(image_paths)
labels = np.array(labels)

X_train, X_test, y_train, y_test = train_test_split(image_paths, labels, test_size=0.2, random_state=42)
X_train, X_val, y_train, y_val = train_test_split(X_train, y_train, test_size=0.25, random_state=42)

def preprocess_image(image_path):
    img = Image.open(image_path)
    img = img.resize((224, 224))
    img = np.array(img) / 255.0
    return img

X_train_processed = np.array([preprocess_image(image_path) for image_path in X_train])
X_val_processed = np.array([preprocess_image(image_path) for image_path in X_val])
X_test_processed = np.array([preprocess_image(image_path) for image_path in X_test])

label_encoder = LabelEncoder()
y_train_encoded = label_encoder.fit_transform(y_train)
y_val_encoded = label_encoder.transform(y_val)
y_test_encoded = label_encoder.transform(y_test)

# Initialize and train the MLP model
mlp = MultiLayerPerceptron(input_size=224*224*3, hidden_size=128, output_size=num_classes, learning_rate=0.01, max_epochs=10)
mlp.train(X_train_processed.reshape(len(X_train_processed), -1), y_train_encoded)

# Evaluate the model on the validation set
y_val_pred = mlp.predict(X_val_processed.reshape(len(X_val_processed), -1))
accuracy_val = accuracy_score(y_val_encoded, y_val_pred)
print("Validation Accuracy:", accuracy_val)

# Evaluate the model on the test set
y_test_pred = mlp.predict(X_test_processed.reshape(len(X_test_processed), -1))
accuracy_test = accuracy_score(y_test_encoded, y_test_pred)
print("Test Accuracy:", accuracy_test)

# Generate classification report for the test set
class_names = label_encoder.classes_
print("Classification Report:")
print(classification_report(y_test_encoded, y_test_pred, target_names=class_names))

# Plot ROC curve
fpr, tpr, thresholds = roc_curve(y_test_encoded, y_test_pred)
plt.plot(fpr, tpr)
plt.title('ROC Curve')
plt.xlabel('False Positive Rate')
plt.ylabel('True Positive Rate')
plt.show()

# Calculate AUC score
auc_score = roc_auc_score(y_test_encoded, y_test_pred)
print("AUC Score:", auc_score)
