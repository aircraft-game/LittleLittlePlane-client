#ifndef __TITLE_SCENE__
#define __TITLE_SCENE__

#include "cocos2d.h"
using namespace cocos2d;


/**
 * ���ⳡ���ࣨ������
 */
class TitleScene : public Scene
{
public:
	/**
	 * ��ȡ���ⳡ����ʵ��
	 * @return ��ȡ����ʵ��
	 */
	static TitleScene* getInstance();

private:
	//���ⳡ����ʵ��
	static TitleScene* instance;

	TitleScene();
	~TitleScene();

	/**
	 * ��ʼ��
	 * @return �Ƿ��ʼ���ɹ�
	 */
	bool init();

	/**
	 * static create()����
	 */
	CREATE_FUNC(TitleScene);
};

#endif