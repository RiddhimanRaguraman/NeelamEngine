#pragma once

#include "ComponentsCommon.h"

namespace Neelam::GameEntity
{
	DEFINE_TYPED_ID(entity_id);

	class entity
	{
	public :
		constexpr explicit entity(entity_id id);
		constexpr explicit entity(); 

	private :
		entity_id _id;
	};
}

