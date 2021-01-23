# Problem statement

**Printing neatly**

Consider the problem of neatly printing a paragraph with a monospaced font (all characters having the same width) on a printer.
The input text is a sequence of n words of lengths L1,L2,...,Ln, measured in characters. We want to print this paragraph neatly on a number of lines that hold a maximum of M characters each.
Out criterion of "neatness is as follows. If a given line containes words i through j, where i<=j, and we leave exactly one space between words, the number of extra space characters at the end of the line is M-j+i-(summation of lengths of words from i to j), which must be non-negative so that the words fit on the line.
We wish to minimize the sum, over all lines except the last, of the cubes of the numbers of extra space characters at the ends of lines. 
Give a dynamic-programming algorithm to print a paragraph of n words on a printer. Analyze the running time and space requirements of your algorithm.

Time Complexity O(n^2).
Space Complexity O(n^2).
