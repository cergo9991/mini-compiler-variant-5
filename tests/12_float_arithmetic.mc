float scale(float value, float factor) {
    return value * factor;
}

int compiled_fn(int arg) {
    float x = scale(8.0, 0.5);
    do {
        x = x + 0.25;
    } while (x < 5.0);

    if (x == 5.0) {
        return arg + 2;
    }

    return 0;
}
