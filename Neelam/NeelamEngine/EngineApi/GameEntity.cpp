#include "pch.h"
#include "GameEntity.h"

namespace Neelam::GameEntity
{
	constexpr entity::entity(entity_id id) : _id(id) 
	{
	}
	constexpr entity::entity() : _id(Id::invalid_id)
	{
	}
}