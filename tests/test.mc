int compiled_fn(int arg) {
    int x = arg;
    int y = x + 5;
    do {
        y = y + 2;
    } while (y < 20);

    if (y > 20) {
        return y;
    } else {
        return y - 1;
    }
}
