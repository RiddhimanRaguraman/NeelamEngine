#pragma once
#include "ComponentsCommon.h"

namespace Neelam::Transform
{
	DEFINE_TYPED_ID(transform_id);

	class Component final {
	public:
		constexpr explicit Component(transform_id id) : _id{ id } {}
		constexpr Component() : _id{ Id::invalid_id } {}
		constexpr transform_id get_id() const { return _id; }
		constexpr bool is_valid() const { return Id::is_valid(_id); }

		Azul::Vec3 getPos() const;
		Azul::Quat getRot() const;
		Azul::Vec3 getScale() const;
	private:
		transform_id _id;
	};
}