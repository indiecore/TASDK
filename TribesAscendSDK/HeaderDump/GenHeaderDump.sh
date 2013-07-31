
ls > HeaderDump.h
sed -r -i "s/^/\#include \"/" HeaderDump.h
sed -r -i "s/$/\"/" HeaderDump.h