#ifndef __SIMULATION_H__
#define __SIMULATION_H__
#include "world_type.h"

void printGrind(const grid_t &grid);

direction_t leftFrom(direction_t dir);

direction_t rightFrom(direction_t dir);

instruction_t getInstruction(const creature_t &creature);

creature_t *getCreature(const grid_t &grid, point_t location);

point_t adjacentPoint(point_t pt, direction_t dir);

void simulateCreature(creature_t &creature, grid_t &grid, bool verbose);

#endif