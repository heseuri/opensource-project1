#include <stdio.h>
#include <dlfcn.h>

int main(void)
{
    void *handle;

    double (*add)(double, double);
    double (*sub)(double, double);
    double (*mul)(double, double);
    double (*div)(double, double);

    handle = dlopen("./lib/libarithmetic.so", RTLD_NOW);

    if (handle == NULL) {
        printf("라이브러리 로딩 실패: %s\n", dlerror());
        return 1;
    }

    dlerror();

    add = dlsym(handle, "add");
    sub = dlsym(handle, "sub");
    mul = dlsym(handle, "mul");
    div = dlsym(handle, "div");

    char *error = dlerror();

    if (error != NULL) {
        printf("함수 검색 실패: %s\n", error);
        dlclose(handle);
        return 1;
    }

    double a = 10;
    double b = 3;

    printf("add: %.2f\n", add(a, b));
    printf("sub: %.2f\n", sub(a, b));
    printf("mul: %.2f\n", mul(a, b));

    if (b != 0)
        printf("div: %.2f\n", div(a, b));

    dlclose(handle);

    return 0;
}
