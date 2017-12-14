#include <Python.h>

static PyObject* my_helloworld(PyObject* self) {
    return Py_BuildValue("s", "Hello, Python extensions!!!");
}

static PyObject* my_func(PyObject* self, PyObject* args) {
    int i;
    double d;
    const char* s;
    
    if (!PyArg_ParseTuple(args, "ids", &i, &d, &s)) {
        return NULL;
    }
    
    Py_RETURN_NONE;
}

static PyObject* my_add(PyObject* self, PyObject* args) {
    int a, b;
    
    if (!PyArg_ParseTuple(args, "ii", &a, &b)) {
        return NULL;
    }
    
    return Py_BuildValue("i", a + b);
}

static PyObject* my_add_substract(PyObject* self, PyObject* args) {
    int a, b;
    
    if (!PyArg_ParseTuple(args, "ii", &a, &b)) {
        return NULL;
    }
    
    return Py_BuildValue("ii", a + b, a - b);
}

static char helloworld_docs[] = "helloworld(): Any message you want to put here.\n";
static char func_docs[]   = "somefunc(i, d, s): Accepts three values and return None.\n";
static char add_docs[] = "add(a, b): returns sum of a and b.";
static char add_substract_docs[] = "add_substract(a, b): returns sum and substract of a and b.";

static PyMethodDef helloworld_funcs[] = {
    {"helloworld", (PyCFunction) my_helloworld, METH_NOARGS, helloworld_docs},
    {"somefunc", my_func, METH_VARARGS, func_docs},
    {"add", my_add, METH_VARARGS, add_docs},
    {"add_substract", my_add_substract, METH_VARARGS, add_substract_docs},
    {NULL}
};

void inithelloworld(void) {
    Py_InitModule3("helloworld", helloworld_funcs, "Extension module example!");
}
