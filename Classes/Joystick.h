#ifndef __JOYSTICK__
#define __JOYSTICK__

#include "cocos2d.h"
#include <string>
using namespace std;
using namespace cocos2d;

//摇杆的方向
enum Direction
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	UP_LEFT,
	UP_RIGHT,
	DOWN_LEFT,
	DOWN_RIGHT
};

/**
 * 摇杆类
 */
class Joystick : public Layer
{
public:
	/**
	 * 创建一个摇杆
	 * @param classis 底盘图片文件路径
	 * @param dot 摇杆触点图片文件路径
	 */
	static Joystick* create(string classis, string touchDot);

	/**
	* 获取当前摇杆方向
	* @return 摇杆当前方向
	*/
	Direction getDirection();

private:
	//有效半径
	double radiusSq;

	//失效半径
	double invalidRadiusSq;

	//底盘精灵
	Sprite* classis;

	//触点精灵
	Sprite* touchDot;

	Joystick();
	~Joystick();

	/**
	 * 初始化
	 * @return 是否初始化成功
	 */
	bool init(string classis, string touchDot);

	//摇杆触点的监听器
	EventListenerTouchOneByOne* listener;

	/* 摇杆触点触摸事件的监听的回调 */
	bool onTouchBegan(Touch* touch, Event* event);
	void onTouchMoved(Touch* touch, Event* event);
	void onTouchEnded(Touch* touch, Event* event);
};

#endif