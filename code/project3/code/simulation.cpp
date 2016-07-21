#include<iostream>
#include<fstream>
#include<sstream>
#include<iomanip>
#include<string>
#include<cstdlib>
#include<cassert>
#include"simulation.h"
#include"world_type.h"
using namespace std;

void printGrind(const grid_t &grid)
{
	for (int i=0;i<grid.height;i++)
	{

		for (int j=0;j<grid.width;j++)
		{
			
			if (grid.squares[i][j]==NULL)
			{
				cout<<"____ ";
			}
			else
			{
				string current_name=grid.squares[i][j]->species->name;
				direction_t current_direction=grid.squares[i][j]->direction;
				string current_direction_show=directShortName[current_direction];
				cout<<current_name[0]<<current_name[1]<<"_"<<current_direction_show<<" ";
			}
		}
		cout<<endl;
	}

}

direction_t leftFrom(direction_t dir)
{
	if (dir== NORTH)
	{
		return WEST;
	}
	else if (dir==WEST)
	{
		return SOUTH;
	}
	else if (dir==SOUTH)
	{
		return EAST;
	}
	else if (dir==EAST)
	{
		return NORTH;
	}
}

direction_t rightFrom(direction_t dir)
{
	if (dir==NORTH)
	{
		return EAST;
	}
	else if (dir==EAST)
	{
		return SOUTH;
	}
	else if (dir==SOUTH)
	{
		return WEST;
	}
	else if (dir==WEST)
	{
		return NORTH;
	}
}

instruction_t getInstruction(const creature_t &creature)
{
	return creature.species->program[creature.programID-1];
}

creature_t *getCreature(const grid_t &grid, point_t location)
{
	int r,c;
	r=location.r;
	c=location.c;
	return grid.squares[r][c];
}

point_t adjacentPoint(point_t pt, direction_t dir)
{
	point_t result;
	if (dir==EAST)
	{
		result.r=pt.r;
		result.c=pt.c+1;
		return result;
	}
	else if (dir==WEST)
	{
		result.r=pt.r;
		result.c=pt.c-1;
		return result;
	}
	else if (dir==SOUTH)
	{
		result.r=pt.r+1;
		result.c=pt.c;
		return result;
	}
	else if (dir==NORTH)
	{
		result.r=pt.r-1;
		result.c=pt.c;
		return result;
	}
}

void simulateCreature(creature_t &creature, grid_t &grid, bool verbose)
{
	
	instruction_t instruction;
	instruction=getInstruction(creature);
	if (verbose==1) {cout<<"Instruction "<<creature.programID<<": ";}

	if (instruction.op==LEFT)
	{

		creature.programID++;
		creature.direction=leftFrom(creature.direction);
		if (verbose==1) {cout<<opName[instruction.op]<<endl;printGrind(grid);}
		else {cout<<opName[instruction.op]<<endl;}

	}
	if (instruction.op==RIGHT)
	{
		creature.programID++;
		creature.direction=rightFrom(creature.direction);
		if (verbose==1) {cout<<opName[instruction.op]<<endl;printGrind(grid);}
		else {cout<<opName[instruction.op]<<endl;}
	}

	if (instruction.op==HOP)
	{
		creature.programID++;
		point_t next_point;
		next_point=adjacentPoint(creature.location, creature.direction);
		if (next_point.r>=0&&next_point.c>=0&&next_point.r<grid.height&&next_point.c<grid.width)
		{
			if (grid.squares[next_point.r][next_point.c]==NULL)
			{
				point_t previous_point=creature.location;
				creature.location=next_point;
				grid.squares[next_point.r][next_point.c]=&creature;
				grid.squares[previous_point.r][previous_point.c]=NULL;
			}
		}
		if (verbose==1) {cout<<opName[instruction.op]<<endl;printGrind(grid);}
		else {cout<<opName[instruction.op]<<endl;}
	}
	
	if (instruction.op==INFECT)
	{
		creature.programID++;
		point_t next_point;
		next_point=adjacentPoint(creature.location, creature.direction);
		point_t previous_point=creature.location;
		if (next_point.r>=0&&next_point.c>=0&&next_point.r<grid.height&&next_point.c<grid.width)
		{
			creature_t *next_creature=getCreature(grid, next_point);
			if (next_creature!=NULL)
			{
				if (next_creature->species->name!=creature.species->name)
				{
					next_creature->species=creature.species;
					next_creature->programID=1;
				}
			}
			
		}
		if (verbose==1) {cout<<opName[instruction.op]<<endl;printGrind(grid);}
		else {cout<<opName[instruction.op]<<endl;}

	}

	



	if (instruction.op==IFEMPTY)
	{
		if (verbose==1) {cout<<opName[instruction.op]<<" "<<instruction.address<<endl;}
		unsigned int next_address=instruction.address;
		point_t next_point;
		next_point=adjacentPoint(creature.location, creature.direction);
		point_t previous_point=creature.location;
		if (next_point.r>=0&&next_point.c>=0&&next_point.r<grid.height&&next_point.c<grid.width)
		{
			creature_t *next_creature=getCreature(grid, next_point);
			if (next_creature==NULL)
			{
				creature.programID=next_address;
				simulateCreature(creature, grid, verbose);

			}
			else
			{
				creature.programID++;
				simulateCreature(creature, grid, verbose);
			}

		}
		else
		{
			creature.programID++;
			simulateCreature(creature, grid, verbose);
		}

	}
	if (instruction.op==IFWALL)
	{
		if (verbose==1) {cout<<opName[instruction.op]<<" "<<instruction.address<<endl;}
		unsigned int next_address=instruction.address;
		point_t next_point;
		next_point=adjacentPoint(creature.location, creature.direction);
		point_t previous_point=creature.location;
		if (next_point.r<0||next_point.c<0||next_point.r>=grid.height||next_point.c>=grid.width)
		{
			creature.programID=next_address;
			simulateCreature(creature, grid, verbose);
		}
		else
		{
			creature.programID++;
			simulateCreature(creature, grid, verbose);
		}

	}
	if (instruction.op==IFSAME)
	{
		if (verbose==1) {cout<<opName[instruction.op]<<" "<<instruction.address<<endl;}
		unsigned int next_address=instruction.address;
		point_t next_point;
		next_point=adjacentPoint(creature.location, creature.direction);
		point_t previous_point=creature.location;
		if (next_point.r>=0&&next_point.c>=0&&next_point.r<grid.height&&next_point.c<grid.width)
		{
			creature_t *next_creature=getCreature(grid, next_point);
			if (next_creature!=NULL)
			{
				if (next_creature->species->name==creature.species->name)
				{
					creature.programID=next_address;
					simulateCreature(creature, grid, verbose);			
				}
				else
				{
					creature.programID++;
					simulateCreature(creature, grid, verbose);
				}
			}
			else
			{
				creature.programID++;
				simulateCreature(creature, grid, verbose);
			}

		}
		else 
		{
			creature.programID++;
			simulateCreature(creature, grid, verbose);
		}

	}
	if (instruction.op==IFENEMY)
	{
		if (verbose==1) {cout<<opName[instruction.op]<<" "<<instruction.address<<endl;}

		unsigned int next_address=instruction.address;
		point_t next_point;
		next_point=adjacentPoint(creature.location, creature.direction);
		point_t previous_point=creature.location;
		if (next_point.r>=0&&next_point.c>=0&&next_point.r<grid.height&&next_point.c<grid.width)
		{
			
			creature_t *next_creature=getCreature(grid, next_point);
			if (next_creature!=NULL)
			{
				if (next_creature->species->name!=creature.species->name)
				{
					creature.programID=next_address;
					simulateCreature(creature, grid, verbose);			
				}
				else
				{
					creature.programID++;
					simulateCreature(creature, grid, verbose);
				}
			}
			else
			{
				
				creature.programID++;

				simulateCreature(creature, grid, verbose);
			}

		}
		else 
		{
			creature.programID++;
			simulateCreature(creature, grid, verbose);
		}

	}


	if (instruction.op==GO)
	{
		if (verbose==1) {cout<<opName[instruction.op]<<" "<<instruction.address<<endl;}
		unsigned int next_address=instruction.address;
		creature.programID=next_address;
		simulateCreature(creature, grid, verbose);
	}
	

	
	
	
}