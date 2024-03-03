/* File: rooms.h
* -------------
* This file defines the RoomArray class, which is responsible for
* storing information about the rooms in our simulation and maintaining
* a matching between agents and rooms.
*/
#ifndef _env_h
#define _env_h

#include <random>
#include <vector>

class Matching {
    public:
        std::vector<int> assignments; // assignments[i] is the agent_id assigned to room i

        Matching(int numRooms);
        int getAssignmentForAgent(int agent_id);
        Matching copy();
};

class RoomArray {
    public:
        int numRooms;
        std::vector<std::normal_distribution<double>> valuationDistributions;
        Matching matching;

        RoomArray(int numRooms);
};

#endif

