#ifndef _STATE_HPP_
#define _STATE_HPP_
#include "../Engine/GameEngine.hpp"
#include <iostream>

class StateI {
public:
	virtual ~StateI() {}
	virtual void Input() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	GameEngine* m_EnginePtr;
};
#endif // !_STATE_HPP_
