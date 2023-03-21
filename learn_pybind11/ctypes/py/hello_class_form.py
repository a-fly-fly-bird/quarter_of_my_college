import ctypes

from numpy.ctypeslib import ndpointer

ll = ctypes.cdll.LoadLibrary
lib = ll("../cpp/build/libhello_class_form.dylib")

lib.myfunc1.restype = ctypes.c_uint64

res = lib.myfunc1()

res = ctypes.string_at(res)

print(res)
