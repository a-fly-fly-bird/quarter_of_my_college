import ctypes
ll = ctypes.cdll.LoadLibrary
lib = ll('../cpp/build/libhello_library.dylib')
lib.SayHi()
