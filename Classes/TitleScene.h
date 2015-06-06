#ifndef __TITLE_SCENE__
#define __TITLE_SCENE__

#include "cocos2d.h"
using namespace cocos2d;


/**
 * 标题场景类（单例）
 */
class TitleScene : public Scene
{
public:
	/**
	 * 获取标题场景的实例
	 * @return 获取到的实例
	 */
	static TitleScene* getInstance();

private:
	//标题场景的实例
	static TitleScene* instance;

	TitleScene();
	~TitleScene();

	/**
	 * 初始化
	 * @return 是否初始化成功
	 */
	bool init();

	/**
	 * static create()方法
	 */
	CREATE_FUNC(TitleScene);
};

#endif