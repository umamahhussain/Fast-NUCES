import cv2
import matplotlib.pyplot as plt
import math
# img=cv2.imread("1.png")
# cv2.imshow("image", img)
# cv2.waitKey(0)

# dimensions = img.shape
# height = img.shape[1] 
# width= img.shape[0]
# number_of_channels = img.shape[2]

# print("Height: ",height,"\nWidth: ",width,"\nNum of Channels: ",number_of_channels)

# for i in range(0,width):
#     for j in range(0,height):
#         sum=img[i][j][0]+img[i][j][1]+img[i][j][2]
#         avg=sum/3
#         img[i][j][0]=avg
#         img[i][j][1]=avg
#         img[i][j][2]=avg

# cv2.imshow("image", img)
# cv2.waitKey(0)



cat=cv2.imread('1.png')
catx=cv2.imread('1.png')
caty=cv2.imread('1.png')

dimensions = cat.shape
height = cat.shape[1] 
width= cat.shape[0]
number_of_channels = cat.shape[2]


# for i in range(width): 
#     for j in range(height): 
#         cat[i][j][0]=round((cat[i][j][0]*0.30)) 
#         cat[i][j][1] =round((cat[i][j][1] * 0.59))
#         cat[i][j][2] =round((cat[i][j][2] * 0.21))
#         b=(int(cat[i][j][0]))
#         c= (int(cat[i][j][1])) 
#         d=(int(cat[i][j][2]))
#         e=int(int(b)+int(c)+int(d))
#         f=int(int(e)//3)
#         cat[i][j][0]=f 
#         cat[i][j][1] =f 
#         cat[i][j][2] = f
#         catx[i][j][0] = f
#         catx[i][j][1] = f
#         catx[i][j][2] = f
#         caty[i][j][0] = f
#         caty[i][j][1] = f
#         caty[i][j][2] = f
#         dog=cat

# cv2.imshow("image of cat",cat)
# cv2.waitKey()


# sfilter =[[0 for i in range(3)]for j in range(3)]
# cv2.imread("1.png")

s1,s2,s3,s4,s5,s6,s7,s8,s9,s10=0,0,0,0,0,0,0,0,0,0

# for i in range(width): 
#     for j in range(height):
#         s1, s2, s3, s4, s5, s6, s7, s8, s9, s10 = 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#         if i<width-1 and j<height-1: 
#             s1 = sfilter[1][1]=catx[i][j][0]//9
#             s2 = sfilter[1][0]=catx[i][j-1][0]//9
#             s3 =sfilter[1][2]=catx[i][j+1][0]//9#*2
#             s4 = sfilter[0][0]=catx[i-1][j-1][0]//9
#             s5 = sfilter[0][1]=catx[i-1][j][0]//9#*2
#             s6 = sfilter[0][2]=catx[i-1][j+1][0]//9#*1 
#             s7 =sfilter[2][0]=catx[i+1][j-1][0]//9#*1 
#             s8 =sfilter[2][1]=catx[i+1][j][0]//9#*2 
#             s9 =sfilter[2][2]=catx[i+1][j+1][0]//9#*1
#             s10=s1+s2+s3+s4+s5+s6+s7+s8+s9
#             catx[i][j][0]=s10 
#             catx[i][j][1] = s10
#             catx[i][j][2] = s10 
#             caty[i][j][0] =s10 
#             caty[i][j][1] = s10
#             caty[i][j][2] = s10

# cv2.imshow('image of blur cat',caty)
# cv2.waitKey()

# pfilter =[[0 for i in range(3)]for j in range(3)]

# i,j,k=0,0,0 
# h,m,n=0,0,0 

# for i in range(width):
#     for j in range(height): 
#         if i<=width-3 and j<=height-3: 
#             pfilter[0][0] = cat[i][j]   
#             pfilter[0][2] = cat[i][j + 2]
#             pfilter[1][0] = cat[i + 1][j] 
#             pfilter[1][2] =cat[i + 1][j + 2] 
#             pfilter[2][0] = cat[i + 2][j]
#             pfilter[2][2] = cat[i + 2][j + 2] 
#             h = (1 *pfilter[0][0]) + (pfilter[0][2] * -1) 
#             m = (2 *pfilter[1][0]) + (pfilter[1][2] * -2) 
#             n = (1 *pfilter[2][0]) + (pfilter[2][2] * -1)
#             total=h+m+n 
#             cat[i][j]=abs(total)
#             catx[i][j]=cat[i][j] # 
#             caty[i][j] = cat[i][j]

# cv2.imshow("sobel filter with vertical blurring",catx) 
# cv2.waitKey()

# for i in range(width):
#     for j in range(height): 
#         if i<=width-3 and j<=height-3:
#             pfilter[0][0] = caty[i][j] 
#             pfilter[2][0] =caty[i+2][j] 
#             pfilter[0][1] = caty[i][j+1]
#             pfilter[2][1] = caty[i + 2][j + 1]
#             pfilter[0][2] = caty[i][j+2] 
#             pfilter[2][2] =caty[i + 2][j + 2] 
#             h = (1 * pfilter[0][0]) +(pfilter[2][0] * -1) 
#             m = (2 * pfilter[0][1]) +(pfilter[2][1] * -2) 
#             n = (1 * pfilter[0][2]) +(pfilter[2][2] * -1) 
#             total=h+m+n
#             cat[i][j]=abs(total) 
#             caty[i][j]=cat[i][j]


# cv2.imshow("sobel apply with horizontal sobel ",caty)
# cv2.waitKey()

# i,j=0,0 
# for i in range(width): 
#     for j in range(height):
#         mag=(math.sqrt(int(catx[i][j][0])**2 + int(caty[i][j][0])**2))
#         dog[i][j] = mag

# cv2.imshow("magnitude formula",dog)
# cv2.waitKey() 
# cv2.destroyAllWindows()
# cv2.destroyAllWindows()

A=[]
B=[]
C=[]

# for i in range(width): 
#     for j in range(height):
#         A[cat[i][j][0]]+=1
#         B[cat[i][j][1]]+=1
#         C[cat[i][j][2]]+=1

cat = cv2.imread('1.png')
# Convert the image to grayscale
gray_cat = cv2.cvtColor(cat, cv2.COLOR_BGR2GRAY)
# Calculate the histogram
histogram = cv2.calcHist([gray_cat], [0], None, [256], [0, 256])

# Plot the histogram
plt.plot(histogram, color='black')
plt.xlabel('Pixel Intensity')
plt.ylabel('Frequency')
plt.title('Histogram of Grayscale Image')
plt.show()

