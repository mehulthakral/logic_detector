class Solution 
{
    static inline int CYCLE = -1;
    static inline int TO_VISIT = 0;
    static inline int SAFE = 1;

    static auto to_graph( const std::vector<std::vector<int>>& prerequisites )
    {
        auto graph = std::unordered_map<int, std::vector<int>>();

        for( auto& prerequsite : prerequisites )
        {
            const auto course = prerequsite[ 0 ];
            const auto req = prerequsite[ 1 ];

            graph[ course ].push_back( req );
        }

        return graph;
    }

    static bool is_safe( const int course, 
        std::unordered_map<int, std::vector<int>>& graph,
        std::vector<int>& states )
    {
    	// if we have already seen this course and determined
    	// it is safe, then we can safely exit.
        if( states[ course ] == SAFE )
            return true;

    	// otherwise, mark the course as HAVING a cycle
        // which will be picked if we reach this course
        // again by traversing the graph in the loop below.
        states[ course ] = CYCLE;

    	// check all the prereqs for this courses
        for( auto adj : graph[ course ] )
        {
        	// if any adj course has a cycle, then we can't finish
            if( states[ adj ] == CYCLE || !is_safe( adj, graph, states ) )
                return false;
        }

		// otherwise, mark this course safe and return
        states[ course ] = SAFE;
        
        return true;
    }

public:

	/// <summary>
	/// can finish
	/// </summary>
	/// <param name="numCourses">number of courses</param>
	/// <param name="prerequisites">list of prerequsites</param>
	/// <returns>if we can take all the courses safely</returns>
    static bool canFinish( const int numCourses, 
        const std::vector<std::vector<int>>& prerequisites )
    {
    	// convert the course prerequsites to a graph.
        auto graph = to_graph( prerequisites );
    	// keep track of the states of each course, all initially set
    	// to 0 / to visit
        auto states = std::vector<int>( numCourses, TO_VISIT );

        for( auto course = 0; course < numCourses; ++course )
        {
        	// if any course has a cycle, then we cannot finish.
            if( !is_safe( course, graph, states ) )
            {
                return false;
            }
        }

        return true;
    }
};
