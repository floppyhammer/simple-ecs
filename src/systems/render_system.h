#ifndef SIMPLE_ECS_MODEL_RENDER_SYSTEM_H
#define SIMPLE_ECS_MODEL_RENDER_SYSTEM_H

#include "../coordinator.h"
#include "../entity.h"
#include "../system.h"

namespace SimpleEcs {

class RenderSystem : public System {
public:
    void update(const std::weak_ptr<Coordinator> &p_coordinator);

    void draw(const std::weak_ptr<Coordinator> &_coordinator, int cmd_buffer);
};

} // namespace SimpleEcs

#endif // SIMPLE_ECS_MODEL_RENDER_SYSTEM_H
