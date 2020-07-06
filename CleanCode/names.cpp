#include <vector>

class BadNames1 {
    std::vector<std::pair<int, int>> game_board;

    std::vector<std::pair<int,int>> getThem()
    {
        std::vector<std::pair<int, int>> list1 {};
        for (std::pair<int, int> x : game_board) {
            if (x.first == 4) {
                list1.push_back(x);
            }
        }
    }
};



class BadNames2 {
    enum class Status { Flagged, Unflagged};
    struct Cell {
        Status status { Status::Flagged };
        int bomb_count { 0 };
    };

    std::vector<Cell> game_board;

    std::vector<Cell> getFlaggedCells()
    {
        std::vector<Cell> flagged_cells {};
        for (Cell x : game_board) {
            if (x.status == Status::Flagged) {
                flagged_cells.push_back(x);
            }
        }
    }
};

class BdNms3 {
    int ts_yymmdd;
};

class BadNames4 {
    int unix_timestamp;
};

const int INCLUDE_NONE = 0;
const int INCLUDE_FIRST = 1;
const int INCLUDE_SECOND = 2;
const int INCLUDE_BOTH = 3;

const int INCLUDE_NO_DATE = 0;
const int INCLUDE_START_DATE = 1;
const int INCLUDE_END_DATE = 2;
const int INCLUDE_BOTH_DATES = 3;

int MY_CONTROLLER_FOR_EFFICIENT_HANDLING_OF_STRINGS = 1;
int MY_CONTROLLER_FOR_EFFICIENT_STORING_OF_STRINGS = 2;

class ObjectManager;
class ObjectController;

// Disinformation

class Pair {
    int first;
    int second;
    int third;
};

class Triple {
    int first;
    int second;
    int third;
};


void copy(char a1[], char a2[]) {
    while (*(a2++) = *(a1++))
        ;
}

int* pi_target;