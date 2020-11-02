# encoding:utf-8
from collections import defaultdict
from random import uniform
from math import sqrt
import matplotlib.pyplot as plt
import matplotlib.colors


#读取txt文件到数据矩阵中
def read_points():
    dataset = []
    with open('data.txt', 'r') as file:
    #with open('Iris.txt', 'r') as file:
        for line in file:
            if line == '\n':
                continue
            dataset.append(list(map(float, line.split(' '))))
        file.close()
        return dataset


def distance(a, b):
    dimention = len(a)
    sum = 0
    for i in range(dimention):
        sq = (a[i] - b[i]) ** 2
        sum += sq
    return sqrt(sum)


#更新中心点时调用
#计算一类点的中心点
def point_avg(points):
    dimensions = len(points[0])
    new_center = []
    for dimension in range(dimensions):
        sum = 0
        for p in points:
            sum += p[dimension]
        new_center.append(float("%.8f" % (sum / float(len(points)))))
    return new_center


#更新中心点
def update_centers(data_set, assignments, k):
    new_means = defaultdict(list)
    centers = []
    for assignment, point in zip(assignments, data_set):
        new_means[assignment].append(point)
    for i in range(k):
        points = new_means[i]
        centers.append(point_avg(points))
    return centers


#用于确定每个点属于哪个聚类中心
def assign_points(data_points, centers):
    assignments = []
    for point in data_points:
        shortest = float('inf')
        shortest_index = 0
        #对k个聚类中心进行遍历
        for i in range(len(centers)):
            value = distance(point, centers[i])
            if value < shortest:
                shortest = value
                shortest_index = i
        #assignments用于存储当前点属于哪个聚类中心
        assignments.append(shortest_index)
    #set()函数创建的为无需不重复序列
    if len(set(assignments)) < len(centers):
        print("\n--!!分类好的数据聚类中心小于规定值，请重新运行程序！!!!--\n")
        exit()
    return assignments


#随机初始化k个聚类中心
#计算聚类的k个中心点的坐标（在这为四维的）
def generate_k(data_set, k):
    centers = []
    #读取第一行数据长度 判断一共有几维数据
    dimentions = len(data_set[0])
    min_max = defaultdict(int)
    for j in range(k):
        rand_point = []
        for i in range(dimentions):
            #uniform() 随机生成在 [x, y] 范围内的实数。
            tmp = float("%.3f" % (uniform(0, 8)))
            rand_point.append(tmp)
        centers.append(rand_point)
    return centers
 
 
#kmeans++算法实现
#初始化k个聚类中心点时采用取大距离的方法选取下一个聚类中 
def kpp_centers(data_set: list, k: int) -> list:
     """
     从数据集中返回 k 个对象可作为质心
     """
     cluster_centers = []
     cluster_centers.append(random.choice(data_set))
     d = [0 for _ in range(len(data_set))]
     for _ in range(1, k):
         total = 0.0
         for i, point in enumerate(data_set):
             d[i] = get_closest_dist(point, cluster_centers) # 与最近一个聚类中心的距离
             total += d[i]
         total *= random.random()
        for i, di in enumerate(d): # 轮盘法选出下一个聚类中心；
             total -= di
             if total > 0:
                 continue
             cluster_centers.append(data_set[i])
             break
    return cluster_centerss

#数据集 类别 聚类中心
def Drawing(dataset, assignments, centers):
    x = []
    y = []
    xo = []
    yo = []
    # 打印二维数组的每一个值
    #获取数据的第一列和第二列作为x y值 用于画图
    for i in range(len(dataset)):
        x.append(dataset[i][0])
        y.append(dataset[i][1])
    for i in range(len(centers)):
        xo.append(centers[i][0])
        yo.append(centers[i][1])
    # 下面两行代码代表可以输出中文
    matplotlib.rcParams['font.sans-serif'] = [u'SimHei']
    matplotlib.rcParams['axes.unicode_minus'] = False
    #画中心点
    plt.scatter(xo, yo, c='k', marker='x')
    plt.scatter(x, y, c=assignments)
    plt.title(u'K-Means聚类')
    # plt.grid(linestyle=":", color="r")  linestyle：网格线的线条风格 color：网格线的线条颜色
    plt.grid()
    plt.show()


def k_means(dataset, k):
    #初始化k个聚类中心点
    k_points = generate_k(dataset, k)
    assignments = assign_points(dataset, k_points)
    old_assignments = None
    while assignments != old_assignments:
        new_centers = update_centers(dataset, assignments, k)
        old_assignments = assignments
        assignments = assign_points(dataset, new_centers)
    #带标签的数据（已经分类好属于哪一类）zip字典
    #result = list(zip(assignments, dataset))
    Drawing(dataset, assignments, new_centers)


if __name__ == "__main__":
    dataset = read_points()
    k_means(dataset, 3)
    #print("\n{}".format(dataset[0]))