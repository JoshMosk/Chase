#pragma once
#include "Renderer2D.h"
#include <vector>
#include "Vector2.h"
#include "Heap.h"

struct Node;

#define GRID_SIZEX 33
#define GRID_SIZEY 19
#define NODE_SIZE 40

class Grid
{
public:
	Grid();
	~Grid();

	std::vector<Vector2> GetPath(Vector2 v2Start, Vector2 v2End, bool AStar);
	Node* GetNodeByPos(Vector2 v2Pos);

	void Draw(aie::Renderer2D* pRenderer);

	Node* m_Nodes[GRID_SIZEX][GRID_SIZEY];
	Heap<Node*> m_OpenList;
	bool m_ClosedList[GRID_SIZEX][GRID_SIZEY];
};

