#include "render_system.h"

#include "../components/components.h"
#include "../coordinator.h"

namespace SimpleEcs {

void RenderSystem::update(const std::weak_ptr<Coordinator> &p_coordinator) {
    auto coordinator = p_coordinator.lock();

    for (auto const &entity : entities) {
        auto &model = coordinator->get_component<ModelComponent>(entity);
        auto &transform = coordinator->get_component<TransformComponent>(entity);

        // Do something.
    }
}

void RenderSystem::draw(const std::weak_ptr<Coordinator> &_coordinator, int cmd_buffer) {
    auto coordinator = _coordinator.lock();

    for (auto const &entity : entities) {
        auto &model = coordinator->get_component<ModelComponent>(entity);

        // Do something.
    }
}

} // namespace SimpleEcs
