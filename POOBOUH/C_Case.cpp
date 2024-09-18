#include "C_Case.h"
#include "string"

void C_Case::Init(std::string sprite, Vector2D pos)
{
	this->sprite = sprite;
	this->position = pos;
}

void C_Case::AddEntity(C_Entity* entity)
{
	this->entity = entity;
	entity->position = this->position;
}

C_Case::C_Case()
	: entity(nullptr), position(Vector2D(0,0)), sprite(""), caseType(E_CaseType::Empty)
{
}

C_Case::~C_Case()
{
}
