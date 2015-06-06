#include "TitleScene.h"

TitleScene* TitleScene::instance = nullptr;


TitleScene::TitleScene()
{}


TitleScene::~TitleScene()
{}


TitleScene* TitleScene::getInstance()
{
	if (!instance)
	{
		instance = create();
	}
	return  instance;
}


bool TitleScene::init()
{
	if (!Scene::init())
	{
		return false;
	}
	return true;
}

