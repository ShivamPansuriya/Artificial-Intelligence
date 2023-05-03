import copy

def get_states(state: list) -> list:
    states = list()
    
    for row in range(0, len(state)):
        for col in range(0, len(state[row])):
            if(state[row][col] == 0):
                if(row==0 or row==1):
                    tmp_state = copy.deepcopy(state)
                    tmp_state[row][col], tmp_state[row+1][col] = tmp_state[row+1][col], tmp_state[row][col]
                    states.append(tmp_state)

                if(row==1 or row==2):
                    tmp_state = copy.deepcopy(state)
                    tmp_state[row][col], tmp_state[row-1][col] = tmp_state[row-1][col], tmp_state[row][col]
                    states.append(tmp_state)
                
                if(col==0 or col==1):
                    tmp_state = copy.deepcopy(state)
                    tmp_state[row][col], tmp_state[row][col+1] = tmp_state[row][col+1], tmp_state[row][col]
                    states.append(tmp_state)

                if(col==1 or col==2):
                    tmp_state = copy.deepcopy(state)
                    tmp_state[row][col], tmp_state[row][col-1] = tmp_state[row][col-1], tmp_state[row][col]
                    states.append(tmp_state)
    return states

def get_heuristic(states: list) -> list:
    costs={}
    for state in states:
        if state not in closed:
            cost = 0
            for row in range(0, len(state)):
                for col in range(0, len(state[row])):
                    if(state[row][col] != goal[row][col]):
                        cost = cost + 1
            costs[cost]=state
    lst = list(costs.items())
    lst.sort()
    costs = dict(lst)
    return list(costs.values())

def ASTAR() -> None:
    while(len(open)>0):
        node = open.pop(0)
        if node not in closed:
            print(node)
            if(node == goal):
                break
            closed.append(node)
            open[:0]= get_heuristic(get_states(node))

if __name__ == "__main__":
    goal = [
        [1, 2, 3],
        [8, 0, 4],
        [7, 6, 5]
    ]
    
    puzzle = [
        [2, 8, 1],
        [0, 4, 3],
        [7, 6, 5]
    ]

    open = list()
    open.append(puzzle)
    closed = list()

    ASTAR()