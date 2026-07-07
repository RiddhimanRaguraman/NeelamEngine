#pragma once
#include "ComponentsCommon.h"

namespace Neelam::Transform
{
	DEFINE_TYPED_ID(transform_id);

	struct init_info
	{
		// TODO: The last variable of vec4 to be the common multiplier 
		//		 variable need to rework for position and scale
		Azul::Vec4 Position;
		Azul::Quat Rotation;
		Azul::Vec4 Scale;
	};

	transform_id create_transform(const init_info, GameEntity::entity_id entity_id);
	void remove_transform(transform_id id);
}