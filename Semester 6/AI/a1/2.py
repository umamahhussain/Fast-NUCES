from collections import deque
import heapq
import timeit

class PuzzleNode:
    def __init__(self, state, parent=None, action=None, depth=0, cost=0):
        self.state = state
        self.parent = parent
        self.action = action
        self.depth = depth
        self.cost = cost

    def expand(self):
        return [self.child_node(action) for action in self.state.actions()]

    def child_node(self, action):
        next_state = self.state.result(action)
        return PuzzleNode(next_state, self, action, self.depth + 1, self.cost + next_state.cost())

    def solution(self):
        return [node.action for node in self.path()[1:]]

    def path(self):
        node, path_back = self, []
        while node:
            path_back.append(node)
            node = node.parent
        return list(reversed(path_back))

    def __lt__(self, other):
        return self.cost < other.cost

    def __eq__(self, other):
        return self.state == other.state

    def __hash__(self):
        return hash(self.state)


class PuzzleState:
    def __init__(self, tiles):
        self.tiles = tiles

    def actions(self):
        row, col = self.find(0)
        actions = []
        if row > 0:
            actions.append("UP")
        if row < 2:
            actions.append("DOWN")
        if col > 0:
            actions.append("LEFT")
        if col < 2:
            actions.append("RIGHT")
        return actions

    def result(self, action):
        row, col = self.find(0)
        if action == "UP":
            row -= 1
        elif action == "DOWN":
            row += 1
        elif action == "LEFT":
            col -= 1
        elif action == "RIGHT":
            col += 1
        tiles = [list(row) for row in self.tiles]
        tiles[row][col], tiles[self.find(0)[0]][self.find(0)[1]] = tiles[self.find(0)[0]][self.find(0)[1]], tiles[row][col]
        return PuzzleState(tuple(map(tuple, tiles)))

    def find(self, value):
        for i, row in enumerate(self.tiles):
            for j, tile in enumerate(row):
                if tile == value:
                    return i, j

    def cost(self):
        return 1

    def __eq__(self, other):
        return self.tiles == other.tiles

    def __hash__(self):
        return hash(self.tiles)

def DFS(initial, goal):
    start_node = PuzzleNode(initial)
    if start_node.state == goal:
        return [start_node], 1  # Return the start node and count it as visited
    frontier = [start_node]
    explored = set()
    nodes_visited = 0  # Initialize node counter
    while frontier:
        node = frontier.pop()
        explored.add(node.state)
        nodes_visited += 1  # Increment node counter
        if node.state == goal:
            return node.path(), nodes_visited  # Return the solution path and node count
        for child in node.expand():
            if child.state not in explored and child not in frontier:
                frontier.append(child)
    return None, nodes_visited  # Return None if no solution is found


def BFS(initial, goal):
    start_node = PuzzleNode(initial)
    if start_node.state == goal:
        return [start_node], 1  # Return the start node and count it as visited
    frontier = deque([start_node])
    explored = set()
    nodes_visited = 0  # Initialize node counter
    while frontier:
        node = frontier.popleft()
        explored.add(node.state)
        nodes_visited += 1  # Increment node counter
        if node.state == goal:
            return node.path(), nodes_visited  # Return the solution path and node count
        for child in node.expand():
            if child.state not in explored and child not in frontier:
                frontier.append(child)
    return None, nodes_visited  # Return None if no solution is found


def IDS(initial, goal):
    depth = 0
    while True:
        result, nodes_visited = DLS(initial, goal, depth)
        if result:
            return result, nodes_visited
        depth += 1


def DLS(initial, goal, depth):
    start_node = PuzzleNode(initial)
    if start_node.state == goal:
        return [start_node], 1  # Return the start node and count it as visited
    if depth == 0:
        return None, 1  # Return None and count the start node as visited
    frontier = [start_node]
    explored = set()
    nodes_visited = 0  # Initialize node counter
    while frontier:
        node = frontier.pop()
        explored.add(node.state)
        nodes_visited += 1  # Increment node counter
        if node.state == goal:
            return node.path(), nodes_visited  # Return the solution path and node count
        if node.depth < depth:
            for child in node.expand():
                if child.state not in explored and child not in frontier:
                    frontier.append(child)
    return None, nodes_visited  # Return None if no solution is found


def UCS(initial, goal):
    start_node = PuzzleNode(initial)
    if start_node.state == goal:
        return [start_node], 1  # Return the start node and count it as visited
    frontier = [(start_node.cost, start_node)]
    explored = set()
    nodes_visited = 0  # Initialize node counter
    while frontier:
        cost, node = heapq.heappop(frontier)
        explored.add(node.state)
        nodes_visited += 1  # Increment node counter
        if node.state == goal:
            return node.path(), nodes_visited  # Return the solution path and node count
        for child in node.expand():
            if child.state not in explored:
                heapq.heappush(frontier, (child.cost, child))
    return None, nodes_visited  # Return None if no solution is found

def print_solution(algorithm, solution, time_taken, nodes_visited):
    print("-----------------")
    print(f"{algorithm} Algorithm")
    print("-----------------")
    if solution:
        print("Solution Path:")
        print_states_along_path(solution)  # Print the state of each node in the solution path
        print("-----------------")
        print(f"Time taken: {time_taken} seconds")
        print(f"Path Cost: {len(solution)}")
        print(f"No of Node Visited: {nodes_visited}")
        print("-----------------")
    else:
        print("No solution found.")
        print("-----------------")

def print_states_along_path(solution):
    for i, node in enumerate(solution):
        print(f"State {i + 1}:")
        print_state(node.state)
        print("-----")

def print_state(state):
    for row in state.tiles:
        print(" ".join(str(tile) for tile in row))


def main():
    initial_state = PuzzleState(((1, 2, 0), (3, 4, 5), (6, 7, 8)))
    goal_state = PuzzleState(((0, 1, 2), (3, 4, 5), (6, 7, 8)))

    # Measure time taken for DFS
    dfs_solution, dfs_nodes_visited = DFS(initial_state, goal_state)
    dfs_time = timeit.timeit(lambda: DFS(initial_state, goal_state), number=1)

    # Measure time taken for BFS
    bfs_solution, bfs_nodes_visited = BFS(initial_state, goal_state)
    bfs_time = timeit.timeit(lambda: BFS(initial_state, goal_state), number=1)

    # Measure time taken for IDS
    ids_solution, ids_nodes_visited = IDS(initial_state, goal_state)
    ids_time = timeit.timeit(lambda: IDS(initial_state, goal_state), number=1)

    # Measure time taken for UCS
    ucs_solution, ucs_nodes_visited = UCS(initial_state, goal_state)
    ucs_time = timeit.timeit(lambda: UCS(initial_state, goal_state), number=1)

    # Print results
    print_solution("DFS", dfs_solution, dfs_time, dfs_nodes_visited)
    print_solution("BFS", bfs_solution, bfs_time, bfs_nodes_visited)
    print_solution("IDS", ids_solution, ids_time, ids_nodes_visited)
    print_solution("UCS", ucs_solution, ucs_time, ucs_nodes_visited)

if __name__ == "__main__":
    main()
