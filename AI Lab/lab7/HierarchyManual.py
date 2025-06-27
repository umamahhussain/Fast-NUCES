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

def agglomerative_clustering(X, n_clusters):

    clusters = [[i] for i in range(len(X))]

    distances = np.zeros((len(X), len(X)))
    for i in range(len(X)):
        for j in range(i+1, len(X)):
            distances[i, j] = euclidean_distance(X[i], X[j])
            distances[j, i] = distances[i, j]

    while len(clusters) > n_clusters:
        min_distance = np.inf
        min_i, min_j = -1, -1
        for i in range(len(clusters)):
            for j in range(i+1, len(clusters)):
                cluster_distance = min(distances[clusters[i], :][:, clusters[j]])
                if cluster_distance < min_distance:
                    min_distance = cluster_distance
                    min_i, min_j = i, j

        clusters[min_i].extend(clusters[min_j])
        del clusters[min_j]

    labels = np.zeros(len(X), dtype=int)
    for i, cluster in enumerate(clusters):
        labels[cluster] = i

    return labels

data = pd.read_excel('Aglomerative hierarchical single link dataset.xlsx')
X = data[['x-cord', 'y-cord']].values

agg_clusters = agglomerative_clustering(X, n_clusters=3)

plt.scatter(X[:, 0], X[:, 1], c=agg_clusters)
plt.xlabel('X-coordinate')
plt.ylabel('Y-coordinate')
plt.title('Agglomerative Hierarchical Clustering')

for i, city in enumerate(data['city']):
    plt.annotate(city, (X[i, 0], X[i, 1]))

plt.show()

print("\n")
print("Cluster Labels:", agg_clusters)
