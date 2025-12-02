def dfs(graph, source):

    # Initialize an arr as a stack with the starting node
    stack = [source]

    # A set that keeps track of visited nodes to avoid infinite loops in case of cycles
    visited = set()

    # Base case is the empty stack
    while stack:

        # Pop from the stack to prioritize depth
        curr = stack.pop()

        # Skip if the node is already visited
        if curr in visited:
            continue
        
        # Track the visited nodes
        visited.add(curr)

        # Process the current node
        print(curr)

        # Add neighbors in reverse so the leftmost neighbor is processed first
        for neighbor in reversed(graph[curr]):

            if neighbor not in visited:
                stack.append(neighbor)


def dfs_rec(graph, source, visited = None):

    # A set that keeps track of visited nodes to avoid infinite loops in case of cycles
    if visited is None:
        visited = set()

    # Track the visited nodes
    visited.add(source)

    # Process the node
    print(source)

    for neighbor in graph[source]:

        if neighbor not in visited:
            dfs_rec(graph, neighbor, visited)


# Time:
#   V = number of vertices
#   E = number of edges
#
#   O(V + E) => Each vertex is pushed and popped at most once O(V),
#   and each edge is considered exactly once in the loop O(E)

# Space:
#   O(V) => Stack can hold up to O(V) nodes in the worst case and 
#   the visited set contains at most V elements so O(2V) which is O(V)

# Notes:
#   Both iterative and recursive versions have the same complexity analysis.
#   In the former the stack is explicit and in the later it is implicit.
#   Iterative DFS avoids recursion depth limits.
#   Recursive DFS is cleaner & more readable.