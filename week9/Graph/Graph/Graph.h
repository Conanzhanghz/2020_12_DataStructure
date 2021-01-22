//ɾ���ڵ㣬�����һ���ڵ����ɾ���ڵ��λ��
//���Ե�ʱ����Դ�ͷ����֣�vertexes��tag��arcs�ȵȶ�Ҫ�ͷ�
//���ٸ�new��Ҫ�ж��ٸ�delete

template<class T>
class AdjMatrixUndirGraph
{
protected:
	//vertex�ڵ�
	//vexNum�ڵ���Ŀ
	//vexMaxNum���ڵ���Ŀ
	//arc����Ŀ
	int vexNum, vexMaxNum, arcNum;
	//��ű���Ϣ���ڽӾ���
	int** arcs;
	//��Ŷ�����Ϣ���ڽӾ���
	T* vertexes;
	//��־����
	//mutable Status* tag;
public:
	//����es���������Ԫ�أ����춥�����ΪvertexNum������Ķ��������ĿΪvertexMAXNum������Ϊ0������ͼ
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
	//��ʼ���������
	for (int v = 0; v < vexMaxNum; v++)
	{
		arcs[v] = new int[vertexMaxNum];
	}
	//��ʼ���ڽӾ���
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
