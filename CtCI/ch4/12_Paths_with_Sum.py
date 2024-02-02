class TreeNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


def count_paths_with_sum(root, target_sum):
    return count_paths_with_sum_helper(root, target_sum, 0, {})


def count_paths_with_sum_helper(node, target_sum, running_sum, path_count):
    if node is None:
        return 0

    running_sum += node.data

    # Count paths with sum ending at the current node
    total_paths = path_count.get(running_sum - target_sum, 0)

    # If running_sum equals target_sum, then one additional path starts at root. Add in this path.
    if running_sum == target_sum:
        total_paths += 1

    # Add running_sum to pathCounts
    path_count[running_sum] = path_count.get(running_sum, 0) + 1

    # Count paths with sum on the left and right
    total_paths += count_paths_with_sum_helper(
        node.left, target_sum, running_sum, path_count
    )
    total_paths += count_paths_with_sum_helper(
        node.right, target_sum, running_sum, path_count
    )

    # Remove running_sum
    path_count[running_sum] -= 1
    if path_count[running_sum] == 0:
        del path_count[running_sum]

    return total_paths


if __name__ == "__main__":
    root = TreeNode(0)
    root.left = TreeNode(0)
    root.right = TreeNode(0)
    root.right.left = TreeNode(0)
    root.right.left.right = TreeNode(0)
    root.right.right = TreeNode(0)
    print(count_paths_with_sum(root, 0))
    print(count_paths_with_sum(root, 4))
