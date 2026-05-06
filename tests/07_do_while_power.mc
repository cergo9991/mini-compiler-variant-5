int compiled_fn(int arg) {
    int x = 1;
    do {
        x = x * 2;
    } while (x < arg);
    return x;
}
