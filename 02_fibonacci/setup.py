from distutils.core import setup, Extension

setup(name='fib', 
      version='1.0',
      ext_modules=[Extension('fib', ['fib.c'])])
