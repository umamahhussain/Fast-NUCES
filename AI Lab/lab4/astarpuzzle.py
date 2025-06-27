import heapq

# Define a class for the cell/node
class Node:
    def __init__(self, position, parent=None):
        self.position = position
        self.parent = parent
        self.g = 0
        self.h = 0
        self.f = 0

    def __eq__(self, other):
        return self.position == other.position

    def __lt__(self, other):
        return self.f < other.f

    def __hash__(self):
        return hash(self.position)

# Define heuristic function (Manhattan distance)
def heuristic(current_node, goal_node):
    return abs(current_node.position[0] - goal_node.position[0]) + abs(current_node.position[1] - goal_node.position[1])

# Define A* algorithm
def astar(matrix, start, goal):
    open_list = []
    closed_list = set()
    
    start_node = Node(start)
    goal_node = Node(goal)
    
    heapq.heappush(open_list, start_node)
    
    while open_list:
        current_node = heapq.heappop(open_list)
        closed_list.add(current_node)
        
        if current_node == goal_node:
            path = []
            while current_node:
                path.append(current_node.position)
                current_node = current_node.parent
            return len(path) - 1, path[::-1] # Number of steps and path
            
        children = []
        for new_position in [(0, -1), (0, 1), (-1, 0), (1, 0)]:
            node_position = (current_node.position[0] + new_position[0], current_node.position[1] + new_position[1])
            
            if node_position[0] < 0 or node_position[0] >= len(matrix) or node_position[1] < 0 or node_position[1] >= len(matrix[0]):
                continue
                
            if matrix[node_position[0]][node_position[1]] == 1:
                continue
            
            new_node = Node(node_position, current_node)
            children.append(new_node)
        
        for child in children:
            if child in closed_list:
                continue
                
            child.g = current_node.g + 1
            child.h = heuristic(child, goal_node)
            child.f = child.g + child.h
            
            if any(open_node.position == child.position and open_node.f < child.f for open_node in open_list):
                continue
                
            heapq.heappush(open_list, child)
    
    return None

# Define the matrix and blocked cells
matrix = [
    [0, 0, 0, 0],
    [0, 0, 1, 0],
    [0, 1, 0, 0],
    [0, 0, 0, 0],
    [0, 0, 0, 0]
]

# Define start and goal positions
start_position = (1, 1)
goal_position = (3, 3)

# Run A* algorithm
result = astar(matrix, start_position, goal_position)
if result:
    steps, path = result
    print("Minimum number of steps:", steps)
    print("Intermediate path:", path)
else:
    print("No path found.")