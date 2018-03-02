# Balanced-Tree

Ordinary binary search trees suffer from a
troublesome problem. They work well if the data is
inserted into the tree in random order. However, they
become much slower if data is inserted in already-sorted
order (17, 21, 28, 36,…) or inversely sorted order (36, 28,
21, 17,…). When the values to be inserted are already
ordered, a binary tree becomes unbalanced. With an
unbalanced tree, the ability to quickly find (or insert or
delete) a given element is lost.
This project explores one way to solve the problem of
unbalanced trees: the red-black tree, which is a binary
search tree with some added features.
There are other ways to ensure that trees are balanced.
