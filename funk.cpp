#include <iostream>
#include <vector>

double funk(std::vector<int>& fuct, double& yuo) {
    int fh;
    std::cin >> fh;

    if (fh != 0) {
        yuo += fh;
        fuct.push_back(fh);
        funk(fuct, yuo);
    } else {
        return yuo;
    }
}

int main() {
    double yuo = 0;
    std::vector<int> fuct;

    double result = funk(fuct, yuo);
    std::cout << result << std::endl;

    return 0;
}
