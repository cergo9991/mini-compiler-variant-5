int compiled_fn(int arg) {
    int i = 0;
    int sum = 0;
    do {
        sum = sum + i;
        i = i + 1;
    } while (i < arg);
    return sum;
}
