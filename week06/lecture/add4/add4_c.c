int add2_c(int a, int b) {
    return a + b;
}

int add4_c(int a, int b, int c, int d) {
    return add2_c(a, b) + add2_c(c, d);
}
