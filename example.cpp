//DIEGO_A2_2183
/*
#include <algorithm>
#include <iostream>

void merge(std::vector<int>::iterator begin_A, std::vector<int>::iterator end_A,
           std::vector<int>::iterator begin_B, std::vector<int>::iterator end_B) {
    std::vector<int> C(end_B - begin_A);
    auto begin_C = C.begin();
    auto begin_const = begin_A;
    while ((begin_B != end_B) || (begin_A != end_A)) {
        if ((begin_A == end_A) && (begin_B != end_B)) {
            *begin_C = *begin_B;
            ++begin_C;
            ++begin_B;
            continue;
        }
        if ((begin_A != end_A) && (begin_B == end_B)) {
            *begin_C = *begin_A;
            ++begin_C;
            ++begin_A;
            continue;
        }
        if (*begin_A < *begin_B) {
            *begin_C = *begin_A;
            ++begin_C;
            ++begin_A;
        } else {
            *begin_C = *begin_B;
            ++begin_C;
            ++begin_B;
        }
    }
    std::copy(C.begin(), C.end(), begin_const);
}

void merge_sort(std::vector<int>::iterator begin, std::vector<int>::iterator end, size_t size) {
    if (size > 1) {
        size_t left = size / 2;
        size_t right = size - left;
        std::vector<int>::iterator middle = begin;
        middle += left;
        if (size > 2) {
            merge_sort(begin, middle, left);
            merge_sort(middle, end, right);
            merge(begin, middle, middle, end);
        } else {
            merge(begin, middle, middle, end);
        }
    }
}

int main() {
    int n, temp;
    std::cin >> n;
    std::vector<int> diego;
    diego.reserve(n);
    for (int i = 0; i < n; ++i) {
        std::cin>> temp;
        diego.push_back(temp);
    }
    merge_sort(diego.begin(), diego.end(), diego.size());
    auto  it = std::unique(diego.begin(), diego.end());
    diego.resize(it - diego.begin());
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> temp;
        int interest = 0;
        auto bound = std::lower_bound(diego.begin(), diego.end(), temp);
        auto begin = std::begin(diego);
        interest = bound - begin;
        std::cout << interest << '\n';
    }
}
*/

//PAINTS_B1_2183
/*
#include <algorithm>
#include <iostream>

typedef std::vector<std::pair<int, int>> vec_pairs;

void merge(vec_pairs::iterator begin_A, vec_pairs::iterator end_A,
           vec_pairs::iterator begin_B, vec_pairs::iterator end_B) {
    vec_pairs C(end_B - begin_A);
    auto begin_C = C.begin();
    auto begin_const = begin_A;
    while ((begin_B != end_B) || (begin_A != end_A)) {
        if ((begin_A == end_A) && (begin_B != end_B)) {
            *begin_C = *begin_B;
            ++begin_C;
            ++begin_B;
            continue;
        }
        if ((begin_A != end_A) && (begin_B == end_B)) {
            *begin_C = *begin_A;
            ++begin_C;
            ++begin_A;
            continue;
        }
        if (*begin_A < *begin_B) {
            *begin_C = *begin_A;
            ++begin_C;
            ++begin_A;
        } else {
            *begin_C = *begin_B;
            ++begin_C;
            ++begin_B;
        }
    }
    std::copy(C.begin(), C.end(), begin_const);
}

void merge_sort(vec_pairs::iterator begin, vec_pairs::iterator end, size_t size) {
    if (size > 1) {
        size_t left = size / 2;
        size_t right = size - left;
        vec_pairs::iterator middle = begin;
        middle += left;
        if (size > 2) {
            merge_sort(begin, middle, left);
            merge_sort(middle, end, right);
            merge(begin, middle, middle, end);
        } else {
            merge(begin, middle, middle, end);
        }
    }
}

int main() {
    int n;
    int a, b;
    vec_pairs Mal;
    std::cin>> n;
    Mal.reserve(n);
    for (int i = 0; i < n; ++i) {
        std::cin>> a >> b;
        Mal.push_back(std::make_pair(a, b));
    }
    merge_sort(Mal.begin(), Mal.end(), Mal.size());
    std::pair<int, int> interval(0, 0);
    int count = 0;
    for (auto el : Mal) {
        if (el.first <= interval.second + 1) {
            if (el.second > interval.second) {
                count += el.second - interval.second;
                interval.second = el.second;
            }
        }
        if (el.first > interval.second) {
            interval = el;
            count += el.second - el.first + 1;
        }
    }
    std::cout << count;
}
*/

/*
#include <algorithm>
#include <iostream>

void exchange_max(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    std::vector<int>::iterator temp = begin++;
    if (begin != end) {
        for (; begin != end; ++begin) {
            if (*temp < *begin) {
                temp = begin;
            }
        }
        if (*temp != *(--end))
            std::swap(*temp, *(end));
    }
}

void max_sort(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    while (begin != end) {
        exchange_max(begin, end);
        --end;
    }
}

int main() {
    int n, temp;
    std::vector<int> A;
    std::cin>> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> temp;
        A.push_back(temp);
    }
    if (!(A.empty()) || (A.size() > 1)) {
        max_sort(A.begin(), A.end());
    }
    for (auto el : A) {
        std::cout << el << ' ';
    }
    std::cout << std::endl;
}
*/

/*
#include <algorithm>
#include <iostream>

std::vector<int>::iterator partition(std::vector<int>::iterator begin,
                                     std::vector<int>::iterator end,
                                     int pred) {
    std::vector<int>::iterator end_const = end;
    --end;
    int cnt = 0;
    int cnt_M = 0;
    while (begin <= end && begin != end_const) {
        ++cnt_M;
        if (*end < pred) {
            ++cnt;
            std::swap(*begin, *end);
            ++begin;
        } else {
            --end;
        }
    }
    if (begin == end_const)
        --begin;
    std::cout<< cnt << '\n' << cnt_M - cnt << '\n';
    return begin;
}

int main() {
    std::vector<int> A;
    int n, pred, temp;
    std::cin>> n;
    for (int _ = 0; _ < n; ++_) {
        std::cin>> temp;
        A.push_back(temp);
    }
    std::cin>> pred;
    if (n > 0)
        partition(A.begin(), A.end(), pred);
    else
        std::cout<< "0\n0\n";
}
*/
