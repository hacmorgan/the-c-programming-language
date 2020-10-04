# Invoking command
`for catprog in cat ./libraryCat ./syscallCat; do for j in {1..5}; do time (for i in {1..1000}; do $catprog /tmp/bigfile > /dev/null; done); done; done > results.md 2>&1`

# /usr/bin/cat
2.385
2.364
2.380
2.374
2.366

# libraryCat
1:03.89
1:03.53
1:03.82
1:03.72
1:03.65

# syscallCat
2.727
2.708
2.704
2.699
2.692
