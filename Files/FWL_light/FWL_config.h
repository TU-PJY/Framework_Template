#ifndef FWL_CONFIG_H
#define FWL_CONFIG_H

#include <vector>
#include <string>

#define          USING_FWL
#define          N_MAIN_LAYER 1

#define          USING_SUB_MODE
#define          N_SUB_LAYER 1

#define          USING_FRAME_TIME
#define          USING_FRAME_TIME_OUTSIDE



class MODELIST {
public:
	// add mode list here...
	std::vector<std::string> MainModeList = 
	{ "main_mode1", };


	// add popup mode list here...
	std::vector<std::string> SubModeList =
	{ "sub_mode1", };
};



class MAIN_CLS {
public:
	virtual void Update() {}
	virtual void CheckCollision() {}
	virtual void Render() {}
	virtual void CheckDelete() {}
	virtual std::string GetTag() const { return {}; }
	virtual void ActivateDeleteFlag(bool Flag) {}

	// define user function here...

	virtual     ~MAIN_CLS() {}
};


class SUB_CLS {
public:
	virtual void Update() {}
	virtual void CheckCollision() {}
	virtual void Render() {}
	virtual void CheckDelete() {}
	virtual std::string GetTag() const { return {}; }
	virtual void ActivateDeleteFlag(bool Flag) {}

	// define user function here...

	virtual     ~SUB_CLS() {}
};


#endif