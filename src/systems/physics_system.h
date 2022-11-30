#ifndef SIMPLE_ECS_PHYSICS_SYSTEM_H
#define SIMPLE_ECS_PHYSICS_SYSTEM_H

#include <set>

#include "../coordinator.h"
#include "../entity.h"
#include "../system.h"

namespace SimpleEcs {

class PhysicsSystem : public System {
public:
    void update(const std::weak_ptr<Coordinator> &_coordinator, double dt);
};

} // namespace SimpleEcs

#endif // SIMPLE_ECS_PHYSICS_SYSTEM_H
