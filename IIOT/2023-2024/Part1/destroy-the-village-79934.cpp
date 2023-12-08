// @check-accepted: examples Nsmall N1000 N10000 no-limits
#include <functional>
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    size_t n;
    std::cin >> n;

    if (n == 1) {
        std::cout << "0\n";
        return 0;
    }

    std::vector<long long> v(n);
    for (auto &x : v) std::cin >> x;

    std::vector<size_t> step(n);
    step[0] = 0;
    step[n - 1] = n - 1;

    std::vector<size_t> stack{0};
    for (size_t i = 1; i + 1 < n; ++i) {
        if (v[i] - v[i - 1] <= v[i + 1] - v[i]) {
            while (stack.back() > 0 && v[stack.back()] - v[stack.back() - 1] <=
                                           v[i + 1] - v[stack.back()]) {
                stack.pop_back();
            }
            step[i] = stack.back();
        }

        stack.push_back(i);
    }

    stack.assign(1, n - 1);
    for (size_t i = n - 2; i >= 1; --i) {
        if (v[i + 1] - v[i] < v[i] - v[i - 1]) {
            while (stack.back() < n - 1 &&
                   v[stack.back() + 1] - v[stack.back()] <
                       v[stack.back()] - v[i - 1]) {
                stack.pop_back();
            }
            step[i] = stack.back();
        }

        stack.push_back(i);
    }

    stack.clear();

    std::function<size_t(size_t)> find = [&](size_t i) {
        return step[i] == i ? i : step[i] = find(step[i]);
    };

    for (size_t i = 0; i < n; ++i) {
        std::cout << n - 1 - find(i) << ' ';
    }
    std::cout << '\n';
}
