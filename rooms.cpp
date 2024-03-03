#include "rooms.h"

using namespace std;

RoomArray::RoomArray(int numRooms) : matching(numRooms){
    // hyperparameters (all inclusive)
    const int minMeanVal = 100;
    const int maxMeanVal = 10000;
    const int minDeviatVal = 500;
    const int maxDeviatVal = 1000;

    this->numRooms = numRooms;
    // vector with valuations for each room, which we assume is Gaussian
    this->valuationDistributions = vector<normal_distribution<double>>(numRooms);
    random_device rd;
    mt19937 g(rd());
    uniform_int_distribution<int> meanDist(minMeanVal, maxMeanVal);
    uniform_int_distribution<int> deviatDist(minDeviatVal, maxDeviatVal);
    for (int i = 0; i < numRooms; i++) {
        // generate random mean and standard deviation for each room
        this->valuationDistributions[i] = normal_distribution<double>(meanDist(g), deviatDist(g));
    }
    // matching between agents and rooms
    this->matching = Matching(numRooms);
}

Matching::Matching(int numRooms) {
    this->assignments = vector<int>(numRooms, -1);
}

int Matching::getAssignmentForAgent(int agent_id) {
    for (int i = 0; i < assignments.size(); i++) {
        if (assignments[i] == agent_id) {
            return i;
        }
    }
    return -1;
}

Matching Matching::copy() {
    Matching * m = new Matching(this->assignments.size());
    vector<int> v(this->assignments);
    m->assignments = v;
    return *m;
}
