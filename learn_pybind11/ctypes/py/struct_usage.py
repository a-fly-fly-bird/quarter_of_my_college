import ctypes

ll = ctypes.cdll.LoadLibrary

lib = ll("/Users/tanyong/Desktop/code/demo/cpp/build/libstruct_usage.dylib")


class Student(ctypes.Structure):
    _fields_ = [("name", ctypes.c_char_p),
                ("fScore", ctypes.c_float * 3)
                ]

su = Student()

su.name = b"test-sdk"

PARAM = ctypes.c_float * 3

fScore = PARAM()

fScore[0] = 55.1
fScore[1] = 33.2
fScore[2] = 51.3

su.fScore = fScore

Display = lib.CppDisplay
Display.restype = None
Display.argtypes = [Student]

Display(su)

