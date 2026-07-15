#pragma once
#include "ComponentsCommon.h"
#include "TransformComponent.h"

namespace Neelam::Transform
{
	struct init_info
	{
		// TODO: world matrix addition and maybe make this a class
		//		 or use a ctor for struct
		Azul::Vec3 Position;
		Azul::Quat Rotation;
		Azul::Vec3 Scale;
	};

	Component create_transform(const init_info, GameEntity::Entity entity);
	void remove_transform(Component id);
}