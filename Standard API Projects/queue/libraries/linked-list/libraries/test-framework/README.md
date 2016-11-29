There is a problem when using namespaces with templates inside header file. Compilers don't like this situation. More explained here http://stackoverflow.com/questions/3261093/function-template-in-a-namespace-in-a-separate-file-compiles-fine-but-the-linke.

The solution for problem is pretty simple:
1. In your main file instead using "<path_to_file>/Test.h" use "<path_to_file>/Test.cpp"
2. Move template function's implementation from cpp file to header file, and then include file normally "<path_to_file>/Test.h"
