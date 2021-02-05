# Problem Statement

There are several methods for measuring the similarity of two **DNA** sequence by aligning them. One such method to align two sequences x and y consists of inserting spaces at arbitary locatins in the two sequences (including at either end) so that the resulting sequence **x'** and **y'** have the same length but do not have a space in the same position (i.e., for no position j are both x'[j] and y'[j] a space ). Then we assign a "score" to each position. Position j receives a score as follows:

1: +1 if x'[j] = y'[j] and neither is a space.

2: -1 if x'[j] != y'[j] and neither ia a space.

3: -2 if either x'[j] or y'[j] is a space.

The score for the alignment is the sum of the scores of the individual positions. For example, given the sequence x = GATCGGCAT and y = CAATGTGAATC, one alignment is 

G ATCG GCAT

CAAT GTGAATC

A + under a position indicates a score of +1 for that position, a - indicates a score of -1, and a * indicates a score of -2, so that this alignment has a total score of 

6.1 - 2.1 - 4.2 = -4.

Explain how to cast the problem of finding an optimal alignment as an edit distance problem using a subset of the transformation operations copy, replace, delete, insert, twiddle, and kill.
