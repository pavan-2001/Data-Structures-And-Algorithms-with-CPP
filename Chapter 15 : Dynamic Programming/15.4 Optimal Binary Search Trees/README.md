# Problem Statement

Suppose that we are designing a program to translate text from English to French. For each occurrence of each English word in the text, we need to look up for a French Equivalent.
We could perform these lookup operations by building a binary search tree with n English words as keys and their French equivalents as satellite data.
Formally we are given a sequence K=<K1,K2,...,Kn> of n distinct keys in sorted order and we wish to build a **Binary Search Tree** from these keys.
For each key Ki, we have a probability Pi that a search will be for Ki.Some searches may be for values not in K,and we also have n+1 dummy keys representing the values not in K.

We can solve this problem using Dynamic Programming.

Time Complexity of the approach is O(n^3).
