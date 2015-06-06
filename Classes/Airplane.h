#ifndef __AIR_PLANE__
#define __AIR_PLANE__

#include "cocos2d.h"
#include <string>
using namespace cocos2d;
using namespace std;

/**
 * 发射的子弹类型
 */
enum Fire
{
	NORMAL_FIRE,
	POWERFUL_FIRE
};

/**
 * 飞机类
 */
class Airplane : public Sprite
{
public:
	/**
	 * 飞机开火
	 * @param fire 火力的类型
	 */
	void fire(Fire fire);

	/**
	 * 创建飞机
	 */
	static Airplane* create(string fileName);

private:
	Airplane();
};


#endif