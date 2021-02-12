# Problem Statement

Now, suppose that every edge (u,v) belongs to E has an associated non-negative probability p(u,v) of traversing the edge (u,v) from vertex u and thus producing the corresponding sound. The sum of the probabilites of the edges leaving any vertex equals 1. The probability of a path is defined to be the product of the probabilites of its edges. We can view the probability of a path beginning at Vo as the probability that a **"random walk"** beginning at Vo will follow the specified path, where we randomly choose which edge to take leaving a vertex u according to the probabilites of the available edges leaving u.

Extend your answer to part(a) so that if a path is returned, it is a most probable path starting at Vo and having label s . Analyze the running time of your algorithm.

Time complexity is O(K.(V^2)).

Space complexity is O(K.V).
