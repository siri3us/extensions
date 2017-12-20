cdef extern from "Rectangle.h" namespace "shapes":
    cdef cppclass Rectangle:
        Rectangle() except +
        Rectangle(int, int, int, int) except +
        int x0, y0, x1, y1
        int getArea()
        void getSize(int* width, int* heigth)
        void move(int, int)
       
rec_ptr = new Rectangle(1, 2, 3, 4)
try: 
    recArea = rec_ptr.getArea()
finally:
    del rec_ptr
    
cdef extern from "Foo.h":
    cdef cppclass Foo:
        Foo()
  
def func():
    cdef Foo foo
    
cdef class PyRectangle:
    cdef Rectangle c_rect
    def __cinit__(self, int x0, int y0, int x1, int y1):
        self.c_rect = Rectangle(x0, y0, x1, y1)
    def get_area(self):
        return self.c_rect.getArea()
    def get_size(self):
        cdef int width, height
        self.c_rect.getSize(&width, &height)
        return width, height
    def move(self, dx, dy):
        self.c_rect.move(dx, dy)
        
    @property
    def x0(self):
        return self.c_rect.x0
    @x0.setter
    def x0(self):
        def __set__(self, x0): self.c_rect.x0 = x0
