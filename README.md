# Simplic
A refactorization of SimplicCompiler repo 
# File Structure (subject to change)
All header files are stored in `simplic` folder, where its implentation is in `simplic\implement` folder.
- `tofs-cursor.h` and `tofs-cursor.c` for reading files using cursor (contains cursor, reading char from buffer, and go-back)
- `tofs-cleaners.h` and `tofs-cleaners.c` for cleaner funcions (this uses `tofs-cursor` to find comments)
- `tofs-matchers.h` and `tofs-matchers.c` for the string matching for tokens (this uses 
