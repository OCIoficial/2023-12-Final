#include <iostream>
#include <vector>
#include <queue>
#include <unistd.h>

/*
    Grid legend:
    -1: "Target" azulejo
    -2: "Starting" azulejo
    Any number >= 0: Distance from a "Target" tile to a "Starting" Tile
*/

bool check_distance(std::vector<std::vector<int>> &distance, int &min_distance, 
                   const std::pair<int, int> &current, const std::pair<int, int> &prev) {
    // Options: 
    //  1. Distance > current_distance, go with current_distance + 1
    //  2. Goal space, go with current_distance and update min_distance
    //  3. current_distance > min_distance, abort and return
    //      TODO: should this be done in bfs?
    //  4. Start space, do nothing and return
    
    //printf("second value: %d, with total size: %d\n", current.second, distance[0].size() );
    if (current.first < 0 || current.first >= distance.size() ||
    current.second < 0 || current.second >= distance[0].size()) {
        //printf("Exited out of bounds for %d, %d\n", current.first, current.second);
        return false;
    }

    int current_distance = distance[prev.first][prev.second] == -1 ? 1 : distance[prev.first][prev.second] + 1;
    if (current_distance > min_distance) {
        // Case 3
        return false;
    } else if (distance[current.first][current.second] == -1) {
        // Case 4
        return false;
    } else if (distance[current.first][current.second] == -2) { 
        // Case 2
        min_distance = current_distance;
        //printf("Not really setting anything but updating min distance\n");
        return false;
    } else if (distance[current.first][current.second] > current_distance) { 
        // Case 1
        distance[current.first][current.second] = current_distance;
    } else if (distance[current.first][current.second] <= current_distance) { 
        return false;
    } else {
        // How to get this to work with std::unreachable?
        std::cout << "-----UNREACHABLE-----\n";
        // printf("at %d, %d got value %d\n", current.first, current.second, distance[current.first][current.second]);
    }
    //printf("setting value at %d, %d to %d\n", current.first, current.second, distance[current.first][current.second]);
    return true;
}

void bfs(std::vector<std::vector<int>> &distance, int &min_distance, std::pair<int, int> start) {
    std::queue<std::pair<int, int>> next;
    next.push(start);
    while (!next.empty()) {
        auto current_pos = next.front();
        next.pop();
        int current_distance = distance[current_pos.first][current_pos.second];
        if (current_distance == -1 ) {
            current_distance = 0;
        }
        if (current_distance > min_distance) {
            continue;
        }
        // printf("current distance at %d, %d is %d\n", current_pos.first, current_pos.second, current_distance); 
        // printf("Checking down\n");
        if (check_distance(distance, min_distance, {current_pos.first + 1, current_pos.second}, current_pos))
            next.push({current_pos.first + 1, current_pos.second});
        // printf("Checking up\n");
        if (check_distance(distance, min_distance, {current_pos.first - 1, current_pos.second}, current_pos))
            next.push({current_pos.first - 1, current_pos.second});
        // printf("Checking right\n");
        if (check_distance(distance, min_distance, {current_pos.first, current_pos.second + 1}, current_pos))
            next.push({current_pos.first, current_pos.second + 1});
        // printf("Checking left\n");
        if (check_distance(distance, min_distance, {current_pos.first, current_pos.second - 1}, current_pos))
            next.push({current_pos.first, current_pos.second - 1});
        // printf("----------------------------------------------------\n");
        // sleep(3);
    }
}

int overlap;
int read_input(std::vector<std::vector<int>> &distance, int marker, int &min_distance, std::vector<std::pair<int, int>> &goal) {
    // TODO: overlap
    int tile_count = 0;
    for (int i = 0; i < distance.size(); i++) {
        for (int j = 0; j < distance[0].size(); j++) {
            int entry;
            std::cin >> entry;
            //printf("reading %d, %d with value %d\n", i, j, entry);
            if (entry == 1) {
                if (marker == -1 && distance[i][j] == -2) {
                    // Target tiles might overlap with starting tiles
                    overlap++;
                } else {
                    distance[i][j] = marker;
                    // printf("Writing %d at pos %d, %d\n", marker, i, j);
                }
                tile_count++;
            }
            if (marker == -1 && distance[i][j] == -1) {
                goal.push_back({i, j});
            }
        }
    }
    return tile_count;
} 

int main (){
    overlap = 0;
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> distance(n, std::vector<int>(m, 1000001));
    std::vector<std::pair<int, int>> goal;
    int min_distance = 1000002;
    read_input(distance, -2, min_distance, goal);
    int tile_count = read_input(distance, -1, min_distance, goal);
    for (auto start_pos : goal) {
        bfs(distance, min_distance, start_pos);
    }
    if (overlap == 0) {
        std::cout << min_distance + tile_count - 1 << std::endl; 
    } else {
        std::cout << tile_count - overlap << std::endl; 
    }
    return 0;
}
