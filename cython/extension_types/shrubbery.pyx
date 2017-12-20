cdef class Shrubbery:
    cdef public int width, height
    cdef readonly float depth
    def __init__(self, int width, int height, float depth = 0):
        self.width = width
        self.height = height
        self.depth = depth
    def describe(self):
        print("This shrubbery is", self.width, "by", self.height, "with depth", self.depth)
     
