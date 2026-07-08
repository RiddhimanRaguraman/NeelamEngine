#pragma once
#include "ComponentsCommon.h"

namespace Neelam::Transform
{
	DEFINE_TYPED_ID(transform_id);

	struct init_info
	{
		// TODO: world matrix addition and maybe make this a class
		//		 or use a ctor for struct
		Azul::Vec3 Position;
		Azul::Quat Rotation;
		Azul::Vec3 Scale;
	};

	transform_id create_transform(const init_info, GameEntity::entity_id entity_id);
	void remove_transform(transform_id id);
}