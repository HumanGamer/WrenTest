project(WrenLib)

include_directories(lib/wren/src/include)
include_directories(lib/wren/src/vm)
include_directories(lib/wren/src/optional)

set(WREN_SRC
    # Sources
    lib/wren/src/vm/wren_compiler.c
    lib/wren/src/vm/wren_core.c
    lib/wren/src/vm/wren_debug.c
    lib/wren/src/vm/wren_primitive.c
    lib/wren/src/vm/wren_utils.c
    lib/wren/src/vm/wren_value.c
    lib/wren/src/vm/wren_vm.c

    # Sources (Optional)
    lib/wren/src/optional/wren_opt_meta.c
    lib/wren/src/optional/wren_opt_random.c

    # Headers
    lib/wren/src/vm/wren_common.h
    lib/wren/src/vm/wren_compiler.h
    lib/wren/src/vm/wren_core.h
    lib/wren/src/vm/wren_debug.h
    lib/wren/src/vm/wren_math.h
    lib/wren/src/vm/wren_opcodes.h
    lib/wren/src/vm/wren_primitive.h
    lib/wren/src/vm/wren_utils.h
    lib/wren/src/vm/wren_value.h
    lib/wren/src/vm/wren_vm.h

    # Headers (Optional)
    lib/wren/src/optional/wren_opt_meta.h
    lib/wren/src/optional/wren_opt_random.h
)

add_library(WrenLib STATIC ${WREN_SRC})
