#pragma once

#define NULL 0
#define DEFAULT_HASH_SIZE 256

#include<cmath>

template<typename Key, typename Value>
class HashTable {
public:
	explicit HashTable() :m_iHashSize(DEFAULT_HASH_SIZE) { m_pHashTable = new Hash_Node[m_iHashSize]; }
	explicit HashTable(int _Size) : m_iHashSize(_Size) { m_pHashTable = new Hash_Node[m_iHashSize]; }
	virtual ~HashTable() { this->Clear(true); }
public:
	Value& Add(const Key& _key, Value _val);
	Value Find(const Key& _key, Value _val);
	void Delete(const Key& _key);
	void Delete(const Key& _key, Value _val);
	void Clear(bool _bMemeClaer = false);

	void Print(const Key& _key);
private:
	struct Data_Node {		
		Value		pData;
		Data_Node* pNext;
		Data_Node() : pData(NULL), pNext(NULL) {}
		Data_Node(const Key& _key, const Value& _Value) : pData(_Value), pNext(NULL) {}
	};

	struct Hash_Node {
		Data_Node* pDataNode;
		int			DataCount;
		Hash_Node() :pDataNode(NULL), DataCount(0) {}
	};

	Hash_Node* m_pHashTable;
	int m_iHashSize;
private:
	int Hash_Function(const Key& _Key) const {
		return  abs((int)_Key) % m_iHashSize;
	}
};

template<typename Key, typename Value>
inline Value& HashTable<Key, Value>::Add(const Key& _key, Value _val)
{
	int HashIndex = this->Hash_Function(_key);
	if (m_pHashTable[HashIndex].DataCount) {

		Data_Node* pCurNode = m_pHashTable[HashIndex].pDataNode;

		while (pCurNode->pNext)
		{
			pCurNode = pCurNode->pNext;
		}

		pCurNode->pNext = new Data_Node(_key, _val);
		m_pHashTable[HashIndex].DataCount++;

		return pCurNode->pData;
	}
	else {
		m_pHashTable[HashIndex].pDataNode = new Data_Node(_key, _val);
		m_pHashTable[HashIndex].DataCount++;
		return m_pHashTable[m_iHashSize].pDataNode->pData;
	}

}

template<typename Key, typename Value>
inline Value HashTable<Key, Value>::Find(const Key& _key, Value _val)
{
	int HashIndex = this->Hash_Function(_key);
	if (m_pHashTable[HashIndex].DataCount) {

		Data_Node* pCurNode = m_pHashTable[HashIndex].pDataNode;

		while (pCurNode->pNext)
		{
			if (pCurNode->pData == _val)
				return pCurNode->pData;
			pCurNode = pCurNode->pNext;
		}
	}

	return NULL;
}

template<typename Key, typename Value>
inline void HashTable<Key, Value>::Delete(const Key& _key)
{
	int HashIndex = this->Hash_Function(_key);
	if (m_pHashTable[HashIndex].DataCount) {

		Data_Node* pDeleteNode = m_pHashTable[HashIndex].pDataNode;
		Data_Node* pCurrentNode = m_pHashTable[HashIndex].pDataNode->pNext;

		while (pDeleteNode)
		{
			delete pDeleteNode;			
			m_pHashTable[HashIndex].DataCount--;
			pDeleteNode = pCurrentNode;
			if (!pDeleteNode) break;
			pCurrentNode = pCurrentNode->pNext;
		}
	}

}

template<typename Key, typename Value>
inline void HashTable<Key, Value>::Delete(const Key& _key, Value _val)
{
	int HashIndex = this->Hash_Function(_key);
	if (m_pHashTable[HashIndex].DataCount) {

		Data_Node* preNode = nullptr;
		Data_Node* pDeleteNode = m_pHashTable[HashIndex].pDataNode;
		
		while (pDeleteNode)
		{
			if (pDeleteNode->pData == _val) {		

				auto deleteNextNode = pDeleteNode->pNext;				
				delete pDeleteNode;
				m_pHashTable[HashIndex].DataCount--;				
				
				if (!preNode) {
					m_pHashTable[HashIndex].pDataNode = deleteNextNode;
					return;
				}
									
				preNode->pNext = deleteNextNode;				
				break;
			}			
			preNode = pDeleteNode;
			pDeleteNode = pDeleteNode->pNext;	
		}

	}
}

template<typename Key, typename Value>
inline void HashTable<Key, Value>::Clear(bool _bMemeClaer)
{
	for (int i = 0; i < m_iHashSize; ++i)
	{
		if (!m_pHashTable[i].DataCount) continue;

		Data_Node* pDeleteNode = m_pHashTable[i].pDataNode;
		Data_Node* pCurrentNode = m_pHashTable[i].pDataNode->pNext;

		while (true)
		{
			delete pDeleteNode;
			pDeleteNode = pCurrentNode;
			if (!pDeleteNode) break;
			pCurrentNode = pCurrentNode->pNext;
		}

		m_pHashTable[i].pDataNode = nullptr;
		m_pHashTable[i].DataCount = 0;
	}

	if (_bMemeClaer && m_pHashTable) {
		delete[] m_pHashTable;
		m_pHashTable = nullptr;
		m_iHashSize = 0;
	}
}

template<typename Key, typename Value>
inline void HashTable<Key, Value>::Print(const Key& _key)
{
	int HashIndex = this->Hash_Function(_key);
	if (m_pHashTable[HashIndex].DataCount) {

		Data_Node* pCurNode = m_pHashTable[HashIndex].pDataNode;

		while (pCurNode)
		{
			cout << pCurNode->pData << endl;
			pCurNode = pCurNode->pNext;
		}
	}
}
