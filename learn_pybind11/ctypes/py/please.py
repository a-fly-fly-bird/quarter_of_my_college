import ctypes

ll = ctypes.cdll.LoadLibrary

lib = ll('/Users/tanyong/Desktop/code/demo/cpp/build/libplease.dylib')

class CarInfo(ctypes.Structure):
    _fields_ = [("name", ctypes.c_char_p),
                ("battery_life", ctypes.c_float),
                ("rpm", ctypes.c_int)]

ci = lib.PyGetCarInfo

ci.restype = ctypes.c_void_p

info: CarInfo = ci()

print(info)
