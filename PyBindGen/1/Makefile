PYTHON_INCLUDE=/usr/include/python2.5
PYBINDGEN_LOCATION=../../

all: MyModule.so

# build my C library
libmymodule.so: my-module.o
	gcc -shared -o libmymodule.so my-module.o
my-module.o: my-module.h my-module.c
	gcc -fPIC -c -o my-module.o my-module.c

# generate the binding code
my-module-binding.c: my-module.h my-module.py
	PYTHONPATH=$$PYTHONPATH:$(PYBINDGEN_LOCATION) python my-module.py > my-module-binding.c
# build the binding code
my-module-binding.o: my-module-binding.c
	gcc -fPIC -I$(PYTHON_INCLUDE) -c -o my-module-binding.o my-module-binding.c
# build the final python module
MyModule.so: libmymodule.so my-module-binding.o
	gcc -shared -o MyModule.so -L. -lmymodule my-module-binding.o

clean:
	rm -f *.o *.so my-module-binding.c *~ 2>/dev/null

