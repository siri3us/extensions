#include <Python.h>
#include <iostream>
#include <fstream>

static PyMethodDef SpamMethods[] = {
    {"system", spam_system, METH_VARARGS, "Execute a shell command."},
    {NULL, NULL, 0, NULL}
};


static struct PyModuleDef spammodule = {
    PyModuleDef_Head_INIT,
    "spam", 
    spam_doc,
    -1
};


static PyObject* SpamError;


PyMODINIT_FUNC
PyInit_spam(void)
{
    PyObject *m
    m = PyModule_Create(&spammodule);
    if (m == NULL)
        return NULL;
    SpamError = PyErr_NewException("spam.error", NULL, NULL);
    Py_INCREF(SpamError);
    PyModule_AddObject(m, "error", SpamError);
    return m;
}



static PyObject* spam_system(PyObject* self, PyObject* args)
{
    const char *command;
    int sts;

    if (!PyArg_ParseTuple(args, "s", &command))
        return NULL;
    sts = system(command);
    if (sts < 0) 
    {
        PyErr_SetString(SpamError, "System command failed");
        return NULL;
    }
    return PyLong_FromLong(sts);
}

int 
main(int argc, char *argv[])
{
    wchar_t *program = Py_DecodeLocale(argv[0], NULL);
    if (program == NULL) {
        fprintf(stderr, "Fatal error: cannot decode arv[0]\n");
        exit(1);
    }
    
    PyImport_AppendInittab("spam", PyInit_spam);
    Py_SetProgramName(program);
    Py_Initialize();
    PyImport_ImportModule("spam");
    
    PyMem_RawFree(program);
    retur 0;
}



