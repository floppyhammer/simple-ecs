#include <iostream>
#include <random>
#include <stdexcept>

#include "components/components.h"
#include "world.h"

using namespace SimpleEcs;

int main() {
    auto world = World();

    // Test.
    {
        auto entity = world.coordinator->create_entity();

        world.coordinator->add_component(entity, ModelComponent{1});

        TransformComponent transform{};
        world.coordinator->add_component(entity, transform);

        // Hierarchy test.
        {
            auto entity_0 = world.spawn();
            auto entity_0_0 = world.spawn();
            auto entity_0_1 = world.spawn();
            auto entity_0_0_1 = world.spawn();

            world.coordinator->add_component(entity_0, HierarchicalRelations{{entity_0_0}, {}, {}, {}});
            world.coordinator->add_component(entity_0_0,
                                             HierarchicalRelations{{entity_0_0_1}, {}, {entity_0_1}, {entity_0}});
            world.coordinator->add_component(entity_0_1, HierarchicalRelations{{}, {entity_0_1}, {}, {entity_0}});
            world.coordinator->add_component(entity_0_0_1, HierarchicalRelations{{}, {}, {}, {entity_0_0_1}});

            world.hierarchy_system->propagate(world.coordinator, entity_0);
        }
    }

    float dt = 0.001;

    world.update(dt);

    world.draw(1);

    return EXIT_SUCCESS;
}
