/* File: agent.h
* -------------
* This file defines the Agent class, which is the base class for
* all agents in the simulation.  It is responsible for maintaining
* the agent's state and providing a common interface for all agents.
*/

#ifndef _agent_h
#define _agent_h

#include <algorithm>
#include <functional>
#include <random>
#include <iostream>
#include <numeric>
#include <vector>
#include "rooms.h"

class Agent {
    // CONSTANTS CONTROLLING RANDOM VALUES
    int kBudgetParam = 20;
    int kValuationParam = 100;

    public:
        int id;
        double budget;

        // valuations[k] is the valuation of room k
        std::vector<int> valuations;
        // preferences[k] is the kth highest valued room (ties broken by lower room number)
        std::vector<int> preferences;

        Agent(int id, RoomArray rooms);

        int getValuation(int room);
        int getPreferenceRank(int room);

        void printValuations();
        void printPreferences();
};

class AgentArray {
    public:
        int numAgents;
        int numRooms;
        std::vector<Agent> agents;
        // preferences stored as 2d array. preferences[i][j] is the jth highest valued room for agent i
        std::vector<std::vector<int>> preferences;
        // valuations stored as 2d array. valuations[i][j] is the valuation of room j for agent i
        std::vector<std::vector<int>> valuations;

        AgentArray(int numAgents, RoomArray rooms);
        AgentArray copy();

        int computeTotalWelfare(Matching &m);

        void printValuations();
        void printPreferences();
        void printResults(Matching &m);

};

#endif