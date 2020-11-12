#include <iostream>
#include<list>
#include<string>
#include<unordered_map>
using namespace std;


/*
lru算法原理，最新的元素放在最开始，访问后的元素也放在最开始
*/
template<class KeyType, class ValueType>
class LRUCache
{
public:
	LRUCache(int capacity) : m_capacity(capacity) {}

	int get(KeyType key, ValueType& value)
	{
		if (m_map.count(key) <= 0)
		{
			return -1;
		}

		Iter iter = m_map[key];
		value = iter->second;

		m_list.splice(m_list.begin(), m_list, iter);

		return 0;
	}

	void put(KeyType key, ValueType value)
	{
		if (m_map.count(key) >= 1) //访问匹配给当前键值的元素个数
		{
			Iter iter = m_map[key];
			iter->second = value;
			m_list.splice(m_list.begin(), m_list, iter);// 将当前元素放置到链表的最开始位置
		}
		else
		{
			//如果当前插入新的键值对应的数据对
			/*
			1.判断当前链表是否超过最大容量
				超过则删除最后一个元素
				map中也删除对应键值
			2 在链表前插入新加入的键值对
			*/
			Node node(key, value);
			if (m_list.size() == m_capacity)
			{
				m_map.erase(m_list.back().first);
				m_list.pop_back();
			}

			m_list.push_front(node);
			m_map[key] = m_list.begin();
		}
	}

	void show(void(*p)(ValueType*))
	{
		typename std::list<Node>::iterator it;
		for (it = m_list.begin(); it != m_list.end(); it++)
		{
			p(&it->second);
		}
	}

private:
	typedef std::pair<KeyType, ValueType> Node;
	typedef typename std::list<Node>::iterator Iter;
	std::list<Node> m_list; // 双向链表
	std::unordered_map<KeyType, Iter> m_map;
	int m_capacity;
};


void show_func(int* a)
{
	printf("%d\n", *a);
}

int main()
{
	int value;
	LRUCache<std::string, int> cache(5);// 构造 容量为5
	cache.put("aaa", 1);
	cache.put("bbb", 2);
	cache.put("ccc", 3);
	cache.put("ddd", 4);
	cache.put("eee", 5);

	cache.show(show_func);
	cout << endl;

	cache.get("ccc", value);
	cout  << endl;

	cache.show(show_func);
	cout << endl;

	cache.put("fff", 6);

	cache.show(show_func);
	cout << endl;

	system("pause");
	return 0;
}