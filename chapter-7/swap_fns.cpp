// Drill 1 - Swap functions

auto swap_r(int &a, int &b) -> void {
    int temp = a;
    a = b;
    b = temp;
};

auto swap_cr(const int &a, const int &b) -> void {
    int temp = a;
    a = b;
    b = temp;
};

auto swap_v(int a, int b) -> void {
    int temp = a;
    a = b;
    b = temp;
};

int main() {
    int x = 7;
    int y = 9;
    swap_r(x, y); // replace ? by v, r, or cr
    swap_cr(7, 9);
    const int cx = 7;
    const int cy = 9;
    swap_v(cx, cy);
}
