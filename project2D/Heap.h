#pragma once
#include <vector>
#include<functional>

template<typename T>
class Heap
{
public:
	Heap() 
	{
		CompareFunc = [](T a, T b)
		{
			return a < b;
		};
	}
	~Heap() {}

	void Add(T data)
	{
		m_tHeap.push_back(data);
		UpHeap(m_tHeap.size()- 1);
	}

	T Pop()
	{
		T tTemp = m_tHeap[0];
		//m_tHeap.erase(m_tHeap.begin());
		DownHeap();

		return tTemp;
	}

	void SetCompareFunction(std::function<bool(T, T)> func)
	{
		CompareFunc = func;
	}

	std::vector<T> m_tHeap;
private:
	std::function<bool(T, T)> CompareFunc;

	int GetParent(int nIndex)
	{
		return floor((nIndex - 1) / 2);
	}

	int GetChild1(int nIndex)
	{
		return (2 + nIndex) + 1;
	}

	int GetChild2(int nIndex)
	{
		return (2 + nIndex) + 2;
	}

	void UpHeap(int nIndex)
	{
		T tTemp = m_tHeap[nIndex];

		while (true)
		{
			if (GetParent(nIndex) < 0)
			{
				break;
			}

			if (CompareFunc(m_tHeap[nIndex], m_tHeap[GetParent(nIndex)]))
			{
				m_tHeap[nIndex] = m_tHeap[GetParent(nIndex)];
				m_tHeap[GetParent(nIndex)] = tTemp;

				nIndex = GetParent(nIndex);
			}
			else
			{
				break;
			}
		}
	}

	void DownHeap()
	{
		// copy last element to first
		m_tHeap[0] = m_tHeap[m_tHeap.size()-1];
		// delete last one
		m_tHeap.erase(m_tHeap.end()-1);

		// nothing needs to be done if there's nothing to do sthgindinasfinas
		if (m_tHeap.size() <= 0)
		{
			return;
		}
		
		T tTemp = m_tHeap[0];
		int nCurrentIndex = 0;

		while (true)
		{
			if (GetChild1(nCurrentIndex) < m_tHeap.size())
			{
				// has left child
				if (GetChild2(nCurrentIndex) < m_tHeap.size())
				{
					// has right child
					if (CompareFunc(m_tHeap[GetChild1(nCurrentIndex)], m_tHeap[GetChild2(nCurrentIndex)]))
					{
						// child 1 is less than child 2
						if (CompareFunc(m_tHeap[GetChild1(nCurrentIndex)], m_tHeap[nCurrentIndex]))
						{
							// child 1 is less than parent
							m_tHeap[nCurrentIndex] = m_tHeap[GetChild1(nCurrentIndex)];
							m_tHeap[GetChild1(nCurrentIndex)] = tTemp;
							nCurrentIndex = GetChild1(nCurrentIndex);
						}
						else
						{
							break;
						}
					}
					else
					{
						// child 2 is less than child 1
						if (CompareFunc(m_tHeap[GetChild2(nCurrentIndex)], m_tHeap[nCurrentIndex]))
						{
							// child 2 is less than parent
							m_tHeap[nCurrentIndex] = m_tHeap[GetChild2(nCurrentIndex)];
							m_tHeap[GetChild2(nCurrentIndex)] = tTemp;
							nCurrentIndex = GetChild2(nCurrentIndex);
						}
						else
						{
							break;
						}
					}
				}
				else 
				{
					// doesnt have 2nd child
					if (CompareFunc(m_tHeap[GetChild1(nCurrentIndex)], m_tHeap[nCurrentIndex]))
					{
						// child is less than parent
						m_tHeap[nCurrentIndex] = m_tHeap[GetChild1(nCurrentIndex)];
						m_tHeap[GetChild1(nCurrentIndex)] = tTemp;
						nCurrentIndex = GetChild1(nCurrentIndex);
					}
					else
					{
						break;
					}
				}
			}
			else
			{
				break;
			}
		}
	}
};

