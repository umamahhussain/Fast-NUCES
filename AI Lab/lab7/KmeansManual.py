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

def euclidean_distance(point1, point2):
    return ((point1[0] - point2[0])**2 + (point1[1] - point2[1])**2)**0.5

def compute_distances(data, centroids):
    distances = np.zeros((len(centroids), len(data)))

    for i, centroid in enumerate(centroids):
        for j, point in enumerate(data):
            distances[i, j] = euclidean_distance(point, centroid)
    return distances

def k_means(data, initial_centroids, max_iters=100):
    data_np = data[['x', 'y']].values
    centroids = np.array(initial_centroids)

    for _ in range(max_iters):
        distances = compute_distances(data_np, centroids)
        labels = np.argmin(distances, axis=0)

        for i, centroid in enumerate(centroids):
            data[f'({centroid[0]},{centroid[1]})'] = distances[i]

        data[f'Cluster_{_+1}'] = labels + 1

        new_centroids = []
        for j in range(len(centroids)):
            cluster_points = data_np[labels == j]
            if len(cluster_points) > 0:
                new_centroids.append(cluster_points.mean(axis=0))
            else:
                new_centroids.append(centroids[j])

        new_centroids = np.array(new_centroids)

        if np.all(centroids == new_centroids):
            break

        centroids = new_centroids

    return centroids, labels


pdf = pd.read_excel('k mean dataset.xlsx')
initial_centroids = [[2, 10], [5, 8], [1, 2]]


centroids, labels = k_means(pdf, initial_centroids)

print(pdf)
print("\n")

for cluster in np.unique(labels):
    plt.scatter(pdf['x'][labels == cluster], pdf['y'][labels == cluster], label=f'Cluster {cluster+1}')

plt.scatter(centroids[:, 0], centroids[:, 1], c='black', marker='x', label='Centroids')

plt.xlabel('X')
plt.ylabel('Y')
plt.title('K-Means Clustering')
plt.legend()
plt.grid(True)
plt.show()