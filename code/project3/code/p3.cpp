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





int main(int argc, char *argv[])
{
	try
	{
		int throw_v;
		if (argc<4)
		{
			throw_v=1;
			throw throw_v;
		}

		//open the summary file
		ifstream summary_file;
		summary_file.open(argv[1]);
		if (!summary_file)
		{
			cout<<"Error: Cannot open file "<<argv[1]<<"!"<<endl;
			return 0;
		}

		//read the summary file
		string line_summary;
		int i_summary=0;
		string summary_string[MAXSPECIES+1];
		while(getline(summary_file,line_summary))
		{	
			if (i_summary>MAXSPECIES)
			{
				cout<<"Error: Too many species!"<<endl;
				cout<<"Maximal number of species is "<<MAXSPECIES<<"."<<endl;
				summary_file.close();//close the summary file
				return 0;
			}		
			
			summary_string[i_summary]=line_summary;
			i_summary++;

		}	
		summary_file.close();//close the summary file


		int num_species=i_summary-1;
		string program_dir=summary_string[0];

		//save all the species into the structure
		species_t species[MAXSPECIES];
		for (int i=0; i<num_species; i++)
		{
			species[i].name=summary_string[i+1];
		}


		//open each program and read each species into structure
		
		for (int i=0; i<num_species; i++)
		{
			//open the program
			ifstream program_file;
			string program_file_name=program_dir+"/"+species[i].name;
			program_file.open(program_file_name.c_str());
			if (!program_file)
			{
				cout<<"Error: Cannot open file "<<program_file_name<<"!"<<endl;
				program_file.close();
				return 0;
			}

			//read the programs instructions into strings
			string line_program;
			string program_string[MAXPROGRAM];
			int i_program=0;
			while (getline(program_file,line_program))
			{
				if (line_program!=""&&i_program<MAXPROGRAM)
				{
					program_string[i_program]=line_program;
					i_program++;
				}
				else if (line_program!=""&&i_program>=MAXPROGRAM)
				{
					cout<<"Error: Too many instructions for species "<<species[i].name<<"!"<<endl;
					cout<<"Maximal number of instructions is "<<MAXPROGRAM<<"."<<endl;
					program_file.close();
					return 0;
				}
				else if (line_program=="")
				{
					break;
				}
				
				
			}
			program_file.close(); //close the program file

			species[i].programSize=i_program;

			for (int j=0; j<i_program; j++)
			{
				instruction_t program_instruction_trans;
				string operation;
				int address_help=0;
				istringstream helper;
				helper.str(program_string[j]);
				helper>>operation>>address_help;
				int exist_helper=-1;

				for (int k=0;k<9;k++)
				{
					if (opName[k]==operation)
					{
						exist_helper=k;
						break;
					}

				}
				if (exist_helper==-1)
				{
					cout<<"Error: Instruction "<<operation<<" is not recognized!"<<endl;
					return 0;
				}
				program_instruction_trans.op=(opcode_t)exist_helper;
				if (address_help!=0)
				{
					program_instruction_trans.address=address_help;
				}
				species[i].program[j]=program_instruction_trans;

			}	
		}

		//read the world file

		ifstream world_file;
		world_file.open(argv[2]);
		if (!world_file)
		{
			cout<<"Error: Cannot open file "<<argv[2]<<"!"<<endl;
			return 0;
		}
		string line_world;
		int world_height;
		int world_width;
		getline(world_file,line_world);
		world_height=atoi(line_world.c_str());
		getline(world_file,line_world);
		world_width=atoi(line_world.c_str());
		if (world_height>MAXHEIGHT||world_height<1)
		{
			cout<<"Error: The grid height is illegal!"<<endl;
			return 0;
		}
		if (world_width>MAXWIDTH||world_width<1)
		{
			cout<<"Error: The grid width is illegal!"<<endl;
			return 0;
		}
		int i_world=0;
		string world_string[MAXCREATURES];
		while(getline(world_file,line_world))
		{
			if (i_world>=MAXCREATURES)
			{
				cout<<"Error: Too many creatures!"<<endl;
				cout<<"Maximal number of creatures is "<<MAXCREATURES<<"."<<endl;
				world_file.close();
				return 0;
			}
			world_string[i_world]=line_world;
			i_world++;
		}
		world_file.close();
		int num_creatures=i_world;

		creature_t creatures[MAXCREATURES];



		for (int i=0;i<num_creatures;i++)
		{
			istringstream stringstream_creature;
			stringstream_creature.str(world_string[i]);
			string species_creature;
			string direction_creature;
			int row_creature;
			int column_creature;
			stringstream_creature>>species_creature>>direction_creature>>row_creature>>column_creature;
			int exist_species=-1;
			for (int j=0; j<num_species; j++)
			{

				if (species_creature==species[j].name)
				{
					exist_species=j;
					
					break;
				}
			}
			if (exist_species==-1)
			{
				cout<<"Error: Species "<<species_creature<<" not found!"<<endl;
				return 0;
			}
			creatures[i].species=&species[exist_species];
			int exist_direction=-1;
			for (int j=0;j<4;j++)
			{
				if(direction_creature==directName[j])
				{
					exist_direction=j;
					break;
				}
			}
			if(exist_direction==-1)
			{
				cout<<"Error: Direction "<<direction_creature<<" is not recognized!"<<endl;
				return 0;
			}
			creatures[i].direction=(direction_t)exist_direction;
			if (row_creature>=world_height||column_creature>=world_width||row_creature<0||column_creature<0)
			{
				cout<<"Error: Creature ("<<species_creature<<" "<<direction_creature<<" "<<row_creature<<" "<<column_creature<<") is out of bound!"<<endl;
				cout<<"The grid size is "<<world_height<<"-by-"<<world_width<<"."<<endl;
				return 0;
			}
			point_t point_creature;
			point_creature.r=row_creature;
			point_creature.c=column_creature;
			creatures[i].location=point_creature;

			
			creatures[i].programID=1;
		}

		//check whether each square in the grid is occupied by at most one creatures
		for (int i=0;i<num_creatures-1;i++)
		{
			for (int j=i+1;j<num_creatures;j++)
			{
				if (creatures[i].location.r==creatures[j].location.r&&creatures[i].location.c==creatures[j].location.c)
				{
					cout<<"Error: Creature ("<<creatures[j].species->name<<" "<<directName[creatures[j].direction]<<" "<<creatures[j].location.r<<" "<<creatures[j].location.c<<") overlaps with creature ("<<creatures[i].species->name<<" "<<directName[creatures[i].direction]<<" "<<creatures[i].location.r<<" "<<creatures[i].location.c<<")!"<<endl;
					return 0;	
				}
			}
		}

		int rounds=atoi(argv[3]);

		if (rounds<0)
		{
			cout<<"Error: Number of simulation rounds is negative!"<<endl;
			return 0;
		}

		//initialize world
		world_t world;
		
		world.grid.height=world_height;
		world.grid.width=world_width;

		
		
		world.numSpecies=num_species;
		world.numCreatures=num_creatures;

		for (int i=0;i<MAXSPECIES;i++)
		{
			world.species[i]=species[i];
		}

		for (int i=0;i<MAXCREATURES;i++)
		{
			world.creatures[i]=creatures[i];
		}

		for (int i=0; i<MAXHEIGHT;i++)
		{
			for (int j=0;j<MAXWIDTH;j++)
			{
				world.grid.squares[i][j]=NULL;
			}
		}
		for (int i=0; i<num_creatures;i++)
		{
			world.grid.squares[creatures[i].location.r][creatures[i].location.c]=&world.creatures[i];
		}

		cout<<"Initial state"<<endl;
		printGrind(world.grid);
		
		bool verbose=0;
		if (argc>4)
		{
			if (argv[4][0]=='v'&&argv[4][1]=='\0')
			{
				verbose=1;
			}
			if (argv[4][0]=='v'&&argv[4][1]=='e'&&argv[4][2]=='r'&&argv[4][3]=='b'&&argv[4][4]=='o'&&argv[4][5]=='s'&&argv[4][6]=='e'&&argv[4][7]=='\0')
			{
				verbose=1;
			}
		}
		
		
		

		








		if (verbose==1)
		{
			for (int i=0;i<rounds;i++)
			{
			
				cout<<"Round "<<i+1<<endl;
			
				for (int k=0;k<num_creatures;k++)
				{
					cout<<"Creature ("<<world.creatures[k].species->name<<" "<<directName[world.creatures[k].direction]<<" "<<world.creatures[k].location.r<<" "<<world.creatures[k].location.c<<") takes action:"<<endl;

					simulateCreature(world.creatures[k], world.grid, verbose);
				}
				
			}
		}
		else
		{
			for (int i=0;i<rounds;i++)
			{
			
				cout<<"Round "<<i+1<<endl;
			
				for (int k=0;k<num_creatures;k++)
				{
					cout<<"Creature ("<<world.creatures[k].species->name<<" "<<directName[world.creatures[k].direction]<<" "<<world.creatures[k].location.r<<" "<<world.creatures[k].location.c<<") takes action: ";

					simulateCreature(world.creatures[k], world.grid, verbose);
				}
				printGrind(world.grid);
				
			}
		}

		


	}
	catch (int throw_v)
	{
		if (throw_v==1)
		{
			cout<<"Error: Missing arguments!"<<endl;
			cout<<"Usage: ./p3 <species-summary> <world-file> <rounds> [v|verbose]"<<endl;
		}
		return 0;
	}


}

