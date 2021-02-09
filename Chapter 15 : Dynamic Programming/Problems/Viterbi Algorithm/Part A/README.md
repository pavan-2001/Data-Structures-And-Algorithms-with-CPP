# Problem Statement

**Viterbi Algorithm**

We can use dynamic programming on a directed graph G = (V,E) from speech recognition. Each edge (u,v) belong to E is labeled with a sound sigma(u,v)  from a finite set of sounds. The labeled graph is a formal model of a person speaking a restricted language. Each path in the graph starting from a distinguished vertex Vo belongs V corresponds to a possible sequence of sounds produced by the model. We define the label of a directed path to be the concatenation of the labels of the edges on that path.

Describe an efficient algorithm that, given an edge-labeled graph G with distinguished vertex Vo and a sequence S = <s1,s2,s3,...,sK> of sounds from the set, 
returns a path vertex Vo and a sequence s as its label. if any such path exists. Otherwise, the algorithm should return NO-SUCH-PATH. Analyze the running time of your algorithm .

