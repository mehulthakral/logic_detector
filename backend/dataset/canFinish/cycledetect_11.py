class Solution:
    def helper(self, course):
        if self.finish[course] == 1:  # visiting
            return False
        if self.finish[course] == -1:  # already finished course
            return True
        # when self.finish[course] == 0, for unvisited course
        self.finish[course] = 1  # mark as visiting
        if self.prerequisites[course]:  # when prerequisites for this course is not None
            for base in self.prerequisites[course]:
                if not self.helper(base):
                    return False
        self.finish[course] = -1  # mark as finished course
        return True

    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        self.prerequisites = [[] for i in range(numCourses)]
        self.finish = [0 for i in range(numCourses)]
        for course, base in prerequisites:
            self.prerequisites[course].append(base)
        len_prerequisite = [len(prerequisite) for prerequisite in self.prerequisites]
        if min(len_prerequisite) > 0:
            return False
        for i in range(numCourses):
            if not self.helper(i):
                return False
        return True
