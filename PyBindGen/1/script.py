# -*- coding: utf-8 -*-

import pybindgen
import sys

mod = pybindgen.Module('MyModule')
mod.add_include('"my_module.h"')
mod.add_function('MyModuleDoAction', None, [])
mod.generate(sys.stdout)
