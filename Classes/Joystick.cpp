#include "Joystick.h"
#include <cmath>
#define _USE_MATH_DEFINES

Joystick::Joystick()
{
	radiusSq = 0;
	invalidRadiusSq = 0;
	classis = nullptr;
	touchDot = nullptr;
}

Joystick::~Joystick()
{
 ;;
}


Joystick* Joystick::create(string classis, string dot)
{
	Joystick* instance = new Joystick();
	if (instance && instance->init(classis, dot))
	{
		return instance;
	}
	else
	{
		CC_SAFE_DELETE(instance);
		return nullptr;
	}
}

bool Joystick::init(string classis, string touchDot)
{
	if (!Layer::init())
	{
		return false;
	}
	this->classis = Sprite::create(classis);
	this->touchDot = Sprite::create(touchDot);
	this->addChild(this->classis, 0);
	this->addChild(this->touchDot, 1);
	listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(Joystick::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(Joystick::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(Joystick::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	return true;
}

Direction Joystick::getDirection()
{
	double angle = CC_RADIANS_TO_DEGREES(touchDot->getPosition().getAngle());
	if ( -22.5<= angle && angle < 22.5) return RIGHT;
	else if (22.5 <= angle && angle < 67.5) return UP_RIGHT;
	else if (67.5 <= angle && angle < 112.5) return UP;
	else if (112.5 <= angle && angle < 157.5) return UP_LEFT;
	else if ((157.5 <= angle && angle < 180) || (-180 <= angle && angle < -157.5)) return LEFT;
	else if (-157.5 <= angle && angle <-112.5) return DOWN_LEFT;
	else if (-112.5 <= angle && angle <-67.5) return DOWN;
	else if (-67.5 <= angle && angle <-22.5) return DOWN_RIGHT;
}


bool Joystick::onTouchBegan(Touch* touch, Event* event)
{
	log("aaaa");
	Vec2 touchPosOnNode = this->convertToNodeSpace(touch->getLocation());
	if (invalidRadiusSq <= touchPosOnNode.getLengthSq() && touchPosOnNode.getLengthSq() < radiusSq)
	{
		touchDot->setPosition(touchPosOnNode);
		return true;
	}
	else
	{
		return false;
	}
}

void Joystick::onTouchMoved(Touch* touch, Event* event)
{
	double lengthSq = this->convertToNodeSpace(touch->getLocation()).getLengthSq();
	if (invalidRadiusSq <= lengthSq && lengthSq < radiusSq)
	{
		touchDot->setPosition(touchDot->getPosition() + touch->getDelta());
	}
	else
	{
		touchDot->setPosition(Vec2(0, 0));
	}
}

void Joystick::onTouchEnded(Touch* touch, Event* event)
{
	touchDot->setPosition(Vec2(0, 0));
}
