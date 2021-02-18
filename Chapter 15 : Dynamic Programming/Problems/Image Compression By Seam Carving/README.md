# Problem Statement

We are given a color picture consisting of an **m x n** array A[1...m , 1...n] of pixels, where each pixel specifies a triple of red, green and blue(RGB) intensities. Suppose that we wish to compress this picture slightly. Specifically, we wish to remove one pixel from each of the m rows, so that the whole picture becomes one pixel narrower. To avoid disturbing visual effects, however, we require that the pixels removed in two adjacent rows be in the same or adjacent columns; the pixels removed form a "seam" from the top row to the bottom  row where successive pixels in the seam are adjacent vertically or diagonally.

Suppose now that along with each pixel A[i,j], we have calculated a real-valued disruption measure d[i,j], indicating how disruptive it would be to remove pixel A[i,j]. Intutively, the lower a pixel's disruption measure, the more similar the pixel is to its neighbors. Suppose further that we define the disruption measure of a seam to be the sum of the disruption measures of its pixels.

Give an algorithm to find a seam with the lowest disruption measure. How efficient is your algorithm?

Time Complexity O(n.m).

Space Complexity O(n.m).
