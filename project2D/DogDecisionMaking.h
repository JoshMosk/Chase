#pragma once
class SeeTargetDecision;

class DogDecisionMaking
{
public:
	DogDecisionMaking();
	~DogDecisionMaking();

	//is human in range
	//yes
		//is mouse in sight
		//yes
			//chase mouse
		//no
			//flock with human
	//no
		//seek human
};

