// Q-Learning.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
using namespace std;

float max(float A, float B) {
	if (A > B)
		return A;
	else
		return B;
}

// Coordinates of agent and goal
int agent_x = 2;
int agent_y = 2;
int goal_x = 11;
int goal_y = 7;

const int boundary_low_x = 0; // lower x boundary that the agent cannot be less than
const int boundary_high_x = 13; // upper x boundary that the agent cannot be greater than
const int boundary_low_y = 0; // lower y boundary that the agent cannot be less than
const int boundary_high_y = 9; // upper y boundary that the agent cannot be greater than

struct Cell
{
	float value;
	bool already_seen;
};

void display_table(Cell grid[][14]) {

	// Display the Table

	for (int r = 0; r < boundary_high_y + 1; r++) { // r spans the range 0 to high y boundary
		for (int c = 0; c < boundary_high_x + 1; c++) { // c spans the range 0 to high x boundary
			printf("%F", grid[r][c].value);

		}
		printf("\n");
	}
	printf("\n");
	printf("\n");
}



float find(int agent_x, int agent_y, int goal_x, int goal_y, Cell grid[][14]) {
	if (agent_x == goal_x && agent_y == goal_y) { //If you found the goal
		return grid[goal_y][goal_x].value;

	}
	else if (grid[agent_y][agent_x].already_seen == true) {
		return grid[agent_y][agent_x].value;
	}
	// set position to zero
	grid[agent_y][agent_x].already_seen = true;

	// check values around location
	// choose the biggest one
	float biggest_so_far = 0;
	// If I can go North, go North and tell me what the biggest number is
	if (agent_y - 1 < boundary_low_y) {
		//call function find
		biggest_so_far = max(find(agent_x, agent_y, goal_x, goal_y, grid), biggest_so_far);
	}

	// If I can go South...
	if (agent_y + 1 < boundary_high_y) {
		//call function find
		biggest_so_far = max(find(agent_x, agent_y, goal_x, goal_y, grid), biggest_so_far);
	}
	// If I can go West...
	if (agent_x - 1 > boundary_low_x) {
		//call function find
		biggest_so_far = max(find(agent_x, agent_y, goal_x, goal_y, grid), biggest_so_far);
	}
	// If I can go East...
	if (agent_x + 1 < boundary_high_x) {
		//call function find
		biggest_so_far = max(find(agent_x, agent_y, goal_x, goal_y, grid), biggest_so_far);
	}

	// update the currect cell value
	grid[agent_y][agent_x].value = biggest_so_far / 0.9f;

	// return to where I used to be
	return grid[agent_y][agent_x].value;

}

int main()
{
	// setting up numbers for each box in the grid
	Cell grid[10][14];
	for (size_t r = 0; r < boundary_high_y + 1; r++) { //size_t is like int but less bits
		for (size_t c = 0; c < boundary_high_x + 1; c++) {
			grid[r][c].value = 0;
			grid[r][c].already_seen = false;
		}

	}
	grid[goal_y][goal_x].value = 1000.0f;
	find(agent_x, agent_y, goal_x, goal_y, grid);
	display_table(grid);



	return 0;
}
