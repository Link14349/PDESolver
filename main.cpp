#include <iostream>
#include "mesh.h"
#include "value.h"
#include <pde.h>
#include <cmath>
using std::string;

int main() {
//    Mesh<Vec2> mesh(1, 1, 0.001);
//    mesh.fill([](float x, float y) {
//        return Vec2(x * x + y, y * y);
//    });
//    while (true) {
//        float x, y;
//        std::cin >> x >> y;
//        std::cout << (string)mesh.partial_x(x, y) << ";" << (string)mesh.partial_y(x, y) << std::endl;
//    }
    PDE<VVec2, Number, Number> pde(
                MeshList<VVec2, Number, Number>(1, 1, 0.001f),
                PartialList<VVec2, Number, Number>(
                    [](float x, float y) -> VVec2 {
                        return VVec2(0, 0);
                    },
                    [](float x, float y) -> Number {
                        return 0;
                    },
                    [](float x, float y) -> Number {
                        return 0;
                    }
        )
    );
    return 0;
}
