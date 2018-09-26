#include "Grid.h"
#include "Node.h"
#include <stdlib.h>

#define GRID_SPACING 12
#define OFFSET_X 0
#define OFFSET_Y 0

Grid::Grid()
{
	for (int x = 0; x < GRID_SIZEX; x++)
	{
		for (int y = 0; y < GRID_SIZEY; y++)
		{
			m_Nodes[x][y] = new Node();
			m_Nodes[x][y]->m_v2Pos.x = OFFSET_X + NODE_SIZE * x;
			m_Nodes[x][y]->m_v2Pos.y = OFFSET_Y + NODE_SIZE * y;

			m_Nodes[x][y]->m_nIndexX = x;
			m_Nodes[x][y]->m_nIndexY = y;
		}
	}

	for (int x = 0; x < GRID_SIZEX; x++)
	{
		for (int y = 0; y < GRID_SIZEY; y++)
		{
			m_Nodes[x][y]->m_Neighbours[0] = nullptr;
			m_Nodes[x][y]->m_Neighbours[1] = nullptr;
			m_Nodes[x][y]->m_Neighbours[2] = nullptr;
			m_Nodes[x][y]->m_Neighbours[3] = nullptr;
			m_Nodes[x][y]->m_Neighbours[4] = nullptr;
			m_Nodes[x][y]->m_Neighbours[5] = nullptr;
			m_Nodes[x][y]->m_Neighbours[6] = nullptr;
			m_Nodes[x][y]->m_Neighbours[7] = nullptr;

			m_Nodes[x][y]->m_nCosts[0] = 10;
			m_Nodes[x][y]->m_nCosts[1] = 14;
			m_Nodes[x][y]->m_nCosts[2] = 10;
			m_Nodes[x][y]->m_nCosts[3] = 14;
			m_Nodes[x][y]->m_nCosts[4] = 10;
			m_Nodes[x][y]->m_nCosts[5] = 14;
			m_Nodes[x][y]->m_nCosts[6] = 10;
			m_Nodes[x][y]->m_nCosts[7] = 14;

			if (y < GRID_SIZEY - 1)		//up
			{
				m_Nodes[x][y]->m_Neighbours[0] = m_Nodes[x][y + 1];
			}
			if (y < GRID_SIZEY - 1 && x < GRID_SIZEX - 1)		//up right
			{
				m_Nodes[x][y]->m_Neighbours[1] = m_Nodes[x + 1][y + 1];
			}
			if (x < GRID_SIZEX - 1)		//right
			{
				m_Nodes[x][y]->m_Neighbours[2] = m_Nodes[x + 1][y];
			}
			if (y > 0 && x < GRID_SIZEX - 1)		//down right
			{
				m_Nodes[x][y]->m_Neighbours[3] = m_Nodes[x + 1][y - 1];
			}
			if (y > 0)		//down
			{
				m_Nodes[x][y]->m_Neighbours[4] = m_Nodes[x][y - 1];
			}
			if (y > 0 && x > 0)		//down left
			{
				m_Nodes[x][y]->m_Neighbours[5] = m_Nodes[x - 1][y - 1];
			}
			if (x > 0)		//left
			{
				m_Nodes[x][y]->m_Neighbours[6] = m_Nodes[x - 1][y];
			}
			if (y < GRID_SIZEY - 1 && x > 0)		//up left
			{
				m_Nodes[x][y]->m_Neighbours[7] = m_Nodes[x - 1][y + 1];
			}
		}


		m_OpenList.SetCompareFunction([](Node* a, Node* b)
		{
			return a->m_nFScore < b->m_nFScore;
		});
	}

	//for (int i = 0; i < GRID_SIZEX * 4; i++)
	//{
	//	int x = rand() % GRID_SIZEX;
	//	int y = rand() % GRID_SIZEY;

	//	m_Nodes[x][y]->m_bBlocked = true;
	//}
	m_Nodes[1][1]->m_bBlocked = true;

	m_Nodes[3][3]->m_bBlocked = true;
	m_Nodes[3][4]->m_bBlocked = true;
	m_Nodes[3][5]->m_bBlocked = true;
	m_Nodes[3][6]->m_bBlocked = true;
	m_Nodes[4][6]->m_bBlocked = true;
	m_Nodes[5][6]->m_bBlocked = true;
	m_Nodes[6][6]->m_bBlocked = true;

	m_Nodes[12][12]->m_bBlocked = true;
	m_Nodes[12][13]->m_bBlocked = true;
	m_Nodes[12][14]->m_bBlocked = true;
	m_Nodes[12][15]->m_bBlocked = true;
	m_Nodes[12][16]->m_bBlocked = true;
	m_Nodes[12][17]->m_bBlocked = true;

	m_Nodes[17][10]->m_bBlocked = true;
	m_Nodes[18][10]->m_bBlocked = true;
	m_Nodes[19][10]->m_bBlocked = true;
	m_Nodes[20][10]->m_bBlocked = true;

	m_Nodes[25][20]->m_bBlocked = true;
	m_Nodes[25][21]->m_bBlocked = true;
	m_Nodes[25][22]->m_bBlocked = true;
	m_Nodes[27][20]->m_bBlocked = true;
	m_Nodes[27][21]->m_bBlocked = true;
	m_Nodes[27][22]->m_bBlocked = true;
	m_Nodes[26][20]->m_bBlocked = true;
}

Grid::~Grid()
{
	for (int x = 0; x < GRID_SIZEX; x++)
	{
		for (int y = 0; y > GRID_SIZEY; y++)
		{
			delete m_Nodes[x][y];
		}
	}
}

void Grid::Draw(aie::Renderer2D* pRenderer)
{
	for (int x = 0; x < GRID_SIZEX; x++)
	{
		for (int y = 0; y < GRID_SIZEY; y++)
		{
			if (m_Nodes[x][y]->m_bBlocked)
			{
				continue;
			}

			Vector2 v2Pos = m_Nodes[x][y]->m_v2Pos;
			if (m_ClosedList[x][y])
				pRenderer->setRenderColour(0.8, 0, 1, 1);
			else
				pRenderer->setRenderColour(1, 1, 1, 1);
			pRenderer->drawBox(v2Pos.x, v2Pos.y, NODE_SIZE * 1.5 - GRID_SPACING, NODE_SIZE * 1.5 - GRID_SPACING);
			//pRenderer->drawCircle(v2Pos.x, v2Pos.y, NODE_SIZE - GRID_SPACING);


			for (int i = 0; i < NEIGHBOUR_COUNT; i++)
			{
				if (m_Nodes[x][y]->m_Neighbours[i])
				{
					if (m_Nodes[x][y]->m_Neighbours[i]->m_bBlocked)
					{
						continue;
					}
					Vector2 v2NeighbourPos = m_Nodes[x][y]->m_Neighbours[i]->m_v2Pos;
					pRenderer->setRenderColour(1, 1, 1);
					pRenderer->drawLine(v2Pos.x, v2Pos.y, v2NeighbourPos.x, v2NeighbourPos.y, 2);
				}
			}
			Node* prev = m_Nodes[x][y]->m_pPrev;
			if (prev)
			{
				Vector2 pos = prev->m_v2Pos;
				pRenderer->setRenderColour(0.7f, 0, 0);
				pRenderer->drawLine(pos.x, pos.y, v2Pos.x, v2Pos.y, 2);
			}
		}
	}
}


std::vector<Vector2> Grid::GetPath(Vector2 v2Start, Vector2 v2End, bool AStar)
{
	std::vector<Vector2> path;

	Node* pStart = GetNodeByPos(v2Start);
	Node* pEnd = GetNodeByPos(v2End);

	if (!pStart || !pEnd)		//safety check
	{
		return path;
	}
	if (pStart->m_bBlocked || pEnd->m_bBlocked)
	{
		return path;
	}

	for (int x = 0; x < GRID_SIZEX; x++)
	{
		for (int y = 0; y > GRID_SIZEY; y++)
		{
			m_Nodes[x][y]->m_nFScore = 0;
			m_Nodes[x][y]->m_nGScore = 0;
			m_Nodes[x][y]->m_nHScore = 0;
			m_Nodes[x][y]->m_pPrev = nullptr;
		}
	}

	//pathfinding setup
	m_OpenList.m_tHeap.clear();
	memset(m_ClosedList, 0, sizeof(bool) * GRID_SIZEX * GRID_SIZEY);

	pStart->m_nGScore = 0;
	pStart->m_pPrev = nullptr;
	m_OpenList.Add(pStart);

	while (m_OpenList.m_tHeap.size() > 0)
	{

		//remove current from openlist and add to closedlist
		Node* pCurrent = m_OpenList.Pop();
		m_ClosedList[pCurrent->m_nIndexX][pCurrent->m_nIndexY] = true;

		if (pCurrent == pEnd)		//if current is end
		{
			path.push_back(pCurrent->m_v2Pos);		//add path to end

			while (pCurrent->m_pPrev)		//while current's prev isn't null
			{
				pCurrent = pCurrent->m_pPrev;		//set current to prev
				path.push_back(pCurrent->m_v2Pos);		//add current to path
			}
			return path;
		}

		
		for (int i = 0; i < NEIGHBOUR_COUNT; i++)		//loop through all neighbours and add to openlist
		{
			Node* pNeighbour = pCurrent->m_Neighbours[i];

			
			if (!pNeighbour)		//skip null neighbours
			{
				continue;
			}

			if (pNeighbour->m_bBlocked)		//skip blocked neigbours
			{
				continue;
			}

			
			if (m_ClosedList[pNeighbour->m_nIndexX][pNeighbour->m_nIndexY])		//skip neighbours already in closed list
			{
				continue;
			}

			
			if (std::find(m_OpenList.m_tHeap.begin(), m_OpenList.m_tHeap.end(), pNeighbour) != m_OpenList.m_tHeap.end())		//if neighbours already in openlist
			{
				int newGScore = pCurrent->m_nGScore + pCurrent->m_nCosts[i];

				if (newGScore < pNeighbour->m_nGScore)		//update if better path
				{
					
					pNeighbour->m_nGScore = newGScore;
					pNeighbour->m_nFScore = pNeighbour->m_nGScore + pNeighbour->m_nHScore;
					pNeighbour->m_pPrev = pCurrent;
				}
			}
			else
			{
				//calculate neighbour scores and add node to openlist 
				pNeighbour->m_nGScore = pCurrent->m_nGScore + pCurrent->m_nCosts[i];		//calculate gscore

				if (AStar)
				{

					int nDiffX = abs(pEnd->m_nIndexX - pNeighbour->m_nIndexX);
					int nDiffY = abs(pEnd->m_nIndexY - pNeighbour->m_nIndexY);

					pNeighbour->m_nHScore = (nDiffX + nDiffY) * 10;
				}
				else
				{
					pNeighbour->m_nHScore = 0;		//Dijkstras
				}

				pNeighbour->m_nFScore = pNeighbour->m_nGScore + pNeighbour->m_nHScore;		//calculate fscore

				pNeighbour->m_pPrev = pCurrent;		//set path to prev node
				
				m_OpenList.Add(pNeighbour);		//add node to openlist
			}
		}
	}

	return path;
}

Node* Grid::GetNodeByPos(Vector2 v2Pos)
{
	int x = (int)((v2Pos.x - OFFSET_X) / NODE_SIZE);
	int y = (int)((v2Pos.y - OFFSET_Y) / NODE_SIZE);

	if (x < 0)
	{
		x = 0;
		//return nullptr;
	}
	if (y < 0)
	{
		y = 0;
		//return nullptr;
	}
	if (x >= GRID_SIZEX)
	{
		x = GRID_SIZEX;
		//return nullptr;
	}
	if (y >= GRID_SIZEY)
	{
		y = GRID_SIZEY;
		//return nullptr;
	}

	return m_Nodes[x][y];
}