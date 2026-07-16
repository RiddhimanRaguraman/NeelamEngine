#include "Entity.h"
#include "MathEngine.h"
#include "Transform.h"

namespace Neelam::GameEntity
{
    namespace {
        Util::vector<Transform::Component> transforms;
        Util::vector<Id::generation_type> generations;
        Util::deque<entity_id>            free_ids;
    }
    Entity Neelam::GameEntity::Create_Game_Entity(const entity_info& info)
    {
        assert(info.transform);
        if (!info.transform)  return Entity{};

        entity_id id;
        if (free_ids.size() > Id::min_deleted_elements )
        {
            id = free_ids.front();
            assert(!is_alive(Entity{ id }));
            free_ids.pop_front();
            id = entity_id{ Id::New_generation(id)};
            ++generations[ Id::Index(id) ];
        }
        else
        {
            id = entity_id{ (Id::ID_type)generations.size() };
            generations.push_back(0);

            // Resize Components - Note that we dont resize cause we want the number 
            //                     of memory allocations stays low
            transforms.emplace_back();
        }
        const Entity new_entity{ id };
        const Id::ID_type index{ Id::Index(id) };

        // Create Transform Component
        assert(!transforms[index].is_valid());
        transforms[index] = Transform::create_transform(*info.transform, new_entity);
        if (!transforms[index].is_valid()) return {};

        return new_entity;
    }

    void Remove_Game_Entity(Entity e)
    {
        const entity_id id{ e.get_id() };
        const Id::ID_type index{ Id::Index(id) };
        assert(is_alive(e));
        if (is_alive(e))
        {
            Transform::remove_transform(transforms[index]);
            transforms[index] = {}; 
            free_ids.push_back(id);

        }
    }

    bool is_alive(Entity e)
    {
        assert(e.is_valid());
        const entity_id id{ e.get_id() };
        const Id::ID_type index{ Id::Index(id) };
        assert(index < generations.size());
        assert(generations[index] == Id::generation(id));
        return (generations[index] == Id::generation(id) && transforms[index].is_valid());
    }

    void shutdown()
    {
        // purge() releases each raw block outright, leaving these file-scope
        // containers holding nullptr before the leak check runs.
        transforms.purge();
        generations.purge();
        free_ids.purge();
    }

    Transform::Component Entity::transform() const
    {
        assert(is_alive(*this));
        const Id::ID_type index{ Id::Index(_id) };
        return transforms[index];
    }

}