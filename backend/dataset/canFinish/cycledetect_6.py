class Solution:
    def canFinish(self, n, E):
        arrow   = defaultdict(list)
        prereqs = defaultdict(set)
        for x,y in E:
            arrow  [y].append(x)  # courses must be taken as y -> x
            prereqs[x].add   (y)  # x, after y
        #
        # Waiting: courses with prerequisites (the rest are ok)
        waiting = {e[0] for e in E}
        # Front: Foundational courses that we can use to get started
        #        "Courses that are foundational to others without having prerequisites themselves"
        front    = {e[1] for e in E} - waiting 
        #
        while front:
            new = []
            for y in front:
                # Visit all "courses=x" that depend on "front=y"
                for x in arrow[y]:
                    #     Arrow-Order: y -> [x1,x2,x3]
                    # Remove "y" as prerequisite of "xi" (it's free to take now)
                    prereqs[x].remove(y) 
                    # if x is now free of prerequisites, then declare it a foundational course
                    if not prereqs[x]:   
                        # append to new generation of foundational courses
                        new.append(x)
                        # Remove problematic course "x"
                        waiting.remove(x)
            front = new
        if waiting:
            return False
        return True
