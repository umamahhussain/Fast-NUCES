import cv2
import math

img=cv2.imread('1.png')
img=cv2.resize(img,(40,40))

dimensions = img.shape
height = img.shape[1] 
width= img.shape[0]
number_of_channels = img.shape[2]

w, h = width,height
array = [[0 for x in range(w)] for y in range(h)]
print(array)
temp1=0
temp2=0

for i in range(39):
  for j in range(39):
    temp1=img[i][j][0]
    temp2=img[i+1][j+1][0]
    print(temp1,temp2)
    array[temp1][temp2]+=1

    temp1=img[i][j][1]
    temp2=img[i+1][j+1][1]
    print(temp1,temp2)
    array[temp1][temp2]+=1

    temp1=img[i][j][2]
    temp2=img[i+1][j+1][2]
    print(temp1,temp2)
    array[temp1][temp2]+=1

print(array)
