class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        
		# Constant defined for course state
        NOT_CHECKED, CHECKING, COMPLETED = 0, 1, 2
        
        # -------------------------------
        
        def has_deadlock( course )->bool:
            
            if course_state[course] == CHECKING:
                # There is a cycle(i.e., deadlock ) in prerequisites
                return True
            
            elif course_state[course] == COMPLETED:
                # current course has been checked and marked as completed
                return False
            
            
            
            # update current course as checking
            course_state[course] = CHECKING
            
            # check pre_course in DFS and detect whether there is deadlock
            for pre_course in requirement[course]:
                
                if has_deadlock( pre_course ):
                    # deadlock is found, impossible to finish all courses
                    return True
                
                                
            # update current course as completed
            course_state[course] = COMPLETED
            
            return False
        
        # -------------------------------
        
        # each course maintain a list of its own prerequisites
        requirement = collections.defaultdict( list )
        
        for course, pre_course in prerequisites:
            requirement[course].append( pre_course )
        
        
        # each course maintain a state among {NOT_CHECKED, CHECKING, COMPLETED}
		# Initial state is NOT_CHECKED 
        course_state = [ NOT_CHECKED for _ in range(numCourses) ]
           
        # Launch cycle (i.e., deadlock ) detection in DFS
        for course_idx in range(0, numCourses):
            
            if has_deadlock(course_idx):
                # deadlock is found, impossible to finish all courses
                return False
        
        # we can finish all course with required order 
        return True
            
            
