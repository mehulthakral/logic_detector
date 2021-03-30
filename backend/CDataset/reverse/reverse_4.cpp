int reverse(int x) {
    int ans = 0, copy = abs(x);

    while (copy > 0) {
        if (INT32_MAX / 10 < ans) return 0;  // check overflow
        ans = ans * 10 + copy % 10;
        copy /= 10;
    }

    return x < 0 ? -ans : ans;
}
