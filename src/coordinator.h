#ifndef SIMPLE_ECS_COORDINATOR_H
#define SIMPLE_ECS_COORDINATOR_H

#include <memory>

#include "component_manager.h"
#include "entity_manager.h"
#include "system_manager.h"

namespace SimpleEcs {

class Coordinator {
public:
    Coordinator() {
        init();
    }

    // Entity methods.
    // --------------------------------------------
    Entity create_entity() {
        return entity_manager->create_entity();
    }

    void destroy_entity(Entity entity) {
        entity_manager->destroy_entity(entity);

        component_manager->entity_destroyed(entity);

        system_manager->entity_destroyed(entity);
    }
    // --------------------------------------------

    // Component methods.
    // --------------------------------------------
    template <typename T>
    void register_component() {
        component_manager->register_component<T>();
    }

    template <typename T>
    void add_component(Entity entity, T component) {
        component_manager->add_component<T>(entity, component);

        auto signature = entity_manager->get_signature(entity);
        signature.set(component_manager->get_component_type<T>(), true);
        entity_manager->set_signature(entity, signature);

        system_manager->entity_signature_changed(entity, signature);
    }

    template <typename T>
    void remove_component(Entity entity) {
        component_manager->remove_component<T>(entity);

        auto signature = entity_manager->get_signature(entity);
        signature.set(component_manager->get_component_type<T>(), false);
        entity_manager->set_signature(entity, signature);

        system_manager->entity_signature_changed(entity, signature);
    }

    template <typename T>
    T &get_component(Entity entity) {
        return component_manager->get_component<T>(entity);
    }

    template <typename T>
    ComponentType get_component_type() {
        return component_manager->get_component_type<T>();
    }
    // --------------------------------------------

    // System methods.
    // --------------------------------------------
    template <typename T>
    std::shared_ptr<T> register_system() {
        return system_manager->register_system<T>();
    }

    template <typename T>
    void set_system_signature(Signature signature) {
        system_manager->set_signature<T>(signature);
    }
    // --------------------------------------------

private:
    std::shared_ptr<EntityManager> entity_manager;
    std::shared_ptr<ComponentManager> component_manager;
    std::shared_ptr<SystemManager> system_manager;

    void init() {
        // Create pointers to each manager.
        entity_manager = std::make_shared<EntityManager>();
        component_manager = std::make_shared<ComponentManager>();
        system_manager = std::make_shared<SystemManager>();
    }
};

} // namespace SimpleEcs

#endif // SIMPLE_ECS_COORDINATOR_H
