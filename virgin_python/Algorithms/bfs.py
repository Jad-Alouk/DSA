from collections import deque

# Using deque improves efficiency when removing the first element

def bfs(graph, source):

    # Initialize a queue with the starting node
    queue = deque([source])

    # A set that keeps track of visited nodes to avoid infinite loops in case of cycles
    visited = set()

    # Terminating condition is the empty queue
    while queue:

        # Shift from the queue to prioritize breadth
        curr = queue.popleft()

        # Skip if the node is already visited
        if curr in visited:
            continue

        # Track the visited nodes
        visited.add(curr)

        # Process the current node
        print(curr)

        # Add neighbors at the end of the queue to process FIFO
        for neighbor in graph[curr]:

            if neighbor not in visited:
                queue.append(neighbor)


# Time:
#   V = number of vertices
#   E = number of edges
#
#   O(V + E) => Each vertex is pushed and popped at most once O(V),
#   and each edge is considered exactly once in the loop O(E)

# Space:
#   O(V) => Deque can hold up to O(V) nodes in the worst case and 
#   the visited set contains at most V elements so O(2V) which is O(V)