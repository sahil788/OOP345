template <class K, class V, int N>

class KVList
{
	
	//V v[N];
	struct
	{
		K k;
		V v;
	} 
	data[N];
	size_t count;
	
	public:
		KVList()  
		{
			count = 0;
		}
		
		size_t size() const 
		{
			return count;
		}
		
		const K& key(int i) const
		{
			//return k[i];
			return data[i].k;
		}
		
		const V& value (int i) const 
		{
			//return v[i];
			return data[i].v;
		}
		
		KVList& add(const K& kk, const V& vv)
		{
			if(count < N)
			{
				//k[count] = kk, v[count] = vv;
				data[count].k =kk, data[count].v = vv;
				count++;
			}
			return *this;
		}
		int find(const K& kk) const
		{
			for(int i = 0; i <count; i ++)
			{
				//if(kk == k[i])
					if(kk == data[i].k)
					return i;
				return 0;
			}
		}
		
		KVList& replace(int i, const K& kk, const V& vv)
		{
			if(0 <= i && i < count)
			{
				data[i].k = kk , data[i].v = vv;
			}
            return *this;
		}		
};