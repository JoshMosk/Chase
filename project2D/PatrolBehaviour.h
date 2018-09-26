#pragma once
#include "BaseSteeringBehaviour.h"
#include <vector>
#include "Vector2.h"

class PatrolBehaviour : public BaseSteeringBehaviour
{
public:
	PatrolBehaviour(Agent* pSelf);
	~PatrolBehaviour();

	void AddPatrolPoint(Vector2 v2NewPoint);

	Vector2 Update(float fDeltaTime, Vector2 v2Target = Vector2())override;

//private:
	std::vector<Vector2> m_path;
	int nCurrentPoint;
};

