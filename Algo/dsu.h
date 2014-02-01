/*
	Disjoint Set Union by Aidarbek Suleymenov - 2014
*/
class DSU
{
	public:
	int parent[10000];
	int   size[10000];
	int changeValue(int x,int y)
	{
		int c = x;
	    	x = y;
	    	y = c; 
	}
	void insert_set(int v)
	{	
		parent[v] = v;
		size[v]   = 1;
	}
	int size_set(int a)
	{
		return size[find_set(a)];
	}
	int find_set(int v)
	{
		if(v==parent[v])
		{
			return v;
		}	
		else
		{
			return parent[v] = find_set(parent[v]);
		}	
	}
	void union_set(int a,int b)
	{
		a = find_set(a);
		b = find_set(b);
		if(a!=b)
		{
			if(size[a]<size[b])
			{
				changeValue(a,b);
			}
			parent[b] = a;
			size[a]+=size[b];
		}
	}
	bool in_one_set(int a,int b)
	{
		if(find_set(a)==find_set(b)) return 1;
		else return 0;
	}
};