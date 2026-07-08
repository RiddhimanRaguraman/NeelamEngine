#include "Entity.h"
#include "MathEngine.h"

namespace Neelam::GameEntity
{
    namespace {
        Util::vector<Id::generation_type> generations;
        Util::deque<entity_id>            free_ids;
    }
    entity Neelam::GameEntity::Create_Game_Entity(const entity_info& info)
    {
        assert(info.transform);
        if (!info.transform)  return entity{};


    }

    void Remove_Game_Entity(entity_id id)
    {

    }

    bool is_alive(entity_id id)
    {
        return false;
    }
}