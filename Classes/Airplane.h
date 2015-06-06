#ifndef __AIR_PLANE__
#define __AIR_PLANE__

#include "cocos2d.h"
#include <string>
using namespace cocos2d;
using namespace std;

/**
 * ������ӵ�����
 */
enum Fire
{
	NORMAL_FIRE,
	POWERFUL_FIRE
};

/**
 * �ɻ���
 */
class Airplane : public Sprite
{
public:
	/**
	 * �ɻ�����
	 * @param fire ����������
	 */
	void fire(Fire fire);

	/**
	 * �����ɻ�
	 */
	static Airplane* create(string fileName);

private:
	Airplane();
};


#endif