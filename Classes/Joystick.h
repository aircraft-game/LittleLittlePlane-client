#ifndef __JOYSTICK__
#define __JOYSTICK__

#include "cocos2d.h"
#include <string>
using namespace std;
using namespace cocos2d;

//ҡ�˵ķ���
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
 * ҡ����
 */
class Joystick : public Layer
{
public:
	/**
	 * ����һ��ҡ��
	 * @param classis ����ͼƬ�ļ�·��
	 * @param dot ҡ�˴���ͼƬ�ļ�·��
	 */
	static Joystick* create(string classis, string touchDot);

	/**
	* ��ȡ��ǰҡ�˷���
	* @return ҡ�˵�ǰ����
	*/
	Direction getDirection();

private:
	//��Ч�뾶
	double radiusSq;

	//ʧЧ�뾶
	double invalidRadiusSq;

	//���̾���
	Sprite* classis;

	//���㾫��
	Sprite* touchDot;

	Joystick();
	~Joystick();

	/**
	 * ��ʼ��
	 * @return �Ƿ��ʼ���ɹ�
	 */
	bool init(string classis, string touchDot);

	//ҡ�˴���ļ�����
	EventListenerTouchOneByOne* listener;

	/* ҡ�˴��㴥���¼��ļ����Ļص� */
	bool onTouchBegan(Touch* touch, Event* event);
	void onTouchMoved(Touch* touch, Event* event);
	void onTouchEnded(Touch* touch, Event* event);
};

#endif