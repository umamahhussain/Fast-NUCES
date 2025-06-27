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

data = pd.read_excel('Aglomerative hierarchical single link dataset.xlsx')

X = data[['x-cord', 'y-cord']].values

agg_clustering = AgglomerativeClustering(n_clusters = 3)
agg_clusters = agg_clustering.fit_predict(X)

plt.scatter(X[:, 0], X[:, 1], c=agg_clusters)
plt.xlabel('X-coordinate')
plt.ylabel('Y-coordinate')
plt.title('Agglomerative Hierarchical Clustering')

for i, city in enumerate(data['city']):
    plt.annotate(city, (X[i, 0], X[i, 1]))

plt.show()

print("\n")
print("Cluster Labels:", agg_clusters)
