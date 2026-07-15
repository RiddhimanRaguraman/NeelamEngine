#include "Transform.h"

namespace Neelam::Transform
{
    namespace 
    {
        Util::vector<Azul::Vec3> positions;
        Util::vector<Azul::Quat> rotations;
        Util::vector<Azul::Vec3> scales;

    } // anonymous namespace 

    Component create_transform(const init_info info, GameEntity::Entity entity)
    {
        assert(entity.is_valid());
        const Id::ID_type entity_index{ Id::Index(entity.get_id()) };
        if (positions.size() > entity_index)
        {
            rotations[entity_index] = info.Rotation;
            positions[entity_index] = info.Position;
            scales[entity_index] = info.Scale;
        }
        else
        {
            assert(positions.size() == entity_index);
            positions.emplace_back(info.Position);
            rotations.emplace_back(info.Rotation);
            scales.emplace_back(info.Scale);
        }

        return Component(transform_id{ (Id::ID_type)positions.size() - 1 });
    }

    void remove_transform(Component c)
    {
        assert(c.is_valid());
    }


    Azul::Vec3 Component::getPos() const
    {
        assert(is_valid());
        return positions[Id::Index(_id)];
    }

    Azul::Quat Component::getRot() const
    {
        assert(is_valid());
        return rotations[Id::Index(_id)];
    }
    
    Azul::Vec3 Component::getScale() const 
    {
        assert(is_valid());
        return scales[Id::Index(_id)];

    }

}