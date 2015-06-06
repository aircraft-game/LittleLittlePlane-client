#include "Airplane.h"

Airplane::Airplane()
{}

Airplane* Airplane::create(string fileName)
{
	Airplane* instance = new Airplane();
	if (instance && instance->initWithFile(fileName))
	{
		return instance;
	}
	else
	{
		CC_SAFE_DELETE(instance);
		return nullptr;
	}
}

void Airplane::fire(Fire fire)
{

}