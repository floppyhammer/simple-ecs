#include "hierarchy_system.h"

#include <iostream>
#include <queue>

#include "../components/components.h"

namespace SimpleEcs {

void traverse_children(const std::weak_ptr<Coordinator> &_coordinator, Entity node) {
    auto coordinator = _coordinator.lock();
    auto &relations = coordinator->get_component<HierarchicalRelations>(node);

    auto current_child = relations.first_child;

    while (true) {
        // Go to current child.
        if (current_child.has_value()) {
            Entity child_entity = current_child.value();
            // Get child hierarchy.
            auto &child_relations = coordinator->get_component<HierarchicalRelations>(child_entity);

            std::cout << child_entity << "  ";

            traverse_children(_coordinator, child_entity);

            // Get next child.
            current_child = child_relations.next_sibling;
        } else {
            std::cout << "| ";
            break;
        }
    }
}

void HierarchySystem::propagate(const std::weak_ptr<Coordinator> &_coordinator, Entity root) {
    traverse_children(_coordinator, root);
}

} // namespace SimpleEcs
