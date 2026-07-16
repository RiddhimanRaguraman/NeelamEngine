#include "CommonHeaders.h"
#include "Entity.h"
#include "Transform.h"

using namespace Neelam;

namespace{
	// The editor's UI works in degrees; every Azul math entry point takes radians.
	// (The math lib ships no Deg2Rad, only Azul::MATH_PI in Constants.h.)
	constexpr float Deg2Rad(const float degrees)
	{
		return degrees * (Azul::MATH_PI / 180.0f);
	}

	struct TransformComponentDescriptor
	{
		float Position[3];
		float Rotation[3];		// Euler angles, in DEGREES -- the editor's convention
		float Scale[3];

		// Translate the flat wire format into the engine's SIMD math types.
		// This is exactly why the interop layer exists: the editor speaks loose
		// Euler degrees, the engine stores an Azul::Quat built from radians.
		Transform::init_info to_init_info() const
		{
			Transform::init_info info{};

			info.Position = Azul::Vec3(Position[0], Position[1], Position[2]);
			info.Rotation = Azul::Quat(Azul::Rot3::ZXY,
									   Deg2Rad(Rotation[0]),
									   Deg2Rad(Rotation[1]),
									   Deg2Rad(Rotation[2]));
			info.Scale    = Azul::Vec3(Scale[0], Scale[1], Scale[2]);

			return info;
		}

	};

	struct GameEntityDescriptor 
	{ 
		TransformComponentDescriptor Transform; 
	};

	GameEntity::Entity Entity_From_Id(Id::ID_type id)
	{
		return GameEntity::Entity{ GameEntity::entity_id {id} };
	}

} // anonymous namespace

ENGINE_API Id::ID_type CreateGameEntity(GameEntityDescriptor *e)
{
	assert(e);
	Transform::init_info transform_info{ e->Transform.to_init_info() };
	GameEntity::entity_info entity_info{ &transform_info };
	return GameEntity::Create_Game_Entity(entity_info).get_id();
}

ENGINE_API void RemoveGameEntity(Id::ID_type id)
{
	assert(Id::is_valid(id));
	GameEntity::Remove_Game_Entity(Entity_From_Id(id));
}