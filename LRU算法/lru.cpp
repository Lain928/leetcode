#include <iostream>
#include <unordered_map>
#include <list>
#include <utility>
using namespace std;
using namespace stdext;

class LRUCache {
public:
	LRUCache(int capacity) 
	{
		m_capacity = capacity;
	}

	int get(int key) {
		int retValue = -1;
		unordered_map<int, list<pair<int, int> > ::iterator> ::iterator it = cachesMap.find(key);

		//�����Cashe�У�����¼�ƶ����������ǰ��
		if (it != cachesMap.end())
		{
			retValue = it->second->second;
			//�ƶ�����ǰ��
			list<pair<int, int> > ::iterator ptrPair = it->second;
			pair<int, int> tmpPair = *ptrPair;
			caches.erase(ptrPair++);
			caches.push_front(tmpPair);


			//�޸�map�е�ֵ
			cachesMap[key] = caches.begin();
		}
		return retValue;
	}

	void set(int key, int value) {

		unordered_map<int, list<pair<int, int> > ::iterator> ::iterator it = cachesMap.find(key);

		if (it != cachesMap.end()) //�Ѿ���������
		{
			list<pair<int, int> > ::iterator ptrPait = it->second;
			ptrPait->second = value;
			//�ƶ�����ǰ��
			pair<int, int > tmpPair = *ptrPait;
			caches.erase(ptrPait);
			caches.push_front(tmpPair);


			//����map
			cachesMap[key] = caches.begin();
		}
		else //����������
		{
			pair<int, int > tmpPair = make_pair(key, value);


			if (m_capacity == caches.size()) //�Ѿ���
			{
				int delKey = caches.back().first;
				caches.pop_back(); //ɾ�����һ��


								   //ɾ����map�е���Ӧ��
				unordered_map<int, list<pair<int, int> > ::iterator> ::iterator delIt = cachesMap.find(delKey);
				cachesMap.erase(delIt++);
			}


			caches.push_front(tmpPair);
			cachesMap[key] = caches.begin(); //����map
		}
	}


private:
	int m_capacity;                                                                        //cashe�Ĵ�С
	list<pair<int, int> > caches;                                                  //��һ��˫����洢cashe������
	unordered_map< int, list<pair<int, int> > ::iterator> cachesMap;         //ʹ��map�ӿ���ҵ��ٶ�
};


int main(int argc, char** argv)
{
	LRUCache s(2);
	s.set(2, 1);
	s.set(1, 1);
	cout << s.get(2) << endl;
	s.set(4, 1);
	s.set(5, 2);
	cout << s.get(5) << endl;
	cout << s.get(4) << endl;
	getchar();
	return 0;
}