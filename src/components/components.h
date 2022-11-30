#ifndef SIMPLE_ECS_COMPONENTS_H
#define SIMPLE_ECS_COMPONENTS_H

#include <optional>
#include <queue>

#include "../component.h"

namespace SimpleEcs {

// Dummy types.
typedef int InputEvent;
typedef int Vec3F;
typedef int MvpPushConstant;
typedef int Mesh3d;

// INPUT
// -----------------------------
struct MouseInputComponent {
    std::queue<InputEvent> input_queue;
};

struct KeyInputComponent {
    std::queue<InputEvent> input_queue;
};
// -----------------------------

// PHYSICS
// -----------------------------
struct RigidBodyComponent {
    Vec3F velocity;
    Vec3F force;
};

struct TransformComponent {
    Vec3F position;
    Vec3F scale;
    // Quaternion rotation;
};

struct GravityComponent {
    Vec3F force;
};
// -----------------------------

// RENDER
struct ModelComponent {
    Mesh3d mesh;
};

// HIERARCHY
struct HierarchicalRelations {
    std::optional<Entity> first_child{};
    std::optional<Entity> prev_sibling{};
    std::optional<Entity> next_sibling{};
    std::optional<Entity> parent{};
};

} // namespace SimpleEcs

#endif // SIMPLE_ECS_COMPONENTS_H
