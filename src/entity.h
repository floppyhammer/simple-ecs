#ifndef SIMPLE_ECS_ENTITY_H
#define SIMPLE_ECS_ENTITY_H

#include <cstdint>

namespace SimpleEcs {

// A simple type alias
using Entity = std::uint32_t;

// Used to define the size of arrays later on
const Entity MAX_ENTITIES = 5000;

} // namespace SimpleEcs

#endif // SIMPLE_ECS_ENTITY_H
