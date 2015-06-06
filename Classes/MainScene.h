#ifndef __MAIN_SCENE__
#define __MAIN_SCENE__

#include "cocos2d.h"
#include "AirPlane.h"
#include "Joystick.h"
using namespace cocos2d;

/**
 * �������ࣨ������
 */
class MainScene : public Scene
{
public:
	//�ɻ�����
	Airplane* airplane;

	//ҡ��
	Joystick* joystick;

	/**
	 * ��ȡ��������ʵ��
	 * @return ��ȡ����ʵ��
	 */
	static MainScene* getInstance();

private:
	//��������ʵ��
	static MainScene* instance;

	//�ɻ����ӵ����ڵ�ͼ��
	Layer* planeLayer;

	MainScene();
	~MainScene();

	/**
	 * ��ʼ��
	 * @return �Ƿ��ʼ���ɹ�
	 */
	bool init();

	/**
	 * static create()����
	 */
	CREATE_FUNC(MainScene);
};

#endif