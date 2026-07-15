#pragma once

#include "ComponentsCommon.h"
#include "TransformComponent.h"

namespace Neelam::GameEntity
{
	DEFINE_TYPED_ID(entity_id);

	class Entity
	{
	public :
		constexpr explicit Entity(entity_id id) : _id{ id } {}
		constexpr Entity() : _id{ Id::invalid_id } {}
		constexpr entity_id get_id() const { return _id; }
		constexpr bool is_valid() const { return Id::is_valid(_id); }
		Transform::Component transform() const;
	private :
		entity_id _id;
	};
}

