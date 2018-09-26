#pragma once
#include "Vector2.h"

#define NEIGHBOUR_COUNT 8

struct Node
{
	Vector2 m_v2Pos;
	Node* m_Neighbours[NEIGHBOUR_COUNT];
	int m_nCosts[NEIGHBOUR_COUNT];

	Node* m_pPrev;

	int m_nIndexX;
	int m_nIndexY;

	int m_nFScore;
	int m_nGScore;
	int m_nHScore;

	bool m_bBlocked = false;
};