#ifndef HIERARCHY_SYSTEM_H
#define HIERARCHY_SYSTEM_H

#include "../coordinator.h"
#include "../entity.h"
#include "../system.h"

namespace SimpleEcs {

class HierarchySystem : public System {
public:
    void propagate(const std::weak_ptr<Coordinator> &_coordinator, Entity root);
};

} // namespace SimpleEcs

#endif // HIERARCHY_SYSTEM_H
