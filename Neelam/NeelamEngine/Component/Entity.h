#pragma once

#include "ComponentsCommon.h"

namespace Neelam
{
	namespace GameEntity
	{
		struct entity_info										// entity init info
		{

		};

		entity_id Create_Game_Entity(const entity_info& info);	// To add Game Entity
		void Remove_Game_Entity(entity_id id);			        // remove game entity
		bool is_alive(entity_id id);							// entity alive check
	}
}
