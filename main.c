#include <Python.h>
#include <stdio.h>

char hellofunc_docs[] = "Hello world description.";


PyObject * hello(PyObject *self, PyObject *args) {
    puts("Hello World");
    return PyLong_FromLong(0);
}

PyMethodDef hello_funcs[] = {
    { "hello", (PyCFunction)hello, METH_NOARGS, hellofunc_docs},
    { NULL}
};

char hellomod_docs[] = "This is hello world module.";

PyModuleDef hello_mod = {
    PyModuleDef_HEAD_INIT,
    "hello",
    hellomod_docs,
    -1,
    hello_funcs,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC PyInit_hello(void) {
    return PyModule_Create(&hello_mod);
}
