#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

//	T - long int
//	V - long int
//


template < class T, class V >
struct SegmentTreeNode
{
	T data;
	V property;

	void assigninitialvalues(T dt = 0)
	{
		data = dt;
		property = dt;
	}

	SegmentTreeNode merge(SegmentTreeNode &node1, SegmentTreeNode &node2)
	{
		SegmentTreeNode<T,V> node;
		node.assigninitialvalues();
		//	The OPeration to make the
		//	Statistic into order.
		node.property = node1.property + node2.property;
		return node;
	}

	SegmentTreeNode mergeforquery(SegmentTreeNode node1, SegmentTreeNode node2)
	{
		SegmentTreeNode<T,V> node;
		node.assigninitialvalues();
		//	The OPeration to make the
		//	Statistic into order.
		node.property = node1.property + node2.property;
		return node;
	}

	void displayreqdval()
	{
		printf("%ld\n", property);
	}
};


template< class T, class V >
class SegmentTree
{
private:
	
	vector < SegmentTreeNode<T,V> > Tree;
	int sizeoftree;

public:

	void initializebysize(int N)
	{
		int size =  1,i;
		for (; size < N; size<<=1);
		size<<=1;
		sizeoftree = size;
		for (i = 0; i < size; ++i)
		{
			SegmentTreeNode<T,V> node;
			node.assigninitialvalues();
			Tree.push_back(node);
		}
	}

	SegmentTreeNode<T,V>& MakeTree(vector < T > &datavec, int left, int right, int curindex = 1)
	{

		cout<<"left : "<<left<<" right : "<<right<<" Curindex : "<<curindex<<" size : "<<sizeoftree<<endl;
		if (left >= right)
		{
			Tree[curindex].assigninitialvalues(datavec[left]);
			return Tree[curindex];
		}
		else
		{
			int mid = (left + right)/2;
			Tree[curindex] = Tree[curindex].merge(MakeTree(datavec, left, mid, 2 * curindex),MakeTree(datavec, mid+1,right,2*curindex+1));
			return Tree[curindex];
		}
	}

	SegmentTreeNode<T,V> Query(int low, int high, int left, int right, int curindex = 1)
	{
		cout<<"left : "<<left<<" right : "<<right<<" Curindex : "<<curindex<<" low: "<<low<<" high: "<<high<<endl;
		if (low == left && high == right)
			return Tree[curindex];
		else
		{
			int mid = (left+right)/2;
			if (low > mid)
				return Query(low,high,mid+1,right,2*curindex+1);
			else if(high <= mid)
				return Query(low, high, left, mid, 2*curindex);
			else if(low <= mid && high >= mid)
			{
				SegmentTreeNode<T,V> node;
				return node.mergeforquery(Query(low,mid,left,mid,2*curindex),Query(mid+1,high,mid+1,right,2*curindex+1));
			}
			else
			{
				SegmentTreeNode<T,V> node;
				node.assigninitialvalues(0);
				return node;
			}
		}
	}

	void printquery(int low,int high, int datasize)
	{
		Query(low,high,1,datasize).displayreqdval();
	}

	SegmentTreeNode<T,V> Update(int indextoupdate, int left, int right, int curindex, T newval)
	{
		if (left == right)
		{
			Tree[curindex].data = newval;
			Tree[curindex].property = newval;
			return Tree[curindex];
		}
		else
		{
			int mid = (left + right)/2;
			if (indextoupdate <= mid)
			{
				return Tree[curindex] = Tree[curindex].mergeforquery(Update(indextoupdate,left,mid,2*curindex,newval),Tree[2*curindex+1]);
			}
			else
			{
				return Tree[curindex] = Tree[curindex].mergeforquery(Tree[2*curindex],Update(indextoupdate,mid+1,right,2*curindex+1,newval));
			}
		}
	}

	void printdata()
	{
		int i;
		for (i = 0; i < sizeoftree; ++i)
		{
			cout<<Tree[i].property<<" ";
		}
		cout<<endl;
	}
};


int main(void)
{
	int n,i,q,f,l;
	long int ele,k;
	scanf("%d",&n);
	vector < long int > data;
	data.push_back(-1);
	for (i = 0; i < n; ++i)
	{
		scanf("%ld",ele);
		data.push_back(ele);
	}
	SegmentTree tree;
	tree.MakeTree(data,1,data.size()-1);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d%ld",&f,&l,&k);
		tree.printquery(f,l,k,data.size()-1);
	}
}