#pragma once

#include "ComponentsCommon.h"

namespace Neelam
{
#define INIT_INFO (comp) namespace comp {struct init_info;}
	INIT_INFO Transform; 
#undef INIT_INFO
	namespace GameEntity
	{
		struct entity_info										// entity init info
		{
			Transform::init_info* transform{ nullptr };
		};

		entity_id Create_Game_Entity(const entity_info& info);	// To add Game Entity
		void Remove_Game_Entity(entity_id id);			        // remove game entity
		bool is_alive(entity_id id);							// entity alive check
	}
}
