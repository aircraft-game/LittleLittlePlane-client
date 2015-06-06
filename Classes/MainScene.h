#ifndef __MAIN_SCENE__
#define __MAIN_SCENE__

#include "cocos2d.h"
#include "AirPlane.h"
#include "Joystick.h"
using namespace cocos2d;

/**
 * 主场景类（单例）
 */
class MainScene : public Scene
{
public:
	//飞机精灵
	Airplane* airplane;

	//摇杆
	Joystick* joystick;

	/**
	 * 获取主场景的实例
	 * @return 获取到的实例
	 */
	static MainScene* getInstance();

private:
	//主场景的实例
	static MainScene* instance;

	//飞机和子弹所在的图层
	Layer* planeLayer;

	MainScene();
	~MainScene();

	/**
	 * 初始化
	 * @return 是否初始化成功
	 */
	bool init();

	/**
	 * static create()方法
	 */
	CREATE_FUNC(MainScene);
};

#endif