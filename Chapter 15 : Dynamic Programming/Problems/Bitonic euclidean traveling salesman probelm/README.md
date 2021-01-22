# Problem statement

In the **euclidean traveling-salesman problem**, we are given a set of points in the plane and we wish to find the shortest closed tour that connects all n points.
The general problem is NP-hard and its solution is therefore believed to require more than polynomial time.
**J.L. Bentley** has suggested that we simplify the problem by restricting our attention to **bitonic tours**, that is, tours that start at the leftmost point, go strictly rightward to the rightmost point, and then go strictly leftward back to the starting point.
In this case a polynomial-time algorithm is possible.

Describe an O(n^2)-time algorihtm for determining an optimal bitonic tour.You may assume that no two points have the same x-coordinate and that all operations on real numbers take unit time.
(**Hint** : Scan left to right, maintaining optimal posibilities for the two parts of the tour.)
