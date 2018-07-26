#pragma once
#include "BaseSteeringBehaviour.h"
#include <vector>
class FlockingSeperation;
class FlockingAlignment;
class FlockingCohesion;

struct Boid
{
	Agent* pAgent;
	float fMagnitude;
};

class FlockingBehaviour : public BaseSteeringBehaviour
{
public:
	FlockingBehaviour(Agent* pSelf);
	~FlockingBehaviour();

	Vector2 Update(float fDeltaTime, Vector2 v2Target = Vector2());		//v2Target isnt used

	void AddToFlock(Agent* pAgent);

	std::vector<Boid> GetFlock();

	void CalcFlock();
	float fFlockDistance;

	std::vector<Boid> m_flock;
private:

	FlockingSeperation* m_pSeperation;
	FlockingAlignment* m_pAlignment;
	FlockingCohesion* m_pCohesion;
};
