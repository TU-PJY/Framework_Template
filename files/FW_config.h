#pragma once
#define          USING_FRAMEWORK
#define          NUMBER_OF_LAYER 1
#define          START_MODE "mode_name"


class Bridge {
public:
	virtual void update() {}
	virtual void check_collision() {}
	virtual void render() {}
	virtual void check_delete_flag() {}
	
	// define user functions here

	virtual      ~Bridge() {}
};