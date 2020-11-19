## Branch & Bound

Learn Branch & Bound approach by solving Travelling Salesman problem (TSP).

Travelling Salesman Problem (TSP) [^1]
: Given a list of cities and the distances between each pair of cities, what is the shortest possible route that visits each city exactly once and returns to the origin city?
It is an NP-hard problem in combinatorial optimization.
[^1]: Travelling Salesman Problem [definition](https://en.wikipedia.org/wiki/Travelling_salesman_problem)

Branch and Bound (BB, B&B, or BnB) [^2]
: The algorithm explores branches of the rooted tree, which represent subsets of the solution set. Before enumerating the candidate solutions of a branch, the branch is checked against upper and lower estimated bounds on the optimal solution, and is discarded if it cannot produce a better solution than the best one found so far by the algorithm.
[^2]: Branch and Bound [definition](https://en.wikipedia.org/wiki/Branch_and_bound)

---

#### Input

    1.  Number of nodes
    2.  Costs between each node

#### Output

    1.  Route for traversal
    2.  Cost for traversal (Minimum)

---

#### How to run?

For compilation, run the following command:

```bash
make compile
```

For execution, run the following command:

```bash
make run
```

For both compilation and execution, run the following command:
The -all flag is optional as it's default

```bash
make
make all
```

For getting stack-usage-info and debug mode:

```bash
make run-debug
```

For cleaning out all executables and stack-usage-info files:

```bash
make clean
```

---

## Output

![output-for-above-code](https://github.com/atharva007-cmd/Assignments/tree/master/TY-Assignments/DAA/Branch%20and%Bound/travelling-salesperson-implementation.png)

![output-for-above-code](https://github.com/atharva007-cmd/Assignments/tree/master/TY-Assignments/DAA/Branch%20and%Bound/travelling-salesperson-visualization.png)
