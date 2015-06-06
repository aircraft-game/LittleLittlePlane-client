#include "MainScene.h"

MainScene* MainScene::instance = nullptr;


MainScene::MainScene()
{
	airplane = nullptr;
	planeLayer = nullptr;
}


MainScene::~MainScene()
{}


MainScene* MainScene::getInstance()
{
	if (!instance)
	{
		instance = create();
	}
	return  instance;
}


bool MainScene::init()
{
	if (!Scene::init())
	{
		return false;
	}
	//初始化图层
	planeLayer = Layer::create();
	this->addChild(planeLayer, 1);
	//初始化摇杆
	joystick = Joystick::create("test.png", "test.png");
	joystick->setPosition(440, 40);
	this->addChild(joystick, 99);
	log("aaaaa");
	//初始化飞机
	airplane = Airplane::create("test.png");
	airplane->setPosition(240, 50);
	planeLayer->addChild(airplane);
	return true;
}

