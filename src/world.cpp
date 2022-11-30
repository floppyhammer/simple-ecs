#include "world.h"

#include "components/components.h"

namespace SimpleEcs {

World::World() {
    coordinator = std::make_unique<Coordinator>();

    // Register components.
    coordinator->register_component<GravityComponent>();
    coordinator->register_component<RigidBodyComponent>();
    coordinator->register_component<TransformComponent>();
    coordinator->register_component<ModelComponent>();
    coordinator->register_component<HierarchicalRelations>();

    // Register systems.
    // -------------------------------------
    physics_system = coordinator->register_system<PhysicsSystem>();
    // Set signature.
    {
        Signature signature;
        signature.set(coordinator->get_component_type<GravityComponent>());
        signature.set(coordinator->get_component_type<RigidBodyComponent>());
        signature.set(coordinator->get_component_type<TransformComponent>());
        coordinator->set_system_signature<PhysicsSystem>(signature);
    }

    render_system = coordinator->register_system<RenderSystem>();
    // Set signature.
    {
        Signature signature;
        signature.set(coordinator->get_component_type<ModelComponent>());
        signature.set(coordinator->get_component_type<TransformComponent>());
        coordinator->set_system_signature<RenderSystem>(signature);
    }

    hierarchy_system = coordinator->register_system<HierarchySystem>();
    // Set signature.
    {
        Signature signature;
        signature.set(coordinator->get_component_type<HierarchicalRelations>());
        coordinator->set_system_signature<HierarchySystem>(signature);
    }
    // -------------------------------------
}

World::~World() {
    for (auto &entity : entities) {
        coordinator->destroy_entity(entity);
    }
    entities.clear();
}

void World::update(double dt) {
    physics_system->update(coordinator, dt);
}

void World::draw(int cmd_buffer) {
    render_system->draw(coordinator, cmd_buffer);
}

} // namespace SimpleEcs
