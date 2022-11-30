#include "physics_system.h"

#include <chrono>
#include <thread>

#include "../components/components.h"

namespace SimpleEcs {

void PhysicsSystem::update(const std::weak_ptr<Coordinator> &p_coordinator, double dt) {
    auto coordinator = p_coordinator.lock();

    for (auto const &entity : entities) {
        auto &rigidBody = coordinator->get_component<RigidBodyComponent>(entity);
        auto &transform = coordinator->get_component<TransformComponent>(entity);
        auto const &gravity = coordinator->get_component<GravityComponent>(entity);

        transform.position += rigidBody.velocity * dt;
        rigidBody.velocity += gravity.force * dt;
    }
}

} // namespace SimpleEcs
