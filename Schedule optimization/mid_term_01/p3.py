import heapq
import copy
import random
from collections import defaultdict

def prim_with_targets(n, edges, s, targets, pop_probability=0.1):
    graph = defaultdict(list)
    for u, v, w in edges:
        graph[u].append((w, v))
        graph[v].append((w, u))
    
    mst_edges = []
    mst_weight = 0
    visited = [False] * n
    pq = []
    
    # Bắt đầu từ đỉnh nguồn
    heapq.heappush(pq, (0, s, -1))  # (weight, current_node, parent_node)
    
    while pq and targets:
        # Kiểm tra xác suất để lấy phần tử từ hàng đợi
        if random.random() < pop_probability:
            w, u, parent = heapq.heappop(pq)
        else:
            continue

        if visited[u]:
            continue

        visited[u] = True
        if parent != -1:
            mst_edges.append((parent, u))  # Lưu cạnh
            mst_weight += w

        # Xóa khỏi tập targets nếu đã kết nối
        if u in targets:
            targets.remove(u)

        # Thêm các cạnh kề vào hàng đợi ưu tiên
        for edge_w, v in graph[u]:
            if not visited[v]:
                heapq.heappush(pq, (edge_w, v, u))
    
    # Kiểm tra nếu không thể kết nối tất cả targets
    if targets:
        return None
    
    return mst_weight, mst_edges

# Input
n, m = map(int, input().split())
edges = []
for _ in range(m):
    u, v, w = map(int, input().split())
    edges.append((u - 1, v - 1, w))  # Chuyển sang index 0

s = int(input()) - 1  # Đỉnh nguồn (index 0)
t = int(input())      # Số đỉnh đích
targets = set(map(lambda x: int(x) - 1, input().split()))  # Chuyển sang index 0

# Tìm MST kết nối từ s tới targets
results = []
for i in range(50):
    results.append(prim_with_targets(n, edges, s, copy.deepcopy(targets)))

# Chọn kết quả tốt nhất
min_mst_weight = float('inf')
min_id = -1
for i, result in enumerate(results):
    if result is None:
        continue
    mst_weight, _ = result
    if mst_weight < min_mst_weight:
        min_mst_weight = mst_weight
        min_id = i

if min_id == -1:
    print("Impossible to connect all targets")
else:
    mst_weight, mst_edges = results[min_id]
    print(len(mst_edges))
    for u, v in mst_edges:
        print(u + 1, v + 1)
