# SimpleIDE

A simple command-line helper to compile and optionally run C++ programs.

## Building

Compile the helper itself:

```bash
g++ simpleide.cpp -o simpleide
```

## Usage

```bash
./simpleide <source.cpp> [-o output] [-r]
```

- `-o`, `--output` - name of the compiled executable (default: `a.out`)
- `-r`, `--run` - run the executable after successful compilation

Example:

```bash
./simpleide main.cpp -o main -r
```

This will compile `main.cpp` into `main` and run it automatically.
