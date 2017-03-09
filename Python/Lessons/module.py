import os, sys

print(os.getcwd())
print(sys.path)

import mymodule

print(mymodule.f(4, 2))

print(help("modules"))
