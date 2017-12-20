from distutils.core import setup
from distutils.extension import Extension
from Cython.Build import cythonize

ext_modules=[
    Extension("gravity_cy2",
              sources=["gravity_cy2.pyx"],
              libraries=["m"] # Unix-like specific
    )
]

setup(
  name = "gravity_cy2",
  ext_modules = cythonize(ext_modules)
)

