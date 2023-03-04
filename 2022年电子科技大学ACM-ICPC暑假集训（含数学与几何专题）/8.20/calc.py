inf = 1000000000
ax, ay = eval(input())
bx, by = eval(input())
cx, cy = eval(input())
dx, dy = eval(input())
k1 = (by - ay) / (bx - ax)
b1 = ay - k1 * ax
k2 = (dy - cy) / (dx - cx)
b2 = cy - k2 * cx
print("k1 = {}, b1 = {}".format(k1, b1))
print("k2 = {}, b2 = {}".format(k2, b2))
x = (b2 - b1) / (k1 - k2)
y = k1 * x + b1
print("X = {}".format(x))
print("Y = {}".format(y))
