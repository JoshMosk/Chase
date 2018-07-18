#include "PatrolBehaviour.h"
#include "Agent.h"
#include "SeekBehaviour.h"

PatrolBehaviour::PatrolBehaviour(Agent* pSelf)
	:BaseSteeringBehaviour(pSelf)
{
	nCurrentPoint = 0;
}

PatrolBehaviour::~PatrolBehaviour()
{
}

void PatrolBehaviour::AddPatrolPoint(Vector2 v2NewPoint)
{
	m_path.push_back(v2NewPoint);
}

Vector2 PatrolBehaviour::Update(float fDeltaTime, Vector2 v2Target)
{
	if (m_pSelf->GetPosition().x < m_path[nCurrentPoint].x + 20)
	{
		if (m_pSelf->GetPosition().y < m_path[nCurrentPoint].y - 20)
		{
			nCurrentPoint++;
		}
	}

	if (nCurrentPoint > m_path.size() - 1)
	{
		nCurrentPoint = 0;
	}

	SeekBehaviour Seek = SeekBehaviour(m_pSelf);

	return Seek.Update(fDeltaTime, m_path[nCurrentPoint]);
}