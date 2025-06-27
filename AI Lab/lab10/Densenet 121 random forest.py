# -*- coding: utf-8 -*-
"""
Created on Sun Jan  8 00:30:46 2023

@author: mujta
"""

import numpy as np
import matplotlib.pyplot as plt
import glob
import cv2
from keras.models import Model, Sequential
from keras.layers import Dense, Flatten, Conv2D, MaxPooling2D
from keras.layers.normalization import batch_normalization
import os
import seaborn as sns
from keras.applications.densenet import DenseNet121
from sklearn.model_selection import train_test_split
from sklearn import metrics
from sklearn.metrics import confusion_matrix
print(os.listdir("early crop weed segment/"))
SIZE = 224  # Resize images
#
# # Capture training data and labels into respective lists
DATASET_IMAGES = []
DATASET_LABELS = []
Train_Accuracy = []
Test_Accuracy = []
#
for directory_path in glob.glob("early crop weed segment/*"):
    label = directory_path.split("\\")[-1]
    print(label)
    for img_path in glob.glob(os.path.join(directory_path, "*.JPG")):
        print(img_path)
        img = cv2.imread(img_path, cv2.IMREAD_COLOR)
        img = cv2.resize(img, (SIZE, SIZE))
        img = cv2.cvtColor(img, cv2.COLOR_RGB2BGR)
        DATASET_IMAGES.append(img)
        DATASET_LABELS.append(label)
#
# # Convert lists to arrays
DATASET_IMAGES = np.array(DATASET_IMAGES)
DATASET_LABELS = np.array(DATASET_LABELS)


# # Encode labels from text to integers.
from sklearn import preprocessing
le = preprocessing.LabelEncoder()
#print(type(DATASET_LABELS))
#le.fit(DATASET_LABELS)
#aaa=le.transform(DATASET_LABELS)
#print(aaa[0])
#bbb=(le.inverse_transform(aaa))
#print(bbb[0])


#le.fit(DATASET_LABELS)
#DATASET_LABELS_ENCODED = le.transform(DATASET_LABELS)


X_train, X_test, y_train, y_test = train_test_split(DATASET_IMAGES, DATASET_LABELS, test_size = 0.3,random_state=42)
le.fit(y_test)
test_labels_numeric_encoded = le.transform(y_test)
le.fit(y_train)
train_labels_numeric_encoded = le.transform(y_train)
#print(test_labels_numeric_encoded[0])
#print(train_labels_numeric_encoded[0])

train_inverse_transform_alpha_encoded = le.inverse_transform(train_labels_numeric_encoded)
#print(train_inverse_transform_alpha_encoded[0])

test_inverse_transform_alpha_encoded = le.inverse_transform(test_labels_numeric_encoded )
#print(test_inverse_transform_alpha_encoded[0])

#shape = X_train.shape
#print(f'Shape [0] total  {shape[0]}')
#print(f'Shape [0] row  {shape[1]}')
#print(f'Shape [0] colum  {shape[2]}')


#shape = y_train.shape
#print(f'y_Shape [0] rows  {shape[0]}')


#from keras.utils import to_categorical
#
#y_train_one_hot = to_categorical(y_train)
#y_test_one_hot = to_categorical(y_test)


Densenet_model = DenseNet121(weights='imagenet', include_top=False, input_shape=(SIZE, SIZE, 3))
#
# # Make loaded layers as non-trainable. This is important as we want to work with pre-trained weights
for layer in Densenet_model.layers:
    layer.trainable = False
#
Densenet_model.summary()  # Trainable parameters will be 0
#
# # Now, let us use features from convolutional network for RF
feature_extractor = Densenet_model.predict(X_train)
#
features = feature_extractor.reshape(feature_extractor.shape[0], -1)
#print((features.shape)) #(355,25088)
#print(features.shape[0])
#print(features.shape[1])

#
X_for_RF = features  # This is our X input to RF
#
# # RANDOM FOREST
from sklearn.ensemble import RandomForestClassifier
#
for i in range(2,301):
    RF_model = RandomForestClassifier(n_estimators=i, random_state=42)
#
# # Train the model on training data
    RF_model.fit(X_for_RF, y_train)
    prediction_RF = RF_model.predict(X_for_RF)
    #print(type(prediction_RF))
    #print(prediction_RF[0])
    #print(y_train[0])


#le.fit(y_test)
#test_labels_numeric_encoded = le.transform(y_test)
    le.fit(y_train)
    prediction_train_labels_numeric_encoded = le.transform(prediction_RF)
#print(test_labels_numeric_encoded[0])
#print(train_labels_numeric_encoded[0])
    prediction_train_inverse_transform_alpha_encoded = le.inverse_transform(prediction_train_labels_numeric_encoded)
#print(train_inverse_transform_alpha_encoded[0])

#test_inverse_transform_alpha_encoded = le.inverse_transform(test_labels_numeric_encoded )



    print(metrics.classification_report(train_labels_numeric_encoded, prediction_train_labels_numeric_encoded))
#print("TRAINING Accuracy = ", metrics.accuracy_score(train_labels_numeric_encoded, prediction_train_labels_numeric_encoded))
    print(f"TRAINING Accuracy with trees {i} {metrics.accuracy_score(train_labels_numeric_encoded, prediction_train_labels_numeric_encoded)}")
    Train_Accuracy.append(metrics.accuracy_score(train_labels_numeric_encoded, prediction_train_labels_numeric_encoded))

    X_test_feature = Densenet_model.predict(X_test)
    X_test_features = X_test_feature.reshape(X_test_feature.shape[0], -1)
#


# # Now predict using the trained RF model.
    prediction_RF = RF_model.predict(X_test_features)
    #print(prediction_RF [1])

# # Inverse le transform to get original label back.
#prediction_RF = le.inverse_transform(prediction_RF)
    #print(prediction_RF)
#
    #print(y_test)
#
    le.fit(prediction_RF)
    test_ko_encode=le.transform(prediction_RF)
    le.inverse_transform(test_ko_encode)
    print(metrics.classification_report(test_labels_numeric_encoded, test_ko_encode))
#print("TESTING Accuracy = ", metrics.accuracy_score(y_test, prediction_RF))


    print(f" TESTING Accuracy with trees {i} { metrics.accuracy_score(y_test, prediction_RF) } " )
    Test_Accuracy.append(metrics.accuracy_score(y_test, prediction_RF))

number_of_trees=[]
for i in range(2,301):
    number_of_trees.append(i)
    
#for i in range(2,301):
    
    
    

    
plt.bar(number_of_trees, Train_Accuracy)
plt.title('Training accuracies with random forest trees')
plt.xlabel('number of trees')
plt.ylabel('Training accuracies')
plt.figure(figsize=(15,4))
plt.show()


plt.bar(number_of_trees, Test_Accuracy)
plt.title('Test accuracies with random forest trees')
plt.xlabel('number of trees')
plt.ylabel('Test accuracies')
plt.figure(figsize=(15,4))
plt.show()

file = open("Training accuracies.txt", "w+")
file_Two = open("Testing accuracies.txt", "w+")
Temp_Training_array = np.array(Train_Accuracy)
Temp_Testing_array = np.array(Test_Accuracy)
str_Temp_Training_array = str(Temp_Training_array)
str_Temp_Testing_array = str(Temp_Testing_array)
file.write(str_Temp_Training_array)
file_Two.write(str_Temp_Testing_array)
file.close()
file_Two.close()

print(Train_Accuracy)
print(Test_Accuracy)

max_Train_Accuracy = Train_Accuracy[0]
Train_index = 0
max_Test_Accuracy = Test_Accuracy[0]
Test_index = 0



#a=[1,2,3,4,5]
#print(len(a))
#for i in range(5):
#    print(i)

for i in range(len(Train_Accuracy)):
    if (max_Train_Accuracy < Train_Accuracy[i]):
        max_Train_Accuracy = Train_Accuracy[i]
        Train_index = i

for i in range(len(Test_Accuracy)):
    if (max_Test_Accuracy < Test_Accuracy[i]):
        max_Test_Accuracy = Test_Accuracy[i]
        Test_index = i
        
        
print(f" max_Train_Accuracy{max_Train_Accuracy} index Train_index {Train_index}")        
print(f" max_Test_Accuracy{max_Test_Accuracy} index Test_index { Test_index}")

for i in range(len(Train_Accuracy)):
    print(Train_Accuracy[i])   


for i in range(len(Test_Accuracy)):
    print(Test_Accuracy[i])    




#print("Accuracy = ", metrics.accuracy_score(y_test, prediction_RF))

#from sklearn.metrics import confusion_matrix

#cm = confusion_matrix(y_test, prediction_RF)
#print(cm)
#sns.heatmap(cm, annot=True)

#Check results on a few select images
#n=np.random.randint(0, X_test.shape[0])
#img = X_test[n]
#plt.imshow(img)
#input_img = np.expand_dims(img, axis=0) #Expand dims so the input is (num images, x, y, c)
#input_img_feature=VGG_model.predict(input_img)
#input_img_features=input_img_feature.reshape(input_img_feature.shape[0], -1)
#prediction_RF = RF_model.predict(input_img_features)[0]
#prediction_RF = le.inverse_transform([prediction_RF])  #Reverse the label encoder to original name
#print("The prediction for this image is: ", prediction_RF)

#print("The actual label for this image is: ", y_test[n])



