import numpy as np
import pandas as pd
from scipy import ndimage
from scipy.cluster import hierarchy
from scipy.spatial import distance_matrix
from matplotlib import pyplot as plt
from sklearn import manifold, datasets
from sklearn.cluster import AgglomerativeClustering
from sklearn.datasets import make_blobs
from sklearn.cluster import KMeans
from sklearn.neighbors import KNeighborsClassifier

pdf = pd.read_excel('k mean dataset.xlsx')
print ("Shape of dataset: ", pdf.shape)

datasets = pdf[['x', 'y']]

k = 3

kmeans_sklearn = KMeans(n_clusters=k)
kmeans_sklearn.fit(datasets)

centroids_sklearn = kmeans_sklearn.cluster_centers_
labels_sklearn = kmeans_sklearn.labels_

plt.scatter(datasets['x'], datasets['y'], c=labels_sklearn, label='Data Points')
plt.scatter(centroids_sklearn[:, 0], centroids_sklearn[:, 1], marker='x', color='red', label='Centroids')

plt.title('K-means Clustering (scikit-learn)')
plt.xlabel('X')
plt.ylabel('Y')
plt.legend()
plt.grid(True)
plt.show()