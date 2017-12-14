import ctypes

class MyStruct(ctypes.Structure):
    _fields_ = [("a", c_int),
                ("b", c_int)]
