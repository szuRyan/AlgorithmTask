class SortedArray:
    def __init__(self, capacity = 20):
        """
        构造函数
        """
        self._capacity = capacity  #数组最大容量
        self._size = 0             #数组已使用的大小
        self._data = [None]*self._capacity #初始化元素
    
    def SortedArrayAdd(self, elem):
        """
        对大小固定的有序数组进行增加元素
        elem:待添加元素
        """
        #首元素添加
        if self._size == 0:
            self._data[0] = elem
            self._size += 1
            return 
        #数组已满就退出
        if self._size == self._capacity:
            print("数组已满")
            return
        #倒序遍历数组，移动后面的元素，直到找到插入位置
        for i in range(self._size-1, -1, -1):
            if elem < self._data[i]:
                self._data[i+1] = self._data[i]
            else:
                break
        #找到位置进行插入，更新size
        self._data[i+1] = elem
        self._size += 1
        
    def Delet(self, index):
        """
        删除指定位置index的元素
        """
        #1.判断index的合法性
        if index<0 or index>self._size-1:
            print("index不合法！删除失败")
            return 
        #2.依次挪动元素
        for i in range(index+1, self._size, 1):
            self._data[i-1] = self._data[i]
        #3.更新size
        self._size -=1
       
    def print(self):
        """
        打印数组
        """
        for i in range(self._size):
            print(self._data[i],end = '\t')
			
			
array1 = SortedArray(20)
for i in range(10):
    array1.SortedArrayAdd(i+1)
array1.print()
#添加元素
print("\n添加元素:")
array1.SortedArrayAdd(1.23)
array1.print()
print()
array1.SortedArrayAdd(4)
array1.print()
#删除元素
print("\n删除元素:")
array1.Delet(6)
array1.print()
