## Branch & Bound

Learn Branch & Bound approach by solving Travelling Salesman problem (TSP).

<dl>
  <dt>Travelling Salesman Problem (TSP)</dt>
  <dd>Given a list of cities and the distances between each pair of cities, what is the shortest possible route that visits each city exactly once and returns to the origin city? It is an NP-hard problem in combinatorial optimization.</dd>
  <dt>Branch and Bound (BB, B&B, or BnB)</dt>
  <dd>The algorithm explores branches of the rooted tree, which represent subsets of the solution set. Before enumerating the candidate solutions of a branch, the branch is checked against upper and lower estimated bounds on the optimal solution, and is discarded if it cannot produce a better solution than the best one found so far by the algorithm.</dd>
</dl>

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

```console
make compile
```

For execution, run the following command:

```console
make run
```

For both compilation and execution, run the following command:
The -all flag is optional as it's default

```console
make
make all
```

For getting stack-usage-info and debug mode:

```console
make run-debug
```

For cleaning out all executables and stack-usage-info files:

```console
make clean
```

---

## Output

<img src="https://github.com/atharva007-cmd/Assignments/blob/master/TY-Assignments/DAA/Branch%20and%20Bound/travelling-salesperson-implementation.png" width="35%" />

<img src="https://github.com/atharva007-cmd/Assignments/blob/master/TY-Assignments/DAA/Branch%20and%20Bound/travelling-salesperson-visualization.png" width="35%" />
