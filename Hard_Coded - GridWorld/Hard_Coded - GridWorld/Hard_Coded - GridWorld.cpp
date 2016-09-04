// Hard-Coded Policy.cpp : Defines the entry point for the console application.
//

#include <iostream> 
#include "stdafx.h"
using namespace std;

const int boundary_low_x = 0; // lower x boundary that the agent cannot be less than
const int boundary_high_x = 13; // upper x boundary that the agent cannot be greater than
const int boundary_low_y = 0; // lower y boundary that the agent cannot be less than
const int boundary_high_y = 9; // upper y boundary that the agent cannot be greater than

void display_table(int agent_x, int agent_y, int goal_x, int goal_y) {
	// Gives grid boundaries and positions agent and goal in grid
	char grid[boundary_high_y][boundary_high_x];
	grid[agent_y][agent_x] = 'A';
	grid[goal_y][goal_x] = 'G';

	// Display the Table
	for (int r = 0; r < boundary_high_y + 1; r++) { // r spans the range 0 to high y boundary
		for (int c = 0; c < boundary_high_x + 1; c++) { // c spans the range 0 to high x boundary
														// when a spot in the grid is A or G
			if (grid[r][c] == 'A' || grid[r][c] == 'G') {
				printf("%c", grid[r][c]); // print its value at its position in the grid
			}
			else {
				printf("%c", '-'); // everything else is a dash, prettier this way
			}
		}
		printf("\n");
	}
	printf("\n");
	printf("\n");
}


int main()
{
	int agent_x = 2;
	int agent_y = 2;
	int goal_x = 11;
	int goal_y = 7;

	// Take the agent coordinates and
	// Move, one at a time, to get the x coordinate to match with the goal.
	// Move to get the y coordinate to match the goal
	while (agent_x != goal_x) {

		if (agent_x > goal_x) {
			agent_x--;
		}
		else {
			agent_x++;
		}
		display_table(agent_x, agent_y, goal_x, goal_y);
	}
	while (agent_y != goal_y) {
		if (agent_y > goal_y) {
			agent_y--;
		}
		else {
			agent_y++;
		}
		display_table(agent_x, agent_y, goal_x, goal_y);
	}
	printf("Goal Found ");
	// Display Amount of steps to find goal

	return 0;
}
