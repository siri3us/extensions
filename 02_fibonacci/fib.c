#include <Python.h>
#include <stdlib.h>

int _fib(int n)
{
    if (n > 45) {
        return -1;
    }
    int* buffer = (int*) malloc(sizeof(int) * (n + 1));
    if (!buffer) {
        return -1;
    }
    buffer[0] = buffer[1] = 1;
    int i;
    for (i = 2; i <= n; ++i) {
        buffer[i] = buffer[i - 1] + buffer[i - 2];
    }
    int value = buffer[n]; 
    free(buffer);
    return value;
}


static PyObject *OverflowError;

static PyObject* fib(PyObject* self, PyObject* args) {
    int n;
    if (!PyArg_ParseTuple(args, "i", &n)) {
        return NULL;
    }
    int value = _fib(n);
    if (value == -1) {
        PyErr_SetString(OverflowError, "Cannot calculate: overflow happens.");
        return NULL;    
    }
    return Py_BuildValue("i", value);
}


static char fib_doc[] = "fib(n): calculating fib number.\n";

static PyMethodDef fib_methods[] = {
    {"fib", fib, METH_VARARGS, fib_doc},
    {NULL}
};

static struct PyModuleDef fibmodule =
{
    PyModuleDef_HEAD_INIT,
    "fib",                        /* name of module */
    "Module for fib numbers.",    /* module documentation, may be NULL */
    -1,                           /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
    fib_methods
};


PyMODINIT_FUNC PyInit_fib(void) {
    PyObject *m;
    m = PyModule_Create(&fibmodule);
    if (m == NULL) {
        return NULL;
    }
    
    OverflowError = PyErr_NewException("fib.OverflowError", NULL, NULL);
    Py_INCREF(OverflowError);
    PyModule_AddObject(m, "error", OverflowError);
    return m;
}
