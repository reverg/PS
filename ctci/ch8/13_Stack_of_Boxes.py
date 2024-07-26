class Box:
    def __init__(self, w, h, d):
        self.width = w
        self.height = h
        self.depth = d

    def can_be_under(self, b):
        return self.width > b.width and self.height > b.height and self.depth > b.depth

    def can_be_above(self, b):
        if not b:
            return True
        return self.width < b.width and self.height < b.height and self.depth < b.depth

    def __str__(self):
        return f"Box({self.width},{self.height},{self.depth})"


class BoxComparator:
    def compare(self, x, y):
        return y.height - x.height


def create_stack(boxes):
    boxes.sort(key=lambda box: box.height, reverse=True)
    max_height = 0
    stack_map = [0] * len(boxes)
    for i in range(len(boxes)):
        height = create_stack_helper(boxes, i, stack_map)
        max_height = max(max_height, height)
    return max_height


def create_stack_helper(boxes, bottom_index, stack_map):
    if bottom_index < len(boxes) and stack_map[bottom_index] > 0:
        return stack_map[bottom_index]

    bottom = boxes[bottom_index]
    max_height = 0
    for i in range(bottom_index + 1, len(boxes)):
        if boxes[i].can_be_above(bottom):
            height = create_stack_helper(boxes, i, stack_map)
            max_height = max(height, max_height)
    max_height += bottom.height
    stack_map[bottom_index] = max_height
    return max_height


if __name__ == "__main__":
    box_list = [
        Box(6, 4, 4),
        Box(8, 6, 2),
        Box(5, 3, 3),
        Box(7, 8, 3),
        Box(4, 2, 2),
        Box(9, 7, 3),
    ]
    height = create_stack(box_list)
    print(height)
