#ifndef SIMPLE_ECS_WORLD_H
#define SIMPLE_ECS_WORLD_H

#include <memory>
#include <vector>

#include "coordinator.h"
#include "entity.h"
#include "systems/hierarchy_system.h"
#include "systems/physics_system.h"
#include "systems/render_system.h"

namespace SimpleEcs {

class World {
public:
    World();

    ~World();

    Entity spawn() {
        auto entity = coordinator->create_entity();

        entities.insert(entity);

        return entity;
    }

    template <typename T>
    void add_component(Entity entity, T component) {
        coordinator->add_component(entity, component);
    }

    void update(double dt);

    void draw(int cmd_buffer);

public:
    std::shared_ptr<Coordinator> coordinator;

    std::shared_ptr<RenderSystem> render_system;

    std::shared_ptr<PhysicsSystem> physics_system;

    std::shared_ptr<HierarchySystem> hierarchy_system;

private:
    std::set<Entity> entities;
};

} // namespace SimpleEcs

#endif // SIMPLE_ECS_WORLD_H
