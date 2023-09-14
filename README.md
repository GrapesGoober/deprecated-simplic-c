# Simplic
A refactorization of SimplicCompiler repo 
# File Structure (subject to change)
All header files are stored in `simplic` folder, where its implentation is in `simplic\implement` folder.
- `tofs-cursor` for reading files using cursor (contains cursor, reading char from buffer, and go-back)
- `tofs-cleaners` for cleaner funcions (this uses `tofs-cursor` to find comments)
- `tofs-matchers` for the string matching for tokens (this uses
- `aofs-assembler` for assembler functions
- `aofs-hexfile` for writing to hex file
