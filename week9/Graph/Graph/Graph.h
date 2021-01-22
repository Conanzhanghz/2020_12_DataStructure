//删除节点，把最后一个节点放在删除节点的位置
//考试的时候资源释放俩分，vertexes，tag，arcs等等都要释放
//多少个new，要有多少个delete

template<class T>
class AdjMatrixUndirGraph
{
protected:
	//vertex节点
	//vexNum节点数目
	//vexMaxNum最大节点数目
	//arc边数目
	int vexNum, vexMaxNum, arcNum;
	//存放边信息的邻接矩阵
	int** arcs;
	//存放顶点信息的邻接矩阵
	T* vertexes;
	//标志数组
	//mutable Status* tag;
public:
	//根据es数组的数据元素，构造顶点个数为vertexNum、允许的顶点最大数目为vertexMAXNum、边数为0的无向图
	AdjMatrixUndirGraph(T es[], int vertexNum, int vertexMaxNum);
	//T& ??
	void InsertVex(const T& d);
};

template<class T>
AdjMatrixUndirGraph<T>::AdjMatrixUndirGraph(T es[], int vertexNum, int vertexMaxNum)
{
	vexNum = vertexNum;
	vexMaxNum = vertexMaxNum;
	arcNum = 0;
	vertexes = new T[vertexNum];
	//??
	arcs = (int**)new int* [vertexMaxNum];
	//初始化顶点矩阵
	for (int v = 0; v < vexMaxNum; v++)
	{
		arcs[v] = new int[vertexMaxNum];
	}
	//初始化邻接矩阵
	for (int v = 0; v < vexNum; v++)
	{
		vertexes[v] = es[v];
		for (int u = 0; u < vexNum; u++)
		{
			arcs[v][u] = 0;
		}
	}
}

template<class T>
void AdjMatrixUndirGraph<T>::InsertVex(const T& d)
{
	if (vexNum == vexMaxNum)
	{
		return;
	}
	else
	{
		vertexes[vexNum] = d;
		for (int v = 0; v <= vexNum; v++)
		{

		}
	}
}
