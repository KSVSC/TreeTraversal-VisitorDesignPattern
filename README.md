# Tree Traversal AST

Given an infix expression, the code parser it according to the grammar given in [calc.yy](https://github.com/KSVSC/TreeTraversal-VisitorDesignPattern/blob/main/astcpp-visitor_working/calc.yy) and constructs an AST. It does tree-traversal procedures to prints postfix and prefix patterns of the given infix expressions and evaluate them.

## Installation

### Flex & Bison

```bash
$ sudo apt-get update
$ sudo apt-get upgrade
$ sudo apt-get install flex bison
```

### Check Installation

```bash
$ which bison
$ which flex
```

## Usage

There are two methods approached for tree-traversal.
* Normal Postfix pattern generation
* Postfix pattern generation using Visitor design pattern 

__Both directories have a Makefile__  

#### Compile  
```bash
$ make
```
#### Run
```bash
$ ./calc
```
#### Clean
```bash
$ make clean
```
## Note
* Make sure you install latest versions of flex and bison
