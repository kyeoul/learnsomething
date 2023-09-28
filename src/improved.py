def max_area(height):
    max_area = 0
    n = len(height)

    ptr1 = 0
    ptr2 = n - 1

    while(ptr1 < ptr2):
        h1 = height[ptr1]
        h2 = height[ptr2]
        width = ptr2 - ptr1
        current_area = min(h1, h2) * width
        max_area = max(max_area, current_area)

        if(h1 < h2):
            ptr1 += 1
        else:
            ptr2 += 1

    return max_area
