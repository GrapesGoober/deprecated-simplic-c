# Simplic
A refactorization of SimplicCompiler repo 
# File Structure (subject to change)
- `simplic-node.h` and `simplic-node.c` for custom node structure used throughout simplic
- `simplic-token.h` for token definition and consts used by tokens. no functions here
- `tofs-cursor.h` and `tofs-cursor.c` for reading files using cursor (also contains implementation of cursor)
- `tof-cleaners.h` and `tof-cleaners.c` for cleaner funcions
- `tofs-matchers.h` and `tofs-matchers.c` for simple matching functions, like `tof_kwtype` or `tof_ident`
