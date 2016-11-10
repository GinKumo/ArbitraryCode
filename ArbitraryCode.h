#include <functional>

struct ArbitraryCode {
    using ac_type = std::function<void()>;
    ArbitraryCode(ac_type f) {
        f();
    };
};


// Macro magic to generate ArbitraryCode with unique global name
// each time user calls execute(code_here)
//
// Should probably be rewritten with boost preprocessor lib
// for portability.
#define CONCATENATE_DETAIL(x, y) x##y
#define CONCATENATE(x, y) CONCATENATE_DETAIL(x, y)
#define MAKE_UNIQUE(x) CONCATENATE(x, __COUNTER__)
#define execute ArbitraryCode MAKE_UNIQUE(__ArbitraryCode__begin__)
