#include "rsl/rsl.h"
namespace rslCache{
fn main(){;
    ptr<int> x = new int;;
    print(x);;
    *x = 5;;
    print(*x);;
    x.clear() // Deletes memory;
;
    print(x); // Won't print anything;
    print(*x) //this will not either;
;
};
}
